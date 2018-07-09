---
title: 使用Android Support Annotations优化你的代码
---

Android Support Annotations提供的注解允许你像lint检查那样提供一些提示信息在审查代码上，这可以帮助你解决一些难以发现的代码问题。
****
###  **添加依赖**

 1. 选择**File > Project Structure**
 2. 点击**Dependencies**标签
 3. 点击“+”按钮然后选择**Library dependency**那项
 4. 在弹出的选择框选择support-annotations然后点击ok

用上面的方法添加的依赖一般都是最新的，然后在build.gradle就会多出一行依赖。
```groovy
dependencies {
    compile 'com.android.support:support-annotations:23.3.0'
}
```

***
### **Nullness 注解**

添加@Nullable和@NonNull注解去检验一个给定的变量，参数或者返回的值是否有效。

* @Nullable 表示一个参数，变量，或方法返回值可以为null

* @NonNull 表示一个参数，变量，或方法返回值不能为null

例如添加了@NonNull这个注解表示context和attrs这两个参数不能为空
```java
import android.support.annotation.NonNull;
...

    /** Add support for inflating the <fragment> tag. */
    @NonNull
    @Override
    public View onCreateView(String name, @NonNull Context context,
      @NonNull AttributeSet attrs) {
      ...
      }
...
```

***
###  **Resource 注解**

对Android引用的资源类型验证，可以用来区分像**Drawables**和 **R.string**这种同是integer的类型资源。

添加@StringRes注解检验resId是否为string的资源id
```java
import android.support.annotation.StringRes;
...
    public abstract void setTitle(@StringRes int resId);
    ...
```
同类型的注解还有 @DrawableRes, @DimenRes, @ColorRes, 和@InterpolatorRes等等

***
###  **Thread 注解**

如果一个方法需要在特定类型的线程中调用，就可以添加这些注解帮助代码审查。

* @UiThread

* @MainThread

* @WorkerThread

* @BinderThread

> 注意： @MainThread 和 @UiThread 是可以互换的，所以被注解方法只允许从这2个注解声明的线程中调用。

***
###  **Value Constraint 注解**

使用@IntRange, @FloatRange, 和 @Size 注解检对传递的参数进行验证。

* @IntRange  指定一个int的值必须在一个规定范围内

例如取一个alpha值在0-255之间
```java
public void setAlpha(@IntRange(from=0,to=255) int alpha) { … }
```
* @FloatRange 指定一个float的值必须在一个规定范围内

例如取一个alpha值在0.0-1.0之间
```java
public void setAlpha(@FloatRange(from=0.0, to=1.0) float alpha) {...}
```


* @Size 表示被注解的元素必须有一个给定的数量或长度

@Size 注解检查集合或数组的数量，以及String的长度。例如一个集合必须要有一个存在的值就使用@Size(min=1)注解去检查这个集合的是否合法。又比如使用 @Size(2) 注解表示这个数组必须要包含两个存在的值。

例子：表示location这个数组必须要有一个值
```java
int[] location = new int[3];
button.getLocationOnScreen(@Size(min=1) location);
```

***
###  **Permission 注解**

使用@RequiresPermission注解用来检验一个方法的调用者是否已经拥有此权限。对只检查单个权限是否为有效权限，使用**anyOf**属性，对检查一组权限使用**allOf**属性。

```java
@RequiresPermission(Manifest.permission.SET_WALLPAPER)
public abstract void setWallpaper(Bitmap bitmap) throws IOException;
```


```java
@RequiresPermission(allOf = {
    Manifest.permission.READ_EXTERNAL_STORAGE,
    Manifest.permission.WRITE_EXTERNAL_STORAGE})
public static final void copyFile(String dest, String source) {
    ...
}

```

***
###  **CheckResults 注解**

使用@CheckResults注解检验方法的结果或返回值是否有使用。

```java
@CheckResult(suggest="#enforcePermission(String,int,int,String)")
public abstract int checkPermission(@NonNull String permission, int pid, int uid);
```

***
###  **CallSuper 注解**

使用@CallSuper注解检验方法是否调用super实现了父类的方法。

```java
@CallSuper
protected void onCreate(Bundle savedInstanceState) {
}

```

***
### **Enumerated 注解**

使用**@IntDef** 和 **@StringDef** 注解可以使用注解方式代替枚举实现整型或字符串的列举类型，以检验其他类型的代码引用。

```java
import android.support.annotation.IntDef;
...
public abstract class ActionBar {
    ...
    //Define the list of accepted constants
    @IntDef({NAVIGATION_MODE_STANDARD, NAVIGATION_MODE_LIST, NAVIGATION_MODE_TABS})

    //Tell the compiler not to store annotation data in the .class file
    @Retention(RetentionPolicy.SOURCE)

    //Declare the NavigationMode annotation
    public @interface NavigationMode {}

    //Declare the constants
    public static final int NAVIGATION_MODE_STANDARD = 0;
    public static final int NAVIGATION_MODE_LIST = 1;
    public static final int NAVIGATION_MODE_TABS = 2;

    //Decorate the target methods with the annotation
    @NavigationMode
    public abstract int getNavigationMode();

    //Attach the annotation
    public abstract void setNavigationMode(@NavigationMode int mode);
```
如果模型参数不是定义好的常数之一，那么在你构建这段代码时就会生成一段警告。

