
我浏览material.io网站时，从所谓的“Material Design 2”中找到一些新的组件，并发现Snackbar已经改变了，它不再占用整个屏幕长度，并且周围会有一个间距。

![](https://ws1.sinaimg.cn/mw690/00677ch9gy1ft4v3r6yb3j30ke0i6qne)

但我并没有从Support Library的alpha版本中找到它，所以我决定自己实现一下。

## 1、创建Drawable文件

```xml
<shape xmlns:android="http://schemas.android.com/apk/res/android"
    android:shape="rectangle">
    <solid android:color="#323232" />
    <corners android:radius="4dp" />
</shape>
```

## 2、创建工具类

```java
public class SnackbarHelper {

    public static void config(Context context, Snackbar snack) {
        addMargins(snack);
        setRoundBordersBg(context, snack);
        ViewCompat.setElevation(snack.getView(), 6f);
    }

    private static void addMargins(Snackbar snack) {
        ViewGroup.MarginLayoutParams params = (ViewGroup.MarginLayoutParams) snack.getView().getLayoutParams();
        params.setMargins(12, 12, 12, 12);
        snack.getView().setLayoutParams(params);
    }

    private static void setRoundBordersBg(Context context, Snackbar snackbar) {
        snackbar.getView().setBackground(context.getResources().getDrawable(R.drawable.bg_snackbar));
    }
}
```

## 3、使用

```java
public void showSnackbar(View view) {
    Snackbar snackbar = Snackbar.make(view, "这个一个snackbar", Snackbar.LENGTH_SHORT);
    snackbar.setAction("ok", new View.OnClickListener() {
        @Override
        public void onClick(View v) {

        }
    });
    snackbar.setActionTextColor(Color.RED);
    SnackbarHelper.config(MainActivity.this, snackbar);
    snackbar.show();
}
```

## 4、展示

![](https://ws1.sinaimg.cn/mw690/00677ch9gy1ft4uvpwhpzj30j404kdfw)