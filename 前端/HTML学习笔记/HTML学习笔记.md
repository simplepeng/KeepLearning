
# 简介

* HTML 是描述网页的语言

- HTML 指的是超文本标记语言 (**H**yper **T**ext **M**arkup **L**anguage)
- &lt;html&gt; 与 &lt;/html&gt;  之间的文本描述网页
- &lt;body&gt;  与 &lt;/body&gt;  之间的文本是可见的页面内容
- &lt;h1&gt;  与 &lt;/h1&gt;  之间的文本被显示为标题
- &lt;p&gt;  与 &lt;/p&gt;  之间的文本被显示为段落

# 基础

## 标题

HTML 标题（Heading）是通过 &lt;h1&gt;  - &lt;h6&gt;  等标签进行定义的

```html
<h1>This is a heading</h1>
<h2>This is a heading</h2>
<h3>This is a heading</h3>
```

## 段落

HTML 段落（paragraph）是通过 &lt;p&gt; 标签进行定义的

```html
<p>This is a paragraph.</p>
<p>This is another paragraph.</p>
```

## 链接

HTML 链接（hypertext reference）是通过 &lt;a&gt; 标签进行定义的

```html
<a href="http://www.w3school.com.cn">This is a link</a>
```

也可以用图像作为链接

```html
<a href="/example/html/lastpage.html">
<img border="0" src="/i/eg_buttonnext.gif" />
</a>
```

"链接文本" 不必一定是文本。图片或其他 HTML 元素都可以成为链接

### target 属性

使用 Target 属性，你可以定义被链接的文档在何处显示

在新窗口打开文档：

```html
<a href="http://www.w3school.com.cn/" target="_blank">Visit W3School!</a>
```

### name属性

name 属性规定锚（anchor）的名称,任意名称都可以

您可以使用 name 属性创建 HTML 页面中的书签，可以使用 id 属性来替代 name 属性，命名锚同样有效

书签不会以任何特殊方式显示，它对读者是不可见的

当使用命名锚（named anchors）时，我们可以创建直接跳至该命名锚（比如页面中某个小节）的链接，这样使用者就无需不停地滚动页面来寻找他们需要的信息了

```html
<a name="label">锚（显示在页面上的文本）</a>
```

首先，我们在 HTML 文档中对锚进行命名（创建一个书签）：

```html
<a name="tips">基本的注意事项 - 有用的提示</a>
```

然后，我们在同一个文档中创建指向该锚的链接：

```html
<a href="#tips">有用的提示</a>
```

您也可以在其他页面中创建指向该锚的链接：

```html
<a href="http://www.w3school.com.cn/html/html_links.asp#tips">有用的提示</a>
```

## 图像

HTML 图像是通过 <img> 标签进行定义的

```html
<img src="w3school.jpg" width="104" height="142" />
```

### 替换文本属性（Alt）

alt 属性用来为图像定义一串预备的可替换的文本

```html
<img src="boat.gif" alt="Big Boat">
```

在浏览器无法载入图像时，替换文本属性告诉读者她们失去的信息。此时，浏览器将显示这个替代性的文本而不是图像。为页面上的图像都加上替换文本属性是个好习惯，这样有助于更好的显示信息，并且对于那些使用纯文本浏览器的人来说是非常有用的

## 水平线

<hr /> 标签在 HTML 页面中创建水平线（horizontal rule），hr 元素可用于分隔内容

```html
<p>This is a paragraph</p>
<hr />
<p>This is a paragraph</p>
<hr />
<p>This is a paragraph</p>
```

## 注释

```html
<!-- This is a comment -->
```

## 换行

不产生一个新段落的情况下进行换行（新行），请使用 <br/ 标签

```html
<p>This is<br />a para<br />graph with line breaks</p>
```

# 元素

HTML 元素指的是从开始标签（start tag）到结束标签（end tag）的所有代码

| 开始标签                | 元素内容            | 结束标签 |
| ----------------------- | ------------------- | -------- |
| <p>                     | This is a paragraph | </p>     |
| <a href="default.htm" > | This is a link      | </a>     |
| <br />                  |                     |          |

# 属性

HTML 标签可以拥有*属性*。属性提供了有关 HTML 元素的*更多的信息*。

属性总是以名称/值对的形式出现，比如：*name="value"*。

属性总是在 HTML 元素的*开始标签*中规定

