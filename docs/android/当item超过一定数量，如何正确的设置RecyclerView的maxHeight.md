# 当item超过一定数量，如何正确的设置RecyclerView的maxHeight

有时候，我们会遇到这种需求：一个线性的列表布局，当item量很少的时候，就是`wrap_content`直接展示完所有item，但是当item数量超过某个数时就要`固定高度`，让其变成可滑动展示更多的item。所以我们第一个想法就是用`RecyclerView`，应该没人会用`ListView`或自己写个`自定义ViewGroup`吧。

但是当我们使用`RecyclerView`+`maxHeight`的时候，会发现其实`maxHeight`是不起作用的。

```xml
    <androidx.recyclerview.widget.RecyclerView
        android:id="@+id/recyclerView"
        android:layout_width="match_parent"
        android:layout_height="wrap_content"
        android:maxHeight="100dp" />
```

![warp_recycler_view.gif](https://i.loli.net/2020/11/06/a9ntXMs5AyrcGD1.gif)

那么为什么会造成这种原因呢？其实在我之前写的一篇博客也提到过：`RecyclerView`将`onMeasure`的转交给了`LayoutManager`，并且`LayoutManager`里面有个`isAutoMeasureEnabled（）`方法用来配置`LayoutManager`是否开启`自测量`。我们常用的`LinearLayoutManager`或`GridLayoutManager`都是默认返回`true`的。

[博客地址](https://juejin.im/post/6870770285247725581)

## 实现思路

所以实现思路就很简单了：设定一个`maxLine`参数，当`RecyclerView`的`itemCount`小于这个值`isAutoMeasureEnabled()`都是返回`true`，让`LayoutManager`去`自测量`。当`itemCount`大于`maxLine`时就重写`onMeasure`方法，在里面去设置`RecyclerView`的`限定宽高`。

## 代码实现

```kotlin
class MaxLineLinearLayoutManager : LinearLayoutManager {

    private var mMaxLine = 0

    constructor(
        context: Context?,
        maxLine: Int
    ) : super(context) {
        Helper.checkMaxCount(maxLine)
        this.mMaxLine = maxLine
    }

    constructor(
        context: Context?,
        orientation: Int,
        reverseLayout: Boolean,
        maxLine: Int
    ) : super(context, orientation, reverseLayout) {
        Helper.checkMaxCount(maxLine)
        this.mMaxLine = maxLine
    }

    override fun onMeasure(
        recycler: RecyclerView.Recycler,
        state: RecyclerView.State,
        widthSpec: Int,
        heightSpec: Int
    ) {
        if (itemCount <= mMaxLine || itemCount == 0) {
            super.onMeasure(recycler, state, widthSpec, heightSpec)
            return
        }

        val child = recycler.getViewForPosition(0)

        //
        addView(child)
        measureChildWithMargins(child, 0, 0)
        val itemWidth = getDecoratedMeasuredWidth(child)
        val itemHeight = getDecoratedMeasuredHeight(child)
        removeAndRecycleView(child, recycler)

        val widthMode = View.MeasureSpec.getMode(widthSpec)
        val heightMode = View.MeasureSpec.getMode(heightSpec)
        var width = 0
        var height = 0

        if (orientation == HORIZONTAL) {
            height = if (heightMode == View.MeasureSpec.EXACTLY) {
                View.MeasureSpec.getSize(heightSpec)
            } else {
                itemHeight
            }
            width = itemWidth * mMaxLine
        } else {
            width = if (widthMode == View.MeasureSpec.EXACTLY) {
                View.MeasureSpec.getSize(widthSpec)
            } else {
                itemWidth
            }
            height = itemHeight * mMaxLine
        }

        setMeasuredDimension(width, height)
    }

    override fun isAutoMeasureEnabled(): Boolean {
        if (itemCount <= mMaxLine) {
            return super.isAutoMeasureEnabled()
        }
        return false
    }


}
```

代码很简单，应该不加注释也能看懂。如果看不懂的可以去看看我之前的那篇分析`自定义LayoutManager`的文章。

[博客地址](https://juejin.im/post/6870770285247725581)

```kotlin
 recyclerView.layoutManager = MaxLineLinearLayoutManager(this, maxLine = 3)
```

![maxline_layoutmanager.gif](https://i.loli.net/2020/11/06/7VRBYIiEZ2WbP8a.gif)

## 源码地址

[https://github.com/simplepeng/MaxLineLayoutManager](https://github.com/simplepeng/MaxLineLayoutManager)

