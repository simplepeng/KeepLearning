# Android架构组件(Architecture Components)介绍

## 为什么需要架构组件

> 之前有多少人是把所有代码都写在 **Activity**里面？几乎每个人都干过一次，对吧！

Android 框架层面上允许自由的做到上面这点，但是后来我们意识到了这么做会带来的问题，这使得我们的代码变得臃肿不堪，难以维护。所以才出现了像mvp，mvvm这样不同的架构模式，这使得我们可以编写更健壮的和可测试的代码。但是Android Team并没有这样的官方组件。而且，我们作为开发者更喜欢争论哪种架构模式更好。

直到Android团队意识到他们需要**明确表态**并告诉我们应如何构建应用程序，其结果就是发布架构组件和相关指南。

## 架构组件是什么

一个新的库集合，可帮助您设计健壮的，可测试的和可维护的应用程序。从管理UI组件生命周期和处理数据持久性类开始

简而言之，这些库将帮助我们解决，配置更改，内存泄漏，怎么编写可测试的应用程序的常见问题，在维护架构的同时减少模板代码。

## 整体架构

![](http://p6uvwa6u4.bkt.clouddn.com/img/1_-yY0l4XD3kLcZz0rO1sfRA.png)

以下是您可以**一起或单独**使用它们的组件。

## Lifecycle

Lifecycle提供了类和接口让您可以构建出具有感知生命周期变化的组件，这些组件可以根据**Activity**和**Fragment**当前的生命周期自动调整自己的状态。

## ViewModel

它是被设计用来储存和管理与UI相关数据的组件，以便数据能够在屏幕旋转等配置变化下保存下来。它不应该访问您的视图结构或保留Activity或Fragment的引用。

它有以下职责：

*  主要职责就是管理UI的数据
* 它处理`Activity`/ `Fragment`和应用程序的其他部分之间的通信
* 在配置更改时保存数据

这意味着我们的`Activity`或`Fragment`不会负责保存数据，只包含与UI相关的代码。

> ViewModel是具有生命感知的，所以不需要担心内存泄露问题

## LiveData

LiveData是一个保存值（数据持有者）并允许观察值变化的组件。它被设计用来保存ViewModel中的值，但它也可被用于在应用程序中共享数据。LiveData也能感知生命周期的变化，它能在Activity还存在时候接受数据的改变并在不存在时防止崩溃。

LiveData的优点：

* 始终保持最新的数据
* 正确的应对配置变化
* 没有内存泄漏

### Lifecycle — ViewModel — LiveData

![](http://p6uvwa6u4.bkt.clouddn.com/img/1_C-f2QtBVExDrkyPLNSa7xQ.png)

## Room

Room提供了一个SQLite的抽象层，可以在充分利用SQLite的同时流畅访问的数据库。

简而言之，它就像SQLite数据库的一个ORM，它意味着你可以直接将对象保存到数据库中，并且Room会很好地将对象正确保存到数据库中。

Room的优点：

* 原始的SQL查询
* 消除了在SQL查询和Java数据对象之间转换的样板代码
* 不需要写Cursor或Loader

## 结论

最后，我觉得这是自构建Android应用程序以来的最好方式。虽然有些迟到，但是总比缺席好。我们可以用这些组件构建出令人惊讶的应用。

### 参考

https://developer.android.com/topic/libraries/architecture/

### 其他

[Android架构组件(Architecture Components)介绍](https://blog.csdn.net/qq_21793463/article/details/80841182)

[Android架构组件—LiveData](https://blog.csdn.net/qq_21793463/article/details/80841186)

[Android架构组件—ViewModel](https://blog.csdn.net/qq_21793463/article/details/80841196)

[Android架构组件Room的使用](https://blog.csdn.net/qq_21793463/article/details/78905316)