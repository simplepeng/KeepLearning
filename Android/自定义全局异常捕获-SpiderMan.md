# 如何自定义一个全局异常捕获器-SpiderMan

## 一图胜前言

![](https://simple-bucket-1257044365.cos.ap-chongqing.myqcloud.com/debug.gif)



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

## 高级操作

### 解析Throwable

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

### 跳转新的界面显示Crash信息

```java
Intent intent = new Intent(mContext, CrashActivity.class);
intent.putExtra(CrashActivity.CRASH_MODEL, model);
intent.setFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
mContext.startActivity(intent);
```

在对Throwable解析完成后，我们就可以跳转到一个新的Activity并展示Crash的相关信息，这里`Context`是Application的Context，所有必须使用`Intent.FLAG_ACTIVITY_NEW_TASK`才能成功跳转。

### 分享Crash信息

**分享文本**

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

**分享长图**

分享图片要涉及东西就多啦，比如ScrollView的截图，如何保存到Sd卡，6.0需要动态权限检测，7.0还要兼容fileprovider，具体看源码吧，哈哈哈哈！

![](https://ws1.sinaimg.cn/mw690/00677ch9gy1ftoekwmvl3j30af0hygof)

## 源码地址

[https://github.com/simplepeng/SpiderMan](https://github.com/simplepeng/SpiderMan)