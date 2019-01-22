# Android Selector的简写

在Android中，我们需要实现一个View的点击或选中样式的改变，大多数情况下我们都是使用`drawable`文件，也就是`selector`,`shape`等组成的资源文件。大致套路如下的常规写法：

## 常规写法

比如新建一个正常状态下的shape文件`sp_normal.xml`，选中状态的`sp_checked.xml`，组合两个shape的`sr_default.xml`。

```xml
<?xml version="1.0" encoding="utf-8"?>
<!--sp_normal.xml-->
<shape xmlns:android="http://schemas.android.com/apk/res/android"
    android:shape="rectangle">
    <solid android:color="@android:color/black" />
    <corners android:radius="4dp" />
</shape>
```

```xml
<?xml version="1.0" encoding="utf-8"?>
<!--sp_checked.xml-->
<shape xmlns:android="http://schemas.android.com/apk/res/android"
    android:shape="rectangle">
    <solid android:color="@android:color/holo_red_light" />
    <corners android:radius="4dp" />
</shape>
```

```xml
<?xml version="1.0" encoding="utf-8"?>
<!--sr_default.xml-->
<selector xmlns:android="http://schemas.android.com/apk/res/android">
    <item android:drawable="@drawable/sp_normal" android:state_checked="false" />
    <item android:drawable="@drawable/sp_checked" android:state_checked="true" />
</selector>
```

然后将`sr_default.xml`设置给View的`background`

```xml
<CheckedTextView
        android:id="@+id/tv_normal_n"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:layout_marginTop="44dp"
        android:background="@drawable/sr_default"
        android:checked="false"
        android:padding="10dp"
        android:text="普通的 checked == false"
        android:textColor="@android:color/white"
        app:layout_constraintLeft_toLeftOf="parent"
        app:layout_constraintRight_toRightOf="parent"
        app:layout_constraintTop_toTopOf="parent" />

<CheckedTextView
        android:id="@+id/tv_normal_c"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:layout_marginTop="24dp"
        android:background="@drawable/sr_default"
        android:checked="true"
        android:padding="10dp"
        android:text="普通的 checked == true"
        android:textColor="@android:color/white"
        app:layout_constraintLeft_toLeftOf="parent"
        app:layout_constraintRight_toRightOf="parent"
        app:layout_constraintTop_toBottomOf="@id/tv_normal_n" />
```

显示效果如下：

![](https://simple-bucket-1257044365.cos.ap-chongqing.myqcloud.com/20190122140638.png)

下面我们来看看怎么简写这个样式。

## 简易写法

我们只需要新建一个`sr_simplify.xml`文件，父标签是`selector`，子shape标签用`item`标签包裹。

```xml
<?xml version="1.0" encoding="utf-8"?>
<!--sr_simplify.xml-->
<selector xmlns:android="http://schemas.android.com/apk/res/android">

    <item android:state_checked="false">
        <shape xmlns:android="http://schemas.android.com/apk/res/android"
            android:shape="rectangle">
            <solid android:color="@android:color/black" />
            <corners android:radius="4dp" />
        </shape>
    </item>

    <item android:state_checked="true">
        <shape xmlns:android="http://schemas.android.com/apk/res/android"
            android:shape="rectangle">
            <solid android:color="@android:color/holo_red_light" />
            <corners android:radius="4dp" />
        </shape>
    </item>

</selector>
```

布局跟上面布局差不多，直接看显示效果：

![](https://simple-bucket-1257044365.cos.ap-chongqing.myqcloud.com/20190122141201.png)

## 总结

我们实践发现两种写法都可以实现同样的需求，但是具体要使用哪种可以依据自己的实际情况来抉择。

* 方式一可以实现更好的解耦，shape文件也可以复用
* 方式二写起来更加简单，也减少了样式文件

[源码地址：https://github.com/simplepeng/AndroidExamples/tree/master/example_simplify_selector](https://github.com/simplepeng/AndroidExamples/tree/master/example_simplify_selector)