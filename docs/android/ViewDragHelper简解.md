# ViewDragHelper简解

## 概述

ViewDragHelper是一个用于编写自定义视图组的实用程序类。它提供了许多有用的操作和状态跟踪，允许用户在其父视图组中拖动和重新定位视图。（ps:来自官方注释）

## 简单入门

* 创建ViewDragHelper的实例
* 回调相关触摸的方法

```Java
public class DragLayout extends LinearLayout {

    private ViewDragHelper mViewDragHelper;

    public DragLayout(Context context) {
        super(context);
    }

    public DragLayout(Context context, AttributeSet attrs) {
        super(context, attrs);

        mViewDragHelper = ViewDragHelper.create(this, new ViewDragHelper.Callback() {

            /**
             *
             * @param child 当前捕获的子view
             * @param pointerId
             * @return 返回true 表示可以捕获该子view
             */
            @Override
            public boolean tryCaptureView(View child, int pointerId) {
                return true;
            }

            /**
             * 默认的实现返回的为0，没实现水平的移动，
             * 所以必须重写该方法并返回水平方向移动的位置
             *
             * @param child 即将被拖动的子view
             * @param left 即将移动到左边的位置
             * @param dx 水平方向移动了的距离
             * @return 水平方向移动新的left值，可以用来限制child view移动的边界控制
             */
            @Override
            public int clampViewPositionHorizontal(View child, int left, int dx) {
                return left;
            }

            /**
             *同上，方向变为竖直方向
             *
             * @param child 同上
             * @param top 同上，值变为top
             * @param dy 竖直方向移动了的距离
             * @return 同上个方法，值变成top
             */
            @Override
            public int clampViewPositionVertical(View child, int top, int dy) {
                return top;
            }
        });
    }

    @Override
    public boolean onInterceptTouchEvent(MotionEvent ev) {
        return mViewDragHelper.shouldInterceptTouchEvent(ev);
    }

    @Override
    public boolean onTouchEvent(MotionEvent event) {
        mViewDragHelper.processTouchEvent(event);
        return true;
    }
}
```

![](https://ws1.sinaimg.cn/mw690/00677ch9gy1focugums9dg309g0g1gmi)

这样就很简单的实现了几个可以拖动的view，布局很简单，就DragLayout里面放了3个TextView就不贴出来了。

## 创建ViewDragHelper的实例

创建ViewDragHelper只能用create静态方法，因为ViewDragHelper的构造方法是私有的。

ViewDragHelper提供了两个create静态方法，上面已经出现了一种，还有一个就是加了一个sensitivity参数

```java
public static ViewDragHelper create(ViewGroup forParent, float sensitivity, Callback cb)
```

* forParent：监听的父ViewGroup
* sensitivity： helper识别拖动开始的敏感值，值越大越敏感，默认为1.0f
* cb：监听的回调

##回调的方法

上面已经提到了3种，接下来看看还有其他哪些回调方法

```java
/**
 * 当拖拽状态改变时回调这个
 * @param state 拖拽状态
 *
 * @see #STATE_IDLE 闲置状态
 * @see #STATE_DRAGGING 正在被拖拽
 * @see #STATE_SETTLING 拖拽结束，自动滚动
 */
public void onViewDragStateChanged(int state) {}

/**
 * 被捕获view位置发生改变时候回调
 */
public void onViewPositionChanged(View changedView, int left, int top, int dx, int dy) {}

/**
 *  当被捕获的view处于正在被拖拽或者自动滚动的状态回调此方法
 */
public void onViewCaptured(View capturedChild, int activePointerId) {}

/**
 * 当被拖拽的view拖拽结束时回调(松开手指)
 * @param xvel 水平方向的速率
 * @param yvel 竖直方向的速率
 */
public void onViewReleased(View releasedChild, float xvel, float yvel) {}

/**
 * 当前没有捕获到子view并且父viewgroup被订阅的边缘被触摸时回调(不是屏幕边缘)
 */
public void onEdgeTouched(int edgeFlags, int pointerId) {}

/**
 * 当给定的边缘可能被锁定时调用
 *
 * 返回true锁定边缘
 */
public boolean onEdgeLock(int edgeFlags) {
    return false;
}

/**
 * 当前没有捕获到子view并且父viewgroup被订阅的边缘开始拖拽时回调
 *
 * @param edgeFlags 边缘标记
 * @see #EDGE_LEFT 左
 * @see #EDGE_TOP 上
 * @see #EDGE_RIGHT 右
 * @see #EDGE_BOTTOM 下
 */
public void onEdgeDragStarted(int edgeFlags, int pointerId) {}

/**
 * 调用此方法来确定子视图的z轴的顺序
 */
public int getOrderedChildIndex(int index) {
    return index;
}

/**
 * 返回可拖动子view水平方向可移动的大小范围
 */
public int getViewHorizontalDragRange(View child) {
    return 0;
}

/**
 * 返回可拖动子view竖直方向可移动的范围大小
 */
public int getViewVerticalDragRange(View child) {
    return 0;
}
```

 上面的方法onEdgeDragStarted和onEdgeTouched想要响应回调还要必须设置边缘追踪可用

```java
public void setEdgeTrackingEnabled(int edgeFlags)
```

## ViewDragHelperd的其他方法

```java
	/**
     * 在父视图的坐标系统中找到指定点下的最顶层的子节点
     */
    public View findTopChildUnder(int x, int y)
    /**
     * 返回当前被捕获的子view或者没有子view被捕获则返回null
     */
    public View getCapturedView()
    /**
     * 调用此方法的结果等同于接收ACTION_CANCEL事件
     */
    public void cancel() 
    /**
     * 内部调用了cancel方法，并且会停止所有正在进行的动作，包括动画
     */
    public void abort()
    /**
   	 * 捕获特定的子view
   	 */
    public void captureChildView(View childView, int activePointerId)
    /**
   	 * 惯性滑动被捕获的view
   	 */
    public void flingCapturedView(int minLeft, int minTop, int maxLeft, int maxTop)
    /**
   	 * 带动画效果的移动view
   	 */
    public boolean smoothSlideViewTo(View child, int finalLeft, int finalTop)
    /**
   	 * 判断当前被捕获的子View是否还需要继续移动
   	 */
    public boolean continueSettling(boolean deferCallbacks)
```

