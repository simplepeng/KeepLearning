# 简介

* CSS 指 层叠样式表 (Cascading Style Sheets)
* 样式定义**如何显示** HTML 元素
* 样式通常存储在**样式表**中
* 把样式添加到 HTML 4.0 中，是为了**解决内容与表现分离的问题**
* **外部样式表**可以极大提高工作效率，外部样式表通常存储在 **.css 文件**中
* 多个样式定义可**层叠**为一
* 样式对网页中元素位置的排版进行像素级精确控制

# 语法

CSS 规则由两个主要的部分构成：选择器，以及一条或多条声明

```css
h1 {color:blue;font-size:12px;}
```

选择器通常是您需要改变样式的 HTML 元素。

每条声明由一个属性和一个值组成。

属性（property）是您希望设置的样式属性（style attribute）。每个属性有一个值。属性和值被冒号分开。

```html
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8"> 
<title>W3Cschool教程(w3cschool.cn)</title> 
<style>
p
{
	color:red;
	text-align:center;
} 
</style>
</head>

<body>
<p>Hello World!</p>
<p>This paragraph is styled with CSS.</p>
</body>
</html>
```

## 颜色的写法

**英文单词**

```css
p { color: red; }
```

**16进制**

 ```css
p { color: #ff0000; }
p { color: #f00; }
 ```

**RGB值**

```css
p { color: rgb(255,0,0); } 
p { color: rgb(100%,0%,0%); }
```

## 注释

```css
/*这是个注释*/
```

# 选择器

如果你要在HTML元素中设置CSS样式，你需要在元素中设置"id" 或 "class"选择器。

## id选择器（#）

```css
#para1
{
text-align:center;
color:red;
}
```

id 选择器可以为标有特定 id 的 HTML 元素指定特定的样式

HTML元素以id属性来设置id选择器,CSS 中 id 选择器以 "#" 来定义

 ```html
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8"> 
<title>W3Cschool教程(w3cschool.cn)</title> 
<style>
#para1
{
	text-align:center;
	color:red;
} 
</style>
</head>

<body>
<p id="para1">Hello World!!!</p>
<p>This paragraph is not affected by the style.</p>
</body>
</html>
 ```

> ID属性不要以数字开头，数字开头的ID在 Mozilla/Firefox 浏览器中不起作用
>
> ID属性只能在每个 HTML 文档中出现一次

## class 选择器（.）

```css
.center {
    text-align:center;
    color:red;
}
```

class 选择器用于描述一组元素的样式，class 选择器有别于id选择器，class可以在多个元素中使用

class 选择器在HTML中以class属性表示, 在 CSS 中，类选择器以一个点"."号显示

**所有拥有 center 类的 HTML 元素均为居中**

```html
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8"> 
<title>W3Cschool教程(w3cschool.cn)</title> 
<style>
.center
{
	text-align:center;
}
</style>
</head>

<body>
<h1 class="center">标题居中</h1>
<p class="center">段落居中。</p> 
</body>
</html>
```

**所有的 p 元素使用 class="center" 让该元素的文本居中**

```html
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8"> 
<title>W3Cschool教程(w3cschool.cn)</title> 
<style>
p.center
{
	text-align:center;
}
</style>
</head>

<body>
<h1 class="center">This heading will not be affected</h1>
<p class="center">This paragraph will be center-aligned.</p> 
</body>
</html>
```

# 创建样式表

## 外部样式表

当样式需要应用于很多页面时，外部样式表将是理想的选择

在使用外部样式表的情况下，你可以通过改变一个文件来改变整个站点的外观

```html
<head> <link rel="stylesheet" type="text/css" href="mystyle.css"> </head>
```

外部样式表可以在任何文本编辑器中进行编辑

文件不能包含任何的 html 标签

样式表应该以 .css 扩展名进行保存

```css
hr {color:sienna;}           
p {margin-left:20px;}            
body {background-image:url(/images/back40.gif);} 
```

## 内部样式表

当单个文档需要特殊的样式时，就应该使用内部样式表

你可以使用 <style> 标签在文档头部定义内部样式表

```html
<head>
<style>
hr {color:sienna;}
p {margin-left:20px;}
body {background-image:url("images/back40.gif");}
</style>
</head>
```

