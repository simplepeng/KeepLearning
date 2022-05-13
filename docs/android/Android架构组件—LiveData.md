# Android架构组件—LiveData

## 前言

**LiveData** 是一个可以保存数据和观察数据变化的组件。他是被设计用来在**ViewModel中**保存数据，

但是同样也可以在应用的其他地方使用。

LiveData使用观察者模式监听数据的改变。这与RxJava的Observable非常类似，但是LiveData不止于此，LiveData是具有生命周期感知能力的。

简单的说，LiveData只是一个普通的数据类型，但是当数据发生变化时，它能够通知其观察者。

## 添加LiveData

### 添加google maven仓库

```groovy
allprojects {
    repositories {
        jcenter()
        google()
    }
}
```

### 添加依赖

```groovy
dependencies {
    // ViewModel and LiveData
    implementation "android.arch.lifecycle:extensions:1.1.1"
    // alternatively, just ViewModel
    implementation "android.arch.lifecycle:viewmodel:1.1.1"
    // alternatively, just LiveData
    implementation "android.arch.lifecycle:livedata:1.1.1"

    annotationProcessor "android.arch.lifecycle:compiler:1.1.1"
}
```

### Java8支持

```groovy
dependencies {
    // Java8 support for Lifecycles
    implementation "android.arch.lifecycle:common-java8:1.1.1"
}
```

## 创建LiveData对象

可以把LiveData想象成一个可以与任何数据一起使用的包装器，包括集合对象，列如：List。LiveData对象通常存储在ViewModel对象中，并通过getter方法访问。

```java
public class NameViewModel extends ViewModel {

// 创建一个包含String的LiveData
private MutableLiveData<String> mCurrentName;

public MutableLiveData<String> getCurrentName() {
      if (mCurrentName == null) {
          mCurrentName = new MutableLiveData<String>();
      }
        return mCurrentName;
    }

}
```

上面代码并没有给LiveDta设置Value，Value的来源可以是WebService或者本地数据库。

## 使用LiveData对象

```java
public class NameActivity extends AppCompatActivity {

    private NameViewModel mModel;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        // 获取ViewModel实例
        mModel = ViewModelProviders.of(this).get(NameViewModel.class);


        // 创建更新UI的观察者
        final Observer<String> nameObserver = new Observer<String>() {
            @Override
            public void onChanged(@Nullable final String newName) {
                // 更新UI
                mNameTextView.setText(newName);
            }
        };

        // 观察LiveData
        mModel.getCurrentName().observe(this, nameObserver);
    }
}
```

上面代码展示了如果监听一个LiveData对象，并切如果LiveDta没有调用`setValue`方法，那么`onChanged`方法也不会回调。

## 扩展LiveData

如果观察者的生命周期处于`STARTED`或`RESUMED`状态，则LiveData会认为观察者处于活动状态。

```java
public class StockLiveData extends LiveData<BigDecimal> {
    private StockManager mStockManager;

    private SimplePriceListener mListener = new SimplePriceListener() {
        @Override
        public void onPriceChanged(BigDecimal price) {
            setValue(price);
        }
    };

    public StockLiveData(String symbol) {
        mStockManager = new StockManager(symbol);
    }

    @Override
    protected void onActive() {
        mStockManager.requestPriceUpdates(mListener);
    }

    @Override
    protected void onInactive() {
        mStockManager.removeUpdates(mListener);
    }
}
```

上面例子中包含3个重要的方法：

* `onActive()` ：当LiveData依附在observer上时调用
* `onInactive()` ：当LiveData不在依附在observer上时调用
* `setValue(T)`：更新LiveData实例的值并通知观察者

## 转换LiveData

您可能想对存储在LiveData对象中的值进行更改后再分配给观察者，或者您可能需要根据另一个LiveData实例返回不同的LiveData实例。Lifecycle软件包提供Transformations类，其中就包括支持这些场景的方法。

`Transformations.map()`

在LiveData使用这个方法可以改变其下游的结果

```java
LiveData<User> userLiveData = ...;
LiveData<String> userName = Transformations.map(userLiveData, user -> {
    user.name + " " + user.lastName
});
```

`Transformations.switchMap()`

类似于`map`，使用这个方法同样可以改变下游的结果，传递给`switchMap()`的函数必须返回一个LiveData对象

```java
private LiveData<User> getUser(String id) {
  ...;
}

LiveData<String> userId = ...;
LiveData<User> user = Transformations.switchMap(userId, id -> getUser(id) );
```

## 参考

[https://developer.android.com/topic/libraries/architecture/livedata](https://developer.android.com/topic/libraries/architecture/livedata)



