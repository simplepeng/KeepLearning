# EventBus搭配LifeCycle可能更美味

## 简要介绍

EventBus：一个用来在组件之间发通知通信的开源库。

LifeCycle：JetPack库中一个能感知生命周期的组件。

Kotlin扩展函数：可以为已经存在的类添加新的方法的黑魔法。

## 解决的问题

在使用`EventBus`时，我们每次在需要接受通知的地方，都需要`注册`和`解绑`监听函数。类似下面的模板代码：

```java
		@Override
    protected void onStart() {
        super.onStart();
        EventBus.getDefault().register(this);
    }

		@Override
    protected void onStop() {
        super.onStop();
				EventBus.getDefault().unregister(this);
    }
```

如果忘记了`unregister`函数，可能就会造成`内存泄露`，`空指针`等奇怪问题。当这个类不需要通知监听时，删除也挺麻烦的。所以很多人可能投向了`LiveDataBus`的怀抱。

那么将`EventBus`和`LifeCycle`搭配上了，注册函数可以怎么写呢？

```kotlin
//Activity|Fragment,所有实现了LifecycleOwner的类
EventBus.getDefault().registerOnStart(this);
```

这就简单多了，对吧！有点`LiveDataBus`那味了。上面的函数会在`onStart`生命周期函数中自动`注册`EventBus监听，并在`onStop`生命周期函数中自动`解绑`监听。

## 可用方法

```kotlin
//生命周期注册监听
EventBus.getDefault().registerOnStart(lifecycleOwner);
EventBus.getDefault().registerOnStart(lifecycleOwner);
EventBus.getDefault().registerOnStart(lifecycleOwner);
//安全调用注册/解绑
EventBus.getDefault().safeRegister(obj);
EventBus.getDefault().safeUnregister(obj);
```

## 实现思路

给EventBus添加扩展函数

```kotlin
/**
 * 在onCreate中注册事件，自动在onDestroy中注销事件
 */
fun <T : LifecycleOwner> EventBus.registerOnCreate(owner: T) {
    if (this.isRegistered(owner)) return
    owner.lifecycle.addObserver(OnCreateLifecycleObserver(this, owner))
}
```

实现`OnCreateLifecycleObserver`

```kotlin
class OnCreateLifecycleObserver<T>(
    private val eventBus: EventBus,
    private val owner: T
) : LifecycleObserver {

}
```

在对应的生命周期函数中添加`注册\解绑`函数

```kotlin
class OnCreateLifecycleObserver<T>(
    private val eventBus: EventBus,
    private val owner: T
) : LifecycleObserver {

    @OnLifecycleEvent(Lifecycle.Event.ON_CREATE)
    fun onCreate() {
        if (eventBus.isRegistered(owner)) return
        eventBus.register(owner)
    }

    @OnLifecycleEvent(Lifecycle.Event.ON_DESTROY)
    fun onDestroy() {
        if (!eventBus.isRegistered(owner)) return
        eventBus.unregister(owner)
    }
}
```

`LifeCycle`不怎么会的可以直接看[官方文档](https://developer.android.com/topic/libraries/architecture/lifecycle?hl=zh-cn)，使用还是蛮简单。

其他生命周期实现类似，具体可看源码实现。

## 源码

[https://github.com/simplepeng/NiceKTX](https://github.com/simplepeng/NiceKTX)