## 内联样式

由于要将表现和内容混杂在一起，内联样式会损失掉样式表的许多优势，请慎用这种方法

例如当样式仅需要在一个元素上应用一次时，要使用内联样式，你需要在相关的标签内使用样式（style）属性，Style 属性可以包含任何 CSS 属性

```html
<p style="color:sienna;margin-left:20px">这是一个段落。</p>
```

# 背景（Backgrounds）

背景属性用于定义HTML元素的背景

- background-color 背景颜色
- background-image 背景图像
- background-repeat 设置背景图像是否及如何重复
- background-attachment 背景图像是否固定或者随着页面的其余部分滚动
- background-position 设置背景图像的起始位置

## 背景颜色（background-color）

background-color 属性定义了元素的背景颜色

```css
h1 {background-color:#6495ed;} 
p {background-color:#e0ffff;} 
div {background-color:#b0c4de;}
```

可以为所有元素设置背景色，包括 body 一直到 em 和 a 等行内元素

background-color 不能继承，其默认值是 transparent。如果一个元素没有指定背景色，那么背景就是透明的，这样其父元素的背景才可见

## 背景图像（backgrond-image）

background-image 属性描述了元素的背景图像

默认情况下，背景图像进行平铺重复显示，以覆盖整个元素实体

```css
body 
{
	background-image:url('http://img.w3cschool.cn/attachments/knowledge/201611/31824.png');
	background-color:#cccccc;
}
```

### 定位

```css
body 
{ 
background-image:url('img_tree.png'); 
background-repeat:no-repeat; 
background-position:right top; 
}
```

#### 关键字

| 单一关键字 | 等价的关键字                   |
| ---------- | ------------------------------ |
| center     | center center                  |
| top        | top center 或 center top       |
| bottom     | bottom center 或 center bottom |
| right      | right center 或 center right   |
| left       | left center 或 center left     |

#### 百分数值

```css
body        
  {        
   background-image:url('img_tree.png');        
   background-repeat:no-repeat;        
  background-position:66% 33%;        
}
```

#### 长度值

```css
body       
  {       
   background-image:url('img_tree.png');        
   background-repeat:no-repeat;        
  background-position:50px 100px;        
  }
```

### 重复模式

| 值        | 说明                                         |
| --------- | -------------------------------------------- |
| repeat    | 背景图像将向垂直和水平方向重复。这是默认     |
| repeat-x  | 只有水平位置会重复背景图像                   |
| repeat-y  | 只有垂直位置会重复背景图像                   |
| no-repeat | background-image不会重复                     |
| inherit   | 指定background-repea属性设置应该从父元素继承 |

## 简写属性

```css
body {background:#ffffff url('img_tree.png') no-repeat right top;}
```

#  文本（Text）

## 颜色（color）

颜色属性被用来设置文字的颜色

```html
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8"> 
<title>W3Cschool教程(w3cschool.cn)</title> 
<style>
body {color:red;}
h1 {color:#00ff00;}
p.ex {color:rgb(0,0,255);}
</style>
</head>

<body>
<h1>This is heading 1</h1>
<p>This is an ordinary paragraph. Notice that this text is red. The default text-color for a page is defined in the body selector.</p>
<p class="ex">This is a paragraph with class="ex". This text is blue.</p>
</body>
</html>
```

## 对齐方式（text-align）

文本排列属性是用来设置文本的水平对齐方式

文本可居中或对齐到左或右,两端对齐

当text-align设置为"justify"，每一行被展开为宽度相等，左，右外边距是对齐（如杂志和报纸）

```html
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8"> 
<title>W3Cschool教程(w3cschool.cn)</title> 
<style>
h1{text-align:center}
p.date{text-align:right}
p.main{text-align:justify}
</style>
</head>

<body>
<h1>CSS text-align 实例</h1>
<p class="date">2015 年 3 月 14 号</p>
<p class="main">“当我年轻的时候，我梦想改变这个世界;当我成熟以后，我发现我不能够改变这个世界，我将目光缩短了些，决定只改变我的国家;当我进入暮年以后，我发现我不能够改变我们的国家，我的最后愿望仅仅是改变一下我的家庭，但是，这也不可能。当我现在躺在床上，行将就木时，我突然意识到：如果一开始我仅仅去改变我自己，然后，我可能改变我的家庭;在家人的帮助和鼓励下，我可能为国家做一些事情;然后，谁知道呢?我甚至可能改变这个世界。”</p>
<p><b>注意：</b> 重置浏览器窗口大小查看 "justify" 是如何工作的。</p>
</body>

</html>
```

