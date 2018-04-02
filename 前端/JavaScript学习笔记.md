
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

## Location

window.location 对象用于获得当前页面的地址 (URL)，并把浏览器重定向到新的页面

*window.location* 对象在编写时可不使用 window 这个前缀

- location.hostname 返回 web 主机的域名
- location.pathname 返回当前页面的路径和文件名
- location.port 返回 web 主机的端口 （80 或 443）
- location.protocol 返回所使用的 web 协议（http:// 或 https://）
- location.href 属性返回当前页面的 URL

### Assign

location.assign() 方法加载新的文档

```html
<html>
<head>
<script>
function newDoc()
  {
  window.location.assign("http://www.w3school.com.cn")
  }
</script>
</head>
<body>

<input type="button" value="加载新文档" onclick="newDoc()">

</body>
</html>
```

## History

window.history 对象包含浏览器的历史

*window.history* 对象在编写时可不使用 window 这个前缀

- history.back() - 与在浏览器点击后退按钮相同
- history.forward() - 与在浏览器中点击按钮向前相同

## Navigator

window.navigator 对象包含有关访问者浏览器的信息

window.navigator 对象在编写时可不使用 window 这个前缀

```html
<div id="example"></div>
<script>
txt = "<p>Browser CodeName: " + navigator.appCodeName + "</p>";
txt+= "<p>Browser Name: " + navigator.appName + "</p>";
txt+= "<p>Browser Version: " + navigator.appVersion + "</p>";
txt+= "<p>Cookies Enabled: " + navigator.cookieEnabled + "</p>";
txt+= "<p>Platform: " + navigator.platform + "</p>";
txt+= "<p>User-agent header: " + navigator.userAgent + "</p>";
txt+= "<p>User-agent language: " + navigator.systemLanguage + "</p>";
document.getElementById("example").innerHTML=txt;
</script>
```

警告：来自 navigator 对象的信息具有误导性，不应该被用于检测浏览器版本，这是因为：

- navigator 数据可被浏览器使用者更改
- 浏览器无法报告晚于浏览器发布的新操作系统

##  消息框

### 警告框

警告框经常用于确保用户可以得到某些信息

当警告框出现后，用户需要点击确定按钮才能继续进行操作

```html
alert("文本")
```

### 确认框

确认框用于使用户可以验证或者接受某些信息

当确认框出现后，用户需要点击确定或者取消按钮才能继续进行操作

如果用户点击确认，那么返回值为 true。如果用户点击取消，那么返回值为 false

```
confirm("文本")
```

### 提示框

提示框经常用于提示用户在进入页面前输入某个值

当提示框出现后，用户需要输入某个值，然后点击确认或取消按钮才能继续操纵

如果用户点击确认，那么返回值为输入的值。如果用户点击取消，那么返回值为 null

```
prompt("文本","默认值")
```

## 计时

通过使用 JavaScript，我们有能力作到在一个设定的时间间隔之后来执行代码，而不是在函数被调用后立即执行。我们称之为计时事件

### setTimeout()

```javascript
var t=setTimeout("javascript语句",毫秒)
```

setTimeout() 方法会返回某个值。在上面的语句中，值被储存在名为 t 的变量中。假如你希望取消这个 setTimeout()，你可以使用这个变量名来指定它

setTimeout() 的第一个参数是含有 JavaScript 语句的字符串。这个语句可能诸如 "alert('5 seconds!')"，或者对函数的调用，诸如 alertMsg()"

第二个参数指示从当前起多少毫秒后执行第一个参数

### clearTimeout()

```javascript
clearTimeout(setTimeout_variable)
```

取消setTimeout()

## Cookies

cookie 是存储于访问者的计算机中的变量。每当同一台计算机通过浏览器请求某个页面时，就会发送这个 cookie。你可以使用 JavaScript 来创建和取回 cookie 的值

# HTML DOM (文档对象模型)

当网页被加载时，浏览器会创建页面的文档对象模型（Document Object Model）