HTML 链接由 <a> 标签定义。链接的地址在 href 属性中指定：

```html
<a href="http://www.w3school.com.cn">This is a link</a>
```

使用小写属性

始终为属性加引号，如果属性本身带有双引号，就必须加单引号

```html
name='Bill "HelloWorld" Gates'
```

# 样式

style 属性用于改变 HTML 元素的样式

```html
<html>
<body style="background-color:PowderBlue;">

<h1>Look! Styles and colors</h1>

<p style="font-family:verdana;color:red">
This text is in Verdana and red</p>

<p style="font-family:times;color:green">
This text is in Times and green</p>

<p style="font-size:30px">This text is 30 pixels high</p>

</body>
</html>
```

## 应该避免使用下面这些标签和属性：

| 标签                 | 描述               |
| -------------------- | ------------------ |
| &lt;center&gt;             | 定义居中的内容。   |
| &lt;font&gt; 和 &lt;basefont&gt; | 定义 HTML 字体。   |
| &lt;s&gt; 和 &lt;strike&gt;      | 定义删除线文本     |
| &lt;u&gt;                  | 定义下划线文本     |
| 属性                 | 描述               |
| align                | 定义文本的对齐方式 |
| bgcolor              | 定义背景颜色       |
| color                | 定义文本颜色       |

对于以上这些标签和属性：请使用样式代替！

# 表格

表格由 &lt;table&gt; 标签来定义。每个表格均有若干行（由  &lt;tr&gt; 标签（table row）定义），每行被分割为若干单元格（由  &lt;td&gt; 标签定义）。字母 td 指表格数据（table data），即数据单元格的内容。数据单元格可以包含文本、图片、列表、段落、表单、水平线、表格等等

```html
<table border="1">
<tr>
<td>row 1, cell 1</td>
<td>row 1, cell 2</td>
</tr>
<tr>
<td>row 2, cell 1</td>
<td>row 2, cell 2</td>
</tr>
</table>
```

## 边框

border 属性定义边框的粗细，不设置就没有边框

## 表头

表格的表头使用 &lt;th&gt; 标签（table heading）进行定义

# 列表

## 无序列表

无序列表是一个项目的列表，此列项目使用粗体圆点（典型的小黑圆圈）进行标记

无序列表始于 &lt;ul&gt; 标签（unordered list）。每个列表项始于 &lt;li&gt; （list）

```html
<ul>
<li>Coffee</li>
<li>Milk</li>
</ul>
```

- Coffee
- Milk

列表项内部可以使用段落、换行符、图片、链接以及其他列表等等

## 有序列表

同样，有序列表也是一列项目，列表项目使用数字进行标记

有序列表始于 &lt;ol&gt; 标签（ordered list）。每个列表项始于 <li> 标签

```html
<ol>
<li>Coffee</li>
<li>Milk</li>
</ol>
```

1. Coffee
2. Milk

列表项内部可以使用段落、换行符、图片、链接以及其他列表等等

## 定义列表

自定义列表不仅仅是一列项目，而是项目及其注释的组合

自定义列表以 &lt;dl&gt; 标签（definition list）开始。每个自定义列表项以 <dt> 开始。每个自定义列表项的定义以 &lt;dd&gt; 开始

```html
<dl>
<dt>Coffee</dt>
<dd>Black hot drink</dd>
<dt>Milk</dt>
<dd>White cold drink</dd>
</dl>
```

Coffee

Black hot drink

Milk

White cold drink

定义列表的列表项内部可以使用段落、换行符、图片、链接以及其他列表等等

# 块

大多数 HTML 元素被定义为块级元素（block level element）或内联元素（ inline element）

## 块元素

块级元素在浏览器显示时，通常会以新行来开始（和结束）

&lt;h1>, &lt;p>, &lt;ul>, &lt;table>

## 内联元素

内联元素在显示时通常不会以新行开始

例子：&lt;b>, &lt;td>, &lt;a>, &lt;img>

## div元素

HTML &lt;div> 元素是块级元素，它是可用于组合其他 HTML 元素的容器

