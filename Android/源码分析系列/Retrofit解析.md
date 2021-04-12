# 自己对Retrofit的理解

## 带着问题看源码

1. 有了OkHttp，为啥要多造个Retrofit出来
2. 都在说Retrofit的`动态代理`，那么为啥Retrofit需要使用动态代理
3. 为啥设计`ConverterFactory`和`CallAdapterFactory`
4. 怎么支持Kotlin的协程的
5. 一次请求的完整过程，是如何转交给OkHttp的
6. 如何把成功的回调抛到主线程的

## 有了OkHttp，为啥要多造个Retrofit出来

答案很简单：那就是相对于OkHttp使用更方便，我自己的理解就是Retrofit只是对OkHttp的封装。

## 都在说Retrofit的动态代理，那么为啥Retrofit需要使用动态代理

啥是动态代理？其实可以简单的理解成`给一个类的全部方法注册一个监听，也可以说是回调`，这样当这个类调用方法时就会执行这个回调，也就是`InvocationHandler`的`invoke`方法。这也是Retrofit的`Api`类设计成`Interface`的原因。

```java
Proxy.newProxyInstance(service.getClassLoader(), new Class<?>[] { service },
        new InvocationHandler() {
          
          private final Platform platform = Platform.get();
          private final Object[] emptyArgs = new Object[0];

          @Override public @Nullable Object invoke(Object proxy, Method method,
              @Nullable Object[] args) throws Throwable {

            return loadServiceMethod(method).invoke(args != null ? args : emptyArgs);
          }
        });
```

那为啥Retrofit就要用动态代理呢？答案就是简单，方便，省事。在`loadServiceMethod`方法中有对请求的统一处理，解析方法上的`注解`，`请求类型`，`响应类型`，然后交给OkHttp去处理。不贴源码了，源码还是要自己看才香！

那么动态代理有性能影响吗？答案肯定是：有。因为使用到了反射去动态创建代理类，但是这个性能影响完全可以忽略。更多的性能影响是在`loadServiceMethod`方法造成的，因为`loadServiceMethod`中有一些操作是放在主线程中执行的，例如知乎就遇到了代理方法造成耗时的问题：[知乎安卓客户端启动优化 - Retrofit 代理](https://zhuanlan.zhihu.com/p/40097338)。优化的思路就是把 使用`二次动态代理`把`loadServiceMethod()` 的调用扔到`非 UI 线程上`。

还有没有办法继续优化？讲道理应该是可以的，可以像`ButterKnife`一样使用`APT`技术在编译时去创建代理类，直接不使用动态代理，用空间换时间。但是这样就需要对Retrofit的源码进行改动，并且也会增加编译阶段的耗时，见仁见智吧，如何取舍看自己。

## 为啥设计ConverterFactory和CallAdapterFactory

`ConverterFactory`和`CallAdapterFactory`都相当于一种`适配器`模式。

一个提供了`请求和响应数据`的适配，你可以使用`Gson`，`Jackson`，`Moshi`等不同的反序列化库。

一个提供了`请求方式的`适配。你可以使用`RxJava`，`LiveData`，`协程`等不同的方式去发送HTTP请求。

## 怎么支持Kotlin的协程的



## 一次请求的完整过程，是如何转交给OkHttp的



## 如何把成功的回调抛到主线程的

```java
//Platform
static class MainThreadExecutor implements Executor {
  private final Handler handler = new Handler(Looper.getMainLooper());
  @Override public void execute(Runnable r) {
    handler.post(r);
  }
}
```

