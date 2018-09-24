# Android Material buttons

## 前言

 [Google Material Design](https://material.google.com/components/buttons.html) 的文档中提到：“当按钮被触摸时应该给与用户相应的反馈”，现在有了**compat**支持库实现这种效果将会非常简单。

![](http://p6uvwa6u4.bkt.clouddn.com/img/1_Dj3YxY5_isjWAvBsNx1Kvw.gif)

## 添加资源

将最新的appcompat库添加到您的项目中

```groovy
dependencies {
    //replace X.X.X with the latest version
    compile 'com.android.support:appcompat-v7:X.X.X'
}
```

Activity必须继承**AppCompatActivity**

```groovy
public class ButtonActivity extends AppCompatActivity {
...
}
```

将button添加到布局文件

```xml
<Button
    android:layout_width="match_parent"
    android:layout_height="wrap_content"
    android:text="@string/action_click_me" />
```

这样，你的App就拥有了一个基于材料设计的按钮

## 样式

要应用您的自定义颜色，您可以在styles.xml中定义按钮样式

将**colorButtonNormal**和**colorControlHighlight**添加到您的主题中

这将为应用中的所有按钮应用相同的设计

```xml
<style name="AppTheme" parent="Theme.AppCompat.Light.NoActionBar">
    ...
    <item name="colorButtonNormal">@color/colorPrimary</item>
    <item name="colorControlHighlight">@color/colorAccent</item>
</style>
```

如果你想单独设置按钮的样式，可以在styles.xml中创建一个单独按钮主题

```xml
<style name="PrimaryButton" parent="Theme.AppCompat">
    <item name="colorButtonNormal">@color/colorPrimary</item>
    <item name="colorControlHighlight">@color/colorAccent</item>
</style>
```

并在您的按钮上引用该主题

```xml
<Button
    android:layout_width="match_parent"
    android:layout_height="wrap_content"
    android:text="@string/action_click_me"
    android:theme="@style/PrimaryButton" />
```

>或者，如果您的目标是API 21+（5.0），您可以通过直接将android：backgroundTint添加到按钮来设置背景颜色，但请注意，这在旧版本中不起作用

## 扁平化样式按钮

在styles.xml中创建扁平化样式按钮的主题

```xml
<style name="PrimaryFlatButton" parent="Theme.AppCompat.Light">
    <item name="android:buttonStyle">@style/Widget.AppCompat.Button.Borderless.Colored</item>
    <item name="colorControlHighlight">@color/colorAccent</item>
    <item name="colorAccent">@color/colorPrimary</item>
</style>
```

并在您的按钮上引用样式

```xml
<Button
    android:layout_width="match_parent"
    android:layout_height="wrap_content"
    android:text="@string/button_normal"
    android:theme="@style/PrimaryFlatButton" />
```

这样就得到了一个扁平化样式的按钮

[原文连接](https://medium.com/android-bits/android-material-button-e7b92cb014e0)















