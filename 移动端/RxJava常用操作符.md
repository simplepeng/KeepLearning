---
title: RxJava常用操作符
---
## 原文地址

> http://reactivex.io/documentation/operators.html#alphabetical

## 创建操作

用于创建Observable（被观察者）的操作符

* Create（创建） — 通过调用观察者（observer）的方法从头开始创建一个Observable
* Defer（推迟） — 在观察者订阅之前不创建这个Observable，为每一个观察者创建一个新的Observable
* Empty/Never/Throw — 创建行为有限和非常精确的特殊Observable
* From（来自） — 将一些其它的对象或数据结构转换为Observable
* Interval（间隔） — 创建一个Observable，它发出以特定时间间断的整数序列
* Just（仅仅） — 将一个对象或者一组对象转换为一个会发出该对象或那些对象的Observable
* Range（范围） — 创建一个发出指定范围的整数序列的Observable
* Repeat（重复） — 创建一个重复发出特定的数据项或序列的Observable
* Start（开始） — 创建一个发出函数的返回值的Observable
* Timer（定时器） — 创建在一个指定的延迟之后发出单个数据项的Observable

## 变换操作

用于对Observable发出的数据进行变换的操作符

* Buffer（缓冲） — 定期从Observable收集数据到一个集合，并将这些数据项打包发出，而不是一次发出一个
* FlatMap（扁平映射） — 将Observable发出的数据变换为Observables集合，然后将这些 Observable发出的数据平坦化的放进一个单独的Observable，可以认为是一个将嵌套的数据结构展开的过程
* GroupBy（分组） — 将Observable分拆为一组Observable，将原始Observable发出的数据按Key分组，每一个Observable发出一组不同的数据项
* Map（映射） — 通过对序列的每一项都应用一个函数变换Observable发出的数据，实质是对序列中的每一项执行一个函数，函数的参数就是这个数据项
* Scan（扫描） — 对Observable发出的每一项数据应用一个函数，然后按顺序依次发出这些值
* Window（窗口） — 定期将来自Observable的数据分拆成一些Observable窗口，然后发出这些窗口，而不是每次发出一项。类似于Buffer，但Buffer发出的是数据，Window发出的是Observable，每一个Observable发出原始Observable的数据的一个子集
* cast（强转） — 在发出数据之前强制将Observable发出的所有数据转换为指定类型

## 过滤操作

用于从Observable发射的数据中选择性的过滤一些数据的操作符

* Debounce（防反跳）— 如果在特定的时间跨度已经过去而没有发出另一个数据项，则只从Observable发出一个数据项
* Distinct（去重） — 抑制Observable发出的重复数据
* ElementAt（取值） — 取值取特定位置的那一项数据
* Filter（过滤） — 过滤掉没有通过断言测试的数据项，只发射通过测试的
* First（首选） — 只从Observable发出第一个数据项满足条件的第一个数据项
* IgnoreElements（忽略所有的数据） — 不从Observable发出任何数据项，但保留终止通知(onError或 onCompleted)
* Last（末项） — 只发出Observable发出最后一条数据
* Sample（抽样检查） — 定期发射最新的数据，等于就是数据抽样，有的实现里叫ThrottleFirst
* Skip（跳过） — 跳过由Observable发出的前n个数据项
* SkipLast（跳过末项） — 跳过由Observable发出的最好n个数据项
* Take — 只发出由Observable发出的前n项数据
* TakeLast — 只发出由Observable发出的最好n项数据

## 组合操作

用于将多个Observable组合成一个单一的Observable的操作符

