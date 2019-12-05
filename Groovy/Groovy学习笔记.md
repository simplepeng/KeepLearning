## Groovy是什么

Groovy是一种基于JVM（Java虚拟机）的敏捷开发语言，它结合了Python、Ruby和Smalltalk的许多强大的特性，Groovy 代码能够与 Java 代码很好地结合，也能用于扩展现有代码。由于其运行在 JVM 上的特性，Groovy 可以使用其他 Java 语言编写的库。

## HelloWorld

```groovy
class HelloWrold{
    static void static main(args) {
        println "Hello World"
    }
}
```

## 变量

Groovy中的变量可以通过两种方式定义 - 使用数据类型的本地语法，或者使用def关键字。

```groovy
def a = "hello"
def b = 1
def c = 'world'
```

## 运算符

常用运算符和Java没什么区别

### 范围运算符

Groovy支持范围的概念，并在`..`符号的帮助下提供范围运算符的符号。

```groovy
def rang = 0..5
```

## 循环

`while`，`for`常规循环和Java类似

### for-in

```groovy
for(int i in 1..5) { 
      println(i); 
 } 
```

## 逻辑条件语句

`if-else`，`switch`和Java类似

## 方法

Groovy的方法使用`def`关键字定义，定义形参时不必声明类型。

也可以给方法添加修饰符`public`，`private`，`protected`，默认为`public`

```groovy
def method(){
  return "hello world";
}
```

### 默认参数

如果使用非默认和默认参数，则必须注意，默认参数应在参数列表的末尾定义。

```groovy
def method(arg,arg2 = 1,arg3 = "hello"){
  
}
```

## 集合-List

```groovy
def list = [1,2,3,4];
println(list);

list.add(12);
```

## 映射-Map

## 闭包



## 参考文献

* https://www.w3cschool.cn/groovy/
* https://www.ibm.com/developerworks/cn/education/java/j-groovy/j-groovy.html