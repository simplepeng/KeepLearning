---
title: ViewPagerTransforms的深入理解-给viewpager切换加动画
---

github地址：
>https://github.com/simplepeng/ViewPagerTransforms

每当viewpager上一个可见或依附的页面发生了滚动事件就会调用PageTransformer，这让应用可以使用自定义transformation让viewpager某一个页面视图上实现某些特定的动画属性。

但是这样的属性动画只能支持到android3.0版本或以上，在早期的版本上设置viewpager的PageTransformer会被忽略。

###公有方法

**transformPage**   应用属性动画到一个指定的页面
```
void transformPage (View page, float position)
```
| 参数 | 解释    |
|-------|-------|
| pager       |  View: 应用切换动画到哪一个页面上 |
| position | float: position表示相对于当前页正中的位置，0表示在正中的这个页面，1表示右边一个完整的页面，-1表示左边一个完整的页面 |


###首先是一个很平常的viewpager

![这里写图片描述](http://img.blog.csdn.net/20160819101519477)
```
package com.example.simple.pagertransformdemo;

public class MainActivity extends AppCompatActivity {

    private int imgIds[] = {R.drawable.img_1, R.drawable.img_2, R.drawable.img_3};

    private List<View> viewList = new ArrayList<>();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        

        for (int i = 0; i < 3; i++) {
            View rootView = View.inflate(MainActivity.this, R.layout.item_pager, null);
            ImageView imageView = (ImageView) rootView.findViewById(R.id.pager_iv);
            imageView.setImageResource(imgIds[i]);
            TextView textView = (TextView) rootView.findViewById(R.id.pager_tv);
            textView.setText(String.valueOf(i));
            viewList.add(i, rootView);
        }

	ViewPager viewPager = (ViewPager) findViewById(R.id.viewPager);
        viewPager.setAdapter(new MyAdapter());
    }

    private class MyAdapter extends PagerAdapter {

        @Override
        public int getCount() {
            return 3;
        }

        @Override
        public boolean isViewFromObject(View view, Object object) {
            return view == object;
        }

        @Override
        public Object instantiateItem(ViewGroup container, int position) {
            container.addView(viewList.get(position));
            return viewList.get(position);
        }

        @Override
        public void destroyItem(ViewGroup container, int position, Object object) {
            container.removeView(viewList.get(position));
        }

    }
}

```

```
<?xml version="1.0" encoding="utf-8"?>
<RelativeLayout
    xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:tools="http://schemas.android.com/tools"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    android:paddingLeft="@dimen/activity_horizontal_margin"
    android:paddingRight="@dimen/activity_horizontal_margin"
    android:paddingTop="@dimen/activity_vertical_margin"
    android:paddingBottom="@dimen/activity_vertical_margin"
    tools:context="com.example.simple.pagertransformdemo.MainActivity">

    <android.support.v4.view.ViewPager
        android:id="@+id/viewPager"
        android:layout_width="match_parent"
        android:layout_height="match_parent" />
</RelativeLayout>
```

```
<?xml version="1.0" encoding="utf-8"?>
<RelativeLayout xmlns:android="http://schemas.android.com/apk/res/android"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    >

    <ImageView
        android:id="@+id/pager_iv"
        android:layout_width="match_parent"
        android:layout_height="match_parent"
        android:scaleType="fitXY"
        />

    <TextView
        android:id="@+id/pager_tv"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="xxxx"
        android:layout_centerInParent="true"
        android:textSize="20sp"
        android:textColor="@android:color/holo_red_dark"
        />

</RelativeLayout>
```
### 接着是一个放大进入的viewpager
![这里写图片描述](http://img.blog.csdn.net/20160819142937893)

我们多加了一行代码

```
 viewPager.setPageTransformer(true ,new ZoomInTransform());
```
看看这这句代码的作用

| 参数 | 解释 |
|-------------|-------------|
|reverseDrawingOrder  |    boolean值，true表示提供的PageTransformer画view时是倒序，false则是正序 |
|transformer  |   将修改每一页动画属性的PageTransformer |
</br>
看源码也可以得出
```
public void setPageTransformer(boolean reverseDrawingOrder, PageTransformer transformer) {
        if (Build.VERSION.SDK_INT >= 11) {
            final boolean hasTransformer = transformer != null;
            final boolean needsPopulate = hasTransformer != (mPageTransformer != null);
            mPageTransformer = transformer;
            setChildrenDrawingOrderEnabledCompat(hasTransformer);
            if (hasTransformer) {
            //reverseDrawingOrder等于true时为倒序，false为正序
                mDrawingOrder = reverseDrawingOrder ? DRAW_ORDER_REVERSE : DRAW_ORDER_FORWARD;
            } else {
                mDrawingOrder = DRAW_ORDER_DEFAULT;
            }
            if (needsPopulate) populate();
        }
    }
```

將 reverseDrawingOrder 改爲 false 看看效果
```
viewPager.setPageTransformer(false ,new ZoomInTransform());
```
![这里写图片描述](http://img.blog.csdn.net/20160819151005806)

再看看ZoomInTransform的代碼就一目了然了
```
public class ZoomInTransform implements ViewPager.PageTransformer {

    public static final String TAG = "simple_PagerTransform";

    @Override
    public void transformPage(View page, float position) {
     
        int width = page.getWidth();
        int height = page.getHeight();
		//這裏只對右邊的view做了操作
        if (position > 0 && position <= 1) {//right scorlling
        //position是1.0->0,但是沒有等於0
            Log.e(TAG, "right----position====" + position);
            //設置該view的X軸不動
            page.setTranslationX(-width * position);
            //設置縮放中心點在該view的正中心
            page.setPivotX(width / 2);
            page.setPivotY(height / 2);
            //設置縮放比例（0.0，1.0]
            page.setScaleX(1 - position);
            page.setScaleY(1 - position);

        } else if (position >= -1 && position < 0) {//left scrolling

        } else {//center

        }
    }
}
```

我们还可以看看transformPage是怎么來的
```
//這是viewpager源代碼的一部分，transformPage方法的來源
if (mPageTransformer != null) {
            final int scrollX = getScrollX();
            final int childCount = getChildCount();
            //遍历viewpager所有的子view
            for (int i = 0; i < childCount; i++) {
                final View child = getChildAt(i);
                final LayoutParams lp = (LayoutParams) child.getLayoutParams();

                if (lp.isDecor) continue;
//position等於該view的左起點減去在X軸的位移除以viewpager的寬度，也就是算出真正的位移比例
                final float transformPos = (float) (child.getLeft() - scrollX) / getClientWidth();
                mPageTransformer.transformPage(child, transformPos);
            }
        }
```

### 下面来一个炫酷点的，感觉有点3D效果的样子
![这里写图片描述](http://img.blog.csdn.net/20160819175453552)
```
public class SimplePageTransform implements ViewPager.PageTransformer {

    @Override
    public void transformPage(View view, float position) {
        int width = view.getWidth();
        int pivotX = 0;
        if (position <= 1 && position > 0) {// right scrolling  
            pivotX = 0;
        } else if (position == 0) {

        } else if (position < 0 && position >= -1) {// left scrolling
            pivotX = width;
        }
        //设置x轴的锚点
        view.setPivotX(pivotX);
        //设置绕Y轴旋转的角度
        view.setRotationY(90f * position);
    }
}
```
###我们再将transformPage改造一下

```
@Override
    public void transformPage(View view, float position) {
        if (position <= 1 && position > 0) {
            int hashCode = view.hashCode();
            Log.d(TAG,"right hashCode="+hashCode);
        } else if (position == 0) {
            int hashCode = view.hashCode();
            Log.d(TAG,"center hashCode="+hashCode);
        } else if (position < 0 && position >= -1) {
            int hashCode = view.hashCode();
            Log.w(TAG,"left hashCode="+hashCode);
        }
    }
```
看看log信息

* 下一页的view hashcode
>left hashCode=75472620
>right hashCode=55231157
>center hashCode=55231157

* 再下一页的view hashcode
 >left hashCode=55231157
 >right hashCode=45932420
 >center hashCode=45932420

* 上一页的view hashcode
>left hashCode=55231157
>right hashCode=45932420
>center hashCode=55231157

* 再上一页的view hashcode
>left hashCode=75472620
>right hashCode=55231157
>center hashCode=75472620

由此以及上面transformPage方法的出处可得出规律，transformPage返回的view并不是一个，而是根据相应的position的返回相应的view。
</br>
也由此可以提出viewpager的坐标系（ps:不会画图请不要打我）
![这里写图片描述](http://img.blog.csdn.net/20160820224621697)
浅蓝色为left view，红色为center view，深蓝色为right view，当滑动事件开始，他们的关系也会跟变化，所以可得出在[-1,0)这个区间为left，(0，1]这个区间为right，只有当等于0才为center。如果viewpager里面view很多肯定就还会有-2，+2等等的其他坐标点，但是我们只关注left，center，right这3个view上就可以实现很多炫酷的动画啦！

### 总结

* 给viewpager加动画并不难，只需要实现PageTransformer类transformPage的方法，再利用相应的view和position加上view属性动画就好啦！
* 而且还可以设置view切换时的顺序，想要实现炫酷的动画也不难，只要肯动脑。
* transformPage返回的view并不是一个view，而是根据position返回相应的view。
* transformPage返回的view的区间[-1,0)这个区间为left，(0，1]这个区间为right，只有当等于0为center
*  viewpager的PageTransformer是在3.0以后加的新特性
 * ps:如果想兼容3.0以下也有办法，要么用反射，要么就自己自定义一个view实现viewpager所有功能，其实android很多兼容包都会利用反射技能去兼容低版本无法使用新特性这样一个缺点




























