**DIV**是[层叠样式表](https://baike.baidu.com/item/%E5%B1%82%E5%8F%A0%E6%A0%B7%E5%BC%8F%E8%A1%A8)中的定位技术，全称DIVision，即为划分。有时可以称其为图层

&lt;div> 元素没有特定的含义。除此之外，由于它属于块级元素，浏览器会在其前后显示折行。

如果与 CSS 一同使用，&lt;div> 元素可用于对大的内容块设置样式属性

&lt;div> 元素的另一个常见的用途是文档布局。它取代了使用表格定义布局的老式方法。使用 &lt;table> 元素进行文档布局不是表格的正确用法。&lt;table> 元素的作用是显示表格化的数据

## span元素

HTML &lt;span> 元素是内联元素，可用作文本的容器

&lt;span> 元素也没有特定的含义

当与 CSS 一同使用时，&lt;span> 元素可用于为部分文本设置样式属性

# 类

对 HTML 进行分类（设置类），使我们能够为元素的类定义 CSS 样式

为相同的类设置相同的样式，或者为不同的类设置不同的样式

```html
<!DOCTYPE html>
<html>
<head>
<style>
.cities {
    background-color:black;
    color:white;
    margin:20px;
    padding:20px;
} 
</style>
</head>

<body>

<div class="cities">
<h2>London</h2>
<p>
London is the capital city of England. 
It is the most populous city in the United Kingdom, 
with a metropolitan area of over 13 million inhabitants.
</p>
</div> 

</body>
</html>
```

## 分类块级元素

HTML &lt;div> 元素是*块级元素*。它能够用作其他 HTML 元素的容器

设置 &lt;div> 元素的类，使我们能够为相同的 &lt;div> 元素设置相同的类

```html
<!DOCTYPE html>
<html>
<head>
<style>
.cities {
    background-color:black;
    color:white;
    margin:20px;
    padding:20px;
} 
</style>
</head>

<body>

<div class="cities">
<h2>London</h2>
<p>London is the capital city of England. 
It is the most populous city in the United Kingdom, 
with a metropolitan area of over 13 million inhabitants.</p>
</div>

<div class="cities">
<h2>Paris</h2>
<p>Paris is the capital and most populous city of France.</p>
</div>

<div class="cities">
<h2>Tokyo</h2>
<p>Tokyo is the capital of Japan, the center of the Greater Tokyo Area,
and the most populous metropolitan area in the world.</p>
</div>

</body>
</html>
```

## 分类行级元素

HTML &lt;span> 元素是行内元素，能够用作文本的容器

设置 &lt;span> 元素的类，能够为相同的 &lt;span> 元素设置相同的样式

```html
<!DOCTYPE html>
<html>
<head>
<style>
  span.red {color:red;}
</style>
</head>
<body>

<h1>My <span class="red">Important</span> Heading</h1>

</body>
</html>
```

# 布局

## 使用&lt;div>元素的HTML布局

&lt;div> 元素常用作布局工具，因为能够轻松地通过 CSS 对其进行定位

```html
<!DOCTYPE html>
<html>
<head>
<style>
#header {
    background-color:black;
    color:white;
    text-align:center;
    padding:5px;
}
#nav {
    line-height:30px;
    background-color:#eeeeee;
    height:300px;
    width:100px;
    float:left;
    padding:5px;	      
}
#section {
    width:350px;
    float:left;
    padding:10px;	 	 
}
#footer {
    background-color:black;
    color:white;
    clear:both;
    text-align:center;
   padding:5px;	 	 
}
</style>
</head>

<body>
<div id="header">
<h1>City Gallery</h1>
</div>

<div id="nav">
London<br>
Paris<br>
Tokyo<br>
</div>

<div id="section">
<h2>London</h2>
<p>
London is the capital city of England. It is the most populous city in the United Kingdom,
with a metropolitan area of over 13 million inhabitants.
</p>
<p>
Standing on the River Thames, London has been a major settlement for two millennia,
its history going back to its founding by the Romans, who named it Londinium.
</p>
</div>

<div id="footer">
Copyright ? W3Schools.com
</div>

</body>
</html>
```

## 使用HTML5的布局

HTML5 提供的新语义元素定义了网页的不同部分

HTMl5语义元素

| header  | 定义文档或节的页眉             |
| ------- | ------------------------------ |
| nav     | 定义导航链接的容器             |
| section | 定义文档中的节                 |
| article | 定义独立的自包含文章           |
| aside   | 定义内容之外的内容（比如侧栏） |
| footer  | 定义文档或节的页脚             |
| details | 定义额外的细节                 |
| summary | 定义 details 元素的标题        |

```html
<!DOCTYPE html>
<html>

<head>
<style>
header {
    background-color:black;
    color:white;
    text-align:center;
    padding:5px;	 
}
nav {
    line-height:30px;
    background-color:#eeeeee;
    height:300px;
    width:100px;
    float:left;
    padding:5px;	      
}
section {
    width:350px;
    float:left;
    padding:10px;	 	 
}
footer {
    background-color:black;
    color:white;
    clear:both;
    text-align:center;
    padding:5px;	 	 
}
</style>
</head>

<body>

<header>
<h1>City Gallery</h1>
</header>

<nav>
London<br>
Paris<br>
Tokyo<br>
</nav>

<section>
<h1>London</h1>
<p>
London is the capital city of England. It is the most populous city in the United Kingdom,
with a metropolitan area of over 13 million inhabitants.
</p>
<p>
Standing on the River Thames, London has been a major settlement for two millennia,
its history going back to its founding by the Romans, who named it Londinium.
</p>
</section>

<footer>
Copyright W3Schools.com
</footer>

</body>
</html>

```

## 使用表格的HTML布局

注释：&lt;table> 元素不是作为布局工具而设计的

&lt;table> 元素的作用是显示表格化的数据

使用 &lt;table> 元素能够取得布局效果，因为能够通过 CSS 设置表格元素的样式：

```html
<body>

<table class="lamp">
<tr>
  <th>
    <img src="/images/lamp.jpg" alt="Note" style="height:32px;width:32px">
  </th>
  <td>
    The table element was not designed to be a layout tool.
  </td>
</tr>
</table>

</body>
```

```html
<style>
table.lamp {
    width:100%;
    border:1px solid #d4d4d4;
}
table.lamp th, td {
    padding:10px;
}
table.lamp td {
    width:40px;
}
</style>
```

# 框架

通过使用框架，你可以在同一个浏览器窗口中显示不止一个页面。每份HTML文档称为一个框架，并且每个框架都独立于其他的框架

使用框架的坏处：

- 开发人员必须同时跟踪更多的HTML文档
- 很难打印整张页面

## 框架结构标签

- 框架结构标签（&lt;frameset>）定义如何将窗口分割为框架
- 每个 frameset 定义了一系列行*或*列
- rows/columns 的值规定了每行或每列占据屏幕的面积

frameset 标签也被某些文章和书籍译为框架集

## 框架标签

&lt;Frame> 标签定义了放置在每个框架中的 HTML 文档

在下面的这个例子中，我们设置了一个两列的框架集。第一列被设置为占据浏览器窗口的 25%。第二列被设置为占据浏览器窗口的 75%

```html
<frameset cols="25%,75%">
   <frame src="frame_a.htm">
   <frame src="frame_b.htm">
</frameset>
```

# 内联框架

iframe用于在网页中显示网页

```html
<iframe src="URL" width="200" height="200" frameborder="0"></iframe>
```

## 使用iframe作为链接的目标

iframe 可用作链接的目标（target）

链接的 target 属性必须引用 iframe 的 name 属性

```html
<iframe src="demo_iframe.htm" name="iframe_a"></iframe>
<p><a href="http://www.w3school.com.cn" target="iframe_a">W3School.com.cn</a></p>
```

# 脚本

## script元素

&lt;script> 标签用于定义客户端脚本，比如 JavaScript

script 元素既可包含脚本语句，也可通过 src 属性指向外部脚本文件

必需的 type 属性规定脚本的 MIME 类型

JavaScript 最常用于图片操作、表单验证以及内容动态更新

```html
<script type="text/javascript">
document.write("Hello World!")
</script>
```

## noscript标签

&lt;noscript> 标签提供无法使用脚本时的替代内容，比方在浏览器禁用脚本时，或浏览器不支持客户端脚本时

```html
<script type="text/javascript">
document.write("Hello World!")
</script>
<noscript>Your browser does not support JavaScript!</noscript>
```

# 头部元素

## head元素

&lt;head> 元素是所有头部元素的容器。&lt;head> 内的元素可包含脚本，指示浏览器在何处可以找到样式表，提供元信息，等等

以下标签都可以添加到 head 部分：&lt;title>、&lt;base>、&lt;link>、&lt;meta>、&lt;script> 以及 &lt;style>

## title元素

&lt;title&gt; 标签定义文档的标题。

title 元素在所有 HTML/XHTML 文档中都是必需的。

title 元素能够：

- 定义浏览器工具栏中的标题
- 提供页面被添加到收藏夹时显示的标题
- 显示在搜索引擎结果中的页面标题


```html
<!DOCTYPE html>
<html>
<head>
<title>Title of the document</title>
</head>

<body>
The content of the document......
</body>

</html>
```

## base元素

&lt;base&gt; 标签为页面上的所有链接规定默认地址或默认目标（target）

```html
<head>
<base href="http://www.w3school.com.cn/images/" />
<base target="_blank" />
</head>
```

## link元素

&lt;link&gt; 标签定义文档与外部资源之间的关系

&lt;link&gt; 标签最常用于连接样式表

```html
<head>
<link rel="stylesheet" type="text/css" href="mystyle.css" />
</head>
```

## style元素

<style> 标签用于为 HTML 文档定义样式信息

您可以在 style 元素内规定 HTML 元素在浏览器中呈现的样式

```html
<head>
<style type="text/css">
body {background-color:yellow}
p {color:blue}
</style>
</head>
```

#  表单

## form元素

HTML 表单用于收集用户输入

&lt;form&gt; 元素定义 HTML 表单

```html
<form>
 .
form elements
 .
</form>
```

## 表单元素

### input元素

*&lt;input&gt; 元素是最重要的*表单元素*

&lt;input&gt; 元素有很多形态，根据不同的 type 属性

| 类型   | 描述                                 |
| ------ | ------------------------------------ |
| text   | 定义常规文本输入。                   |
| radio  | 定义单选按钮输入（选择多个选择之一） |
| submit | 定义提交按钮（提交表单）             |

#### 文本输入

*&lt;input type="text"&gt; 定义用于*文本输入*的单行输入字段

```html
<form>
 First name:<br>
<input type="text" name="firstname">
<br>
 Last name:<br>
<input type="text" name="lastname">
</form> 
```

#### 单选按钮输入

*&lt;input type="radio"&gt; 定义*单选按钮*

单选按钮允许用户在有限数量的选项中选择其中之一

```html
<form>
<input type="radio" name="sex" value="male" checked>Male
<br>
<input type="radio" name="sex" value="female">Female
</form> 
```

#### 提交按钮

*&lt;input type="submit"&gt; 定义用于向*表单处理程序*（form-handler）*提交*表单的按钮

表单处理程序通常是包含用来处理输入数据的脚本的服务器页面

表单处理程序在表单的 *action* 属性中指定

```html
<form action="action_page.php">
First name:<br>
<input type="text" name="firstname" value="Mickey">
<br>
Last name:<br>
<input type="text" name="lastname" value="Mouse">
<br><br>
<input type="submit" value="Submit">
</form> 
```

#### password

*&lt;input type="password"&gt; 定义*密码字段*

```html
<form>
 User name:<br>
<input type="text" name="username">
<br>
 User password:<br>
<input type="password" name="psw">
</form> 
```

####   复选框

&lt;input type="checkbox"&gt; 定义复选框

复选框允许用户在有限数量的选项中选择零个或多个选项

```html
<form>
<input type="checkbox" name="vehicle" value="Bike">I have a bike
<br>
<input type="checkbox" name="vehicle" value="Car">I have a car 
</form> 
```

#### HTMl5 输入类型

HTML5 增加了多个新的输入类型：

- color
- date
- datetime
- datetime-local
- email
- month
- number
- range
- search
- tel
- time
- url
- week

注释：老式 web 浏览器不支持的输入类型，会被视为输入类型 text

### Action属性

*action 属性*定义在提交表单时执行的动作

向服务器提交表单的通常做法是使用提交按钮

通常，表单会被提交到 web 服务器上的网页

在上面的例子中，指定了某个服务器脚本来处理被提交表单：

```html
<form action="action_page.php">
```

如果省略 action 属性，则 action 会被设置为当前页面

### Method属性

*method 属性*规定在提交表单时所用的 HTTP 方法（*GET* 或 *POST*）

```html
<form action="action_page.php" method="GET">
```

```html
<form action="action_page.php" method="POST">
```

### Name属性

如果要正确地被提交，每个输入字段必须设置一个 name 属性

```html
<form action="action_page.php">
First name:<br>
<input type="text" value="Mickey">
<br>
Last name:<br>
<input type="text" name="lastname" value="Mouse">
<br><br>
<input type="submit" value="Submit">
</form> 
```

### fieldset组合表单数据

&lt;fieldset&gt;* 元素组合表单中的相关数据

*&lt;legend&gt; 元素为 &lt;fieldset&gt; 元素定义标题

```html
<form action="action_page.php">
<fieldset>
<legend>Personal information:</legend>
First name:<br/>
<input type="text" name="firstname" value="Mickey">
<br>
Last name:<br/>
<input type="text" name="lastname" value="Mouse">
<br><br>
<input type="submit" value="Submit"></fieldset>
</form> 
```

### form属性列表

| 属性           | 描述                                                       |
| -------------- | ---------------------------------------------------------- |
| accept-charset | 规定在被提交表单中使用的字符集（默认：页面字符集）。       |
| action         | 规定向何处提交表单的地址（URL）（提交页面）。              |
| autocomplete   | 规定浏览器应该自动完成表单（默认：开启）。                 |
| enctype        | 规定被提交数据的编码（默认：url-encoded）。                |
| method         | 规定在提交表单时所用的 HTTP 方法（默认：GET）。            |
| name           | 规定识别表单的名称（对于 DOM 使用：document.forms.name）。 |
| novalidate     | 规定浏览器不验证表单。                                     |
| target         | 规定 action 属性中地址的目标（默认：_self）。              |

### select元素（下拉列表）

*&lt;select&gt; 元素定义*下拉列表*

```html
<select name="cars">
<option value="volvo">Volvo</option>
<option value="saab">Saab</option>
<option value="fiat">Fiat</option>
<option value="audi">Audi</option>
</select>
```

*&lt;option*&gt; 元素定义待选择的选项。

列表通常会把首个选项显示为被选选项。

您能够通过添加 selected 属性来定义预定义选项

```html
<option value="fiat" selected>Fiat</option>
```

### textarea 元素

*&lt;textarea&gt; 元素定义多行输入字段（*文本域*）

```html
<textarea name="message" rows="10" cols="30">
    The cat was playing in the garden.
</textarea>
```

### button 元素

*&lt;button&gt;* 元素定义可点击的*按钮*

```html
<button type="button" onclick="alert('Hello World!')">Click Me!</button>
```

### HTML5 detailst 元素

*&lt;datalist&gt;* 元素为 &lt;input&gt; 元素规定预定义选项列表

用户会在他们输入数据时看到预定义选项的下拉列表

&lt;input&gt; 元素的 *list* 属性必须引用 &lt;datalist&gt; 元素的 *id* 属性

```html
<form action="action_page.php">
<input list="browsers">
<datalist id="browsers">
   <option value="Internet Explorer">
   <option value="Firefox">
   <option value="Chrome">
   <option value="Opera">
   <option value="Safari">
</datalist> 
</form>
```

## 输入(input)属性

### value 属性

*value* 属性规定输入字段的初始值

```html
<form action="">
 First name:<br>
<input type="text" name="firstname" value="John">
<br>
 Last name:<br>
<input type="text" name="lastname">
</form> 
```

### readonly 属性

*readonly* 属性规定输入字段为只读（不能修改）

```html
<form action="">
 First name:<br/>
<input type="text" name="firstname" value="John" readonly>
<br>
 Last name:<br/>
<input type="text" name="lastname">
</form> 
```

readonly 属性不需要值。它等同于 readonly="readonly"

### disable 属性

*disabled* 属性规定输入字段是禁用的

被禁用的元素是不可用和不可点击的

被禁用的元素不会被提交

### size 属性

*size* 属性规定输入字段的尺寸（以字符计）

### maxlength 属性

*maxlength* 属性规定输入字段允许的最大长度

如设置 maxlength 属性，则输入控件不会接受超过所允许数的字符

该属性不会提供任何反馈。如果需要提醒用户，则必须编写 JavaScript 代码

注释：输入限制并非万无一失。JavaScript 提供了很多方法来增加非法输入。如需安全地限制输入，则接受者（服务器）必须同时对限制进行检查

### HTML5 属性

HTML5 为 &lt;input&gt; 增加了如下属性：

- autocomplete
- autofocus
- form
- formaction
- formenctype
- formmethod
- formnovalidate
- formtarget
- height 和 width
- list
- min 和 max
- multiple
- pattern (regexp)
- placeholder
- required
- step

并为 &lt;form&gt; 增加如下属性：

- autocomplete
- novalidate



