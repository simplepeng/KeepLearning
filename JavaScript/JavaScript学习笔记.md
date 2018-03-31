
# 基本语法

```javascript
var a = 2;
var b = 'hello world';
```

大致和java差不多，但是可以省略语句结尾的分号（建议不省略）

# 注释

* 行注释 //
* 块注释 /*...*/

```javascript
//行注释
/*
块注释
*/
```

# 数据类型

## 数字类型 Number

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

##  字符串 String

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

## 布尔 Boolean

布尔（逻辑）只能有两个值：true 或 false

```javascript
var a = true;
var b = 2 < 1;// b = false
```

## Undefined 和 Null

`null`表示一个空的值，而`undefined`表示值未定义。

这并没有什么卵用，区分两者的意义不大。大多数情况下，我们都应该用`null`。`undefined`仅仅在判断函数参数是否传递的情况下有用（峰哥淘气了。。。。）

## 数组 Array

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

## 对象 Object

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

# 函数

## 定义函数

```javascript
function 函数名(参数){
  ....
  return 返回值；//可选
}
```

## 匿名函数

```javascript
var 函数名 = function（参数）{
  ...
  return 返回值；//可选
}
```

# 异常

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

# 操作 HTML 元素

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
# Js 对象

JavaScript 中的所有事物都是对象：字符串、数值、数组、函数...

此外，JavaScript 允许自定义对象

## 日期对象 Date

### 定义日期

Date 对象用于处理日期和时间，可以通过 new 关键词来定义 Date 对象

```javascript
var myDate=new Date() 
```

Date 对象自动使用当前的日期和时间作为其初始值

### 操作日期

```javascript
var myDate=new Date()
myDate.setFullYear(2008,7,9)
```

注意：表示月份的参数介于 0 到 11 之间。也就是说，如果希望把月设置为 8 月，则参数应该是 7.

```javascript
var myDate=new Date()
myDate.setDate(myDate.getDate()+5)
```

注意：如果增加天数会改变月份或者年份，那么日期对象会自动完成这种转换

### 比较日期

```javascript
var myDate=new Date();
myDate.setFullYear(2008,8,9);

var today = new Date();

if (myDate>today)
{
alert("Today is before 9th August 2008");
}
else
{
alert("Today is after 9th August 2008");
}
```

## 数组对象

### 定义数组

数组对象用来在单独的变量名中存储一系列的值

我们使用关键词 new 来创建数组对象

```javascript
var myArray=new Array()
```

```javascript
var mycars=new Array()
mycars[0]="Saab"
mycars[1]="Volvo"
mycars[2]="BMW"
```

```javascript
var mycars=new Array("Saab","Volvo","BMW")
```

还是这样爽一点吧

```javascript
var cars=["Audi","BMW","Volvo"];
```

## 正则表达式对象 RegExp 

RegExp 对象用于规定在文本中检索的内容

RegExp 是正则表达式的缩写。

当您检索某个文本时，可以使用一种模式来描述要检索的内容。RegExp 就是这种模式。

简单的模式可以是一个单独的字符。

更复杂的模式包括了更多的字符，并可用于解析、格式检查、替换等等。

您可以规定字符串中的检索位置，以及要检索的字符类型，等等。

```javascript
var patt1=new RegExp("e");
```

### RegExp 对象的方法

RegExp 对象有 3 个方法：test()、exec() 以及 compile()

#### test()

test() 方法检索字符串中的指定值。返回值是 true 或 false

```javascript
var patt1=new RegExp("e");
document.write(patt1.test("The best things in life are free")); 
//输出 true
```

#### exec()

exec() 方法检索字符串中的指定值。返回值是被找到的值。如果没有发现匹配，则返回 null

```javascript
var patt1=new RegExp("e");
document.write(patt1.exec("The best things in life are free")); 
//输出 e
```

#### compile()

compile() 方法用于改变 RegExp

compile() 既可以改变检索模式，也可以添加或删除第二个参数

```javascript
var patt1=new RegExp("e");

document.write(patt1.test("The best things in life are free"));

patt1.compile("d");

document.write(patt1.test("The best things in life are free"));
```

由于字符串中存在 "e"，而没有 "d"，以上代码的输出是

```javascript
truefalse
```

# 浏览器对象模型 BOM

浏览器对象模型 (BOM) 使 JavaScript 有能力与浏览器“对话

浏览器对象模型（Browser Object Model）尚无正式标准。

由于现代浏览器已经（几乎）实现了 JavaScript 交互性方面的相同方法和属性，因此常被认为是 BOM 的方法和属性

## Window

### window 对象

所有浏览器都支持 *window* 对象。它表示浏览器窗口。

所有 JavaScript 全局对象、函数以及变量均自动成为 window 对象的成员。

全局变量是 window 对象的属性。

全局函数是 window 对象的方法。

甚至 HTML DOM 的 document 也是 window 对象的属性之一

```javascript
window.document.getElementById("header");
```

可省略window前缀

```javascript
document.getElementById("header");
```

### window 尺寸

有三种方法能够确定浏览器窗口的尺寸（浏览器的视口，不包括工具栏和滚动条）

对于Internet Explorer、Chrome、Firefox、Opera 以及 Safari：

- window.innerHeight - 浏览器窗口的内部高度
- window.innerWidth - 浏览器窗口的内部宽度

对于 Internet Explorer 8、7、6、5：

- document.documentElement.clientHeight
- document.documentElement.clientWidth

或者

- document.body.clientHeight
- document.body.clientWidth

实用的 JavaScript 方案（涵盖所有浏览器）

```javascript
var w=window.innerWidth
|| document.documentElement.clientWidth
|| document.body.clientWidth;

var h=window.innerHeight
|| document.documentElement.clientHeight
|| document.body.clientHeight;
```

### 其他window方法

- window.open() - 打开新窗口
- window.close() - 关闭当前窗口
- window.moveTo() - 移动当前窗口
- window.resizeTo() - 调整当前窗口的尺寸


## Screen

window.screen 对象包含有关用户屏幕的信息

window.screen 对象在编写时可以不使用 window 这个前缀

### 可用宽度

screen.availWidth 属性返回访问者屏幕的宽度，以像素计，减去界面特性，比如窗口任务栏

```javascript
<script>
document.write("可用宽度：" + screen.availWidth);
</script>
```

### 可用高度

screen.availHeight 属性返回访问者屏幕的高度，以像素计，减去界面特性，比如窗口任务栏

```javascript
<script>
document.write("可用高度：" + screen.availHeight);
</script>
```