## 修饰（text-decoration）

text-decoration 属性用来设置或删除文本的装饰

从设计的角度看 text-decoration属性主要是用来删除链接的下划线

```html
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8"> 
<title>W3Cschool教程(w3cschool.cn)</title> 
<style>
h1 {text-decoration:overline;}
h2 {text-decoration:line-through;}
h3 {text-decoration:underline;}
a {text-decoration:none;}
</style>
</head>

<body>
<h1>This is heading 1</h1>
<h2>This is heading 2</h2>
<h3>This is heading 3</h3>
<p>Link to: <a href="http://www.w3cschool.cn">w3cschool.cn</a></p>
</body>

</html>
```

## 转换（text-transform）

文本转换属性是用来指定在一个文本中的大写和小写字母

可用于所有字句变成大写或小写字母，或每个单词的首字母大写

```html
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8"> 
<title>W3Cschool教程(w3cschool.cn)</title> 
<style>
p.uppercase {text-transform:uppercase;}
p.lowercase {text-transform:lowercase;}
p.capitalize {text-transform:capitalize;}
</style>
</head>

<body>
<p class="uppercase">This is some text.</p>
<p class="lowercase">This is some text.</p>
<p class="capitalize">This is some text.</p>
</body>
</html>
```

## 缩进（text-indent）

文本缩进属性是用来指定文本的第一行的缩进

```html
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8"> 
<title>W3Cschool教程(w3cschool.cn)</title> 
<style>
p {text-indent:50px;}
</style>
</head>
<body>

<p>In my younger and more vulnerable years my father gave me some advice that I've been turning over in my mind ever since. 'Whenever you feel like criticizing anyone,' he told me, 'just remember that all the people in this world haven't had the advantages that you've had.'</p>

</body>
</html>
```

## 间隔（word-spacing）

word-spacing 属性可以改变字（单词）之间的标准间隔。其默认值 normal 与设置值为 0 是一样的

```html
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8"> 
<title>W3Cschool教程(w3cschool.cn)</title> 
<style>
p
{ 
	word-spacing:30px;
}
</style>
</head>
<body>

<p>
This is some text. This is some text.
</p>

</body>
</html>
```

## 所有css文本属性

