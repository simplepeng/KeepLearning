## PopupMenu简单使用

`PopupMenu` 是锚定到 `View` 的模态菜单。如果空间足够，它将显示在定位视图下方，否则显示在其上方

<img src="https://ws1.sinaimg.cn/mw690/00677ch9gy1fmwxv9ycibj30bc0dqt90" />

```java
public void popup(View view) {
        //初始化PopupMenu
        PopupMenu pm = new PopupMenu(MainActivity.this, view);
        //填充menu api14及以上可这么用
        pm.inflate(R.menu.item_menu);
        //低版本用法
        //pm.getMenuInflater().inflate(R.menu.item_menu, pm.getMenu());
        //显示
        pm.show();
        //设置item点击事件
        pm.setOnMenuItemClickListener(new PopupMenu.OnMenuItemClickListener() {
            @Override
            public boolean onMenuItemClick(MenuItem item) {
                int itemId = item.getItemId();
                return false;
            }
        });
        //设置PopupMenu关闭的监听
        pm.setOnDismissListener(new PopupMenu.OnDismissListener() {
            @Override
            public void onDismiss(PopupMenu menu) {

            }
        });
    }
```

在res文件夹下创建menu文件夹，并创建对应的menu.xml

```Xml
<?xml version="1.0" encoding="utf-8"?>
<menu xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:app="http://schemas.android.com/apk/res-auto">

    <item
        android:id="@+id/item1"
        android:icon="@mipmap/ic_launcher"
        android:title="item1" />

    <item
        android:id="@+id/item2"
        android:icon="@mipmap/ic_launcher"
        android:title="item2" />
    <item
        android:id="@+id/item3"
        android:icon="@mipmap/ic_launcher"
        android:title="item3" />
    <item
        android:id="@+id/item4"
        android:icon="@mipmap/ic_launcher"
        android:title="item4" />
</menu>
```

## 创建菜单组

菜单组是指一系列具有某些共同特征的菜单项。通过菜单组，您可以：

- 使用 `setGroupVisible()` 显示或隐藏所有项目
- 使用 `setGroupEnabled()` 启用或禁用所有项目
- 使用 `setGroupCheckable()` 指定所有项目是否可选中

通过将 `<item>` 元素嵌套在菜单资源中的 `<group>` 元素内，或者通过使用 `add()` 方法指定组 ID，您可以创建组。

```Xml
<menu xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:app="http://schemas.android.com/apk/res-auto">

    <item
        android:id="@+id/item1"
        android:icon="@mipmap/ic_launcher"
        android:title="item1" />

    <group>
        <item
            android:id="@+id/g_item1"
            android:icon="@mipmap/ic_launcher"
            android:title="g_item1" />

        <item
            android:id="@+id/g_item2"
            android:icon="@mipmap/ic_launcher"
            android:title="g_item2" />

    </group>
</menu>
```

## 显示图标

可以看到上面的menu文件我们设置icon属性但是并没有显示出来，这是怎么回事呢？那就看看源码吧.

刚好我找到这么一个方法

```Java
public void setForceShowIcon(boolean forceShowIcon) {
        mForceShowIcon = forceShowIcon;
        if (mPopup != null) {
            mPopup.setForceShowIcon(forceShowIcon);
        }
    }
```

我用蹩脚的英语翻译一下子，意思就是：设置弹出菜单的适配器是否被强制显示图标，感觉这方法没毛病。然后这个方法属于MenuPopupHelper这个类，再找到PopupMenu这类中用到MenuPopupHelper的地方，然后我又傻眼了。

```java
public class PopupMenu {
    private final Context mContext;
    private final MenuBuilder mMenu;
    private final View mAnchor;
    final MenuPopupHelper mPopup;
  .......
}
```

这个mPopup变量是默认修饰符修饰的，并且也没有暴露get方法，看来只有以暴制暴了-那就是用java的反射机制了，上代码。

```java
 try {
            Field mPopup = pm.getClass().getDeclaredField("mPopup");
            mPopup.setAccessible(true);
            MenuPopupHelper menuPopupHelper = (MenuPopupHelper) mPopup.get(pm);
            menuPopupHelper.setForceShowIcon(true);

        } catch (NoSuchFieldException e) {
            e.printStackTrace();
        } catch (IllegalAccessException e) {
            e.printStackTrace();
        }
```

run 一下看看！

![](https://ws1.sinaimg.cn/mw690/00677ch9gy1fmx0wc1z1gj30bq0gswf5)

差不多是这个样子

