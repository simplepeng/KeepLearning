# JavaScript入门笔记

## 基本语法

```javascript
var a = 2;
var b = 'hello world';
```

大致和java差不多，但是可以省略语句结尾的分号（建议不省略）

## 注释

* 行注释 //
* 块注释 /*...*/

```javascript
//行注释
/*
块注释
*/
```

## 数据类型

### 数字类型 Number

JavaScript 只有一种数字类型，不区分整数和浮点数，统一用Number表示

```javascript
123; // 整数123
0.456; // 浮点数0.456
1.2345e3; // 科学计数法表示1.2345x1000，等同于1234.5
-99; // 负数
NaN; // NaN表示Not a Number，当无法计算结果时用NaN表示
Infinity; // Infinity表示无限大，当数值超过了JavaScript的Number所能表示的最大值时，就表示为Infinity
```

所有 JavaScript 数字均为 64 位
JavaScript 不是类型语言。与许多其他编程语言不同，JavaScript 不定义不同类型的数字，比如整数、短、长、浮点等等。

JavaScript 中的所有数字都存储为根为 10 的 64 位（8 比特），浮点数

###  字符串 String

字符串是以单引号('')或双引号("”)括起来的任意文本

```javascript
var a = 'hello';
var b = "world";
```

*需要特别注意的是*，字符串是不可变的，如果对字符串的某个索引赋值，不会有任何错误，但是，也没有任何效果

```javascript
var a = "hello";
a[0] = 'x';
alert(a);//a 依然等于 hello
```

### 布尔 Boolean

布尔（逻辑）只能有两个值：true 或 false

```javascript
var a = true;
var b = 2 < 1;// b = false
```

### Undefined 和 Null

`null`表示一个空的值，而`undefined`表示值未定义。

这并没有什么卵用，区分两者的意义不大。大多数情况下，我们都应该用`null`。`undefined`仅仅在判断函数参数是否传递的情况下有用（峰哥淘气了。。。。）

### 数组 Array

JavaScript的数组可以包括任意数据类型

```javascript
var a = [1,'hello',null,true,3.3];
```

也可以用new Array创建数组， 但不是不推荐下面这种写法

```javascript
var arr = new Array(1,2,3);
```

*请注意*，直接给`Array`的`length`赋一个新的值会导致`Array`大小的变化

```javascript
var arr = [1, 2, 3];
arr.length; // 3
arr.length = 6;
arr; // arr变为[1, 2, 3, undefined, undefined, undefined]
arr.length = 2;
arr; // arr变为[1, 2]
```

*请注意*，如果通过索引赋值时，索引超过了范围，同样会引起`Array`大小的变化：

```javascript
var arr = [1, 2, 3];
arr[5] = 'x';
arr; // arr变为[1, 2, 3, undefined, undefined, 'x']
```

大多数其他编程语言不允许直接改变数组的大小，越界访问索引会报错。然而，JavaScript的`Array`却不会有任何错误。在编写代码时，不建议直接修改`Array`的大小，访问索引时要确保索引不会越界。

### 对象 Object

对象由花括号分隔。在括号内部，对象的属性以名称和值对的形式 (name : value) 来定义，属性由逗号分隔

```javascript
var person = {
  name:'simple',
  age:24,
  city:'chongqing'
};
```

对象的键都是字符串类型，值可以是任意类型

如果属性名包含特殊字符，就必须用`''`括起来

```javascript
var person = {
    name: 'simple',
    'middle-school': 'No.1 Middle School'
};
```

访问这个属性也无法使用`.`操作符，必须用`['xxx']`来访问

```javascript
person['middle-school'] //'No.1 Middle School'
```

## 函数

### 定义函数

```javascript
function 函数名(参数){
  ....
  return 返回值；//可选
}
```

### 匿名函数

```javascript
var 函数名 = function（参数）{
  ...
  return 返回值；//可选
}
```

## 异常

捕获异常

```javascript
try
  {
  //在这里运行代码
  }
catch(err)
  {
  //在这里处理错误
  }
```

抛出异常 Throw

```javascript
throw exception
```

异常可以是 JavaScript 字符串、数字、逻辑值或对象。

## 操作 HTML 元素

如需从 JavaScript 访问某个 HTML 元素，您可以使用 document.getElementById(*id*) 方法。

请使用 "id" 属性来标识 HTML 元素：

```html
<!DOCTYPE html>
<html>
<body>
<h1>我的第一张网页</h1>
<p id="demo">我的第一个段落</p>
<script>
document.getElementById("demo").innerHTML="我的第一段 JavaScript";
</script>
</body>
</html>
```