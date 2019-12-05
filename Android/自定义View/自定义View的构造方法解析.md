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