| 属性                                                         | 描述                     |
| ------------------------------------------------------------ | ------------------------ |
| [color](https://www.w3cschool.cn/cssref/pr-text-color.html)  | 设置文本颜色             |
| [direction](https://www.w3cschool.cn/cssref/pr-text-direction.html) | 设置文本方向             |
| [letter-spacing](https://www.w3cschool.cn/cssref/pr-text-letter-spacing.html) | 设置字符间距             |
| [line-height](https://www.w3cschool.cn/cssref/pr-dim-line-height.html) | 设置行高                 |
| [text-align](https://www.w3cschool.cn/cssref/pr-text-text-align.html) | 对齐元素中的文本         |
| [text-decoration](https://www.w3cschool.cn/cssref/pr-text-text-decoration.html) | 向文本添加修饰           |
| [text-indent](https://www.w3cschool.cn/cssref/pr-text-text-indent.html) | 缩进元素中文本的首行     |
| [text-shadow](https://www.w3cschool.cn/cssref/css3-pr-text-shadow.html) | 设置文本阴影             |
| [text-transform](https://www.w3cschool.cn/cssref/pr-text-text-transform.html) | 控制元素中的字母         |
| [unicode-bidi](https://www.w3cschool.cn/cssref/pr-text-unicode-bidi.html) | 设置或返回文本是否被重写 |
| [vertical-align](https://www.w3cschool.cn/cssref/pr-pos-vertical-align.html) | 设置元素的垂直对齐       |
| [white-space](https://www.w3cschool.cn/cssref/pr-text-white-space.html) | 设置元素中空白的处理方式 |
| [word-spacing](https://www.w3cschool.cn/cssref/pr-text-word-spacing.html) | 设置字间距               |

# 字体（fonts）

CSS字体属性定义字体，加粗，大小，文字样式

## 字型

在CSS中，有两种类型的字体系列名称：

- **通用字体系列** - 拥有相似外观的字体系统组合（如 "Serif" 或 "Monospace"）
- **特定字体系列** - 一个特定的字体系列（如 "Times" 或 "Courier"）

## 字体系列（font-family）

font-family 属性设置文本的字体系列

font-family 属性应该设置几个字体名称作为一种"后备"机制，如果浏览器不支持第一种字体，他将尝试下一种字体

如果字体系列的名称超过一个字，它必须用引号，如Font Family："宋体"

```html
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8"> 
<title>W3Cschool教程(w3cschool.cn)</title>
<style>
p.serif{font-family:"Times New Roman",Times,serif;}
p.sansserif{font-family:Arial,Helvetica,sans-serif;}
</style>
</head>

<body>
<h1>CSS font-family</h1>
<p class="serif">这一段的字体是 Times New Roman 。</p>
<p class="sansserif">这一段的字体是 Arial 。</p>

</body>
</html>
```

## 样式（font-style）

主要是用于指定斜体文字的字体样式属性

这个属性有三个值：

- 正常 - 正常显示文本
- 斜体 - 以斜体字显示的文字
- 倾斜的文字 - 文字向一边倾斜（和斜体非常类似，但不太支持）

```html
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8"> 
<title>W3Cschool教程(w3cschool.cn)</title>
<style>
p.normal {font-style:normal;}
p.italic {font-style:italic;}
p.oblique {font-style:oblique;}
</style>
</head>

<body>
<p class="normal">This is a paragraph, normal.</p>
<p class="italic">This is a paragraph, italic.</p>
<p class="oblique">This is a paragraph, oblique.</p>
</body>

</html>
```

## 字体大小（font-size）

font-size 属性设置文本的大小

绝对大小：

- 设置一个指定大小的文本
- 不允许用户在所有浏览器中改变文本大小
- 确定了输出的物理尺寸时绝对大小很有用

相对大小：

- 相对于周围的元素来设置大小
- 允许用户在浏览器中改变文字大小

### 设置字体大小像素

```css
h1 {font-size:40px;} 
h2 {font-size:30px;} 
p {font-size:14px;}
```

### 用em设置字体大小

为了避免Internet Explorer 中无法调整文本的问题，许多开发者使用 em 单位代替像素

1em和当前字体大小相等。在浏览器中默认的文字大小是16px

```css
h1 {font-size:2.5em;} /* 40px/16=2.5em */ 
h2 {font-size:1.875em;} /* 30px/16=1.875em */ 
p {font-size:0.875em;} /* 14px/16=0.875em */
```

### 使用百分比和em组合

在所有浏览器的解决方案中，设置 <body>元素的默认字体大小的是百分比

```css
body {font-size:100%;} 
h1 {font-size:2.5em;} 
h2 {font-size:1.875em;} 
p {font-size:0.875em;}
```

## 所有css字体属性

| Property                                                     | 描述                               |
| ------------------------------------------------------------ | ---------------------------------- |
| [font](https://www.w3cschool.cn/cssref/pr-font-font.html)    | 在一个声明中设置所有的字体属性     |
| [font-family](https://www.w3cschool.cn/cssref/pr-font-font-family.html) | 指定文本的字体系列                 |
| [font-size](https://www.w3cschool.cn/cssref/pr-font-font-size.html) | 指定文本的字体大小                 |
| [font-style](https://www.w3cschool.cn/cssref/pr-font-font-style.html) | 指定文本的字体样式                 |
| [font-variant](https://www.w3cschool.cn/cssref/pr-font-font-variant.html) | 以小型大写字体或者正常字体显示文本 |
| [font-weight](https://www.w3cschool.cn/cssref/pr-font-weight.html) | 指定字体的粗细。                   |

# 链接（link）

## 链接样式

链接的样式，可以用任何CSS属性（如颜色，字体，背景等）

特别的链接，可以有不同的样式，这取决于他们是什么状态

这四个链接状态是：

- a:link - 正常，未访问过的链接
- a:visited - 用户已访问过的链接
- a:hover - 当用户鼠标放在链接上时
- a:active - 链接被点击的那一刻

```html
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8"> 
<title>W3Cschool教程(w3cschool.cn)</title> 
<style>
a:link {color:#FF0000;}    /* unvisited link */
a:visited {color:#00FF00;} /* visited link */
a:hover {color:#FF00FF;}   /* mouse over link */
a:active {color:#0000FF;}  /* selected link */
</style>
</head>

<body>
<p><b><a href="/css/" target="_blank">这是一个链接</a></b></p>
<p><b>注意：</b> a:hover 必须在 a:link 和 a:visited 之后，需要严格按顺序才能看到效果。</p>
<p><b>注意：</b> a:active 必须在 a:hover 之后。</p>
</body>
</html>
```

## 文本修饰（text-decoration）

```css
a:link {text-decoration:none;} 
a:visited {text-decoration:none;} 
a:hover {text-decoration:underline;} 
a:active {text-decoration:underline;}
```

##  背景颜色

背景颜色属性指定链接背景色

```css
a:link {background-color:#B2FF99;} 
a:visited {background-color:#FFFF85;} 
a:hover {background-color:#FF704D;} 
a:active {background-color:#FF704D;}
```

# 列表样式

CSS列表属性作用如下：

- 设置不同的列表项标记为有序列表（数字或字母）
- 设置不同的列表项标记为无序列表 （小黑点、小方框等）
- 设置列表项标记为图像

## 列表项标记（list-style-type）

```html
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8"> 
<title>W3Cschool教程(w3cschool.cn)</title> 
<style>
ul.a {list-style-type:circle;}
ul.b {list-style-type:square;}
ol.c {list-style-type:upper-roman;}
ol.d {list-style-type:lower-alpha;}
</style>
</head>

<body>
<p>无序列表实例:</p>

<ul class="a">
  <li>Coffee</li>
  <li>Tea</li>
  <li>Coca Cola</li>
</ul>

<ul class="b">
  <li>Coffee</li>
  <li>Tea</li>
  <li>Coca Cola</li>
</ul>

<p>有序列表实例:</p>

<ol class="c">
  <li>Coffee</li>
  <li>Tea</li>
  <li>Coca Cola</li>
</ol>

<ol class="d">
  <li>Coffee</li>
  <li>Tea</li>
  <li>Coca Cola</li>
</ol>

</body>
</html>
```

下列是对list-style-type属性的常见属性值的描述：

- none：不使用项目符号
- disc：实心圆
- circle：空心圆
- square：实心方块
- demical：阿拉伯数字 
- lower-alpha：小写英文字母 
- upper-alpha：大写英文字母 
- lower-roman：小写罗马数字 
- upper-roman：大写罗马数字

## 列表项标记的图像

要指定列表项标记的图像，使用列表样式图像属性：

```css
ul
{
list-style-image: url('sqpurple.gif');
}
```

## 缩写

在单个属性中可以指定所有的列表属性，这就是所谓的缩写属性

```css
ul
{
list-style: square url("sqpurple.gif");
}
```

如果使用缩写属性值的顺序是：

- list-style-type
- list-style-position 
- list-style-image

## 所有css列表属性

| 属性                                                         | 描述                                               |
| ------------------------------------------------------------ | -------------------------------------------------- |
| [list-style](https://www.w3cschool.cn/cssref/pr-list-style.html) | 简写属性。用于把所有用于列表的属性设置于一个声明中 |
| [list-style-image](https://www.w3cschool.cn/cssref/pr-list-style-image.html) | 将图象设置为列表项标志。                           |
| [list-style-position](https://www.w3cschool.cn/cssref/pr-list-style-position.html) | 设置列表中列表项标志的位置。                       |
| [list-style-type](https://www.w3cschool.cn/cssref/pr-list-style-type.html) | 设置列表项标志的类型。                             |

# 表格（table）

使用css提升html表格的外关

## 边框（border）

```css
table, th, td 
{ 
border: 1px solid black; 
}
```

在上面的例子中的表格有双边框。这是因为表和th/ td元素有独立的边界

为了显示一个表的单个边框，使用 border-collapse属性

## 折叠边框（border-collapse）

```css
table 
{ 
border-collapse:collapse; 
} 
table,th, td 
{ 
border: 1px solid black; 
}
```

## 宽度和高度（width，height）

 ```css
table 
{ 
width:100%; 
} 
th 
{ 
height:50px; 
}
 ```

## 文字对齐（text-align，vertical-align）

表格中的文本对齐和垂直对齐属性

text-align属性设置水平对齐方式，像左，右，或中心：

```css
td 
{ 
text-align:right; 
}
```

垂直对齐属性设置垂直对齐，比如顶部，底部或中间：

```css
td 
{ 
height:50px; 
vertical-align:bottom; 
}
```

## 填充

如果在表的内容中控制空格之间的边框，应使用td和th元素的填充属性

 ```css
td 
{ 
padding:15px; 
}
 ```

## 颜色

下面的例子指定边框的颜色，和th元素的文本和背景颜色

 ```css
table, td, th 
{ 
border:1px solid green; 
} 
th 
{ 
background-color:green; 
color:white; 
}
 ```

# 盒子模型

CSS盒模型本质上是一个盒子，封装周围的HTML元素，它包括：边距，边框，填充，和实际内容

![](https://www.w3cschool.cn/statics/images/course/box-model.gif)

不同部分的说明：

- **Margin（外边距）** - 清除边框区域。Margin没有背景颜色，它是完全透明
- **Border（边框）** - 边框周围的填充和内容。边框是受到盒子的背景颜色影响
- **Padding（内边距）** - 清除内容周围的区域。会受到框中填充的背景颜色影响
- **Content（内容）** - 盒子的内容，显示文本和图像

在盒模型中，外边距可以是负值，而且在很多情况下都要使用负值的外边距

# 边框（border）

CSS 边框 (border) 可以是围绕元素内容和内边距的一条或多条线，对于这些线条，您可以自定义它们的样式、宽度以及颜色

## 样式（border-style）

```html
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8"> 
<title>W3Cschool教程(w3cschool.cn)</title> 
<style>
//默认无边框
p.none {border-style:none;}
//定义一个点线框
p.dotted {border-style:dotted;}
//定义一个虚线框
p.dashed {border-style:dashed;}
//定义实线边界
p.solid {border-style:solid;}
//定义两个边界。 两个边界的宽度和border-width的值相同
p.double {border-style:double;}
//定义3D沟槽边界。效果取决于边界的颜色值
p.groove {border-style:groove;}
//定义3D脊边界。效果取决于边界的颜色值
p.ridge {border-style:ridge;}
//定义一个3D的嵌入边框。效果取决于边界的颜色值
p.inset {border-style:inset;}
//定义一个3D突出边框。 效果取决于边界的颜色值
p.outset {border-style:outset;}
//隐藏边框
p.hidden {border-style:hidden;}
</style>
</head>

<body>
<p class="none">No border.</p>
<p class="dotted">A dotted border.</p>
<p class="dashed">A dashed border.</p>
<p class="solid">A solid border.</p>
<p class="double">A double border.</p>
<p class="groove">A groove border.</p>
<p class="ridge">A ridge border.</p>
<p class="inset">An inset border.</p>
<p class="outset">An outset border.</p>
<p class="hidden">A hidden border.</p>
</body>

</html>
```

## 宽度（border-width）

为边框指定宽度有两种方法：可以指定长度值，比如 2px 或 0.1em；或者使用 3 个关键字之一，它们分别是 thin 、medium（默认值） 和 thick

## 颜色（border-color）

border-color属性用于设置边框的颜色，它一次可以接受最多 4 个颜色值

您还可以设置边框的颜色为"transparent"

border-color单独使用是不起作用的，必须得先使用border-style来设置边框样式

## 单独设置各边的样式

```css
p 
{ 
border-top-style:dotted; 
border-right-style:solid; 
border-bottom-style:dotted; 
border-left-style:solid; 
}
```

## css边框全部属性

| 属性                                                         | 描述                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [border](https://www.w3cschool.cn/cssref/pr-border.html)     | 简写属性，用于把针对四个边的属性设置在一个声明。             |
| [border-style](https://www.w3cschool.cn/cssref/pr-border-style.html) | 用于设置元素所有边框的样式，或者单独地为各边设置边框样式。   |
| [border-width](https://www.w3cschool.cn/cssref/pr-border-width.html) | 简写属性，用于为元素的所有边框设置宽度，或者单独地为各边边框设置宽度。 |
| [border-color](https://www.w3cschool.cn/cssref/pr-border-color.html) | 简写属性，设置元素的所有边框中可见部分的颜色，或为 4 个边分别设置颜色。 |
| [border-bottom](https://www.w3cschool.cn/cssref/pr-border-bottom.html) | 简写属性，用于把下边框的所有属性设置到一个声明中。           |
| [border-bottom-color](https://www.w3cschool.cn/cssref/pr-border-bottom-color.html) | 设置元素的下边框的颜色。                                     |
| [border-bottom-style](https://www.w3cschool.cn/cssref/pr-border-bottom-style.html) | 设置元素的下边框的样式。                                     |
| [border-bottom-width](https://www.w3cschool.cn/cssref/pr-border-bottom-width.html) | 设置元素的下边框的宽度。                                     |
| [border-left](https://www.w3cschool.cn/cssref/pr-border-left.html) | 简写属性，用于把左边框的所有属性设置到一个声明中。           |
| [border-left-color](https://www.w3cschool.cn/cssref/pr-border-left-color.html) | 设置元素的左边框的颜色。                                     |
| [border-left-style](https://www.w3cschool.cn/cssref/pr-border-left-style.html) | 设置元素的左边框的样式。                                     |
| [border-left-width](https://www.w3cschool.cn/cssref/pr-border-left-width.html) | 设置元素的左边框的宽度。                                     |
| [border-right](https://www.w3cschool.cn/cssref/pr-border-right.html) | 简写属性，用于把右边框的所有属性设置到一个声明中。           |
| [border-right-color](https://www.w3cschool.cn/cssref/pr-border-right-color.html) | 设置元素的右边框的颜色。                                     |
| [border-right-style](https://www.w3cschool.cn/cssref/pr-border-right-style.html) | 设置元素的右边框的样式。                                     |
| [border-right-width](https://www.w3cschool.cn/cssref/pr-border-right-width.html) | 设置元素的右边框的宽度。                                     |
| [border-top](https://www.w3cschool.cn/cssref/pr-border-top.html) | 简写属性，用于把上边框的所有属性设置到一个声明中。           |
| [border-top-color](https://www.w3cschool.cn/cssref/pr-border-top-color.html) | 设置元素的上边框的颜色。                                     |
| [border-top-style](https://www.w3cschool.cn/cssref/pr-border-top-style.html) | 设置元素的上边框的样式。                                     |
| [border-top-width](https://www.w3cschool.cn/cssref/pr-border-top-width.html) | 设置元素的上边框的宽度。                                     |

# 轮廓（outline）

轮廓（outline）是绘制于元素周围的一条线，位于边框边缘的外围，可起到突出元素的作用

轮廓（outline）属性指定了样式，颜色和外边框的宽度

轮廓（outline）属性的位置让它不像边框那样参与到文档流中，因此轮廓出现或消失时不会影响文档流，即不会导致文档的重新显示

![](https://www.w3cschool.cn/statics/images/course/box_outline.gif)

## 轮廓属性

| 属性                                                         | 说明                             | 值                                                       | CSS  |
| ------------------------------------------------------------ | -------------------------------- | -------------------------------------------------------- | ---- |
| [outline](https://www.w3cschool.cn/cssref/pr-outline.html)   | 在一个声明中设置所有的外边框属性 | *outline-coloroutline-styleoutline-width*inherit         | 2    |
| [outline-color](https://www.w3cschool.cn/cssref/pr-outline-color.html) | 设置外边框的颜色                 | *color-namehex-numberrgb-number*invertinherit            | 2    |
| [outline-style](https://www.w3cschool.cn/cssref/pr-outline-style.html) | 设置外边框的样式                 | nonedotteddashedsoliddoublegrooveridgeinsetoutsetinherit | 2    |
| [outline-width](https://www.w3cschool.cn/cssref/pr-outline-width.html) | 设置外边框的宽度                 | thinmediumthick*length*inherit                           |      |

# 外边距（margin）

CSS Margin(外边距)属性定义元素周围的空间

CSS Margin属性接受任何长度单位、百分数值甚至负值

margin可以单独改变元素的上，下，左，右边距。也可以一次改变所有的属性

| 值       | 说明                                       |
| -------- | ------------------------------------------ |
| auto     | 设置浏览器边距。这样做的结果会依赖于浏览器 |
| *length* | 定义一个固定的margin（使用像素，pt，em等） |
| *%*      | 定义一个使用百分比的边距                   |

# 内边距（padding）

CSS Padding（填充）属性定义元素边框与元素内容之间的空间

## 可能的值

| 值     | 说明                                |
| ------ | ----------------------------------- |
| length | 定义一个固定的填充(像素, pt, em,等) |
| %      | 使用百分比值定义一个填充            |

CSS padding 属性可以使用长度值或百分比值，但与 margin 属性不同，它不允许使用负值

## 内边距的百分比数值

CSS padding 属性的百分比数值是相对于其父元素的 width 计算的，如果改变了父元素的 width，则它们也会改变

```css
p {padding: 20%;}
```

**注意：**上下内边距与左右内边距一致，即上下内边距的百分数会相对于父元素宽度设置，而不是相对于高度

## 填充所有属性

| 属性                                                         | 说明                                       |
| ------------------------------------------------------------ | ------------------------------------------ |
| [padding](https://www.w3cschool.cn/cssref/pr-padding.html)   | 使用缩写属性设置在一个声明中的所有填充属性 |
| [padding-bottom](https://www.w3cschool.cn/cssref/pr-padding-bottom.html) | 设置元素的底部填充                         |
| [padding-left](https://www.w3cschool.cn/cssref/pr-padding-left.html) | 设置元素的左部填充                         |
| [padding-right](https://www.w3cschool.cn/cssref/pr-padding-right.html) | 设置元素的右部填充                         |
| [padding-top](https://www.w3cschool.cn/cssref/pr-padding-top.html) | 设置元素的顶部填充                         |

# 分组和嵌套选择器

CSS 分组可以将具有相同样式的选择器进行分组，减少代码量

CSS 嵌套适用于选择器内部的选择器的样式

## 分组选择器（grouping selectors）

在样式表中有很多具有相同样式的元素

```css
h1
{
color:green;
}
h2
{
color:green;
}
p
{
color:green;
}
```

为了尽量减少代码，你可以使用分组选择器

每个选择器用逗号分隔

```css
h1,h2,p 
{ 
color:green; 
}
```

## 嵌套选择器

它可能适用于选择器内部的选择器的样式

```html
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8"> 
<title>W3Cschool教程(w3cschool.cn)</title> 
<style>
p
{
	color:blue;
	text-align:center;
}
.marked
{
	background-color:red;
}
.marked p
{
	color:white;
}
</style>
</head>

<body>
<p>This paragraph has blue text, and is center aligned.</p>
<div class="marked">
<p>This paragraph has not blue text.</p>
</div>
<p>p elements inside a "marked" classed element keeps the alignment style, but has a different text color.</p>
</body>
</html>
```

# 尺寸（dimension）

CSS 尺寸 (Dimension) 属性允许你控制元素的高度和宽度。同样，它允许你增加行间距

| 属性                                                         | 描述                 |
| ------------------------------------------------------------ | -------------------- |
| [height](https://www.w3cschool.cn/cssref/pr-dim-height.html) | 设置元素的高度。     |
| [line-height](https://www.w3cschool.cn/cssref/pr-dim-line-height.html) | 设置行高。           |
| [max-height](https://www.w3cschool.cn/cssref/pr-dim-max-height.html) | 设置元素的最大高度。 |
| [max-width](https://www.w3cschool.cn/cssref/pr-dim-max-width.html) | 设置元素的最大宽度。 |
| [min-height](https://www.w3cschool.cn/cssref/pr-dim-min-height.html) | 设置元素的最小高度。 |
| [min-width](https://www.w3cschool.cn/cssref/pr-dim-min-width.html) | 设置元素的最小宽度。 |
| [width](https://www.w3cschool.cn/cssref/pr-dim-width.html)   | 设置元素的宽度。     |



