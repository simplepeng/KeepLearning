# 简介

* CSS 指层叠样式表 (Cascading Style Sheets)
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

# 显示（display）和可见性（visibility）

display 属性和 visibility属性都可以用来隐藏某个元素，但是这两个属性有不同的定义

## 隐藏元素 display：none或visibility：hidden

隐藏一个元素可以通过把display属性设置为"none"，或把visibility属性设置为"hidden"

visibility:hidden可以隐藏某个元素，但隐藏的元素仍需占用与未隐藏之前一样的空间。也就是说，该元素虽然被隐藏了，但仍然会影响布局

```css
h1.hidden {visibility:hidden;}
```

display:none可以隐藏某个元素，且隐藏的元素不会占用任何空间。也就是说，该元素不但被隐藏了，而且该元素原本占用的空间也会从页面布局中消失

```css
h1.hidden {display:none;}
```

# 定位（positioning）

CSS定位属性允许你为一个元素定位。它也可以将一个元素放在另一个元素后面，并指定一个元素的内容太大时，应该发生什么

元素可以使用的顶部，底部，左侧和右侧属性定位。然而，这些属性无法工作，除非是先设定position属性。他们也有不同的工作方式，这取决于定位方法

## static 定位

HTML元素的默认值，即没有定位，元素出现在正常的流中

静态定位的元素不会受到top, bottom, left, right影响

## fixed 定位

元素的位置相对于浏览器窗口是固定位置

即使窗口是滚动的它也不会移动

```css
p.pos_fixed 
{ 
position:fixed; 
top:30px; 
right:5px; 
}
```

## relative 定位

相对定位元素的定位是相对其正常位置

```css
h2.pos_left 
{ 
position:relative; 
left:-20px; 
} 
h2.pos_right 
{ 
position:relative; 
left:20px; 
}
```

相对定位元素经常被用来作为绝对定位元素的容器块

## absolute 定位

绝对定位的元素的位置相对于最近的已定位父元素，如果元素没有已定位的父元素，那么它的位置相对于<html>

```css
h2 
{ 
position:absolute; 
left:100px; 
top:150px; 
}
```

## 重叠的元素

元素的定位与文档流无关，所以它们可以覆盖页面上的其它元素

z-index属性指定了一个元素的堆叠顺序（哪个元素应该放在前面，或后面）

一个元素可以有正数或负数的堆叠顺序

```css
img 
{ 
position:absolute; 
left:0px; 
top:0px; 
z-index:-1; 
}
```

## 定位所有属性

