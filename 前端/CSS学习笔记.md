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

## id选择器

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

## class 选择器

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

