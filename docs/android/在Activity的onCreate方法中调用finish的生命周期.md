# 在Activity的onCreate方法中调用finish的生命周期

如题，正常来说Activity启动后会正常依次调用`onCreate`、`onStart`、`onResume`方法，关闭时会调用`onPause`、`onStop`、`onDestory`方法。那么当我们在`onCreate`方法中直接调用`finish`方法后生命周期方法又会怎么执行呢？写个demo看看：

## 日志输出

* Activity正常打开，然后关闭的生命周期日志输出

> D/MainActivity: onCreate
> D/MainActivity: onStart
> D/MainActivity: onResume
> D/MainActivity: onPause
> D/MainActivity: onStop
> D/MainActivity: onDestroy

* 在onCreate中直接调用finish后的生命周期日志输出

> D/MainActivity: onCreate
> D/MainActivity: onDestroy

* 在onStart中直接调用finish后的生命周期日志输出

> D/MainActivity: onCreate
> D/MainActivity: onStart
> D/MainActivity: onStop
> D/MainActivity: onDestroy

## 结论

先说结论，下面再分享源码。从上面的log输出可以发现，在`onCreate`方法中调用`finish`方法后，生命周期会直接回调`onDestory`方法。在`onStart`方法中调用`finish`方法后，生命周期会先回调`onStop`，然后再调用`onDestory`方法。看来生命周期方法还是成对出现的。

## 为什么会有这篇博客

偶然在阅读`Activity`源码时，发现了一条注释。

```java
/* <p>You can call {@link #finish} from within this function, in
     * which case onDestroy() will be immediately called after {@link #onCreate} without any of the
     * rest of the activity lifecycle ({@link #onStart}, {@link #onResume}, {@link #onPause}, etc)
     * executing.
*/
protected void onCreate(@Nullable Bundle savedInstanceState) {
}
```

大致翻译：你可以在`onCreate`方法中直接调用`finish`方法，这个操作会在执行完`onCreate`方法后直接调用`onDestroy`方法，而且并不会执行`onStart`，`onResume`,`onPause`等其他生命周期方法。

## 源码分析

源码基于`android-28`分析。从以往的经验得知，Activity的生命周期回调在`ActivityThread`中的`H`这个Handler中回调，再次阅读这个源码才发现，现在`H`里面已经没有了`LAUNCH_ACTIVITY`等生命周期回调Tag，全部放到了`EXECUTE_TRANSACTION`这个Tag中。

```java
//ActivityThread
class H extends Handler {
   public void handleMessage(Message msg) {
     case EXECUTE_TRANSACTION:
                    final ClientTransaction transaction = (ClientTransaction) msg.obj;
                    mTransactionExecutor.execute(transaction);
                    if (isSystem()) {
                        // Client transactions inside system process are recycled on the client side
                        // instead of ClientLifecycleManager to avoid being cleared before this
                        // message is handled.
                        transaction.recycle();
                    }
                    // TODO(lifecycler): Recycle locally scheduled transactions.
                    break;
   }
}
```

`ClientTransaction`里面的具体代码我们不作过多分析，只需知道最后都会回调回来，执行`ActivityThread`中的`handleLaunchActivity`、`handleStartActivity`、`handleResumeActivity`、`handlePauseActivity`等方法。

这里只分析`handleLaunchActivity`方法的执行流程，因为其他方法都是类似的，最终也执行了`Instrumentation`类中的相关方法。

1. `ActivityThread`执行`handleLaunchActivity`方法
2. `handleLaunchActivity`内部执行`performLaunchActivity`方法
3. `performLaunchActivity`方法中调用`mInstrumentation.newActivity`方法反射创建了Activity实例
4. 然后执行了`mInstrumentation.callActivityOnCreate`方法
5. `callActivityOnCreate`方法内部调用了Activity的`performCreate`方法
6. `performCreate`方法就调用了`onCreate`

```java
//伪代码示例
//`ActivityThread`
public Activity handleLaunchActivity(ActivityClientRecord r,
            PendingTransactionActions pendingActions, Intent customIntent) {
  ...
  performLaunchActivity()  
  ...
}

private Activity performLaunchActivity(ActivityClientRecord r, Intent customIntent) {
	...
   activity = mInstrumentation.newActivity(cl, component.getClassName(), r.intent);
   mInstrumentation.callActivityOnCreate(activity, r.state);
  ...
}

//`Instrumentation`
public void callActivityOnCreate(Activity activity, Bundle icicle) {
	prePerformCreate(activity);
	activity.performCreate(icicle);
	postPerformCreate(activity);
}

//`Activity`
final void performCreate(Bundle icicle, PersistableBundle persistentState) {
  if (persistentState != null) {
            onCreate(icicle, persistentState);
        } else {
            onCreate(icicle);
        }
}
```

## 这才是重点

上面都是生命周期回调的源码分析，现在才是重点分析，为什么在`onCreate`方法中调用了`finish`方法直接执行了`onDesotry`方法，而没有执行其他的生命周期方法。

1. 可知我们在onCreate中执行了finish，所以finish方法是关键，所以先分析finish方法

```java
private void finish(int finishTask) {
  ...
   if (ActivityManager.getService()
       .finishActivity(mToken, resultCode, resultData, finishTask)) {
       mFinished = true;
   }
  ...
}
```

`finish`方法中其他代码可以不用管，只关心调用了`AMS`的finishActivity方法和将`mFinished`设置为了`true`。

2. 分析`handleStartActivity`方法

```java
public void handleStartActivity(ActivityClientRecord r,PendingTransactionActions pendingActions) {
  			final Activity activity = r.activity;
        if (r.activity == null) {
            return;
        }
        if (!r.stopped) {
            throw new IllegalStateException("Can't start activity that is not stopped.");
        }
        if (r.activity.mFinished) {
            return;
        }

        // Start
        activity.performStart("handleStartActivity");
        r.setState(ON_START);
}
```

可以看到当activity的`mFinished`变量为`true`时，代码就不会往下执行，所以就不会执行`onStart`生命周期方法。同理`handleResumeActivity`也是一样的执行逻辑。