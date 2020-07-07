## let

### 定义

```kotlin
/**
* Calls the specified function [block] with `this` value as its argument and returns its result.
*/
public inline fun <T, R> T.let(block: (T) -> R): R = block(this)
```

* 被调用对象通过参数传入
* 返回类型是lambda表达式返回的内容

### 典型用法

* 从一种类型转换为另一种类型
* 处理可空性

```kotlin
//从一种类型转换为另一种类型
val result = StringBuilder().let {
    it.append("hello")
    it.append("world")
    42
}
println(result)//42
//处理可空性
str?.let { print(it) }
```

## apply

### 定义

```kotlin
/**
* Calls the specified function [block] with `this` value as its receiver and returns `this` value.
*/
public inline fun <T> T.apply(block: T.() -> Unit): T { block(); return this }
```

* 返回被调用的对象

### 典型用法

* 初始化或配置对象

```kotlin
// 旧的建立对象的方式
val andre = Person()
andre.name = "andre"
andre.company = "Viacom"
andre.hobby = "losing in ping pong"
// 使用apply后
val andre = Person().apply {
    name = "Andre"
    company = "Viacom"
    hobby = "losing in ping pong"
}
```

## also

### 定义

```kotlin
/**
* Calls the specified function [block] with `this` value as its argument and returns `this` value.
*/
@SinceKotlin("1.1")
public inline fun <T> T.also(block: (T) -> Unit): T { block(this); return this }
```

* 被调用对象通过参数传入
* 返回被调用对象

### 典型用法

```kotlin
// 用中间变量转换来自api的数据
val rawData = api.getData()
Log.debug(rawData)
rawData.map {  /** other stuff */  }
// 使用 'also' 保持方法链的调用
api.getData()
    .also { Log.debug(it) }
    .map { /** other stuff */ }
```

## with

### 定义

```kotlin
/**
* Calls the specified function [block] with the given [receiver] as its receiver and returns its result.
*/
public inline fun <T, R> with(receiver: T, block: T.() -> R): R = receiver.block()
```

* 不是扩展功能
* 相关对象作为参数传入
* 返回lambda表达式返回的值

### 典型用法

* 对对象进行逻辑分组调用

```kotlin
//旧的调用方式
    messageBoard.init(“https://url.com”)
    messageBoard.login(token)
    messageBoard.post(“Kotlin’s a way of life bro")
// 使用 'with' 避免重复引用标识符
with(messageBoard) {
    init(“https://url.com”)
    login(token)
    post(“Kotlin’s a way of life bro")
}
```

## run

### 定义

```kotlin
/**
* Calls the specified function [block] with `this` value as its receiver and returns its result.
*/
public inline fun <T, R> T.run(block: T.() -> R): R = block()
```

* 返回类型是lambda表达式返回的内容

### 典型用法

```kotlin
aegonTargaryen = jonSnow.run {
    makeKingOfTheNorth()
    swearsFealtyTo(daenerysTargaryen)
    realIdentityRevealed(“Aegon Targaryen”)
}
```