如果一个参数或返回值引用一个有效的模式，你也可以定义带标志的注解。

```java
import android.support.annotation.IntDef;
...

@IntDef(flag=true, value={
        DISPLAY_USE_LOGO,
        DISPLAY_SHOW_HOME,
        DISPLAY_HOME_AS_UP,
        DISPLAY_SHOW_TITLE,
        DISPLAY_SHOW_CUSTOM
})
@Retention(RetentionPolicy.SOURCE)
public @interface DisplayOptions {}

...
```
如果修饰的参数或返回的值不引用一个有效的模式，那么在你构建这段代码时就会生成一段警告。

***
### **总结**

| 注解 | 解释 |
| ------------- |-------------|
| @AnimatorRes | 表示该参数、字段或者函数返回值应该是一个 Animator 类型的资源 |
| @AnimRes | 表示该参数、字段或者函数返回值应该是一个 Anim 类型的资源 |
| @AnyRes | 表示该参数、字段或者函数返回值应该是一个任意类型的资源 |
| @AnyThred |表示被注解的方法可以在任何线程中被调用 |
| @ArrayRes |表示该参数、字段或者函数返回值应该是一个 Array 类型的资源 |
| @AttrRes| 表示该参数、字段或者函数返回值应该是一个 attribute 类型的资源 |
| @BinderThread| 表示被注解的方法只可以在被绑定的线程中被调用 |
| @BoolRes| 表示该参数、字段或者函数返回值应该是一个布尔类型的资源 |
| @CallSuper| 表示任何重写的方法都必须调用父类的这个方法 |
| @CheckResult |表示不能忽视被注解方法的返回值 |
| @ColorInt |表示该参数、字段或者函数返回值应该是一个颜色值而不是颜色资源引用，例如应该是一个 AARRGGBB 的整数值。|
| @ColorRes| 表示该参数、字段或者函数返回值应该是一个 color 类型的资源，而不是颜色值。注意和 ColorInt 区别 |
| @DimenRes |表示该参数、字段或者函数返回值应该是一个 dimension 类型的资源 |
| @Dimension |表示被注解的整形参数，字段或返回值是一个尺寸类型 |
| @DrawableRes| 表示该参数、字段或者函数返回值应该是一个 drawable 类型的资源 |
| @FloatRange |表示被注解的元素必须是在一个给定范围的float或double值 |
| @FractionRes |表示该参数、字段或者函数返回值应该是一个 fraction 类型的资源 |
| @IdRes |表示该参数、字段或者函数返回值应该是一个资源的 ID 类型 |
| @IntegerRes |表示该参数、字段或者函数返回值应该是一个整数类型的资源 |
| @IntRange |表示被注解的元素必须是在一个给定范围的long或int值 |
| @InterpolatorRes | 表示该参数、字段或者函数返回值应该是一个 interpolator 类型的资源 |
| @keep |表示被注解的元素在构建混淆时不会被删除或缩小字段，会保持原字段 |
| @LayoutRes| 表示该参数、字段或者函数返回值应该是一个 layout 布局文件类型的资源 |
| @MainThread |表示被注解的方法只能在主线程调用 |
| @MenuRes| 表示该参数、字段或者函数返回值应该是一个 menu 类型的资源 |
| @NonNull |表示被注解的参数，字段或返回值不能为空 |
| @Nullable | 表示被注解的参数，字段或返回值可以为空 |
| @PluralsRes| 表示该参数、字段或者函数返回值应该是一个 plurals 类型的资源 |
| @Px |表示这个整形的参数，字段或返回值是一个像素尺寸 |
| @RawRes|表示该参数、字段或者函数返回值应该是一个 raw 类型的资源 |
| @RequiresApi |表示被注解的元素只能在给定的api级别或更高版本上运行 |
| @RequiresPermission |表示被注解的元素需要（或可能需要）一个或多个权限 |
| @RequiresPermission.Read|指定需要允许读权限 |
| @RequiresPermission.Write |指定需要允许写权限 |
| @Size |表示被注解的元素必须有一个给定的大小或长度 |
| @StringDef |表示被注解的元素代表一个逻辑类型并且它的值必须是显示命名的常量 |
| @StringRes |表示该参数、字段或者函数返回值应该是一个字符串类型的资源 |
| @StyleableRes |表示该参数、字段或者函数返回值应该是一个 styleable 类型的资源 |
| @StyleRes |表示该参数、字段或者函数返回值应该是一个 style 类型的资源 |
| @TransitionRes | 表示该参数、字段或者函数返回值应该是一个 transition 类型的资源 |
| @UiThread |表示被注解的方法或构造方法只能在UI线程调用 |
| @VisibleForTesting |主要用到测试方面，用处很少，标志作用 |
| @WorkerThread |表示被注解的方法或构造方法只能在工作线程调用 |
| @XmlRes| 表示该参数、字段或者函数返回值应该是一个 XML 类型的资源 |
