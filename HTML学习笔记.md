# HTML学习笔记

## 简介

* HTML 是描述网页的语言

- HTML 指的是超文本标记语言 (**H**yper **T**ext **M**arkup **L**anguage)
- <html> 与 </html> 之间的文本描述网页
- <body> 与 </body> 之间的文本是可见的页面内容
- <h1> 与 </h1> 之间的文本被显示为标题
- <p> 与 </p> 之间的文本被显示为段落

## 基础

### 标题

HTML 标题（Heading）是通过 <h1> - <h6> 等标签进行定义的

```html
<h1>This is a heading</h1>
<h2>This is a heading</h2>
<h3>This is a heading</h3>
```

### 段落

HTML 段落（paragraph）是通过 <p> 标签进行定义的

```html
<p>This is a paragraph.</p>
<p>This is another paragraph.</p>
```

### 链接

HTML 链接（hypertext reference）是通过 <a> 标签进行定义的

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

#### target 属性

使用 Target 属性，你可以定义被链接的文档在何处显示

在新窗口打开文档：

```html
<a href="http://www.w3school.com.cn/" target="_blank">Visit W3School!</a>
```

#### name属性

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

### 图像

HTML 图像是通过 <img> 标签进行定义的

```html
<img src="w3school.jpg" width="104" height="142" />
```

#### 替换文本属性（Alt）

alt 属性用来为图像定义一串预备的可替换的文本

```html
<img src="boat.gif" alt="Big Boat">
```

在浏览器无法载入图像时，替换文本属性告诉读者她们失去的信息。此时，浏览器将显示这个替代性的文本而不是图像。为页面上的图像都加上替换文本属性是个好习惯，这样有助于更好的显示信息，并且对于那些使用纯文本浏览器的人来说是非常有用的

### 水平线

<hr /> 标签在 HTML 页面中创建水平线（horizontal rule），hr 元素可用于分隔内容

```html
<p>This is a paragraph</p>
<hr />
<p>This is a paragraph</p>
<hr />
<p>This is a paragraph</p>
```

### 注释

```html
<!-- This is a comment -->
```

### 换行

不产生一个新段落的情况下进行换行（新行），请使用 <br/ 标签

```html
<p>This is<br />a para<br />graph with line breaks</p>
```

## 元素

HTML 元素指的是从开始标签（start tag）到结束标签（end tag）的所有代码

| 开始标签                | 元素内容            | 结束标签 |
| ----------------------- | ------------------- | -------- |
| <p>                     | This is a paragraph | </p>     |
| <a href="default.htm" > | This is a link      | </a>     |
| <br />                  |                     |          |

## 属性

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

## 样式

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

### 应该避免使用下面这些标签和属性：

| 标签                 | 描述               |
| -------------------- | ------------------ |
| <center>             | 定义居中的内容。   |
| <font> 和 <basefont> | 定义 HTML 字体。   |
| <s> 和 <strike>      | 定义删除线文本     |
| <u>                  | 定义下划线文本     |
| 属性                 | 描述               |
| align                | 定义文本的对齐方式 |
| bgcolor              | 定义背景颜色       |
| color                | 定义文本颜色       |

对于以上这些标签和属性：请使用样式代替！

## CSS 样式表

层叠样式表 (*C*ascading *S*tyle *S*heets)

当浏览器读到一个样式表，它就会按照这个样式表来对文档进行格式化

### 外部样式表

当样式需要被应用到很多页面的时候，外部样式表将是理想的选择。使用外部样式表，你就可以通过更改一个文件来改变整个站点的外观

```html
<head>
<link rel="stylesheet" type="text/css" href="mystyle.css">
</head>
```

### 内部样式表

当单个文件需要特别样式时，就可以使用内部样式表。你可以在 head 部分通过 <style> 标签定义内部样式表

```html
<head>
<style type="text/css">
body {background-color: red}
p {margin-left: 20px}
</style>
</head>
```

### 内联样式

当特殊的样式需要应用到个别元素时，就可以使用内联样式。 使用内联样式的方法是在相关的标签中使用样式属性。样式属性可以包含任何 CSS 属性

```html
<p style="color: red; margin-left: 20px">
This is a paragraph
</p>
```
## 表格

表格由 <table> 标签来定义。每个表格均有若干行（由 <tr> 标签（table row）定义），每行被分割为若干单元格（由 <td> 标签定义）。字母 td 指表格数据（table data），即数据单元格的内容。数据单元格可以包含文本、图片、列表、段落、表单、水平线、表格等等

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

### 边框

border 属性定义边框的粗细，不设置就没有边框

### 表头

表格的表头使用 <th> 标签（table heading）进行定义

## 列表

### 无序列表

无序列表是一个项目的列表，此列项目使用粗体圆点（典型的小黑圆圈）进行标记

无序列表始于 <ul> 标签（unordered list）。每个列表项始于 <li> （list）

```html
<ul>
<li>Coffee</li>
<li>Milk</li>
</ul>
```

- Coffee
- Milk

列表项内部可以使用段落、换行符、图片、链接以及其他列表等等

### 有序列表

同样，有序列表也是一列项目，列表项目使用数字进行标记

有序列表始于 <ol> 标签（ordered list）。每个列表项始于 <li> 标签

```html
<ol>
<li>Coffee</li>
<li>Milk</li>
</ol>
```

1. Coffee
2. Milk

列表项内部可以使用段落、换行符、图片、链接以及其他列表等等

### 定义列表

自定义列表不仅仅是一列项目，而是项目及其注释的组合

自定义列表以 <dl> 标签（definition list）开始。每个自定义列表项以 <dt> 开始。每个自定义列表项的定义以 <dd> 开始

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

## 块

大多数 HTML 元素被定义为块级元素（block level element）或内联元素（ inline element）

### 块元素

块级元素在浏览器显示时，通常会以新行来开始（和结束）

例子：<h1>, <p>, <ul>, <table>

### 内联元素

内联元素在显示时通常不会以新行开始

例子：<b>, <td>, <a>, <img>

### div元素

HTML <div> 元素是块级元素，它是可用于组合其他 HTML 元素的容器

**DIV**是[层叠样式表](https://baike.baidu.com/item/%E5%B1%82%E5%8F%A0%E6%A0%B7%E5%BC%8F%E8%A1%A8)中的定位技术，全称DIVision，即为划分。有时可以称其为图层

<div> 元素没有特定的含义。除此之外，由于它属于块级元素，浏览器会在其前后显示折行。

如果与 CSS 一同使用，<div> 元素可用于对大的内容块设置样式属性

<div> 元素的另一个常见的用途是文档布局。它取代了使用表格定义布局的老式方法。使用 <table> 元素进行文档布局不是表格的正确用法。<table> 元素的作用是显示表格化的数据

### span元素

HTML <span> 元素是内联元素，可用作文本的容器

<span> 元素也没有特定的含义

当与 CSS 一同使用时，<span> 元素可用于为部分文本设置样式属性

## 类

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

### 分类块级元素

HTML <div> 元素是*块级元素*。它能够用作其他 HTML 元素的容器

设置 <div> 元素的类，使我们能够为相同的 <div> 元素设置相同的类

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

### 分类行级元素

HTML <span> 元素是行内元素，能够用作文本的容器

设置 <span> 元素的类，能够为相同的 <span> 元素设置相同的样式

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