| 属性                                                         | 说明                                                         | 值                                                           | CSS  |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ---- |
| [bottom](https://www.w3cschool.cn/cssref/pr-pos-bottom.html) | 定义了定位元素下外边距边界与其包含块下边界之间的偏移。       | auto *length%*inherit                                        | 2    |
| [clip](https://www.w3cschool.cn/cssref/pr-pos-clip.html)     | 剪辑一个绝对定位的元素                                       | *shape*auto inherit                                          | 2    |
| [cursor](https://www.w3cschool.cn/cssref/pr-class-cursor.html) | 显示光标移动到指定的类型                                     | *url*auto crosshair default pointer move e-resize ne-resize nw-resize n-resize se-resize sw-resize s-resize w-resize text wait help | 2    |
| [left](https://www.w3cschool.cn/cssref/pr-pos-left.html)     | 定义了定位元素左外边距边界与其包含块左边界之间的偏移。       | auto *length%*inherit                                        | 2    |
| [overflow](https://www.w3cschool.cn/cssref/pr-pos-overflow.html) | 设置当元素的内容溢出其区域时发生的事情。                     | auto hidden scroll visible inherit                           | 2    |
| [position](https://www.w3cschool.cn/cssref/pr-class-position.html) | 指定元素的定位类型                                           | absolute fixed relative static inherit                       | 2    |
| [right](https://www.w3cschool.cn/cssref/pr-pos-right.html)   | 定义了定位元素右外边距边界与其包含块右边界之间的偏移。       | auto *length%*inherit                                        | 2    |
| [top](https://www.w3cschool.cn/cssref/pr-pos-top.html)       | 定义了一个定位元素的上外边距边界与其包含块上边界之间的偏移。 | auto *length%*inherit                                        | 2    |
| [z-index](https://www.w3cschool.cn/cssref/pr-pos-z-index.html) | 设置元素的堆叠顺序                                           | *number*auto inherit                                         | 2    |

# 浮动（float）

CSS 的 Float（浮动），会使元素向左或向右移动，其周围的元素也会重新排列

Float（浮动），往往是用于图像，但它在布局时一样非常有用

## 元素怎样浮动

元素的水平方向浮动，意味着元素只能左右移动而不能上下移动

浮动元素之后的元素将围绕它

浮动元素之前的元素将不会受到影响

```html
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8"> 
<title>W3Cschool(w3cschool.cn)</title>
<style>
img 
{
	float:left;
}
</style>
</head>

<body>
<p>在下面的段落中，我们添加了一个 <b>float:left</b> 的图片。导致图片将会浮动在段落的左边。</p>
<p>
<img src="/attachments/cover/cover_css.png" width="95" height="84" />
这是一些文本。这是一些文本。这是一些文本。
这是一些文本。这是一些文本。这是一些文本。
这是一些文本。这是一些文本。这是一些文本。
这是一些文本。这是一些文本。这是一些文本。
这是一些文本。这是一些文本。这是一些文本。
这是一些文本。这是一些文本。这是一些文本。
这是一些文本。这是一些文本。这是一些文本。
这是一些文本。这是一些文本。这是一些文本。
这是一些文本。这是一些文本。这是一些文本。
这是一些文本。这是一些文本。这是一些文本。
</p>
</body>

</html>
```

##  彼此相邻的浮动元素

如果你把几个浮动的元素放到一起，如果有空间的话，它们将彼此相邻

```html
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8"> 
<title>W3Cschool教程(w3cschool.cn)</title> 
<style>
.thumbnail 
{
	float:left;
	width:110px;
	height:90px;
	margin:5px;
}
</style>
</head>

<body>
<h3>图片库</h3>
<p>试着调整窗口,看看当图片没有足够的空间会发生什么。</p>
<img class="thumbnail" src="/statics/images/course/klematis_small.jpg" width="107" height="90">
<img class="thumbnail" src="/statics/images/course/klematis2_small.jpg" width="107" height="80">
<img class="thumbnail" src="/statics/images/course/klematis3_small.jpg" width="116" height="90">
<img class="thumbnail" src="/statics/images/course/klematis4_small.jpg" width="120" height="90">
<img class="thumbnail" src="/statics/images/course/klematis_small.jpg" width="107" height="90">
<img class="thumbnail" src="/statics/images/course/klematis2_small.jpg" width="107" height="80">
<img class="thumbnail" src="/statics/images/course/klematis3_small.jpg" width="116" height="90">
<img class="thumbnail" src="/statics/images/course/klematis4_small.jpg" width="120" height="90">
</body>
</html>
```

## 清除浮动（clear）

元素浮动之后，周围的元素会重新排列，为了避免这种情况，使用 clear 属性

clear 属性指定元素两侧不能出现浮动元素

```html
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8"> 
<title>W3Cschool教程(w3cschool.cn)</title> 
<style>
.thumbnail 
{
	float:left;
	width:110px;
	height:90px;
	margin:5px;
}
.text_line
{
	clear:both;
	margin-bottom:2px;
}
</style>
</head>

<body>
<h3>图片库</h3>
<p>试着调整窗口,看看当图片没有足够的空间会发生什么。.</p>
<img class="thumbnail" src="/statics/images/course/klematis_small.jpg" width="207" height="90">
<img class="thumbnail" src="/statics/images/course/klematis2_small.jpg" width="107" height="80">
<img class="thumbnail" src="/statics/images/course/klematis3_small.jpg" width="116" height="90">
<img class="thumbnail" src="/statics/images/course/klematis4_small.jpg" width="120" height="90">
<h3 class="text_line">第二行</h3>
<img class="thumbnail" src="/statics/images/course/klematis_small.jpg" width="107" height="90">
<img class="thumbnail" src="/statics/images/course/klematis2_small.jpg" width="107" height="80">
<img class="thumbnail" src="/statics/images/course/klematis3_small.jpg" width="116" height="90">
<img class="thumbnail" src="/statics/images/course/klematis4_small.jpg" width="120" height="90">
</body>
</html>
```

## 浮动的所有属性

| 属性                                                         | 描述                               | 值                           | CSS  |
| ------------------------------------------------------------ | ---------------------------------- | ---------------------------- | ---- |
| [clear](https://www.w3cschool.cn/cssref/pr-class-clear.html) | 指定不允许元素周围有浮动元素。     | left right both none inherit | 1    |
| [float](https://www.w3cschool.cn/cssref/pr-class-float.html) | 指定一个盒子（元素）是否可以浮动。 | left right none inherit      | 1    |

#  组合选择器

CSS 组合选择符可以让你直观的明白选择器与选择器之间的关系

在 CSS3 中包含了四种组合方式:

- 后代选取器(以空格分隔)
- 子元素选择器(以大于号分隔）
- 相邻兄弟选择器（以加号分隔）
- 普通兄弟选择器（以波浪号分隔）

## 后台选取器（以空格分隔）

后代选取器匹配所有指定元素的后代元素

```html
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8"> 
<title>W3Cschool教程(w3cschool.cn)</title> 
<style>
div p
{
	background-color:yellow;
}
</style>
</head>
<body>

<div>
<p>段落 1。 在 div 中。</p>
<p>段落 2。 在 div 中。</p>
</div>

<p>段落 3。不在 div 中。</p>
<p>段落 4。不在 div 中。</p>

</body>
</html>
```

## 子元素选择器（以大于号分隔）

与后代选择器相比，子元素选择器（Child selectors）只能选择作为某元素子元素的元素

```html
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8"> 
<title>W3Cschool教程(w3cschool.cn)</title> 
<style>
div>p
{
	background-color:yellow;
}
</style>
</head>

<body>
<h1>Welcome to My Homepage</h1>
<div>
<h2>My name is Donald</h2>
<p>I live in Duckburg.</p>
</div>

<div>
<span><p>I will not be styled.</p></span>
</div>

<p>My best friend is Mickey.</p>
</body>
</html>
```

## 相邻兄弟选择器（以加号分隔）

相邻兄弟选择器（Adjacent sibling selector）可选择紧接在另一元素后的元素，且二者有相同父元素

如果需要选择紧接在另一个元素后的元素，而且二者有相同的父元素，可以使用相邻兄弟选择器（Adjacent sibling selector）

```html
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8"> 
<title>W3Cschool教程(w3cschool.cn)</title> 
<style>
div+p
{
	background-color:yellow;
}
</style>
</head>
<body>

<h1>Welcome to My Homepage</h1>

<div>
<h2>My name is Donald</h2>
<p>I live in Duckburg.</p>
</div>

<p>My best friend is Mickey.</p>

<p>I will not be styled.</p>

</body>
</html>
```

## 普通相邻兄弟选择器（以波浪号分隔）

普通兄弟选择器选取所有指定元素的相邻兄弟元素

```html
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8"> 
<title>W3Cschool教程(w3cschool.cn)</title> 
<style>
div~p
{
	background-color:yellow;
}
</style>
</head>
<body>

<div>
<p>段落 1。 在 div 中。</p>
<p>段落 2。 在 div 中。</p>
</div>

<p>段落 3。不在 div 中。</p>
<p>段落 4。不在 div 中。</p>

</body>
</html>
```

# 伪类（pseudo-classes）

CSS伪类是用来添加一些选择器的特殊效果

由于状态的变化是非静态的，所以元素达到一个特定状态时，它可能得到一个伪类的样式

当状态改变时，它又会失去这个样式。由此可以看出，它的功能和class有些类似，但它是基于文档之外的抽象，所以叫伪类

## 语法

```css
selector:pseudo-class {property:value;}
```

CSS类也可以使用伪类

```css
selector.class:pseudo-class {property:value;}
```

## anchor伪类

在支持 CSS 的浏览器中，链接的不同状态都可以以不同的方式显示

 ```css
a:link {color:#FF0000;} /* 未访问的链接 */ 
a:visited {color:#00FF00;} /* 已访问的链接 */ 
a:hover {color:#FF00FF;} /* 鼠标划过链接 */ 
a:active {color:#0000FF;} /* 已选中的链接 */
 ```

**注意：** 在CSS定义中，a:hover 必须被置于 a:link 和 a:visited 之后，才是有效的。

**注意：** 在 CSS 定义中，a:active 必须被置于 a:hover 之后，才是有效的。

**注意：**伪类的名称不区分大小写。

## 伪类和css类

伪类可以与 CSS 类配合使用：

```css
a.red:visited {color:#FF0000;}       
<a class="red" href="css-syntax.html">CSS Syntax</a>
```

如果在上面的例子的链接已被访问，它会显示为红色

## 所有css伪类/元素

## 所有CSS伪类/元素

| 选择器                                                       | 示例           | 示例说明                                         |
| ------------------------------------------------------------ | -------------- | ------------------------------------------------ |
| [:link](https://www.w3cschool.cn/cssref/sel-link.html)       | a:link         | 选择所有未访问链接                               |
| [:visited](https://www.w3cschool.cn/cssref/sel-visited.html) | a:visited      | 选择所有访问过的链接                             |
| [:active](https://www.w3cschool.cn/cssref/sel-active.html)   | a:active       | 选择正在活动链接                                 |
| [:hover](https://www.w3cschool.cn/cssref/sel-hover.html)     | a:hover        | 把鼠标放在链接上的状态                           |
| [:focus](https://www.w3cschool.cn/cssref/sel-focus.html)     | input:focus    | 选择元素输入后具有焦点                           |
| [:first-letter](https://www.w3cschool.cn/cssref/sel-firstletter.html) | p:first-letter | 选择每个<p> 元素的第一个字母                     |
| [:first-line](https://www.w3cschool.cn/cssref/sel-firstline.html) | p:first-line   | 选择每个<p> 元素的第一行                         |
| [:first-child](https://www.w3cschool.cn/cssref/sel-firstchild.html) | p:first-child  | 选择器匹配属于任意元素的第一个子元素的 <]p> 元素 |
| [:before](https://www.w3cschool.cn/cssref/sel-before.html)   | p:before       | 在每个<p>元素之前插入内容                        |
| [:after](https://www.w3cschool.cn/cssref/sel-after.html)     | p:after        | 在每个<p>元素之后插入内容                        |
| [:lang(*language*)](https://www.w3cschool.cn/cssref/sel-lang.html) | p:lang(it)     | 为<p>元素的lang属性选择一个开始值                |

# 导航栏

熟练使用导航栏，对于任何网站都非常重要

使用CSS你可以转换成好看的导航栏而不是枯燥的HTML菜单

## 导航栏-链接列表

导航条基本上是一个链接列表，所以使用 <ul> 和 <li> 元素非常有意义

 ```html
<!DOCTYPE html>
<html>
<body>
<ul>
<li><a href="#home">Home</a></li>
<li><a href="#news">News</a></li>
<li><a href="#contact">Contact</a></li>
<li><a href="#about">About</a></li>
</ul>

<p>Note: We use href="#" for test links. In a real web site this would be URLs.</p>

</body>
</html>
 ```

# 下拉菜单

```html
<!DOCTYPE html>
<html>
<head>
<title>下拉菜单实例|W3Cschool教程(w3cschool.cn)</title>
<meta charset="utf-8">
<style>
.dropbtn {
    background-color: #4CAF50;
    color: white;
    padding: 16px;
    font-size: 16px;
    border: none;
    cursor: pointer;
}

.dropdown {
    position: relative;
    display: inline-block;
}

.dropdown-content {
    display: none;
    position: absolute;
    background-color: #f9f9f9;
    min-width: 160px;
    box-shadow: 0px 8px 16px 0px rgba(0,0,0,0.2);
}

.dropdown-content a {
    color: black;
    padding: 12px 16px;
    text-decoration: none;
    display: block;
}

.dropdown-content a:hover {background-color: #f1f1f1}

.dropdown:hover .dropdown-content {
    display: block;
}

.dropdown:hover .dropbtn {
    background-color: #3e8e41;
}
</style>
</head>
<body>

<h2>下拉菜单</h2>
<p>鼠标移动到按钮上打开下拉菜单。</p>

<div class="dropdown">
  <button class="dropbtn">下拉菜单</button>
  <div class="dropdown-content">
    <a href="http://www.w3cschool.cn">W3Cschool教程 1</a>
    <a href="http://www.w3cschool.cn">W3Cschool教程 2</a>
    <a href="http://www.w3cschool.cn">W3Cschool教程 3</a>
  </div>
</div>

</body>
</html>
```

# 响应式设计

# 可视区域（Viewport）

viewport 是用户网页的可视区域

手机浏览器是把页面放在一个虚拟的"窗口"（viewport）中，通常这个虚拟的"窗口"（viewport）比屏幕宽，这样就不用把每个网页挤到很小的窗口中（这样会破坏没有针对手机浏览器优化的网页的布局），用户可以通过平移和缩放来看网页的不同部分

## 设置Viewport

一个常用的针对移动网页优化过的页面的 viewport meta 标签大致如下：

- width：控制 viewport 的大小，可以指定的一个值，如果 600，或者特殊的值，如 device-width 为设备的宽度（单位为缩放为 100% 时的 CSS 的像素）。
- height：和 width 相对应，指定高度。
- initial-scale：初始缩放比例，也即是当页面第一次 load 的时候缩放比例。
- maximum-scale：允许用户缩放到的最大比例。
- minimum-scale：允许用户缩放到的最小比例。
- user-scalable：用户是否可以手动缩放

```html
<!DOCTYPE html>
<html>
<head>
<meta http-equiv="content-type" content="text/html; charset=gbk">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<style>
img {
	max-width:100%;
	height:auto;
}
</style>
<script charset="utf-8" async="true" src="i8.js"></script></head>
<body>
<img src="img_chania.jpg" alt="Chania" height="345" width="460">
<p>
Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam 
nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat 
volutpat.
Ut wisi enim ad minim veniam, quis nostrud exerci tation ullamcorper 
suscipit lobortis nisl ut aliquip ex ea commodo consequat. Duis autem 
vel eum iriure dolor in hendrerit in vulputate velit esse molestie 
consequat, vel illum dolore eu feugiat nulla facilisis at vero eros et 
accumsan et iusto odio dignissim qui blandit praesent luptatum zzril 
delenit augue duis dolore te feugait nulla facilisi. Nam liber tempor 
cum soluta nobis eleifend option congue nihil imperdiet doming id quod 
mazim placerat facer possim assum.
Nam liber tempor cum soluta nobis eleifend option congue nihil imperdiet
 doming id quod mazim placerat facer possim assum.
</p>
</body>
</html>
```

# 网格视图

使用网格视图有助于我们设计网页。这让我们向网页添加元素变的更简单

## 创建响应式网格视图

首先确保所有的 HTML 元素都有 **box-sizing** 属性且设置为 **border-box**

确保边距和边框包含在元素的宽度和高度间

```html
<!DOCTYPE html>
<html>
<head>
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<style>
* {
    box-sizing: border-box;
}
.row:after {
    content: "";
    clear: both;
    display: block;
}
[class*="col-"] {
    float: left;
    padding: 15px;
}
.col-1 {width: 8.33%;}
.col-2 {width: 16.66%;}
.col-3 {width: 25%;}
.col-4 {width: 33.33%;}
.col-5 {width: 41.66%;}
.col-6 {width: 50%;}
.col-7 {width: 58.33%;}
.col-8 {width: 66.66%;}
.col-9 {width: 75%;}
.col-10 {width: 83.33%;}
.col-11 {width: 91.66%;}
.col-12 {width: 100%;}
html {
    font-family: "Lucida Sans", sans-serif;
}
.header {
    background-color: #9933cc;
    color: #ffffff;
    padding: 15px;
}
.menu ul {
    list-style-type: none;
    margin: 0;
    padding: 0;
}
.menu li {
    padding: 8px;
    margin-bottom: 7px;
    background-color :#33b5e5;
    color: #ffffff;
    box-shadow: 0 1px 3px rgba(0,0,0,0.12), 0 1px 2px rgba(0,0,0,0.24);
}
.menu li:hover {
    background-color: #0099cc;
}
</style>
</head>
<body>

<div class="header">
<h1>Chania</h1>
</div>

<div class="row">

<div class="col-3 menu">
<ul>
<li>The Flight</li>
<li>The City</li>
<li>The Island</li>
<li>The Food</li>
</ul>
</div>

<div class="col-9">
<h1>The City</h1>
<p>Chania is the capital of the Chania region on the island of Crete. The city can be divided in two parts, the old town and the modern city.</p>
<p>Resize the browser window to see how the content respond to the resizing.</p>
</div>

</div>
</body>
</html>
```

# 媒体查询（@media）

使用 @media 查询，你可以针对不同的媒体类型定义不同的样式

如果浏览器窗口小于 500px, 背景将变为浅蓝色：

```css
@media only screen and (max-width: 500px) {
    body {
        background-color: lightblue;
    }
}
```

## 添加断点

```html
<!DOCTYPE html>
<html>
<head>
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<style>
* {
    box-sizing: border-box;
}
.row:after {
    content: "";
    clear: both;
    display: block;
}
[class*="col-"] {
    float: left;
    padding: 15px;
}
html {
    font-family: "Lucida Sans", sans-serif;
}
.header {
    background-color: #9933cc;
    color: #ffffff;
    padding: 15px;
}
.menu ul {
    list-style-type: none;
    margin: 0;
    padding: 0;
}
.menu li {
    padding: 8px;
    margin-bottom: 7px;
    background-color :#33b5e5;
    color: #ffffff;
    box-shadow: 0 1px 3px rgba(0,0,0,0.12), 0 1px 2px rgba(0,0,0,0.24);
}
.menu li:hover {
    background-color: #0099cc;
}
.aside {
    background-color: #33b5e5;
    padding: 15px;
    color: #ffffff;
    text-align: center;
    font-size: 14px;
    box-shadow: 0 1px 3px rgba(0,0,0,0.12), 0 1px 2px rgba(0,0,0,0.24);
}
.footer {
    background-color: #0099cc;
    color: #ffffff;
    text-align: center;
    font-size: 12px;
    padding: 15px;
}
/* For desktop: */
.col-1 {width: 8.33%;}
.col-2 {width: 16.66%;}
.col-3 {width: 25%;}
.col-4 {width: 33.33%;}
.col-5 {width: 41.66%;}
.col-6 {width: 50%;}
.col-7 {width: 58.33%;}
.col-8 {width: 66.66%;}
.col-9 {width: 75%;}
.col-10 {width: 83.33%;}
.col-11 {width: 91.66%;}
.col-12 {width: 100%;}

@media only screen and (max-width: 768px) {
    /* For mobile phones: */
    [class*="col-"] {
        width: 100%;
    }
}
</style>
</head>
<body>

<div class="header">
<h1>Chania</h1>
</div>

<div class="row">

<div class="col-3 menu">
<ul>
<li>The Flight</li>
<li>The City</li>
<li>The Island</li>
<li>The Food</li>
</ul>
</div>

<div class="col-6">
<h1>The City</h1>
<p>Chania is the capital of the Chania region on the island of Crete. The city can be divided in two parts, the old town and the modern city.</p>
</div>
<div class="col-3 right">
<div class="aside">
<h2>What?</h2>
<p>Chania is a city on the island of Crete.</p>
<h2>Where?</h2>
<p>Crete is a Greek island in the Mediterranean Sea.</p>
<h2>How?</h2>
<p>You can reach Chania airport from all over Europe.</p>
</div>
</div>

</div>

<div class="footer">
<p>Resize the browser window to see how the content respond to the resizing.</p>
</div>

</body>
</html>
```

## 为移动端优先设计

移动端优先意味着在设计桌面和其他设备时优先考虑移动端的设计

这就意味着我们必须对 CSS 做一些改变

在屏幕小于 768px 进行样式修改，同样在屏幕宽度大于 768px 时也需要修改样式。以下是移动端优先实例：

```css
/* 为移动端设计: */
[class*="col-"] {
    width: 100%;
}
@media only screen and (min-width: 768px) {
    /* For desktop: */
    .col-1 {width: 8.33%;}
    .col-2 {width: 16.66%;}
    .col-3 {width: 25%;}
    .col-4 {width: 33.33%;}
    .col-5 {width: 41.66%;}
    .col-6 {width: 50%;}
    .col-7 {width: 58.33%;}
    .col-8 {width: 66.66%;}
    .col-9 {width: 75%;}
    .col-10 {width: 83.33%;}
    .col-11 {width: 91.66%;}
    .col-12 {width: 100%;}
}
```

## 横屏/竖屏

结合CSS媒体查询,可以创建适应不同设备的方向(横屏landscape、竖屏portrait等)的布局

语法：

```css
orientation：portrait | landscape
```

- **portrait：**指定输出设备中的页面可见区域高度大于或等于宽度
- **landscape：** 除portrait值情况外，都是landscape

```css
@media only screen and (orientation: landscape) {
    body {
        background-color: lightblue;
    }
}
```

# 图片

## 使用width属性

如果 width 属性设置为 100%，图片会根据上下范围实现响应式功能：

```css
img { 
    width: 100%; 
    height: auto; 
}
```

## 使用max-width属性

如果 max-width 属性设置为 100%, 图片永远不会大于其原始大小：

```css
img { 
    max-width: 100%; 
    height: auto; 
}
```

## 背景图片

背景图片可以响应调整大小或缩放

以下是三个不同的方法：

1. 如果 background-size 属性设置为 "contain", 背景图片将按比例自适应内容区域。图片保持其比例不变：

```css
<!DOCTYPE html>
<html>
<head>
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<style>
div {
    width: 100%;
    height: 400px;
    background-image: url('/statics/images/course/img_flowers.jpg');
    background-repeat: no-repeat;
    background-size: contain;
    border: 1px solid red;
}
</style>
</head>
<body>

<p>调整浏览器大小查看效果。</p>

<div></div>

</body>
</html>
```

2. 如果 background-size 属性设置为 "100% 100%" ，背景图片将延展覆盖整个区域：

```html
<!DOCTYPE html>
<html>
<head>
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<style>
div {
    width: 100%;
    height: 400px;
    background-image: url('/statics/images/course/img_flowers.jpg');
    background-size: 100% 100%;
    border: 1px solid red;
}
</style>
</head>
<body>

<p>调整浏览器大小查看效果。</p>

<div></div>

</body>
</html>
```

3. 如果 background-size 属性设置为 "cover"，则会把背景图像扩展至足够大，以使背景图像完全覆盖背景区域。注意该属性保持了图片的比例因此 背景图像的某些部分无法显示在背景定位区域中。

```html
<!DOCTYPE html>
<html>
<head>
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<style>
div {
    width: 100%;
    height: 400px;
    background-image: url('/statics/images/course/img_flowers.jpg');
    background-size: cover;
    border: 1px solid red;
}
</style>
</head>
<body>

<p>调整浏览器大小查看效果。</p>

<div></div>

</body>
</html>
```

## 不同设备显示不同图片

大尺寸图片可以显示在大屏幕上，但在小屏幕上确不能很好显示。我们没有必要在小屏幕上去加载大图片，这样很影响加载速度。所以我们可以使用媒体查询，根据不同的设备显示不同的图片

```css
/* For width smaller than 400px: */ 
body { 
    background-image: url('img_smallflower.jpg'); 
} 

/* For width 400px and larger: */ 
@media only screen and (min-width: 400px) { 
    body { 
        background-image: url('img_flowers.jpg'); 
    } 
}
```

你可以使用媒体查询的 min-device-width 替代 min-width 属性，它将检测的是设备宽度而不是浏览器宽度。浏览器大小重置时，图片大小不会改变

```html
/* 设备小于 400px: */ 
body { 
    background-image: url('img_smallflower.jpg'); 
} 

/* 设备大于 400px (也等于): */ 
@media only screen and (min-device-width: 400px) { 
    body { 
        background-image: url('img_flowers.jpg'); 
    } 
}
```

## Html5的'<picture>'元素

HTML5 的 <picture>元素可以设置多张图片

<picture>元素类似于<video> 和 <audio> 元素。可以设备不同的资源，第一个设置的资源为首选使用的：

```css
<picture> 
  <source srcset="img_smallflower.jpg" media="(max-width: 400px)"> 
  <source srcset="img_flowers.jpg"> 
  <img src="img_flowers.jpg" alt="Flowers"> 
</picture>
```

`srcset` 属性的必须的，定义了图片资源

`media` 属性是可选的





