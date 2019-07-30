## Kotlin简介

* 是一门静态类型编程语言，变量的类型在定义的时候就必须确定。(古语云：动态类型一时爽，代码重构火葬场)
* 由`JetBrians`公司开发设计，该公司是一家捷克的软件公司，是著名的IDE开发商，对很多的开发语言和平台都提供了相应的集成开发环境，比如Java的，OC的，JavaScript，PHP，C/C++等。而其中最著名的是IntelliJ IDEA ，Java的集成开发环境，被称为目前最好用的java IDE。而且Android Studio就是Google基于IntelliJ IDEA 开发的。
* Kotlin是开源的，基于Apache2.0协议。
* Kotlin是完全兼容Java，所以切换成本极低。

## 简易入门

### 定义变量/常量

```kotlin
var a:Int = 1
var a = 1//自动推导出类型
```

### 定义方法

```kotlin
fun haha(a:String,b:Int):String{
  
}
```

定义方法使用`fun`关键字，返回值为括号结尾`:`后面的类型参数，没有返回值可以不写

### 逻辑控制

反正就是`if-else`

```kotlin
fun maxOf(a: Int, b: Int): Int {
    if (a > b) {
        return a
    } else {
        return b
    }
}
```

```kotlin
//上面的简写
fun maxOf(a: Int, b: Int) = if (a > b) a else b
```

kotlin的`switch`->`when`,when相对于switch来说，智能太多了。

```kotlin
fun describe(obj: Any): String =
    when (obj) {
        1          -> "One"
        "Hello"    -> "Greeting"
        is Long    -> "Long"
        !is String -> "Not a string"
        else       -> "Unknown"
    }
```

### 遍历，循环

反正也是`for,while`

```kotlin
val items = listOf("apple", "banana", "kiwifruit")
for (item in items) {
    println(item)
}
//区间
for (item in 0..100) {
    println(item)
}
```

```kotlin
val items = listOf("apple", "banana", "kiwifruit")
var index = 0
while (index < items.size) {
    println("item at $index is ${items[index]}")
    index++
}
```

## 相对于Java的优势

定义变量，调用方法可以不用`；`结尾

### 1.空安全

写Java可能遇到最多的就是`NullPointerException`异常了，所以这也是Kotlin引入`空安全`的原因。

在Kotlin中，对象声明分为`可空引用`和`非空引用`两种。

```kotlin
var a:String = "110"//非空引用
var b:String? = "120"//可空引用

a = null//当对非空引用赋null值时，编译器直接报错
b?.length()//当调用可空引用时必须带上·?·号
//当b为null时候，就不会调用改方法，所以也就避免了空指针异常
```

### 2.类型智能转换

```java
//java
if (animal instanceof Dog){
    ((Dog) animal).wangwang();
}else if (animal instanceof Cat){
    ((Cat) animal).miaomiao();
}else if (animal instanceof Sheep){
    ((Sheep) animal).meimei();
}
```

Kotlin使用关键字 `is` 代替Java中的` instanceof`，但它具有自己的强大功能。编译器检查if声明中的对象属于哪种实例，然后转换if代码块中的实例属性

```kotlin
//kotlin
if (animal is Dog) {
    animal.wangwang()
} else if (animal is Cat) {
    animal.miaomiao()
} else if (animal is Sheep) {
    animal.meimei()
}

//更简洁的 使用 when 关键字
when (animal) {
    is Dog -> animal.wangwang()
    is Cat ->  animal.miaomiao()
    is Sheep -> animal.meimei()
}
```

### 3.函数默认参数

```java
//java 
public void wuJianDao(String a, Integer b, Long c) {
        String result = a+"对不起，我是警察";
        call(b);
        kill(c);
    }

    public void wuJianDao(Integer b, Long c) {
        wuJianDao("给个机会，我现在想做个好人", b, c);
    }

    public void wuJianDao(Long c) {
        wuJianDao(110, c);
    }
```

```kotlin
//kotlin
fun wuJianDao(a: String = "给个机会，我现在想做个好人", b: Int = 110, c: Long) {
    var result: String = a + "对不起，我是警察"
    call(b)
    kill(c)
}
//调用方法时前面两个参数不传就是默认值，传了就是传入的值
```

### 4.扩展属性/方法

简单来讲就是给一些已经有的类扩展一些东西出来，不用继承或者包装。

```kotlin
//给集合扩展了一个lastIndex的属性
val <T> List<T>.lastIndex: Int
    get() = size - 1
```



```kotlin
//比如给String扩展了 haha 方法
fun String.haha(a:String){
  var result = this+" --- " +a
  print(result)
}

var b:String = "hehe"
b.haha(a)//hehe --- haha
```

看看Java没有扩展功能是怎么操作的

```java
//ListUtils
public static int getLastIndex(List<T> list){
  return list.size -1;
}
//StringUtils
public static void haha(String a,String b){
  String result = a+" --- "+b;
  print(result)
}
```

这就是为啥分包总有个`utils`，手动斜眼

### 5.字符串模板











