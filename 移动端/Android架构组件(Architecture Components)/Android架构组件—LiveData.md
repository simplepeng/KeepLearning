# Android架构组件—LiveData

## 前言

**LiveData** 是一个可以保存数据和观察数据变化的组件。他是被设计用来在**ViewModel中**保存数据，

但是同样也可以在应用的其他地方使用。

LiveData使用观察者模式监听数据的改变。这与RxJava的observable非常类似，但是LiveData不止于此，LiveData是具有生命周期感知能力的。

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

// Create a LiveData with a String
private MutableLiveData<String> mCurrentName;

    public MutableLiveData<String> getCurrentName() {
        if (mCurrentName == null) {
            mCurrentName = new MutableLiveData<String>();
        }
        return mCurrentName;
    }

// Rest of the ViewModel...
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

        // Other code to setup the activity...

        // Get the ViewModel.
        mModel = ViewModelProviders.of(this).get(NameViewModel.class);


        // Create the observer which updates the UI.
        final Observer<String> nameObserver = new Observer<String>() {
            @Override
            public void onChanged(@Nullable final String newName) {
                // Update the UI, in this case, a TextView.
                mNameTextView.setText(newName);
            }
        };

        // Observe the LiveData, passing in this activity as the LifecycleOwner and the observer.
        mModel.getCurrentName().observe(this, nameObserver);
    }
}
```

上面代码展示了如果监听一个LiveData对象，并切如果LiveDta没有调用`setValue`方法，那么`onChanged`方法也不会回调。

## 扩展LiveData

