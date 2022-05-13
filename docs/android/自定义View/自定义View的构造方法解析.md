```
 access the current theme, resources, etc.
```

# 自定义View的构造方法解析

本文分析基于`android sdk api-29`

自定义view都需要重写父类的构造方法

```java
/**
     * Simple constructor to use when creating a view from code
     * 当直接使用代码创建View时使用
     */
    public CustomView(Context context) {
        super(context);
    }

    /**
     * Constructor that is called when inflating a view from XML
     * The method onFinishInflate() will be called after all children have been
     */
    public CustomView(Context context, @Nullable AttributeSet attrs) {
        super(context, attrs);
    }

    public CustomView(Context context, @Nullable AttributeSet attrs, int defStyleAttr) {
        super(context, attrs, defStyleAttr);
    }

    /**
     * Api21新增的方法
     */
    @RequiresApi(api = Build.VERSION_CODES.LOLLIPOP)
    public CustomView(Context context, @Nullable AttributeSet attrs, int defStyleAttr, int defStyleRes) {
        super(context, attrs, defStyleAttr, defStyleRes);
    }
```

* 只有一个`Context`的用于代码创建View的使用
* 其他的构造方法都是回调到`View(Context context, @Nullable AttributeSet attrs, int defStyleAttr, int defStyleRes)`方法，用于在`xml`中填充view使用。

## 构造方法的形参分析

### Context context

> The Context the view is running in, through which it can access the current theme, resources, etc.
>
> view运行时的上下文，通过它可以访问当前的主题、资源等。

### AttributeSet attrs

> The attributes of the XML tag that is inflating the view
>
> 写在xml标签中的属性集合

### int defStyleAttr

> An attribute in the current theme that contains a reference to a style resource that supplies default values for the view. Can be 0 to not look for defaults.
>
> 当前主题中包含对提供视图默认值的样式资源的引用的属性，可以设置为0不查找默认的样式资源。

### int defStyleRes

>A resource identifier of a style resource that supplies default values for the view, used only if defStyleAttr is 0 or can not be found in the theme Can be 0 to not look for defaults
> 
>样式资源的资源标识符为视图提供默认值，仅在`defStyleAttr`为0或无法在`主题中`找到时使用，可以为0以不查找默认值

其实这些参数最主要的是传递给方法`context.obtainStyledAttributes()`用的，因为最后构造方法也是调用的

`this(context)`方法。

## 属性的优先级

xml中的attr标签 > 通过style引入的标签 > activity或theme中引入的标签 > 构造函数中的defStyleRes