* And/ Then/When - 将两个或更多个Observables通过Pattern（模式）和Plan（计划）发出的数据组合成一个数据集合
- CombineLatest - 当项由两个Observable中的任一个发出时，通过指定的函数组合每个Observable发出的最新项，并基于此函数的结果发出项
* Join - 当在根据由另一Observable发射的项目定义的时间窗期间发出来自一个Observable的项目时，就将两个Observable发射的数据组合成一个并发射
* Merge（合并） - 将多个Observable发射的数据组合并成一个
* StartWith（以...开始） - 在开始从源Observable发出项之前，先发出指定的数据项或数据序列
* Switch（切换） - 将一个发出Observable的Observable转换为另一个Observable，并逐个发射原来Observable最近发射的数据
* Zip - 通过指定的函数将多个Observable的发射组合在一起，并根据此函数的结果为每个组合发出单个数据项

## 错误处理操作

有助于从Observable的错误通知中恢复的操作符

* Catch（捕获） — 继续序列操作，将错误替换为正常的数据，从onError通知中恢复
* Retry（重试） — 如果Observable发射了一个onError通知，重新订阅它，希望它将完成并没有错误

## 辅助操作

用于处理Observable的操作符

* Delay — 延迟一段时间发射结果数据
* Do — 注册对各种Observable生命周期事件采取的操作
* Materialize/Dematerialize — 将发射的数据和通知都当做数据发射，或者反过来
* ObserveOn（观察在） — 指定Observer观察Observable的调度器（Scheduler）（工作线程）
* Serialize（序列化） — 强制Observable按次序发射数据并且功能是有效的
* Subscribe（订阅） — 收到Observable发射的数据和通知后执行的操作
* SubscribeOn（订阅在） — 指定Observable应该在哪个调度器上执行
* TimeInterval(时间间隔) — 将一个Observable转换为发射两个数据之间所耗费时间的Observable
* Timeout（超时） — 如果过了指定的一段时间没有发射数据，则发射错误通知
* Timestamp（时间戳） — 给Observable发射的每个数据项添加一个时间戳
* Using — 创建一个与Observable相同生命周期内存在的一次性资源

## 条件和布尔操作

用于评估，判断一个或多个Observable或Observable中发出的数据项的操作符

* All — 判断Observable发射的所有的数据项是否都满足某些条件
* Amb — 给定两个或者多个源Observe，只让第一个发出数据的Observable发出全部数据
* Contains — 判断Observable是否发射指定的数据项
* DefaultIfEmpty — 发射来自原始Observable的数据，如果原始Observable没有发射数据，就发射一个默认数据
* SequenceEqual — 判断两个Observable是否发出相同的数据序列
* SkipUntil — 丢弃原始Observable发射的数据，直到第二个Observable发射了一个数据，然后发射原始Observable的剩余数据
* SkipWhile — 丢弃原始Observable发射的数据，直到一个特定的条件为false，然后发射原始Observable剩余的数据
* TakeUntil — 丢弃在第二个Observable发出数据项或终止后由Observable发出的数据项
* TakeWhile — 丢弃在指定条件变为false之后由Observable发出的项

## 数学和聚合操作

对Observable发出的整个序列进行操作的操作符

* Average（平均值） — 计算Observable发射的数据序列的平均值，然后发射这个结果
* Concat — 不交错的连接多个Observable的数据
* Count（数量） — 计算Observable发射的数据个数，并只发送此值
* Max（最大值） — 计算并发射数据序列的最大值
* Min（最小值） — 计算并发射数据序列的最小值
* Reduce（归纳） — 按顺序对数据序列的每一个应用某个函数，然后返回这个值
* Sum（总和） — 计算并发射数据序列的和

## 背压操作

* backpressure operators - 为了应对观察者消费事件比被观察者生产事件更快，所以需要背压

## 连接操作

一些有精确可控的订阅行为的特殊Observable

* Connect（连接） — 指示可连接的Observable开始发送数据给订阅者
* Publish — 将普通的Observable转换为可连接的Observable
* RefCount — 使一个可连接的Observable表现得像一个普通的Observable
* Replay — 确保所有的观察者收到同样的数据序列，即使他们在Observable开始发射数据之后才订阅

## 转换操作

* To（变成） — 将Observable转换为其它的对象或数据结构
* Blocking（阻塞） — 阻塞Observable的操作符