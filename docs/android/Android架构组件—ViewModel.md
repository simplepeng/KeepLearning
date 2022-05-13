# 探索Android架构模式中ViewModel

## 前言

我们中的大多数人都遇到过旋转手机并且应用程序崩溃或UI失去状态的问题。

解决它最简单的办法就是配置`Activity`为`potrait`模式，但这是一个很糟糕的做法。

幸运的是，Android团队在2017年Google I / O期间发布了ViewModel。

该ViewModel类被设计用来保存与UI相关的数据并且它是可以感知生命周期变化的，这使得它能够自动应对配置变化（例如屏幕旋转）带来的影响。

它有以下职责：

* 主要职责是管理UI的数据
* 处理`Activity`/ `Fragment`和应用程序的其余部分之间的通信
* 在配置更改期间保留数据

> 注意：它**永远**应该不能访问您的视图层次结构或保留Activity或Fragment的引用。

## 添加组件到项目中

### 添加goolge maven仓库

在project级别下的`build.gradle`中添加

```groovy
allprojects {
    repositories {
        jcenter()
        google()
    }
}
```

在app下的`build.gradle`添加

```groovy
def lifecycle_version = "1.1.1"

    // ViewModel and LiveData
    implementation "android.arch.lifecycle:extensions:$lifecycle_version"
    // alternatively - just ViewModel
    implementation "android.arch.lifecycle:viewmodel:$lifecycle_version" // use -ktx for Kotlin
    // alternatively - just LiveData
    implementation "android.arch.lifecycle:livedata:$lifecycle_version"
    // alternatively - Lifecycles only (no ViewModel or LiveData).
    //     Support library depends on this lightweight import
    implementation "android.arch.lifecycle:runtime:$lifecycle_version"

    annotationProcessor "android.arch.lifecycle:compiler:$lifecycle_version"
    // alternately - if using Java8, use the following instead of compiler
    implementation "android.arch.lifecycle:common-java8:$lifecycle_version"

    // optional - ReactiveStreams support for LiveData
    implementation "android.arch.lifecycle:reactivestreams:$lifecycle_version"

    // optional - Test helpers for LiveData
    testImplementation "android.arch.core:core-testing:$lifecycle_version"
```

##  实现一个简单的ViewModel

```java
public class MyViewModel extends ViewModel {
    private MutableLiveData<List<User>> users;
    public LiveData<List<User>> getUsers() {
        if (users == null) {
            users = new MutableLiveData<List<User>>();
            loadUsers();
        }
        return users;
    }

    private void loadUsers() {
        // 执行一步操作获取users数据
    }
}
```

然后在Activity或者Fragment中获取数据

```java
public class MyActivity extends AppCompatActivity {
    public void onCreate(Bundle savedInstanceState) {
        // 在系统第一次调用onCreate()方法时创建一个ViewModel
        // 重新创建

        MyViewModel model = ViewModelProviders.of(this).get(MyViewModel.class);
        model.getUsers().observe(this, users -> {
            // 更新UI
        });
    }
}
```

如果ViewModel的宿主Activity被重新创建，那么该Activity可以收到自己第一次创建时一个同样的ViewModel。当宿主Activity被`finished`掉的时候，框架会自动帮我们调用ViewModel对象的`onCleard` 方法帮助我们清理资源。

> **注意**：一个ViewMode类l一定不要持有view,生命周期的引用或任何可能持有对Activity上下文的引用的类

ViewModel对象可以包含`LifecycleObservers`，比如`LiveData`。

如果 ViewModel需要 `Application`上下文，例如查找系统服务，则可以扩展`AndroidViewModel` 该类并在构造函数中接收`Application` 构造函数，因为`Application`类会扩展`Context`。

## ViewModel的生命周期

ViewModel对象被限定在通过`ViewModelProvider`获得ViewModel的生命周期里。ViewModel保留在内存中，直到其生命周期结束：在Activity下是在`finishes`的时候，在Fragment下是`detached`的时候。

![](http://p6uvwa6u4.bkt.clouddn.com/img/viewmodel-lifecycle.png)ViewModelProvider

我们通常会在Activity的`onCreate`方法中请求创建ViewModel对象，但是系统可能在Activity的生命周期内多次调用`onCreate`方法，比如 屏幕旋转。但是ViewModel对象会一直存在于从第一次获取ViewMode对象直到Activity的`finished`和`destroyed`。

## 在Fragment之间共享数据

Activity中两个或多个Fragment之间需要通信是很常见的。这些Fragment可以使用同一个Activity作用范围下的ViewModel来处理通信。

```java
public class SharedViewModel extends ViewModel {
    private final MutableLiveData<Item> selected = new MutableLiveData<Item>();

    public void select(Item item) {
        selected.setValue(item);
    }

    public LiveData<Item> getSelected() {
        return selected;
    }
}

public class MasterFragment extends Fragment {
    private SharedViewModel model;
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        model = ViewModelProviders.of(getActivity()).get(SharedViewModel.class);
        itemSelector.setOnClickListener(item -> {
            model.select(item);
        });
    }
}

public class DetailFragment extends Fragment {
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        SharedViewModel model = ViewModelProviders.of(getActivity()).get(SharedViewModel.class);
        model.getSelected().observe(this, { item ->
           // Update the UI.
        });
    }
}
```

注意这两个Fragment在使用ViewModelProvider获取ViewModel时是用的`getActivity()`。因此，这两个Fragment都会收到相同的`SharedViewModel`实例，这个实例作用域是Activity。

这种方法提供了以下好处：

* 这个Activity不需要做任何事情，也不需要了解有关此通信的任何信息
* Fragment之间不需要了解彼此，除了SharedViewModel的联系。如果一个fragment消失了，其他fragment还可以继续正常工作
* 每个Fragment都有其自己的生命周期，并且不受其他生命周期的影响。如果一个Fragment替换另一个Fragment，UI将继续工作而不会出现任何问题

## 初探ViewModel原理

```java
MyViewModel model = ViewModelProviders.of(this).get(MyViewModel.class);
```

ViewModelProviders 其实是` ViewModelStore `的一个实用类，它在内部引用ViewModelStore返回ViewModel实例（如果存在，否则就创建一个并保存下来）。

ViewModelStore内部使用`HashMap`跟踪ViewModel。

```java

public class ViewModelStore {
    private final HashMap<String, ViewModel> mMap = new HashMap();

    public ViewModelStore() {}

    final void put(String key, ViewModel viewModel) {
        ViewModel oldViewModel = (ViewModel)this.mMap.get(key);
        if(oldViewModel != null) {
            oldViewModel.onCleared();
        }
        this.mMap.put(key, viewModel);
    }

    final ViewModel get(String key) {
        return (ViewModel)this.mMap.get(key);
    }

    public final void clear() {
        Iterator var1 = this.mMap.values().iterator();
        while(var1.hasNext()) {
            ViewModel vm = (ViewModel)var1.next();
            vm.onCleared();
        }
        this.mMap.clear();
    }
}
```

### 结论

ViewModels对于从用户界面**分离数据**非常有用，这些**数据**在测试过程中受益，并且配置更改仍然存在，这是在您的应用中使用ViewModel组件的一个重要**理由**。它甚至可以自己清除资源是另一个重要因素。

最后，它使得在Fragment之间通信更容易。

> 利用ViewModels，您无需担心在屏幕旋转或其他配置更改期间应用程序崩溃或丢失UI状态

### 参考

https://developer.android.com/topic/libraries/architecture/viewmodel













