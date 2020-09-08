# 就是这篇文章让你学会了自定义LayoutManager

最开始我在学习自定义LayoutManager的时候，也是网上搜文章，看博客。刚开始看的时候觉得还是那么回事，但是在慢慢的深入LayoutManager源码才发现有很多的博客都是不合格，乃至可以说是很误导人的，所以我才想自己写一篇关于自定义LayoutManager的文章，希望能帮助到一部分人。

## 1. 一些自定义LayoutManager优秀文章推荐

前面虽然说有很多博客是不合格的，但是同样还是有一些优秀的作者的博客对在下启发很大，特别是`Dave`大神`building-a-recyclerview-layoutmanager-part`的系列的文章，真的是讲得不能再棒了！虽然已经是14年的文章，但是放在当下来看，依然是自定义LayoutManager相关文章的顶峰，虽然文章是英文，但是还是强烈推荐阅读！

[Building a RecyclerView LayoutManager – Part 1](http://wiresareobsolete.com/2014/09/building-a-recyclerview-layoutmanager-part-1/)

[Building a RecyclerView LayoutManager – Part 2](http://wiresareobsolete.com/2014/09/recyclerview-layoutmanager-2/)

[Building a RecyclerView LayoutManager – Part 3](http://wiresareobsolete.com/2015/02/recyclerview-layoutmanager-3/)

无意中发现了有B站大佬翻译了`Dave`大神讲解自定义LayoutManager的培训视频，这简直是宝藏，建议收藏多次观看。

[Mastering RecyclerView Layouts](https://www.bilibili.com/video/BV1fW411A76o)

其次就是**张旭童**在CSDN发布`掌握自定义LayoutManager`相关博客，特别是文章中的常见误区和注意事项，建议多次阅读。

[https://blog.csdn.net/zxt0601/article/details/52948009](https://blog.csdn.net/zxt0601/article/details/52948009)

特别是这句话道出了自定义LayoutManager的真谛：`一个合格的LayoutManager，childCount数量不应大于屏幕上显示的Item数量，而scrapCache缓存区域的Item数量应该是0`，这里建议多读几遍，加深理解。

最后就是**陈小媛**的`Android自定义LayoutManager第十一式之飞龙在天`，这么大佬的思路总是那么奇特，逻辑总是那么清晰。

https://blog.csdn.net/u011387817/article/details/81875021

## 2. 先讲自定义LayoutManager的常规套路

1. 继承`RecyclerView.LayoutManager`并实现`generateDefaultLayoutParams()`方法。
2. 按需，重写`onMeasure()`或`isAutoMeasureEnabled()`方法。
3. 重写`onLayoutChildren()`开始填充子View。
4. 重写`canScrollHorizontally()`和`canScrollVertically()`方法支持滑动。
5. 重写`scrollHorizontallyBy()`和`scrollVerticallyBy()`方法在滑动的时候填充view和回收view。
6. 按需，重写`scrollToPosition()`和`smoothScrollToPosition()`方法支持。
7. 解决软键盘弹出或收起`onLayoutChildren()`方法重新调用的问题。

## 3. 再说自定义LayoutManager容易进入的误区

1. 使用RecyclerView或者说继承了LayoutManager就自带了复用机制和视图回收
2. 未正确的重写onMeasure()和isAutoMeasureEnabled()方法
3. onLayoutChildren()时直接加载了全部itemView
4. 未支持scrollToPosition()或smoothScrollToPosition()方法
5. 未解决软键盘弹出或收起onLayoutChildren()方法重新调用的问题。

### 3.1 使用RecyclerView或者说继承了LayoutManager就自带了复用机制和视图回收？

我发现很多人把RecyclerView想得太完美了，认为RecyclerView天生就自带了复用机制和视图回收，只要使用RecyclerView根本不用关心加载item的数量。其实不用很仔细的阅读RecyclerView的源码也能发现，RecyclerView只不过是一个提供了`多级缓存`的`超级ViewGroup`而已。并且RecyclerView只是将自己的`onLayout`方法完全委托给了LayoutManager而已，所以继承LayoutManager也不会自带复用机制和视图回收。

用`LinearLayoutManager`举例，在LinearLayoutManager源码中有一个`recycleByLayoutState()`方法，它在滚动填充itemView时调用，用来回收超出屏幕的itemView，所以我们在自定义LayoutManager的时候要自己注意，什么时候该回收itemView。

```java
    @Override
    public int scrollHorizontallyBy(int dx, RecyclerView.Recycler recycler,
            RecyclerView.State state) {
				...
        return scrollBy(dx, recycler, state);
    }    

    int scrollBy(int delta, RecyclerView.Recycler recycler, RecyclerView.State state) {
      ...
        fill(recycler, mLayoutState, state, false);
      ...
    }

		int fill(RecyclerView.Recycler recycler, LayoutState layoutState,
            RecyclerView.State state, boolean stopOnFocusable) {
      recycleByLayoutState(recycler, layoutState);
      ...
      layoutChunk()
      ...
      recycleByLayoutState(recycler, layoutState); 
    }

		 void recycleByLayoutState(){
       ...
       if (layoutState.mLayoutDirection == LayoutState.LAYOUT_START) {
            recycleViewsFromEnd(recycler, scrollingOffset, noRecycleSpace);
        } else {
            recycleViewsFromStart(recycler, scrollingOffset, noRecycleSpace);
        }
     }
      
```

### 3.2 未正确的重写onMeasure()和isAutoMeasureEnabled()方法

这个问题其实也蛮严重的，说简单点就是没有适配`wrap_content`。从上面自定义LayoutManager的常规套路中的`第1点`可知我们在继承LayoutManager的时候就必须实现`generateDefaultLayoutParams()`方法，所以下面这段代码看上去就很合理。

```java
    @Override
    public RecyclerView.LayoutParams generateDefaultLayoutParams() {
        return new RecyclerView.LayoutParams(ViewGroup.LayoutParams.WRAP_CONTENT,
                ViewGroup.LayoutParams.WRAP_CONTENT);
    }
```

当然这段代码其实是没有任何问题的，它只是给每个itemView装饰了一个LayoutParams而已。但是很多人出于习惯的原因，在布局中添加RecyclerView时，直接就是`width=match_parent`，`height=match_parent`，这样写当然不会出问题，因为这样在RecyclerView测量结束后，LayoutManager调用`getWidth()`，`getHeight()`就直接是parent的宽高，但是如果将width或height改为`wrap_content`，你就会发现getWidth或getHeight等于0。

篇幅原因，具体的细节下面再讲。

### 3.3 onLayoutChildren()时直接加载了全部itemView

网上博客以及Github上有一些Demo，普遍存在下面这种写法：

```java
 for (int i = 0; i < getItemCount(); i++) {
            View view = recycler.getViewForPosition(i);
            addView(view);
            ......
 }
```

有一说一，能写出这种写法的人真的不是在搞笑吗？在onLayoutChildren的时候直接遍历itemCount然后addView，这不是在作死吗！自己就不能把itemCount设个大点的数试试会不会卡死UI渲染吗。当我有这种想法，而且还想去评论区讨教讨教的时候，我又发现了上面那种写法的变种，罢了罢了，这喷子不当也罢😏😏😏。

```java
 for (int i = 0; i < getItemCount(); i++) {
            View view = recycler.getViewForPosition(i);
            addView(view);
            ......
              记录一些item的宽高，位置等信息
            .....
            recyler.recycleView(view)
 }
```

### 3.4 未支持scrollToPosition()或smoothScrollToPosition()方法

这个问题严谨的来讲也不算什么大问题，但是私以为一个合格的LayoutManager的还是应该去适配这两个方法，毕竟RecyclerView的scrollToPosition和smoothScrollToPosition只是对LayoutManager这两个方法的封装，特别是一些发布到Github上的开源库。

### 未解决软键盘弹出或收起onLayoutChildren()方法重新调用的问题

这个问题我发现大多数的人都没注意到，而且有一些开源库也是存在这个问题的。问题出现的根源就是在有EditText获取到焦点导致软键盘弹起或者收起的时候，LayoutManager会重新回调`onLayoutChildren()`方法。如果一个LayoutManager的onLayoutChildren写得不够合理，就会给使用的人带来困扰，详细的内容会放在下面开始自定义LayoutManager再讲。

话说到这里，我在看`LinearLayoutManager`源码又一次对Google工程师深深的折服，在LinearLayoutManager的`onLayoutChildren`方法中有一段代码就是对这种问题的处理，并且还是升级版。

```java
 final View focused = getFocusedChild()
 ...
 else if (focused != null && (mOrientationHelper.getDecoratedStart(focused)
                        >= mOrientationHelper.getEndAfterPadding()
                || mOrientationHelper.getDecoratedEnd(focused)
                <= mOrientationHelper.getStartAfterPadding())) {
      mAnchorInfo.assignFromViewAndKeepVisibleRect(focused, getPosition(focused));
}
```

`assignFromViewAndKeepVisibleRect`方法是关键，有兴趣的可以自己去看看源码。大概逻辑就是：获取到RecyclerView中获取到焦点的那个itemView和它的position，并开始计算其位置，让它保持在软键盘上面的可见范围内。

## 一些有用的Api

在开始自定义LayoutManager前，先解释一些Api的用法，这样可以更快的进入主题。

### 获取一个View

```kotlin
 val view = recycler.getViewForPosition(position)
```

这个方法会从`Recycler`中获取到一个不会为`null`的View，如果position超过itemCount或小于0，就会直接抛出异常。内部代码逻辑就是从不同的缓存中拿View，有就直接返回这个View，没有就用`onCreateViewHolder`创建并返回。

`Recycler`类可以简单理解为一个回收管理站，需要View时就向它要，不需要时就丢给它。

### 将View添加到RecyclerView中

```java
addDisappearingView(View child)
addDisappearingView(View child, int index)
  
addView(View child)
addView(View child, int index)
```

`addDisappearingView`方法主要用于支持预测动画，例如：notifyItemRemoved时的删除动画

`addView`方法更常用，只要是添加View都需要用到它。

### 测量View

```java
measureChild(@NonNull View child, int widthUsed, int heightUsed)
measureChildWithMargins(@NonNull View child, int widthUsed, int heightUsed)
```

两个方法都是用来测量View的相关信息，从名字我们也能看出，一个方法是会带上`margin`计算，另外一个则不会。

`widthUsed`和`heightUsed`也能从名称看出端倪，一般传0就可以了，跟着`LinearLayoutManager`写就对了。

**注意：**测量View也不一定要使用这两个方法，在特殊的情况下，也可以自己写测量的方法，比如在`StaggeredGridLayoutManager`中就是自己重写的测量方法`measureChildWithDecorationsAndMargin()`，以及我的一个开源库[PickerLayoutManager](https://github.com/simplepeng/PickerLayoutManager)中在`onMeasure`中直接使用了`view.measure()`这种原生方法。

### 摆放View

```java
layoutDecorated(@NonNull View child, int left, int top, int right, int bottom)
layoutDecoratedWithMargins(@NonNull View child, int left, int top, int right,
                int bottom) {
```

这两个方法没啥好说的，就是对`view.layout()`的封装，只要写过自定义ViewGroup的人应该也不会陌生。

### 获取View的相关信息

```java
int getPosition(@NonNull View view) 
```

获取View的layout position，这个方法十分有用。

```java
int getDecoratedMeasuredWidth(@NonNull View child)
int getDecoratedMeasuredHeight(@NonNull View child)
```

获取View的宽高，并且是包含了ItemDecoration的占比。

```java
int getDecoratedTop(@NonNull View child)
int getDecoratedLeft(@NonNull View child)
int getDecoratedRight(@NonNull View child)
int getDecoratedBottom(@NonNull View child)
```

获取View的left，top，right，bottom距离RecyclerView边缘的距离，同样包含了了ItemDecoration的占比。

### 移动View

```java
offsetChildrenHorizontal(@Px int dx)
offsetChildrenVertical(@Px int dy)
```

水平或垂直方向的移动全部子View，看源码得知其实就是遍历调用了子View的`offsetTopAndBottom`或`offsetLeftAndRight`方法，这两个方法在自定义ViewGroup移动子View时也经常用到。

### 回收View

```java
detachAndScrapAttachedViews(@NonNull Recycler recycler)
detachAndScrapView(@NonNull View child, @NonNull Recycler recycler)
detachAndScrapViewAt(int index, @NonNull Recycler recycler)
  
removeAndRecycleAllViews(@NonNull Recycler recycler)
removeAndRecycleView(@NonNull View child, @NonNull Recycler recycler)
removeAndRecycleViewAt(int index, @NonNull Recycler recycler)
```

上面几个方法只要记住是`detachAndScrap`开头的就是轻量级的回收View，马上又要添加View回来。`removeAndRecycle`开头的就是加强版的回收View，当再次添加View回来时会执行`onBindViewHolder`方法。

我看网上没啥博客真正讲清楚什么时候该用哪个方法来回收View的，这里有个简单的办法区分什么时候该用哪一个回收View的方法，那就是：

* 在`onLayoutChildren`回收View使用`detachAndScrap`的系列方法，因为onLayoutChildren方法会连续多次调用，`detachAndScrap`系列的方法就是用在这时候。

* 在`滚动发生后`要回收超出屏幕不可见的View时用`removeAndRecycle`的系列方法。

别问我为啥知道，因为我看`LinearLayoutManager`和`StaggeredGridLayoutManager`也是这么用的，嘻嘻！read the fucking source code~

### OrientationHelper帮助类

![img_orientation_helper.png](https://i.loli.net/2020/09/08/AD6sjHya9NnpcFW.png)

这个帮助类值得好好夸赞，这也是我在阅读`LinearLayoutManager`源码时发现的，OrientationHelper是一个抽象类，抽象了大量便利的方法，并且提供了两个静态方法`createHorizontalHelper`和`createVerticalHelper`用来创建相应方向的帮助类供开发者使用。使用OrientationHelper可以大大减少如下我在[StackLayoutManager](https://github.com/simplepeng/StackLayoutManager)的样板代码。

```kotlin
    /**
     * 移动所有子view
     */
    private fun offsetChildren(amount: Int) {
        if (orientation == HORIZONTAL) {
            offsetChildrenHorizontal(amount)
        } else {
            offsetChildrenVertical(amount)
        }
    }
...
    private fun getTotalSpace(): Int {
        return if (orientation == HORIZONTAL) {
            width - paddingLeft - paddingRight
        } else {
            height - paddingTop - paddingBottom
        }
    }
```

## 正式开始自定义LayoutManager

现在我们开始正式讲解如何自定义一个LayoutManager，大概步骤就是如上面`自定义LayoutManager的常规套路`一样，并且我会用我写的两个开源库[PickerLayoutManager](https://github.com/simplepeng/PickerLayoutManager)和[StackLayoutManager](https://github.com/simplepeng/StackLayoutManager)来讲解，喜欢的可以`star`一下。

| https://github.com/simplepeng/StackLayoutManager             | https://github.com/simplepeng/PickerLayoutManager            |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| ![img_stack_layout_manager.png](https://i.loli.net/2020/09/08/iHwhxlT5Ddm2ECg.png) | ![img_picker_layout_manager.png](https://i.loli.net/2020/09/08/Bk1pQf43EyOjxIe.png) |



### 继承LayoutManager并实现generateDefaultLayoutParams()方法

这没啥好说的，generateDefaultLayoutParams是抽象方法，继承LayoutManager就必须实现，你自定义的LayoutManager的itemView支持啥LayoutParams就写哪种，比如我写的[PickerLayoutManager](https://github.com/simplepeng/PickerLayoutManager)和[StackLayoutManager](https://github.com/simplepeng/StackLayoutManager)就是不同的实现。

```kotlin
class PickerLayoutManager:: RecyclerView.LayoutManager(){
      override fun generateDefaultLayoutParams(): RecyclerView.LayoutParams {
        return if (orientation == HORIZONTAL) {
            RecyclerView.LayoutParams(
                RecyclerView.LayoutParams.WRAP_CONTENT,
                RecyclerView.LayoutParams.MATCH_PARENT
            )
        } else {
            RecyclerView.LayoutParams(
                RecyclerView.LayoutParams.MATCH_PARENT,
                RecyclerView.LayoutParams.WRAP_CONTENT
            )
        }
    }
}
```

```kotlin
class StackLayoutManager: RecyclerView.LayoutManager(){
      override fun generateDefaultLayoutParams(): RecyclerView.LayoutParams {
        return RecyclerView.LayoutParams(
            ViewGroup.LayoutParams.WRAP_CONTENT,
            ViewGroup.LayoutParams.WRAP_CONTENT
        )
    }
}
```

### 重写onMeasure()或isAutoMeasureEnabled()方法。

```kotlin
class PickerLayoutManager:: RecyclerView.LayoutManager(){
      override fun onMeasure(
        recycler: RecyclerView.Recycler,
        state: RecyclerView.State,
        widthSpec: Int,
        heightSpec: Int
    ) {
        if (state.itemCount == 0) {
            super.onMeasure(recycler, state, widthSpec, heightSpec)
            return
        }
        if (state.isPreLayout) return

        //假定每个item的宽高一直，所以用第一个view计算宽高，
        //这种方式可能不太好
        val itemView = recycler.getViewForPosition(0)
        addView(itemView)
        //这里不能用measureChild方法，具体看内部源码实现，内部getWidth默认为0
//        measureChildWithMargins(itemView, 0, 0)
        itemView.measure(widthSpec, heightSpec)
        mItemWidth = getDecoratedMeasuredWidth(itemView)
        mItemHeight = getDecoratedMeasuredHeight(itemView)
        //回收这个View
        detachAndScrapView(itemView, recycler)

        //设置宽高
        setWidthAndHeight(mItemWidth, mItemHeight)
    }
  
      private fun setWidthAndHeight(
        width: Int,
        height: Int
    ) {
        if (orientation == HORIZONTAL) {
            setMeasuredDimension(width * visibleCount, height)
        } else {
            setMeasuredDimension(width, height * visibleCount)
        }
    }
}
```

```kotlin
class StackLayoutManager: RecyclerView.LayoutManager(){
      override fun isAutoMeasureEnabled(): Boolean {
        return true
    }
}
```

从上面代码可以看出，`PickerLayoutManager`重写了`onMeasure()`，`StackLayoutManager`重写了`isAutoMeasureEnabled()`方法，跟上面常见误区中的讲得一致。

### 重写onLayoutChildren()开始填充子View。

从这个方法开始，[PickerLayoutManager](https://github.com/simplepeng/PickerLayoutManager)和[StackLayoutManager](https://github.com/simplepeng/StackLayoutManager)的套路都是一致的：计算剩余空间->addView()->measureView()->layoutView()。因为都是模仿`LinearLayoutManager`的写法，所以下面开始只用StackLayoutManager的`伪代码`作代码示例，特别的地方再用不同实现的代码做比较。

记住下面的大多数都是`伪代码`，不要直接复制运行，因为`StackLayoutManager`支持的属性很多，包括了如同`LinearLayoutManager`的`reverseLayout`和`orientation`等，并且下面的示例只会讲`orientation==HORIZONTAL`的代码实现，主要是怕代码逻辑太复杂不好理解，想看具体源码的可以点击上面的源码链接查看。

```kotlin
    override fun onLayoutChildren(recycler: RecyclerView.Recycler, state: RecyclerView.State) {

        //轻量级的将view移除屏幕
        detachAndScrapAttachedViews(recycler)
        //开始填充view

        var totalSpace = width - paddingRight
        var currentPosition = 0

        var left = paddingLeft
        var top = paddingTop
        var right = 0
        var bottom = 0
        //模仿LinearLayoutManager的写法，当可用距离足够和要填充
        //的itemView的position在合法范围内才填充View
        while (totalSpace > 0 && currentPosition < state.itemCount) {
            val view = recycler.getViewForPosition(currentPosition)
            addView(view)
            measureChild(view, 0, 0)

            right = left + getDecoratedMeasuredWidth(view)
            bottom = top + getDecoratedMeasuredHeight(view)
            layoutDecorated(view, left, top, right, bottom)

            currentPosition++
            left += getDecoratedMeasuredWidth(view)
          	//关键点
            totalSpace -= getDecoratedMeasuredWidth(view)
        }
        //layout完成后输出相关信息
        logChildCount("onLayoutChildren", recycler)
    }
```

上面的代码很简单了，相信写过自定义ViewGroup的人都能看懂。上面代码很简单的实现了一个`横向的LinearLayoutManager`，如图所示：

![img_blog_lm_on_layout.png](https://i.loli.net/2020/09/08/dOY2TqHgxeS1oL8.png)

并且在`layout`结束后，增加了一个输出`childCount`的方法。

```kotlin
    private fun logChildCount(tag: String, recycler: RecyclerView.Recycler) {
        Log.d(tag, "childCount = $childCount -- scrapSize = ${recycler.scrapList.size}")
    }
```

> D/onLayoutChildren: childCount = 9 -- scrapSize = 0
> D/onLayoutChildren: childCount = 9 -- scrapSize = 0
> D/onLayoutChildren: childCount = 9 -- scrapSize = 0

从图中可以看出，我们摆放了position`0-8`的itemView，所以`childCount=9`，并且`scrapSize=0`，所以我们这个方法写得是合格的。因为我们用`totalSpace > 0`作了`while`表达式的判断，所以并不用关心`itemCount`有多大。

### 重写canScrollHorizontally()和canScrollVertically()方法支持滑动。

上面已经初始化摆放了一些itemView，但是RecyclerView还是不能滑动的，不信的可以试试。我们必须重写了下面两个方法，RecyclerView才会将滑动的事件交给LayoutManager。

```kotlin
    override fun canScrollHorizontally(): Boolean {
        return orientation == HORIZONTAL
    }

    override fun canScrollVertically(): Boolean {
        return orientation == VERTICAL
    }
```

没啥好说的，想支持哪个方向的滑动，就返回`true`。同时返回true都可以，那就是同时支持上下左右滑动，类似Dave大神那种表格类型的LayoutManager。

### 重写scrollHorizontallyBy()和scrollVerticallyBy()方法在滑动的时候填充view和回收view。

```kotlin
override fun scrollHorizontallyBy(
    dx: Int,
    recycler: RecyclerView.Recycler,
    state: RecyclerView.State
): Int {
    return super.scrollHorizontallyBy(dx, recycler, state)
}
```

这里先讲一下`scrollHorizontallyBy`和`scrollVerticallyBy`两个滑动方法的概念：

* 我看一些博客下有些评论说："实现这两个方法也不能滑动啊！"，说是说这两个方法是滑动的方法，但是其实这两个方法只会返回手指在RecyclerView上的移动距离给我们，就是方法中对应的`dx`和`dy`，`dx>0`就是手指`从左滑向右`，`dy>0`就是手指`从上滑向下`，同理`dx,dy<0`则反，真正移动View的事情还是要开发者自己实现，`LinearLayoutManager`中就简单的用`offsetChildren`方法实现的移动。或者也有的评论说："LayoutManager封装的不够合理，滑动还要我们自己实现！"，讲道理说这种话的小朋友还是世面见少了，他肯定没见过可以斜着拖的LayoutManager，或者在滑动的时候对itemView有种各种变换的LayoutManager，嘻嘻。
* 两个方法的`返回值`同样也十分重要，返回值就是让RecyclerView知道LayoutManager真实的滑动距离，`return 0`时RecyclerView就会展示`overScorll`状态以及`NestedScrolling`的后续处理。关于`NestedScrolling`这点我也没发现有博客讲到，啥？overScorll你也不知道！告辞~

添加`offsetChildrenHorizontal`方法，支持水平方向的滑动。啥？为啥又是`-dx`，看看源码或者实验实验不就知道了。

```kotlin
    override fun scrollHorizontallyBy(
        dx: Int,
        recycler: RecyclerView.Recycler,
        state: RecyclerView.State
    ): Int {
        //移动View
        offsetChildrenHorizontal(-dx)
        return dx
    }
```

![gif_blog_lm_sroll_horizontal.gif](https://i.loli.net/2020/09/08/zphtQDd26m9Kgik.gif)

就这么简单，我们的LayoutManager已经可以滑动了。但是随之而来又发现一个问题：“滑动只是在已存在的这几个children间滑动”。这不是废话吗，我们都没写填充和回收View的方法，肯定没有新的itemView添加进来呀，超过屏幕的View也不会回收呀。下面开始增加填充View和回收View的代码块。

```kotlin
    override fun scrollHorizontallyBy(
        dx: Int,
        recycler: RecyclerView.Recycler,
        state: RecyclerView.State
    ): Int {

        //填充View
        fill(dx, recycler)
        //移动View
        offsetChildrenHorizontal(-dx)
        //回收View
        recycle(dx, recycler)
      
        //输出children
        logChildCount("scrollHorizontallyBy", recycler)
        return dx
    }
```

从上面的代码可以看出，在滑动的时候我们真正只做了三件事，`填充View`-`移动View`-`回收View`，一个合格的LayoutManager`至少`是应该做足这三件事的，并且顺序最好如上面代码一样`先填充-再移动-最后回收`，当然复杂的情况的LayoutManager可以多加一些条件检测和特殊处理，例如`LinearLayoutManager`就是`先回收-再填充-再回收-最后移动`。

### 重写scrollToPosition()和smoothScrollToPosition()方法支持。

### 解决软键盘弹出或收起onLayoutChildren()方法重新调用的问题。