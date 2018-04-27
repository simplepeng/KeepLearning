# [译]从Java切换到Kotlin：5个令Android开发者兴奋的特征

## 1.命名参数

每个Java开发者的噩梦：大量的参数（例如在Cursors或Android中创建SQLite查询），它们的名字和方法定义中的顺序。如果没有文档或IDE帮助，您无法在Java中正确编写它

```java
@Override
public Loader<Cursor> onCreateLoader(int i, Bundle bundle) {
    return new CursorLoader(this, CONTENT_URI, proj, 
                             null, null, null);
}
```

幸运的是，Android Studio团队添加了有用的功能，突出显示了传递给这种功能的参数的名称。但是，Kotlin在没有IDE帮助的情况下实现同样的效果也很容易

## 2.数据类 

对Kotlin来说，这可能是Java编程人员最有用，最“壮观”的选择之一。数据类使每个开发人员的生活变得更加简单，因为它仅用一行代码表示我们心爱的POJO类

Java：

```java
public class Person {
    private final String name;
    private final int age;

    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public String getName() {
        return name;
    }

    public int getAge() {
        return age;
    }
}
```

Kotlin

```kotlin
data class Person(val name: String, val age: Int)
```

这里做了什么？编译器会自动从主构造函数中声明的所有属性中派生下列成员：

* Any类的标准方法（相当于Java中的Object）：equals（），hashCode（），copy（）
* toString() 形式为 Person(name=Michał, age=22)
* 不再需要getter，setter，直接使用对象属性

它有助于摆脱我们通常不想维护的样板代码 - 在Kotlin中，编译器为我们做了。从现在起，我们可以关注应用程序的实际功能，而不是一次又一次重复相同的代码

## 3.空安全和安全的调用

Kotlin的主要目标之一是清除空引用异常。它仍然提供可空的类型，但仅限于与Java代码完全协作。默认的Kotlin类型是非空的，如果您试图将它们标记为null，它不会让您编译通过。

```kotlin
var bundle : Bundle = null //won't compile
var bundle : Bundle? = null //nullable type, it compiles
```

Java中的典型情况:

```java
public void sendMessage(@Nullable Person person, @NotNull Mailer mailer, String message) {
    if (person == null || message == null) return;
    PersonalInfo personalInfo = person.getPersonalInfo();
  
    if (personalInfo == null) return;
    String email = personalInfo.getEmail();
  
    if (email == null) return;
    mailer.sendMessage(email, message);
}
```

同样的情况在Kotlin中：

```kotlin
fun sendMessage(person: Person?, mailer: Mailer, String message){
    val email = client?.personalInfo?.email
    
    if (email != null && message != null) {
        mailer.sendMessage(email, message)
    }
}
```

空检查让我们写更少的代码，使我们的应用程序更好地工作，而且使它看起来更好。这不是很棒吗?

## 4.拓展属性

当我每次需要删除重复的转换时，扩展属性都可以帮助到我，传统方式，我们可能写出如下代码：

```kotlin
var myBigDecimal = 26 as BigDecimal
var otherBigDecimal : BigDecimal = myBigDecimal
```

所以让我们用扩展属性代替上面的代码

```kotlin
val Int.bd : BigDecimal                           
     get() = BigDecimal(this)
```

在我们扩展Int类后，我们现在可以轻松地将我们的Ints转换为BigDecimals,它的工作原理完全相同:

```kotlin
var myBigDecimal = 26.bd
var otherBigDecimal : BigDecimal = myBigDecimal
```

我们已经完成了所有工作，无需从类继承或使用任何类型的设计模式，例如装饰器。 Kotlin提供了以快速和简单的方式使用新功能扩展课程的功能。

## 5.智能转换

当涉及类型转换时，Kotlin将表现得十分智能

```kotlin
fun demo(x: Any) {
    if (x is String) {
        print(x.length) // x is automatically cast to String
    }
}
```

关键字 is 相当于Java中的 instanceof，但它具有自己的强大功能。编译器检查if声明中的对象属于哪种实例，然后转换if代码块中的实例属性

```kotlin
when (x) {
    is Int -> print(x + 1)
    is String -> print(x.length + 1)
    is IntArray -> print(x.sum())
}
```

[原文链接](https://android.jlelse.eu/switching-from-java-to-kotlin-5-exciting-features-for-android-developers-49ce712a546)