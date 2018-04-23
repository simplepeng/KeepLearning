# 边框

# 圆角

在CSS3中border-radius属性就是被用于创建圆角的

```Html
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8"> 
<title>W3Cschool教程(w3cschool.cn)</title> 
<style> 
div
{
	border:2px solid #a1a1a1;
	padding:10px 40px; 
	background:#dddddd;
	width:300px;
	border-radius:25px;
}
</style>
</head>
<body>

<div>border-radius 属性允许您为元素添加圆角边框！ </div>

</body>
</html>
```

## 椭圆边角

```css
#rcorners9 {
    border-radius: 50%;
    background: #8AC007;
    padding: 20px; 
    width: 200px;
    height: 150px;
}
```

## 圆角属性

| 属性                                                         | 描述                                      |
| ------------------------------------------------------------ | ----------------------------------------- |
| [border-radius](https://www.w3cschool.cn/cssref/css3-pr-border-radius.html) | 所有四个边角 border-*-*-radius 属性的缩写 |
| [border-top-left-radius](https://www.w3cschool.cn/cssref/css3-pr-border-top-left-radius.html) | 定义了左上角的弧度                        |
| [border-top-right-radius](https://www.w3cschool.cn/cssref/css3-pr-border-top-right-radius.html) | 定义了右上角的弧度                        |
| [border-bottom-right-radius](https://www.w3cschool.cn/cssref/css3-pr-border-bottom-right-radius.html) | 定义了右下角的弧度                        |
| [border-bottom-left-radius](https://www.w3cschool.cn/cssref/css3-pr-border-bottom-left-radius.html) | 定义了左下角的弧度                        |

# 盒阴影

CSS3中的box-shadow属性被用来添加阴影:

```css
div
{
	width:300px;
	height:100px;
	background-color:yellow;
	box-shadow: 10px 10px 5px #888888;
}
```

## 边界图片

CSS3的border-image属性，可以使用图像创建一个边框

border-image属性允许你指定一个图片作为边框！用于创建上文边框的原始图像

```css
div 
{ 
border-image:url(border.png) 30 30 round; 
-webkit-border-image:url(border.png) 30 30 round; /* Safari 5 and older */ 
-o-border-image:url(border.png) 30 30 round; /* Opera */ 
}
```

# 背景

- background-image
- background-size
- background-origin
- background-clip

## background-image

CSS3中可以通过background-image属性添加背景图片

不同的背景图像和图像用逗号隔开，所有的图片中显示在最顶端的为第一张

```css
#example1 { 
background-image: url(img_flwr.gif), url(paper.gif); 
background-position: right bottom, left top; 
background-repeat: no-repeat, repeat; 
}
```

## background-size 

background-size指定背景图像的大小。CSS3以前，背景图像大小由图像的实际大小决定

CSS3中可以指定背景图片，让我们重新在不同的环境中指定背景图片的大小

您可以指定像素或相对于父元素宽高的百分比大小

```css
div 
{ 
background:url(img_flwr.gif); 
background-size:80px 60px; 
background-repeat:no-repeat; 
}
```

## backgroud-origin

background-Origin属性指定了背景图像的位置区域

content-box, padding-box,和 border-box区域内可以放置背景图像

```css
div 
{ 
background:url(img_flwr.gif); 
background-repeat:no-repeat; 
background-size:100% 100%; 
background-origin:content-box; 
}
```

## background-clip

CSS3中background-clip背景剪裁属性是从指定位置开始绘制

```css
#example1 { 
border: 10px dotted black; 
padding: 35px; 
background: yellow; 
background-clip: content-box; 
}
```

## 属性

| 顺序                                                         | 描述                     | CSS  |
| ------------------------------------------------------------ | ------------------------ | ---- |
| [background-clip](https://www.w3cschool.cn/cssref/css3-pr-background-clip.html) | 规定背景的绘制区域。     | 3    |
| [background-origin](https://www.w3cschool.cn/cssref/css3-pr-background-origin.html) | 规定背景图片的定位区域。 | 3    |
| [background-size](https://www.w3cschool.cn/cssref/css3-pr-background-size.html) | 规定背景图片的尺寸。     | 3    |

# 渐变（Gradients）

CSS3 渐变（gradients）可以让你在两个或多个指定的颜色之间显示平稳的过渡

CSS3 定义了两种类型的渐变（gradients）：

- **线性渐变（Linear Gradients）- 向下/向上/向左/向右/对角方向**
- **径向渐变（Radial Gradients）- 由它们的中心定义**

## 线性渐变

为了创建一个线性渐变，你必须至少定义两种颜色结点

颜色结点即你想要呈现平稳过渡的颜色。同时，你也可以设置一个起点和一个方向（或一个角度）

```css
background: linear-gradient(direction, color-stop1, color-stop2, ...);   
```

### 从上到下（默认情况）

```css
#grad { 
  background: -webkit-linear-gradient(red, blue); /* Safari 5.1 - 6.0 */ 
  background: -o-linear-gradient(red, blue); /* Opera 11.1 - 12.0 */ 
  background: -moz-linear-gradient(red, blue); /* Firefox 3.6 - 15 */ 
  background: linear-gradient(red, blue); /* 标准的语法 */ 
}
```

### 从左到右

```css
#grad { 
  background: -webkit-linear-gradient(left, red , blue); /* Safari 5.1 - 6.0 */ 
  background: -o-linear-gradient(right, red, blue); /* Opera 11.1 - 12.0 */ 
  background: -moz-linear-gradient(right, red, blue); /* Firefox 3.6 - 15 */
  background: linear-gradient(to right, red , blue); /* 标准的语法 */ 
}
```

### 对角

```css
#grad { 
  background: -webkit-linear-gradient(left top, red , blue); /* Safari 5.1 - 6.0 */ 
  background: -o-linear-gradient(bottom right, red, blue); /* Opera 11.1 - 12.0 */ 
  background: -moz-linear-gradient(bottom right, red, blue); /* Firefox 3.6 - 15 */ 
  background: linear-gradient(to bottom right, red , blue); /* 标准的语法 */ 
}
```

### 使用角度

如果你想要在渐变的方向上做更多的控制，你可以定义一个角度，而不用预定义方向（to bottom、to top、to right、to left、to bottom right，等等）

```css
background: linear-gradient(angle, color-stop1, color-stop2);  
```

```css
#grad { 
  background: -webkit-linear-gradient(180deg, red, blue); /* Safari 5.1 - 6.0 */ 
  background: -o-linear-gradient(180deg, red, blue); /* Opera 11.1 - 12.0 */
  background: -moz-linear-gradient(180deg, red, blue); /* Firefox 3.6 - 15 */ 
  background: linear-gradient(180deg, red, blue); /* 标准的语法 */ 
}
```

### 使用透明度（Transparency）

CSS3 渐变也支持透明度（transparency），可用于创建减弱变淡的效果

为了添加透明度，我们使用 rgba() 函数来定义颜色结点。rgba() 函数中的最后一个参数可以是从 0 到 1 的值，它定义了颜色的透明度：0 表示完全透明，1 表示完全不透明

```css
#grad { 
  background: -webkit-linear-gradient(left,rgba(255,0,0,0),rgba(255,0,0,1)); /* Safari 5.1 - 6 */ 
  background: -o-linear-gradient(right,rgba(255,0,0,0),rgba(255,0,0,1)); /* Opera 11.1 - 12*/ 
  background: -moz-linear-gradient(right,rgba(255,0,0,0),rgba(255,0,0,1)); /* Firefox 3.6 - 15*/ 
  background: linear-gradient(to right, rgba(255,0,0,0), rgba(255,0,0,1)); /* 标准的语法 */ 
}
```

### 重复的线性渐变

repeating-linear-gradient() 函数用于重复线性渐变

```css
#grad { 
  /* Safari 5.1 - 6.0 */ 
  background: -webkit-repeating-linear-gradient(red, yellow 10%, green 20%);
  /* Opera 11.1 - 12.0 */ 
  background: -o-repeating-linear-gradient(red, yellow 10%, green 20%); 
  /* Firefox 3.6 - 15 */ 
  background: -moz-repeating-linear-gradient(red, yellow 10%, green 20%); 
  /* 标准的语法 */ 
  background: repeating-linear-gradient(red, yellow 10%, green 20%); 
}
```

## 径向渐变

径向渐变由它的中心定义

为了创建一个径向渐变，你也必须至少定义两种颜色结点。颜色结点即你想要呈现平稳过渡的颜色。同时，你也可以指定渐变的中心、形状（原型或椭圆形）、大小

默认情况下，渐变的中心是 center（表示在中心点），渐变的形状是 ellipse（表示椭圆形），渐变的大小是 farthest-corner（表示到最远的角落）

```css
background: radial-gradient(center, shape size, start-color, ..., last-color);
```

### 颜色结点均匀分布（默认情况）

```css
#grad { 
  background: -webkit-radial-gradient(red, green, blue); /* Safari 5.1 - 6.0 */ 
  background: -o-radial-gradient(red, green, blue); /* Opera 11.6 - 12.0 */ 
  background: -moz-radial-gradient(red, green, blue); /* Firefox 3.6 - 15 */
  background: radial-gradient(red, green, blue); /* 标准的语法 */ 
}
```

### 颜色结点不均匀分布

```css
#grad { 
  background: -webkit-radial-gradient(red 5%, green 15%, blue 60%); /* Safari 5.1 - 6.0 */ 
  background: -o-radial-gradient(red 5%, green 15%, blue 60%); /* Opera 11.6 - 12.0 */ 
  background: -moz-radial-gradient(red 5%, green 15%, blue 60%); /* Firefox 3.6 - 15 */ 
  background: radial-gradient(red 5%, green 15%, blue 60%); /* 标准的语法 */ 
}
```

### 设置形状

shape 参数定义了形状。它可以是值 circle 或 ellipse。其中，circle 表示圆形，ellipse 表示椭圆形。默认值是 ellipse

```css
#grad { 
  background: -webkit-radial-gradient(circle, red, yellow, green); /* Safari 5.1 - 6.0 */ 
  background: -o-radial-gradient(circle, red, yellow, green); /* Opera 11.6 - 12.0 */ 
  background: -moz-radial-gradient(circle, red, yellow, green); /* Firefox 3.6 - 15 */ 
  background: radial-gradient(circle, red, yellow, green); /* 标准的语法 */ 
}
```

### 不同尺寸大小关键字的使用

size 参数定义了渐变的大小。它可以是以下四个值：

- **closest-side**
- **farthest-side**
- **closest-corner**
- **farthest-corner**

```css
#grad1 { 
  /* Safari 5.1 - 6.0 */ 
  background: -webkit-radial-gradient(60% 55%, closest-side,blue,green,yellow,black); 
  /* Opera 11.6 - 12.0 */ 
 background: -o-radial-gradient(60% 55%, closest-side,blue,green,yellow,black); 
 /* Firefox 3.6 - 15 */ 
  background: -moz-radial-gradient(60% 55%, closest-side,blue,green,yellow,black); 
  /* 标准的语法 */ 
 background: radial-gradient(60% 55%, closest-side,blue,green,yellow,black);
} 

#grad2 { 
 /* Safari 5.1 - 6.0 */ 
  background: -webkit-radial-gradient(60% 55%, farthest-side,blue,green,yellow,black); 
 /* Opera 11.6 - 12.0 */ 
  background: -o-radial-gradient(60% 55%, farthest-side,blue,green,yellow,black); 
  /* Firefox 3.6 - 15 */ 
 background: -moz-radial-gradient(60% 55%, farthest-side,blue,green,yellow,black); 
 /* 标准的语法 */ 
  background: radial-gradient(60% 55%, farthest-side,blue,green,yellow,black); 
}
```

### 重复的径向渐变

repeating-radial-gradient() 函数用于重复径向渐变

```css
#grad { 
  /* Safari 5.1 - 6.0 */ 
  background: -webkit-repeating-radial-gradient(red, yellow 10%, green 15%);
  /* Opera 11.6 - 12.0 */ 
  background: -o-repeating-radial-gradient(red, yellow 10%, green 15%); 
  /* Firefox 3.6 - 15 */ 
  background: -moz-repeating-radial-gradient(red, yellow 10%, green 15%); 
  /* 标准的语法 */ 
  background: repeating-radial-gradient(red, yellow 10%, green 15%); 
}
```