![](http://www.w3school.com.cn/i/ct_htmltree.gif)

通过可编程的对象模型，JavaScript 获得了足够的能力来创建动态的 HTML。

- JavaScript 能够改变页面中的所有 HTML 元素
- JavaScript 能够改变页面中的所有 HTML 属性
- JavaScript 能够改变页面中的所有 CSS 样式
- JavaScript 能够对页面中的所有事件做出反应

## 查找HTML元素

通常，通过 JavaScript，您需要操作 HTML 元素

为了做到这件事情，您必须首先找到该元素。有三种方法来做这件事：

- 通过 id 找到 HTML 元素
- 通过标签名找到 HTML 元素
- 通过类名找到 HTML 元素

### 通过id查找HTML元素

在 DOM 中查找 HTML 元素的最简单的方法，是通过使用元素的 id

```javascript
var x=document.getElementById("intro");
```

如果找到该元素，则该方法将以对象（在 x 中）的形式返回该元素

如果未找到该元素，则 x 将包含 null

### 通过标签名查找 HTML 元素

本例查找 id="main" 的元素，然后查找 "main" 中的所有 <p> 元素：

```javascript
var x=document.getElementById("main");
var y=x.getElementsByTagName("p");
```

## 改变HTML

HTML DOM 允许 JavaScript 改变 HTML 元素的内容

### 改变HTML输出流

JavaScript 能够创建动态的 HTML 内容

在 JavaScript 中，document.write() 可用于直接向 HTML 输出流写内容

```html
<!DOCTYPE html>
<html>
<body>
<script>
document.write(Date());
</script>
</body>
</html>
```

提示：绝不要使用在文档加载之后使用 document.write(),这会覆盖该文档

### 改变HTML内容

修改 HTML 内容的最简单的方法时使用 innerHTML 属性

```javascript
document.getElementById(id).innerHTML=new HTML
```

```html
<html>
<body>
<p id="p1">Hello World!</p>
<script>
document.getElementById("p1").innerHTML="New text!";
</script>
</body>
</html>
```

### 改变HTML属性

```javascript
document.getElementById(id).attribute=new value
```

```html
<!DOCTYPE html>
<html>
<body>

<img id="image" src="smiley.gif">

<script>
document.getElementById("image").src="landscape.jpg";
</script>
</body>
</html>
```

## 改变CSS

HTML DOM 允许 JavaScript 改变 HTML 元素的样式

### 改变HTML样式

```javascript
document.getElementById(id).style.property=new style
```

```html
<p id="p2">Hello World!</p>

<script>
document.getElementById("p2").style.color="blue";
</script>
```

## 事件

HTML DOM 使 JavaScript 有能力对 HTML 事件做出反应

## 对事件做出反应

我们可以在事件发生时执行 JavaScript，比如当用户在 HTML 元素上点击时

```
onclick=JavaScript
```

HTML 事件的例子：

- 当用户点击鼠标时
- 当网页已加载时
- 当图像已加载时
- 当鼠标移动到元素上时
- 当输入字段被改变时
- 当提交 HTML 表单时
- 当用户触发按键时

```javascript
<h1 onclick="this.innerHTML='谢谢!'">请点击该文本</h1>
```

```javascript
<!DOCTYPE html>
<html>
<head>
<script>
function changetext(id)
{
id.innerHTML="谢谢!";
}
</script>
</head>
<body>
<h1 onclick="changetext(this)">请点击该文本</h1>
</body>
</html>
```

### 事件属性

如需向 HTML 元素分配 事件，您可以使用事件属性

```javascript
<button onclick="displayDate()">点击这里</button>
```

### 使用HTML DOM来分配事件

HTML DOM 允许您通过使用 JavaScript 来向 HTML 元素分配事件

```javascript
<script>
document.getElementById("myBtn").onclick=function(){
    displayDate()
};
</script>
```

### onload和onunload 事件

onload 和 onunload 事件会在用户进入或离开页面时被触发

onload 事件可用于检测访问者的浏览器类型和浏览器版本，并基于这些信息来加载网页的正确版本

onload 和 onunload 事件可用于处理 cookie

```
<body onload="checkCookies()">
```

### onchange 事件

onchange 事件常结合对输入字段的验证来使用

```html
<input type="text" id="fname" onchange="upperCase()">
```

### onmouseover和onmouseout 事件

onmouseover 和 onmouseout 事件可用于在用户的鼠标移至 HTML 元素上方或移出元素时触发函数

```html
<!DOCTYPE html>
<html>
<body>

<div onmouseover="mOver(this)" onmouseout="mOut(this)" style="background-color:green;width:120px;height:20px;padding:40px;color:#ffffff;">把鼠标移到上面</div>

<script>
function mOver(obj)
{
obj.innerHTML="谢谢"
}

function mOut(obj)
{
obj.innerHTML="把鼠标移到上面"
}
</script>

</body>
</html>
```

### onmousedown、onmouseup 以及 onclick 事件

onmousedown, onmouseup 以及 onclick 构成了鼠标点击事件的所有部分。首先当点击鼠标按钮时，会触发 onmousedown 事件，当释放鼠标按钮时，会触发 onmouseup 事件，最后，当完成鼠标点击时，会触发 onclick 事件

```html
<!DOCTYPE html>
<html>
<body>

<div onmousedown="mDown(this)" onmouseup="mUp(this)" style="background-color:green;color:#ffffff;width:90px;height:20px;padding:40px;font-size:12px;">请点击这里</div>

<script>
function mDown(obj)
{
obj.style.backgroundColor="#1ec5e5";
obj.innerHTML="请释放鼠标按钮"
}

function mUp(obj)
{
obj.style.backgroundColor="green";
obj.innerHTML="请按下鼠标按钮"
}
</script>

</body>
</html>
```

## 元素（节点）

### 创建新的HTML元素

如需向 HTML DOM 添加新元素，您必须首先创建该元素（元素节点），然后向一个已存在的元素追加该元素

```html
<div id="div1">
<p id="p1">这是一个段落</p>
<p id="p2">这是另一个段落</p>
</div>

<script>
//创建新的 <p> 元素
var para=document.createElement("p");
//创建了一个文本节点
var node=document.createTextNode("这是新段落。");
//向 <p> 元素追加这个文本节点
para.appendChild(node);
//向这个已有的元素追加新元素
var element=document.getElementById("div1");
element.appendChild(para);
</script>
```

### 删除已有的HTML元素

如需删除 HTML 元素，您必须首先获得该元素的父元素

```html
<div id="div1">
<p id="p1">这是一个段落。</p>
<p id="p2">这是另一个段落。</p>
</div>

<script>
//找到父元素
var parent=document.getElementById("div1");
//找到子元素
var child=document.getElementById("p1");
//删除子元素
parent.removeChild(child);
</script>
```

通过 parentNode 删除子元素

```javascript
var child=document.getElementById("p1");
child.parentNode.removeChild(child);
```

# CDN 内容分发网络

您总是希望网页可以尽可能地快。您希望页面的容量尽可能地小，同时您希望浏览器尽可能多地进行缓存

如果许多不同的网站使用相同的 JavaScript 框架，那么把框架库存放在一个通用的位置供每个网页分享就变得很有意义了

CDN (Content Delivery Network) 解决了这个问题。CDN 是包含可分享代码库的服务器网络

## 引入jQuery

```javascript
<script src="https://ajax.googleapis.com/ajax/libs/jquery/1.8.3/jquery.min.js">
</script>
```

