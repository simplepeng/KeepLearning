# 如何自定义一个全局异常捕获器-SpiderMan

## 一图胜前言

![crash_info.png](https://i.loli.net/2020/12/30/tlm3ysL8QI16He7.png)

上图中，我们模拟了NullPointerException的发生，系统捕获了该异常，并用一个界面展示了出来。

## 如何实现

想要实现全局异常的捕获我们需要了解`Thead`中的一个内部接口`UncaughtExceptionHandler`，该接口在JDK1.5中被添加。

所有我们需要自定义一个类去实现该接口，并且设置给`Thread`的`DefaultUncaughtExceptionHandler`。

```java
//伪代码
public class SpiderMan implements Thread.UncaughtExceptionHandler {
    private SpiderMan() {
        Thread.setDefaultUncaughtExceptionHandler(this);
    }
    
     @Override
    public void uncaughtException(Thread t, Throwable ex) {

    }
}
```

`UncaughtExceptionHandler`会捕获代码中没有捕获的异常，然后回调给`uncaughtException`方法。

## 解析Throwable

```java
 private CrashModel parseCrash(Throwable ex) {
        CrashModel model = new CrashModel();
        try {
            model.setEx(ex);
            model.setTime(new Date().getTime());
            if (ex.getCause() != null) {
                ex = ex.getCause();
            }
            model.setExceptionMsg(ex.getMessage());
            StringWriter sw = new StringWriter();
            PrintWriter pw = new PrintWriter(sw);
            ex.printStackTrace(pw);
            pw.flush();
            String exceptionType = ex.getClass().getName();

            if (ex.getStackTrace() != null && ex.getStackTrace().length > 0) {
                StackTraceElement element = ex.getStackTrace()[0];

                model.setLineNumber(element.getLineNumber());
                model.setClassName(element.getClassName());
                model.setFileName(element.getFileName());
                model.setMethodName(element.getMethodName());
                model.setExceptionType(exceptionType);
            }

            model.setFullException(sw.toString());
        } catch (Exception e) {
            return model;
        }
        return model;
    }
```

如上代码所示，我们可以从Throwable类中解析出很多有用的信息，包括`崩溃发生的类`，`所在行数`,`exception的类型`...

## 跳转新的界面显示Crash信息

```java
Intent intent = new Intent(mContext, CrashActivity.class);
intent.putExtra(CrashActivity.CRASH_MODEL, model);
intent.setFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
mContext.startActivity(intent);
```

在对Throwable解析完成后，我们就可以跳转到一个新的Activity并展示Crash的相关信息，这里`Context`是Application的Context，所有必须使用`Intent.FLAG_ACTIVITY_NEW_TASK`才能成功跳转。

## 分享Crash信息

![crash_info_share.png](https://i.loli.net/2020/12/30/bzixLvrSoCaDfuk.png)

### 分享文本

把Throwable解析成有用的字符串，调用系统的分享方法

```java
private void shareText(String text) {
        Intent intent = new Intent(Intent.ACTION_SEND);
        intent.setType("text/plain");
        intent.putExtra(Intent.EXTRA_SUBJECT, "崩溃信息：");
        intent.putExtra(Intent.EXTRA_TEXT, text);
        intent.setFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
        startActivity(Intent.createChooser(intent, "分享到"));
    }
```

### 分享长图

分享图片要涉及东西就多啦，比如ScrollView的截图，如何保存到Sd卡，6.0需要动态权限检测，7.0还要兼容fileprovider。

### ScrollView的截图

scrollview截图原理很简单，就是创建一个和ScrollView一样宽高的Bitmap，然后将ScrollView的内容画在Bitmap上。

```java
public Bitmap getBitmapByView(ScrollView view) {
    if (view == null) return null;
    int height = 0;
    for (int i = 0; i < view.getChildCount(); i++) {
        height += view.getChildAt(i).getHeight();
    }
    Bitmap bitmap = Bitmap.createBitmap(view.getWidth(), height, Bitmap.Config.ARGB_8888);
    Canvas canvas = new Canvas(bitmap);
    canvas.drawRGB(255, 255, 255);
    view.draw(canvas);
    return bitmap;
}
```

上面的代码中遍历了ScrollView的所有子view，为了计算出ScrollView的真实高度，但是其实分析源码可以得知ScrollView其实只能有一个子view，所以直接获取ScrollView的第一个子view也是可以的。

```java
//ScrollView
@Override
public void addView(View child) {
    if (getChildCount() > 0) {
        throw new IllegalStateException("ScrollView can host only one direct child");
    }

    super.addView(child);
}
```

接着就是创建一个和ScrollView宽高一样的Bitmap，并将它设置给Canvas，Canvas先draw了一个白色的背景，然后才将view的内容画在Bitmap上。

### 6.0 动态权限

Android从 6.0(API 23)开始，对系统权限做了很大的改变。从6.0开始，一些敏感权限，需要在使用时动态申请，并且用户可以拒绝授权访问这些权限，已授予过的权限，用户也可以去APP设置页面去关闭授权。因为我们需要将长图保存到SD卡后分享，所以我们就需要读写SD卡的权限，读写SD卡权限也属于敏感权限。

我们需要调用`ActivityCompat`类下的`requestPermissions`方法去申请权限。

```java
ActivityCompat.requestPermissions(Activity activity, String[] permissions, int requestCode);
```

* activity 当前申请权限的Activity
* permissions 要申请的权限组
* requestCode 请求码

然后我们需要在当前Activity下重写`onRequestPermissionsResult`来判断用户是否授权了我们申请的权限。

```java
@Override
public void onRequestPermissionsResult(int requestCode, @NonNull String[] permissions,
                                       @NonNull int[] grantResults) {
    //判断请求码，确定当前申请的权限
    if (requestCode == REQUEST_CODE) {
        //判断权限是否申请通过
        if (grantResults.length == 1 && grantResults[0] == PackageManager.PERMISSION_GRANTED) {
            //授权成功
            shareImage();
        } else {
            //授权失败
            showToast("请授予SD卡权限才能分享图片");
        }
    } else {
        super.onRequestPermissionsResult(requestCode, permissions, grantResults);
    }
}
```

其实`github`上已经有很多优秀的权限申请框架了，帮我们简化了很多操作，并且里面有一些思想我们也可以学习一下的。就比如用一个透明的Fragment做代理直接回调权限申请的结果，这样我们就可以不重写`onRequestPermissionsResult`方法。

### 图片保存到SD卡

图片保存到SD卡也很简单，直接new一个File将Bitmap写入即可，但是记得使用完Bitmap及时调用`recycle`回收。

```java
private File BitmapToFile(Bitmap bitmap) {
    if (bitmap == null) return null;
    String path = Environment.getExternalStoragePublicDirectory(Environment.DIRECTORY_DOWNLOADS)
            .getAbsolutePath();
    File imageFile = new File(path, "spiderMan-" + df.format(model.getTime()) + ".jpg");
    try {
        FileOutputStream out = new FileOutputStream(imageFile);
        bitmap.compress(Bitmap.CompressFormat.JPEG, 100, out);
        out.flush();
        out.close();
        bitmap.recycle();
    } catch (FileNotFoundException e) {
        e.printStackTrace();
    } catch (IOException e) {
        e.printStackTrace();
    }
    return imageFile;
}
```

### 7.0 FileProvider

最后才到真正分享图片的环节，分享图片其实就是分享File，但是分享File其实又是用的携带`Uri`的`Intent`，在7.0以前我们可以直接调用`Uri.fromFile(file)`方法直接取得文件的Uri地址，但是7.0以后我们就需要`FileProvider`这个东东。那`FileProvider`又是个啥呢？

从 Android 7.0 开始，为了提高私有目录的安全性，防止应用信息的泄漏，开发人员不能够再简单地通过 `file://`Uri 访问应用的私有目录文件或者让其他应用访问自己的私有目录文件。

并且从 7.0 开始，Android SDK 中的 `StrictMode`策略禁止开发人员在应用外部公开 `file://` Uri。也就是说当我们在应用中使用包含 **file://** Uri 的 `Intent` 离开自己的应用时，程序会出现`FileUriExposedException`的异常。

为了解决这个问题，首先我们在 res/xml 目录下新建一个 xml 文件，用于存放应用需要共享的目录文件。

```xml
<?xml version="1.0" encoding="utf-8"?>
<paths>
    <external-path
        name="image_cache"
        path="Download" />
</paths>
```

然后用一个类去继承`FileProvider`类，这样做的好处是多个应用间同时用到了这个FileProvider类也不会出现冲突。

```java
public class SpiderManFileProvider extends FileProvider {
}
```

接着在`AndroidManifest.xml`加上我们自定义的Provider，因为FileProvider也是继承与ContentProvider，属于四大组件之一，所以必须在AndroidManifest.xml文件中声明。

```xml
<application>
        <provider
            android:name="com.simple.spiderman.SpiderManFileProvider"
            android:authorities="${applicationId}.spidermanfileprovider"
            android:exported="false"
            android:grantUriPermissions="true">
            <meta-data
                android:name="android.support.FILE_PROVIDER_PATHS"
                android:resource="@xml/file_paths" />
        </provider>
</application>
```

最后才是Intent携带File Uri并分享的代码

```java
Intent intent = new Intent();
intent.setAction(Intent.ACTION_SEND);
intent.setType("image/*");
//判断版本是否为7.0及以上
if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.N) {
    Uri contentUri = FileProvider.getUriForFile(getApplicationContext(),
            getApplicationContext().getPackageName() + ".spidermanfileprovider", file);
    intent.putExtra(Intent.EXTRA_STREAM, contentUri);
} else {
    intent.putExtra(Intent.EXTRA_STREAM, Uri.fromFile(file));
}
intent.setFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
intent.addFlags(Intent.FLAG_GRANT_READ_URI_PERMISSION);
startActivity(Intent.createChooser(intent, "分享图片"));
```

##   自动初始化

很多第三方框架或SDK都会有个初始化操作，比如在`Application`的`onCreate`中调用`XXX.init()`，`SpiderMan`在最开始也是这么做的，但是之后学习了`LeakCanary`的做法，就不再需要手动初始化了，那么自动初始化该怎么做呢？

首先定义一个`SpiderManInitProvider`，它是继承于`ContentProvider`的一个子类。然后在`AndroidManifest.xml`中注册这个`ContentProvider`。

```java
public class SpiderManInitProvider extends ContentProvider {
    @Override
    public boolean onCreate() {
        Context application = getContext().getApplicationContext();
        if (application == null) {
            application = Utils.getApplicationByReflect();
        }
        SpiderMan.init(application);
        return true;
    }
 //... 省略默认实现代码
}
```

```xml
    <application>
				
        <provider
            android:name=".SpiderManInitProvider"
            android:authorities="${applicationId}.spiderman-init-provider"
            android:exported="false"
            android:multiprocess="true" />

    </application>
```

从上面代码可以看到，我们就在`ContentProvider`的`onCreate`方法中调用了`SpiderMan`的初始化操作，这样就自动完成了初始化工作。那么为什么这么做就可以了呢？因为Android源码太过复杂，不太好讲解，下面我就简单分析下利用`ContentProvider`做自动初始化的原理。

简单的打点，我们同时在`ContentProvider`和`Application`的`onCreate`方法增加输出，可以发现`ContentProvider`的`onCreate`会先于`Appliction`调用。

> ContentProvider ----> onCreate
>
> Application ----> onCreate

那么直接从`Application`的`onCreate`的方法入手，在一连串的跳转后发现：其实`Application`的`onCreate`方法调用是`Instrumentation`调用了`callApplicationOnCreate`方法，然后这个方法是在`ActivityThread`的`handleBindApplication`方法中调用的。并且在`callApplicationOnCreate`方法前有个`installContentProviders`的方法，这个方法就是创建所有在`AndroidManifest.xml`注册过的`ContentProvider`。

```java
//ActivtyThread
private void handleBindApplication(AppBindData data) {
  ...
    if (!data.restrictedBackupMode) {
                if (!ArrayUtils.isEmpty(data.providers)) {
                    installContentProviders(app, data.providers);
                }
            }
  	...
  		try {
                mInstrumentation.callApplicationOnCreate(app);
            } catch (Exception e) {

            }
  ...
}
```

## 源码地址

[https://github.com/simplepeng/SpiderMan](https://github.com/simplepeng/SpiderMan)