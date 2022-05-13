# 我对Retrofit的理解

## 带着问题看源码

1. 有了OkHttp，为啥要多造个Retrofit出来
2. 都在说Retrofit的`动态代理`，那么为啥Retrofit需要使用动态代理
3. 为什么Api类要设计成接口
4. 为啥设计`ConverterFactory`和`CallAdapterFactory`
5. 一次请求的完整过程，是如何转交给OkHttp的
6. 如何把成功的回调抛到主线程的
7. 怎么支持Kotlin的协程的

## 有了OkHttp，为啥要多造个Retrofit出来

答案很简单：那就是相对于OkHttp使用更方便，我自己的理解就是Retrofit只是对OkHttp的封装。

## 都在说Retrofit的动态代理，那么为啥Retrofit需要使用动态代理

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

`Proxy.newProxyInstance`返回的就是`动态生成的代理类`，当我们调用`代理类.getXXX`等请求网络方法时，就会调用`InvocationHandler.invoke`方法。`invoke`的返回值就是实际方法需要的返回值。

那么动态代理有性能影响吗？答案肯定是：有。因为使用到了反射去动态创建代理类，但是这个性能影响完全可以忽略。更多的性能影响是在`loadServiceMethod`方法造成的，因为`loadServiceMethod`中有一些操作是放在主线程中执行的，例如知乎就遇到了代理方法造成耗时的问题：[知乎安卓客户端启动优化 - Retrofit 代理](https://zhuanlan.zhihu.com/p/40097338)。优化的思路就是把 使用`二次动态代理`把`loadServiceMethod()` 的调用扔到`非 UI 线程上`。

还有没有办法继续优化？讲道理应该是可以的，可以像`ButterKnife`一样使用`APT`技术在编译时去创建代理类，直接不使用动态代理，用空间换时间。但是这样就需要对Retrofit的源码进行改动，并且也会增加编译阶段的耗时，见仁见智吧，如何取舍看自己。

## 为什么Api类要设计成接口

动态代理要求代理的对象必须是接口或者实现接口的类。

## 为啥设计ConverterFactory和CallAdapterFactory

`ConverterFactory`和`CallAdapterFactory`都相当于一种`适配器`模式。

一个提供了`请求和响应数据`的适配，你可以使用`Gson`，`Jackson`，`Moshi`等不同的反序列化库。

一个提供了`请求方式的`适配。你可以使用`RxJava`，`LiveData`，`协程`等不同的方式去发送HTTP请求。

## 一次请求的完整过程，是如何转交给OkHttp的

 一次请求发起就会回调`InvocationHandler的invoke`方法，`loadServiceMethod`方法会先去找是否有`ServiceMethod`的缓存，没有就解析一次`Method`的所有注解拼装成`ServiceMethod`再缓存下来。

```java
//Retrofit
ServiceMethod<?> loadServiceMethod(Method method) {
  ServiceMethod<?> result = serviceMethodCache.get(method);
  if (result != null) return result;

  synchronized (serviceMethodCache) {
    result = serviceMethodCache.get(method);
    if (result == null) {
      result = ServiceMethod.parseAnnotations(this, method);
      serviceMethodCache.put(method, result);
    }
  }
  return result;
}
```

然后调用`ServiceMethod`的`invoke`方法，`ServiceMethod`的直接子类是`HttpServiceMethod`，并且只有它实现了`invoke`抽象方法，并且标记成了`final`。

```java
//HttpServiceMethod
@Override final @Nullable ReturnT invoke(Object[] args) {
  Call<ResponseT> call = new OkHttpCall<>(requestFactory, args, callFactory, responseConverter);
  return adapt(call, args);
}
```

从上面看出这里创建了一个`OkHttpCall`对象，它是`Call`对象的子类，并且调用了`adapt`这个方法，`adapt`是`HttpServiceMethod`的一个`抽象方法`。

```java
//HttpServiceMethod
protected abstract @Nullable ReturnT adapt(Call<ResponseT> call, Object[] args);
```

`HttpServiceMethod`的子类有`CallAdapted`，`SuspendForResponse`，`SuspendForBody`，从子类的`adapt`方法实现可以看出又是一个`callAdapter`代理了`adapt`方法。

```java
//HttpServiceMethod
static final class CallAdapted<ResponseT, ReturnT> extends HttpServiceMethod<ResponseT, ReturnT> {
  private final CallAdapter<ResponseT, ReturnT> callAdapter;
  CallAdapted(RequestFactory requestFactory, okhttp3.Call.Factory callFactory,
      Converter<ResponseBody, ResponseT> responseConverter,
      CallAdapter<ResponseT, ReturnT> callAdapter) {
    super(requestFactory, callFactory, responseConverter);
    this.callAdapter = callAdapter;
  }
  @Override protected ReturnT adapt(Call<ResponseT> call, Object[] args) {
    return callAdapter.adapt(call);
  }
}
```

`callAdapter`都是在`构造方法`中传入进来的，所以我们只要找到`构造方法`在哪里实例化的，就能慢慢找到`callAdpater`是个什么东西了。

其实从上面的源码分析也可以推断出，`CallAdapted类`，`SuspendForResponse类`都是`ServiceMethod`的子类，暂时用到了`ServiceMethod`的地方就是`loadServiceMethod方法`，然后继续深入就是`HttpServiceMethod`的`parseAnnotations`方法。果不其然，上面几个子类都是在这里实例化的。

```java
//HttpServiceMethod
  static <ResponseT, ReturnT> HttpServiceMethod<ResponseT, ReturnT> parseAnnotations(
      Retrofit retrofit, Method method, RequestFactory requestFactory) {
    //...省略掉不相关的代码
    CallAdapter<ResponseT, ReturnT> callAdapter =
        createCallAdapter(retrofit, method, adapterType, annotations);
	 //...省略掉不相关的代码
    //如果不是Kotlin的suspend标注的方法
    if (!isKotlinSuspendFunction) {
      return new CallAdapted<>(requestFactory, callFactory, responseConverter, callAdapter);
    } else if (continuationWantsResponse) {
      //noinspection unchecked Kotlin compiler guarantees ReturnT to be Object.
      return (HttpServiceMethod<ResponseT, ReturnT>) new SuspendForResponse<>(requestFactory,
          callFactory, responseConverter, (CallAdapter<ResponseT, Call<ResponseT>>) callAdapter);
    } else {
      //noinspection unchecked Kotlin compiler guarantees ReturnT to be Object.
      return (HttpServiceMethod<ResponseT, ReturnT>) new SuspendForBody<>(requestFactory,
          callFactory, responseConverter, (CallAdapter<ResponseT, Call<ResponseT>>) callAdapter,
          continuationBodyNullable);
    }
  }
```

`callAdapter`由`createCallAdapter`方法返回，`createCallAdapter`又是调用了`retrofit.callAdapter(returnType, annotations)`方法，其内部是调用了`Retrofit`的`nextCallAdapter`方法，确实挺绕的。

```java
//Retrofit
public CallAdapter<?, ?> nextCallAdapter(@Nullable CallAdapter.Factory skipPast, Type returnType,
    Annotation[] annotations) {
...
  int start = callAdapterFactories.indexOf(skipPast) + 1;
  for (int i = start, count = callAdapterFactories.size(); i < count; i++) {
    CallAdapter<?, ?> adapter = callAdapterFactories.get(i).get(returnType, annotations, this);
    if (adapter != null) {
      return adapter;
    }
  }
...
}
```

从上面的代码可以看出，`nextCallAdapter`方法就是从`callAdapterFactories`集合中找出一个`CallAdapter.Factory`，然后调用其`get方法`返回一个`CallAdapter`，不为null就直接返回该对象。所以我们要先找到`callAdapterFactories`集合是在哪里初始化的，`callAdapterFactories`在`Retrofit`的构造方法里面赋值，然后`Retrofit`由`Builder.build()`方法调用。

```java
//Retrofit.Builder
public Retrofit build() {
  ...
      // Make a defensive copy of the adapters and add the default Call adapter.
      List<CallAdapter.Factory> callAdapterFactories = new ArrayList<>(this.callAdapterFactories);
     
  //这里添加了一个默认CallAdapter
  callAdapterFactories.addAll(platform.defaultCallAdapterFactories(callbackExecutor));
...
      return new Retrofit(callFactory, baseUrl, unmodifiableList(converterFactories),
          unmodifiableList(callAdapterFactories), callbackExecutor, validateEagerly);
    }
```

`platform.defaultCallAdapterFactorie`返回一个默认的`CallAdapter.Factory`集合，但是目前源码里面集合只有一个`DefaultCallAdapterFactory`。

```java
//Platform
List<? extends CallAdapter.Factory> defaultCallAdapterFactories(
    @Nullable Executor callbackExecutor) {
  return singletonList(new DefaultCallAdapterFactory(callbackExecutor));
}
```

所以现在我们只用关心`DefaultCallAdapterFactory`的`get`方法返回是啥就行了。

```java
//DefaultCallAdapterFactory
@Override public @Nullable CallAdapter<?, ?> get(
    Type returnType, Annotation[] annotations, Retrofit retrofit) {

  //是否在HTTP请求方法上添加了SkipCallbackExecutor注解
  final Executor executor = Utils.isAnnotationPresent(annotations, SkipCallbackExecutor.class)
        ? null
        : callbackExecutor;
  //...省略其他无关代码
  return new CallAdapter<Object, Call<?>>() {
    @Override public Type responseType() {
      return responseType;
    }

    @Override public Call<Object> adapt(Call<Object> call) {
      return executor == null
          ? call
          : new ExecutorCallbackCall<>(executor, call);
    }
  };
}
```

从上面代码看出，就是直接返回了一个新的`CallAdapter`而已，所以我们也只用关心`CallAdapter`的`adapt方法`就行。`adapt`返回一个`Call`对象，这不就是`Retrofit`默认请求要添加的那个`Call`嘛。也从上面的代码可以推断出`executor`一般情况都不会是`null`的，所以代码会走` new ExecutorCallbackCall`分支，现在我们又要开始分析`ExecutorCallbackCall`了。

```java
//DefaultCallAdapterFactory  
static final class ExecutorCallbackCall<T> implements Call<T> {
    final Executor callbackExecutor;
    final Call<T> delegate;

    ExecutorCallbackCall(Executor callbackExecutor, Call<T> delegate) {
      this.callbackExecutor = callbackExecutor;
      this.delegate = delegate;
    }

    @Override public void enqueue(final Callback<T> callback) {
      checkNotNull(callback, "callback == null");

      delegate.enqueue(new Callback<T>() {
        @Override public void onResponse(Call<T> call, final Response<T> response) {
          callbackExecutor.execute(new Runnable() {
            @Override public void run() {
              if (delegate.isCanceled()) {
                // Emulate OkHttp's behavior of throwing/delivering an IOException on cancellation.
                callback.onFailure(ExecutorCallbackCall.this, new IOException("Canceled"));
              } else {
                callback.onResponse(ExecutorCallbackCall.this, response);
              }
            }
          });
        }
      }
```

`ExecutorCallbackCall`是实现`Call`的子类，所以它肯定是有`enqueue`和`execute`方法的，但是其实执行请求却是`delegate`这个代理类，`callbackExecutor`就是把响应抛到主线程的执行类，后面小节会讲到。

现在主要分析`delegate`这个代理类，从前面的分析已经知道这个类的实现类就是`OkHttpCall`，所以现在我们只需要关注`OkHttpCall`的`enqueue`或`execute`就行。

```java
//OkHttpCall
public void enqueue(final Callback<T> callback) {
		//...
    synchronized (this) {
    //...
          call = rawCall = createRawCall();
     //...
    }

    call.enqueue(new okhttp3.Callback() {
      @Override public void onResponse(okhttp3.Call call, okhttp3.Response rawResponse) {
					//解析响应体
          response = parseResponse(rawResponse);
        //...
					//回调响应
          callback.onResponse(OkHttpCall.this, response);
      }

      @Override public void onFailure(okhttp3.Call call, IOException e) {
        //回调异常
        callFailure(e);
      }
    });
  }
```

`createRawCall`方法是创建OkHttp请求类的方法

```java
//  OkHttpCall
private okhttp3.Call createRawCall() throws IOException {
    okhttp3.Call call = callFactory.newCall(requestFactory.create(args));
    if (call == null) {
      throw new NullPointerException("Call.Factory returned null.");
    }
    return call;
  }
```

`callFactory`变量其实就是`OkHttpClient`实例，在`Retrofit`的`Builder`中传入，如果没有传入的就是自己实例化一个`OkHttpClient`。

`requestFactory.create(args)`方法就是将请求参数拼装成`OkHttp`需要的`Request`类。

```java
//Retrofit
 public Retrofit build() {
	//...
   okhttp3.Call.Factory callFactory = this.callFactory;
   if (callFactory == null) {
     callFactory = new OkHttpClient();
   }
```

`parseResponse`是解析响应体的方法，方面里面还使用了`converter`来转换数据。

```java
//
Response<T> parseResponse(okhttp3.Response rawResponse) throws IOException {
    //...
T body = responseConverter.convert(catchingBody);
return Response.success(body, rawResponse);
  //...
}
```

## 如何把成功的回调抛到主线程的

```java
//Retrofit
public Retrofit build() {

  Executor callbackExecutor = this.callbackExecutor;
  if (callbackExecutor == null) {
    callbackExecutor = platform.defaultCallbackExecutor();
  }
}
```

如果`Retrofit.Builder`没有调用`callbackExecutor(Executor executor)`方法传入`Executor`，那就用默认的`defaultCallbackExecutor`。

`DefaultCallAdapterFactory.ExecutorCallbackCall`的`callbackExecutor`

```java
//Platform-Android
static class MainThreadExecutor implements Executor {
  private final Handler handler = new Handler(Looper.getMainLooper());
  @Override public void execute(Runnable r) {
    handler.post(r);
  }
}
```

## 怎么支持Kotlin的协程的

`suspend`函数编译成了`Continuation`类，可以自己用AS的`decompile`功能验证。最终使用`SuspendForBody`类来发起请求，它也是`HttpServiceMethod`的子类。

```java
static final class SuspendForBody<ResponseT> extends HttpServiceMethod<ResponseT, Object> {

  //...

  @Override protected Object adapt(Call<ResponseT> call, Object[] args) {
    call = callAdapter.adapt(call);

    //noinspection unchecked Checked by reflection inside RequestFactory.
    Continuation<ResponseT> continuation = (Continuation<ResponseT>) args[args.length - 1];
    return isNullable
        ? KotlinExtensions.awaitNullable(call, continuation)
        : KotlinExtensions.await(call, continuation);
  }
}

```

并通过扩展函数给`Retrofit`的`Call`类增加了`await`的扩展函数





