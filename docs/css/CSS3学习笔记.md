## 边框

## 圆角

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

### 椭圆边角

```css
#rcorners9 {
    border-radius: 50%;
    background: #8AC007;
    padding: 20px; 
    width: 200px;
    height: 150px;
}
```

### 圆角属性

| 属性                                                         | 描述                                      |
| ------------------------------------------------------------ | ----------------------------------------- |
| [border-radius](https://www.w3cschool.cn/cssref/css3-pr-border-radius.html) | 所有四个边角 border-*-*-radius 属性的缩写 |
| [border-top-left-radius](https://www.w3cschool.cn/cssref/css3-pr-border-top-left-radius.html) | 定义了左上角的弧度                        |
| [border-top-right-radius](https://www.w3cschool.cn/cssref/css3-pr-border-top-right-radius.html) | 定义了右上角的弧度                        |
| [border-bottom-right-radius](https://www.w3cschool.cn/cssref/css3-pr-border-bottom-right-radius.html) | 定义了右下角的弧度                        |
| [border-bottom-left-radius](https://www.w3cschool.cn/cssref/css3-pr-border-bottom-left-radius.html) | 定义了左下角的弧度                        |

## 盒阴影

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

### 边界图片

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

## 背景

- background-image
- background-size
- background-origin
- background-clip

### background-image

CSS3中可以通过background-image属性添加背景图片

不同的背景图像和图像用逗号隔开，所有的图片中显示在最顶端的为第一张

```css
#example1 { 
background-image: url(img_flwr.gif), url(paper.gif); 
background-position: right bottom, left top; 
background-repeat: no-repeat, repeat; 
}
```

### background-size 

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

### backgroud-origin

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

### background-clip

CSS3中background-clip背景剪裁属性是从指定位置开始绘制

```css
#example1 { 
border: 10px dotted black; 
padding: 35px; 
background: yellow; 
background-clip: content-box; 
}
```

### 属性

| 顺序                                                         | 描述                     | CSS  |
| ------------------------------------------------------------ | ------------------------ | ---- |
| [background-clip](https://www.w3cschool.cn/cssref/css3-pr-background-clip.html) | 规定背景的绘制区域。     | 3    |
| [background-origin](https://www.w3cschool.cn/cssref/css3-pr-background-origin.html) | 规定背景图片的定位区域。 | 3    |
| [background-size](https://www.w3cschool.cn/cssref/css3-pr-background-size.html) | 规定背景图片的尺寸。     | 3    |

## 渐变（Gradients）

CSS3 渐变（gradients）可以让你在两个或多个指定的颜色之间显示平稳的过渡

CSS3 定义了两种类型的渐变（gradients）：

- **线性渐变（Linear Gradients）- 向下/向上/向左/向右/对角方向**
- **径向渐变（Radial Gradients）- 由它们的中心定义**

### 线性渐变

为了创建一个线性渐变，你必须至少定义两种颜色结点

颜色结点即你想要呈现平稳过渡的颜色。同时，你也可以设置一个起点和一个方向（或一个角度）

```css
background: linear-gradient(direction, color-stop1, color-stop2, ...);   
```

#### 从上到下（默认情况）

```css
#grad { 
  background: -webkit-linear-gradient(red, blue); /* Safari 5.1 - 6.0 */ 
  background: -o-linear-gradient(red, blue); /* Opera 11.1 - 12.0 */ 
  background: -moz-linear-gradient(red, blue); /* Firefox 3.6 - 15 */ 
  background: linear-gradient(red, blue); /* 标准的语法 */ 
}
```

#### 从左到右

```css
#grad { 
  background: -webkit-linear-gradient(left, red , blue); /* Safari 5.1 - 6.0 */ 
  background: -o-linear-gradient(right, red, blue); /* Opera 11.1 - 12.0 */ 
  background: -moz-linear-gradient(right, red, blue); /* Firefox 3.6 - 15 */
  background: linear-gradient(to right, red , blue); /* 标准的语法 */ 
}
```

#### 对角

```css
#grad { 
  background: -webkit-linear-gradient(left top, red , blue); /* Safari 5.1 - 6.0 */ 
  background: -o-linear-gradient(bottom right, red, blue); /* Opera 11.1 - 12.0 */ 
  background: -moz-linear-gradient(bottom right, red, blue); /* Firefox 3.6 - 15 */ 
  background: linear-gradient(to bottom right, red , blue); /* 标准的语法 */ 
}
```

#### 使用角度

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

#### 使用透明度（Transparency）

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

#### 重复的线性渐变

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

### 径向渐变

径向渐变由它的中心定义

为了创建一个径向渐变，你也必须至少定义两种颜色结点。颜色结点即你想要呈现平稳过渡的颜色。同时，你也可以指定渐变的中心、形状（原型或椭圆形）、大小

默认情况下，渐变的中心是 center（表示在中心点），渐变的形状是 ellipse（表示椭圆形），渐变的大小是 farthest-corner（表示到最远的角落）

```css
background: radial-gradient(center, shape size, start-color, ..., last-color);
```

#### 颜色结点均匀分布（默认情况）

```css
#grad { 
  background: -webkit-radial-gradient(red, green, blue); /* Safari 5.1 - 6.0 */ 
  background: -o-radial-gradient(red, green, blue); /* Opera 11.6 - 12.0 */ 
  background: -moz-radial-gradient(red, green, blue); /* Firefox 3.6 - 15 */
  background: radial-gradient(red, green, blue); /* 标准的语法 */ 
}
```

#### 颜色结点不均匀分布

```css
#grad { 
  background: -webkit-radial-gradient(red 5%, green 15%, blue 60%); /* Safari 5.1 - 6.0 */ 
  background: -o-radial-gradient(red 5%, green 15%, blue 60%); /* Opera 11.6 - 12.0 */ 
  background: -moz-radial-gradient(red 5%, green 15%, blue 60%); /* Firefox 3.6 - 15 */ 
  background: radial-gradient(red 5%, green 15%, blue 60%); /* 标准的语法 */ 
}
```

#### 设置形状

shape 参数定义了形状。它可以是值 circle 或 ellipse。其中，circle 表示圆形，ellipse 表示椭圆形。默认值是 ellipse

```css
#grad { 
  background: -webkit-radial-gradient(circle, red, yellow, green); /* Safari 5.1 - 6.0 */ 
  background: -o-radial-gradient(circle, red, yellow, green); /* Opera 11.6 - 12.0 */ 
  background: -moz-radial-gradient(circle, red, yellow, green); /* Firefox 3.6 - 15 */ 
  background: radial-gradient(circle, red, yellow, green); /* 标准的语法 */ 
}
```

#### 不同尺寸大小关键字的使用

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

#### 重复的径向渐变

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

## 文本效果

CSS3中包含几个新的文本特征

- text-shadow 文本阴影
- box-shadow 盒子阴影
- text-overflow 文本溢出
- word-wrap 文本包裹方式
- word-break 

### 文本阴影

指定了水平阴影，垂直阴影，模糊的距离，以及阴影的颜色

```css
h1
{
    text-shadow: 5px 5px 5px #FF0000;
}
```

### 盒子阴影

```css
div { box-shadow: 10px 10px grey;}
```

### Text OverFlow

CSS3文本溢出属性指定应向用户如何显示溢出内容

```css
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8"> 
<title>W3Cschool教程(w3cschool.cn)</title> 
<style> 
div.test
{
	white-space:nowrap; 
	width:12em; 
	overflow:hidden; 
	border:1px solid #000000;
}
</style>
</head>
<body>

<p>以下 div 容器内的文本无法完全显示，可以看到它被裁剪了。</p>
<p>div 使用 "text-overflow:ellipsis":</p>

<div class="test" style="text-overflow:ellipsis;">This is some long text that will not fit in the box</div>
<p>div 使用 "text-overflow:clip":</p>
<div class="test" style="text-overflow:clip;">This is some long text that will not fit in the box</div>
<p>div 使用自定义字符串 "text-overflow: &gt;&gt;"(只在 Firefox 浏览器下有效):</p>
<div class="test" style="text-overflow:'>>';">This is some long text that will not fit in the box</div>
</body>
</html>
```

### 换行

如果某个单词太长，不适合在一个区域内，它扩展到外面：

CSS3中，自动换行属性允许您强制文本换行 - 即使这意味着分裂它中间的一个字：

```css
p {word-wrap:break-word;}
```

### 单词拆分换行

CSS3 单词拆分换行属性指定换行规则：

```css
p.test1 { 
    word-break: keep-all;
} 
p.test2 { 
    word-break: break-all;
}
```

### 属性

| 属性                                                         | 描述                                                     | CSS  |
| ------------------------------------------------------------ | -------------------------------------------------------- | ---- |
| [hanging-punctuation](https://www.w3cschool.cn/cssref/css3-pr-hanging-punctuation.html) | 规定标点字符是否位于线框之外。                           | 3    |
| [punctuation-trim](https://www.w3cschool.cn/cssref/css3-pr-punctuation-trim.html) | 规定是否对标点字符进行修剪。                             | 3    |
| [text-align-last](https://www.w3cschool.cn/cssref/css3-pr-text-align-last.html) | 设置如何对齐最后一行或紧挨着强制换行符之前的行。         | 3    |
| text-emphasis                                                | 向元素的文本应用重点标记以及重点标记的前景色。           | 3    |
| [text-justify](https://www.w3cschool.cn/cssref/css3-pr-text-justify.html) | 规定当  text-align 设置为 "justify" 时所使用的对齐方法。 | 3    |
| [text-outline](https://www.w3cschool.cn/cssref/css3-pr-text-outline.html) | 规定文本的轮廓。                                         | 3    |
| [text-overflow](https://www.w3cschool.cn/cssref/css3-pr-text-overflow.html) | 规定当文本溢出包含元素时发生的事情。                     | 3    |
| [text-shadow](https://www.w3cschool.cn/cssref/css3-pr-text-shadow.html) | 向文本添加阴影。                                         | 3    |
| [text-wrap](https://www.w3cschool.cn/cssref/css3-pr-text-wrap.html) | 规定文本的换行规则。                                     | 3    |
| [word-break](https://www.w3cschool.cn/cssref/css3-pr-word-break.html) | 规定非中日韩文本的换行规则。                             | 3    |
| [word-wrap](https://www.w3cschool.cn/cssref/css3-pr-word-wrap.html) | 允许对长的不可分割的单词进行分割并换行到下一行。         | 3    |

## 字体

在CSS3之前，web设计师必须使用已在用户计算机上安装好的字体，不能够使用离线字体，不过通过CSS3，web设计师可以使用他们喜欢的任意字体。

当您找到或购买到希望使用的字体时，可将该字体文件存放到web服务器上，它会在需要时被自动下载到用户的计算机上

在新的 @font-face 规则中，您必须首先定义字体的名称（比如 myFirstFont），然后指向该字体文件

```css
<style> 
@font-face
{
   font-family: myFirstFont;
   src: url(sansation_light.woff);
}

div
{
   font-family:myFirstFont;
}
</style>
```

## 2D 转换

CSS3转换，我们可以移动，比例化，反过来，旋转，和拉伸元素

变换的效果，让某个元素改变形状，大小和位置

### 方法

- translate()
- rotate()
- scale()
- skew()
- matrix()

### translate 平移

translate()方法，根据左(X轴)和顶部(Y轴)位置给定的参数，从当前元素位置移动。

```css
div
{
transform: translate(50px,100px);
-ms-transform: translate(50px,100px); /* IE 9 */
-webkit-transform: translate(50px,100px); /* Safari and Chrome */
}
```

### rotate 旋转

rotate()方法，在一个给定度数顺时针旋转的元素。负值是允许的，这样是元素逆时针旋转。

```css
div
{
transform: rotate(30deg);
-ms-transform: rotate(30deg); /* IE 9 */
-webkit-transform: rotate(30deg); /* Safari and Chrome */
}
```

### scale 缩放

scale()方法，该元素增加或减少的大小，取决于宽度（X轴）和高度（Y轴）的参数

```css
div
{
transform: scale(2,4);
-ms-transform: scale(2,4); /* IE 9 */
-webkit-transform: scale(2,4); /* Safari and Chrome */
} 
```

### skew 错切

skew()方法，该元素会根据横向（X轴）和垂直（Y轴）线参数给定角度

```css
div
{
transform: skew(30deg,20deg);
-ms-transform: skew(30deg,20deg); /* IE 9 */
-webkit-transform: skew(30deg,20deg); /* Safari and Chrome */
}  
```

### matrix 矩阵

matrix()方法和2D变换方法合并成一个

matrix 方法有六个参数，包含旋转，缩放，移动（平移）和倾斜功能

```css
div
{
transform:matrix(0.866,0.5,-0.5,0.866,0,0);
-ms-transform:matrix(0.866,0.5,-0.5,0.866,0,0); /* IE 9 */
-webkit-transform:matrix(0.866,0.5,-0.5,0.866,0,0); /* Safari and Chrome */
}
```

### 转换方法

| 函数                            | 描述                                     |
| ------------------------------- | ---------------------------------------- |
| matrix(*n*,*n*,*n*,*n*,*n*,*n*) | 定义 2D 转换，使用六个值的矩阵。         |
| translate(*x*,*y*)              | 定义 2D 转换，沿着 X 和 Y 轴移动元素。   |
| translateX(*n*)                 | 定义 2D 转换，沿着 X 轴移动元素。        |
| translateY(*n*)                 | 定义 2D 转换，沿着 Y 轴移动元素。        |
| scale(*x*,*y*)                  | 定义 2D 缩放转换，改变元素的宽度和高度。 |
| scaleX(*n*)                     | 定义 2D 缩放转换，改变元素的宽度。       |
| scaleY(*n*)                     | 定义 2D 缩放转换，改变元素的高度。       |
| rotate(*angle*)                 | 定义 2D 旋转，在参数中规定角度。         |
| skew(*x-angle*,*y-angle*)       | 定义 2D 倾斜转换，沿着 X 和 Y 轴。       |
| skewX(*angle*)                  | 定义 2D 倾斜转换，沿着 X 轴。            |
| skewY(*angle*)                  | 定义 2D 倾斜转换，沿着 Y 轴。            |

## 3D转换

### 属性

| 属性                                                         | 描述                                 | **CSS** |
| ------------------------------------------------------------ | ------------------------------------ | ------- |
| [transform](https://www.w3cschool.cn/cssref/css3-pr-transform.html) | 向元素应用 2D 或 3D 转换。           | 3       |
| [transform-origin](https://www.w3cschool.cn/cssref/css3-pr-transform-origin.html) | 允许你改变被转换元素的位置。         | 3       |
| [transform-style](https://www.w3cschool.cn/cssref/css3-pr-transform-style.html) | 规定被嵌套元素如何在 3D 空间中显示。 | 3       |
| [perspective](https://www.w3cschool.cn/cssref/css3-pr-perspective.html) | 规定 3D 元素的透视效果。             | 3       |
| [perspective-origin](https://www.w3cschool.cn/cssref/css3-pr-perspective-origin.html) | 规定 3D 元素的底部位置。             | 3       |
| [backface-visibility](https://www.w3cschool.cn/cssref/css3-pr-backface-visibility.html) | 定义元素在不面对屏幕时是否可见。     | 3       |

### 方法

| 函数                                                         | 描述                                          |
| ------------------------------------------------------------ | --------------------------------------------- |
| matrix3d(*n***,***n***,** *n***,***n***,***n***,***n* **,***n***,***n***,***n* **,***n***,***n***,***n***,** *n***,***n***,***n***,***n* ) | 定义 3D 转换**，**使用 16 个值的 4x4 矩阵。   |
| translate3d(*x***,***y***,***z*)                             | 定义 3D 转化。                                |
| translateX(*x*)                                              | 定义 3D 转化**，**仅使用用于 X 轴的值。       |
| translateY(*y*)                                              | 定义 3D 转化**，**仅使用用于 Y 轴的值。       |
| translateZ(*z*)                                              | 定义 3D 转化**，**仅使用用于 Z 轴的值。       |
| scale3d(*x***,***y***,***z*)                                 | 定义 3D 缩放转换。                            |
| scaleX(*x*)                                                  | 定义 3D 缩放转换**，**通过给定一个 X 轴的值。 |
| scaleY(*y*)                                                  | 定义 3D 缩放转换**，**通过给定一个 Y 轴的值。 |
| scaleZ(*z*)                                                  | 定义 3D 缩放转换**，**通过给定一个 Z 轴的值。 |
| rotate3d(*x***,***y***,***z***,***angle*)                    | 定义 3D 旋转。                                |
| rotateX(*angle*)                                             | 定义沿 X 轴的 3D 旋转。                       |
| rotateY(*angle*)                                             | 定义沿 Y 轴的 3D 旋转。                       |
| rotateZ(*angle*)                                             | 定义沿 Z 轴的 3D 旋转。                       |
| perspective(*n*)                                             | 定义 3D 转换元素的透视视图。                  |

## 过渡

CSS3中，我们为了添加某种效果可以从一种样式转变到另一个的时候，无需使用Flash动画或JavaScript。

### 如何工作

CSS3 过渡是元素从一种样式逐渐改变为另一种的效果。

要实现这一点，必须规定两项内容：

- 指定要添加效果的CSS属性
- 指定效果的持续时间。

```html
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8"> 
<title>W3Cschool教程(w3cschool.cn)</title>
<style> 
div {
    width: 100px;
    height: 100px;
    background: red;
    -webkit-transition: width 2s, height 2s, -webkit-transform 2s; /* For Safari 3.1 to 6.0 */
    transition: width 2s, height 2s, transform 2s;
}

div:hover {
    width: 200px;
    height: 200px;
    -webkit-transform: rotate(180deg); /* Chrome, Safari, Opera */
    transform: rotate(180deg);
}
</style>
</head>
<body>
<p><b>注意：</b>该实例无法在 Internet Explorer 9 及更早 IE 版本上工作。</p>

<div>鼠标移动到 div 元素上，查看过渡效果。</div>
</body>
</html>
```

### 多项改变

要添加多个样式的变换效果，添加的属性由逗号分隔：

```css
div 
{ 
transition: width 2s, height 2s, transform 2s; 
-webkit-transition: width 2s, height 2s, -webkit-transform 2s; 
} 
```

### 属性

| 属性                                                         | 描述                                         | CSS  |
| ------------------------------------------------------------ | -------------------------------------------- | ---- |
| [transition](https://www.w3cschool.cn/cssref/css3-pr-transition.html) | 简写属性，用于在一个属性中设置四个过渡属性。 | 3    |
| [transition-property](https://www.w3cschool.cn/cssref/css3-pr-transition-property.html) | 规定应用过渡的 CSS 属性的名称。              | 3    |
| [transition-duration](https://www.w3cschool.cn/cssref/css3-pr-transition-duration.html) | 定义过渡效果花费的时间。默认是 0。           | 3    |
| [transition-timing-function](https://www.w3cschool.cn/cssref/css3-pr-transition-timing-function.html) | 规定过渡效果的时间曲线。默认是 "ease"。      | 3    |
| [transition-delay](https://www.w3cschool.cn/cssref/css3-pr-transition-delay.html) | 规定过渡效果何时开始。默认是 0。             | 3    |

```css
div 
{ 
transition-property: width; 
transition-duration: 1s; 
transition-timing-function: linear; 
transition-delay: 2s; 
/* Safari */ 
-webkit-transition-property:width; 
-webkit-transition-duration:1s; 
-webkit-transition-timing-function:linear; 
-webkit-transition-delay:2s; 
}
```

## 动画

CSS3，我们可以创建动画，它可以取代许多网页动画图像，Flash动画，和JAVAScripts。

## @keyframs 规则

@keyframes规则是创建动画

@keyframes规则内指定一个CSS样式和动画将逐步从目前的样式更改为新的样式

```css
@keyframes myfirst
{
from {background: red;}
to {background: yellow;}
}

@-webkit-keyframes myfirst /* Safari and Chrome */
{
from {background: red;}
to {background: yellow;}
}
```

### 动画规则

当在@keyframe创建动画，把它绑定到一个选择器，否则动画不会有任何效果

指定至少这两个CSS3的动画属性绑定向一个选择器：

- 规定动画的名称
- 规定动画的时长

```css
div
{
	width:100px;
	height:100px;
	background:red;
	animation:myfirst 5s;
	-webkit-animation:myfirst 5s; /* Safari and Chrome */
}

@keyframes myfirst
{
	from {background:red;}
	to {background:yellow;}
}

@-webkit-keyframes myfirst /* Safari and Chrome */
{
	from {background:red;}
	to {background:yellow;}
}
```

**注意:** 您必须定义动画的名称和动画的持续时间。如果省略的持续时间，动画将无法运行，因为默认值是0

### 属性

| 属性                                                         | 描述                                                     | CSS  |
| ------------------------------------------------------------ | -------------------------------------------------------- | ---- |
| [@keyframes](https://www.w3cschool.cn/cssref/css3-pr-animation-keyframes.html) | 规定动画。                                               | 3    |
| [animation](https://www.w3cschool.cn/cssref/css3-pr-animation.html) | 所有动画属性的简写属性，除了 animation-play-state 属性。 | 3    |
| [animation-name](https://www.w3cschool.cn/cssref/css3-pr-animation-name.html) | 规定 @keyframes 动画的名称。                             | 3    |
| [animation-duration](https://www.w3cschool.cn/cssref/css3-pr-animation-duration.html) | 规定动画完成一个周期所花费的秒或毫秒。默认是 0。         | 3    |
| [animation-timing-function](https://www.w3cschool.cn/cssref/css3-pr-animation-timing-function.html) | 规定动画的速度曲线。默认是 "ease"。                      | 3    |
| [animation-delay](https://www.w3cschool.cn/cssref/css3-pr-animation-delay.html) | 规定动画何时开始。默认是 0。                             | 3    |
| [animation-iteration-count](https://www.w3cschool.cn/cssref/css3-pr-animation-iteration-count.html) | 规定动画被播放的次数。默认是 1。                         | 3    |
| [animation-direction](https://www.w3cschool.cn/cssref/css3-pr-animation-direction.html) | 规定动画是否在下一周期逆向地播放。默认是 "normal"。      | 3    |
| [animation-play-state](https://www.w3cschool.cn/cssref/css3-pr-animation-play-state.html) | 规定动画是否正在运行或暂停。默认是 "running"。           | 3    |

## 多列

通过 CSS3，您能够创建多个列来对文本进行布局 

- column-count
- column-gap
- column-rule
- column-rule-color
- column-rule-style
- column-rule-width
- column-width

### 创建多列

column-count属性指定元素的列数应分为几列

```css
div
{
-moz-column-count:3; /* Firefox */
-webkit-column-count:3; /* Safari and Chrome */
column-count:3;
}
```

### 指定列中间的间距

column-gap属性指定的列之间的间距

```css
.newspaper
{
	-moz-column-count:3; /* Firefox */
	-webkit-column-count:3; /* Safari and Chrome */
	column-count:3;

	-moz-column-gap:40px; /* Firefox */
	-webkit-column-gap:40px; /* Safari and Chrome */
	column-gap:40px;
}
```

### 列规则

column-rule属性设置列之间的宽度，样式和颜色

```css
.newspaper
{
	-moz-column-count:3; /* Firefox */
	-webkit-column-count:3; /* Safari and Chrome */
	column-count:3;

	-moz-column-gap:40px; /* Firefox */
	-webkit-column-gap:40px; /* Safari and Chrome */
	column-gap:40px;

	-moz-column-rule:4px outset #ff00ff; /* Firefox */
	-webkit-column-rule:4px outset #ff00ff; /* Safari and Chrome */
	column-rule:4px outset #ff00ff;
}
```

### 属性

| 属性                                                         | 说明                             | CSS  |
| ------------------------------------------------------------ | -------------------------------- | ---- |
| [column-count](https://www.w3cschool.cn/cssref/css3-pr-column-count.html) | 指定元素应分为的列数             | 3    |
| [column-fill](https://www.w3cschool.cn/cssref/css3-pr-column-fill.html) | 指定如何填充列                   | 3    |
| [column-gap](https://www.w3cschool.cn/cssref/css3-pr-column-gap.html) | 指定列之间差距                   | 3    |
| [column-rule](https://www.w3cschool.cn/cssref/css3-pr-column-rule.html) | 一个用于设置所有列规则的简写属性 | 3    |
| [column-rule-color](https://www.w3cschool.cn/cssref/css3-pr-column-rule-color.html) | 指定的列之间颜色规则             | 3    |
| [column-rule-style](https://www.w3cschool.cn/cssref/css3-pr-column-rule-style.html) | 指定的列之间的样式规则           | 3    |
| [column-rule-width](https://www.w3cschool.cn/cssref/css3-pr-column-rule-width.html) | 指定的列之间的宽度规则           | 3    |
| [column-span](https://www.w3cschool.cn/cssref/css3-pr-column-span.html) | 指定一个元素应该横跨多少列       | 3    |
| [column-width](https://www.w3cschool.cn/cssref/css3-pr-column-width.html) | 指定列的宽度                     | 3    |
| [columns](https://www.w3cschool.cn/cssref/css3-pr-columns.html) | 缩写属性设置列宽和列数           | 3    |

## 用户界面

在 CSS3 中, 增加了一些新的用户界面特性来调整元素尺寸，框尺寸和外边框

- resize
- box-sizing
- outline-offset

### 调整尺寸（resizing）

CSS3中，resize属性指定一个元素是否应该由用户去调整大小

```css
div
{
    resize:both;
    overflow:auto;
}
```

### 方框大小调整

box-sizing 属性允许您以确切的方式定义适应某个区域的具体内容

```css
div
{
    box-sizing:border-box;
    -moz-box-sizing:border-box; /* Firefox */
    width:50%;
    float:left;
}
```

### 外形修饰（outline-offset）

outline-offset 属性对轮廓进行偏移，并在超出边框边缘的位置绘制轮廓

轮廓与边框有两点不同：

- 轮廓不占用空间
- 轮廓可能是非矩形

```css
div
{
    border:2px solid black;
    outline:2px solid red;
    outline-offset:15px;
}
```

### 新的用户界面特性

| 属性                                                         | 说明                                                         | CSS  |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ---- |
| [appearance](https://www.w3cschool.cn/cssref/css3-pr-appearance.html) | 允许您使一个元素的外观像一个标准的用户界面元素               | 3    |
| [box-sizing](https://www.w3cschool.cn/cssref/css3-pr-box-sizing.html) | 允许你以适应区域而用某种方式定义某些元素                     | 3    |
| [icon](https://www.w3cschool.cn/cssref/css3-pr-icon.html)    | Provides the author the ability to style an element with an iconic equivalent | 3    |
| [nav-down](https://www.w3cschool.cn/cssref/css3-pr-nav-down.html) | 指定在何处使用箭头向下导航键时进行导航                       | 3    |
| [nav-index](https://www.w3cschool.cn/cssref/css3-pr-nav-index.html) | 指定一个元素的Tab的顺序                                      | 3    |
| [nav-left](https://www.w3cschool.cn/cssref/css3-pr-nav-left.html) | 指定在何处使用左侧的箭头导航键进行导航                       | 3    |
| [nav-right](https://www.w3cschool.cn/cssref/css3-pr-nav-right.html) | 指定在何处使用右侧的箭头导航键进行导航                       | 3    |
| [nav-up](https://www.w3cschool.cn/cssref/css3-pr-nav-up.html) | 指定在何处使用箭头向上导航键时进行导航                       | 3    |
| [outline-offset](https://www.w3cschool.cn/cssref/css3-pr-outline-offset.html) | 外轮廓修饰并绘制超出边框的边缘                               | 3    |
| [resize](https://www.w3cschool.cn/cssref/css3-pr-resize.html) | 指定一个元素是否是由用户调整大小                             | 3    |

## 图片

### 圆角图片

```css
img {
    border-radius: 8px;
}
```

### 椭圆形图片

```css
img {
    border-radius: 50%;
}
```

### 响应式图片

响应式图片会自动适配各种尺寸的屏幕

```css
img {
    max-width: 100%;
    height: auto;
}
```

### 卡片式图片

```css
div.polaroid {
    width: 80%;
    background-color: white;
    box-shadow: 0 4px 8px 0 rgba(0, 0, 0, 0.2), 0 6px 20px 0 rgba(0, 0, 0, 0.19);
}

img {width: 100%}

div.container {
    text-align: center;
    padding: 10px 20px;
}
```

### 图片滤镜

CSS `filter` 属性用为元素添加可视效果 (例如：模糊与饱和度)

```css
img {
    width: 33%;
    height: auto;
    float: left; 
    max-width: 235px;
}

.blur {-webkit-filter: blur(4px);filter: blur(4px);}
.brightness {-webkit-filter: brightness(250%);filter: brightness(250%);}
.contrast {-webkit-filter: contrast(180%);filter: contrast(180%);}
.grayscale {-webkit-filter: grayscale(100%);filter: grayscale(100%);}
.huerotate {-webkit-filter: hue-rotate(180deg);filter: hue-rotate(180deg);}
.invert {-webkit-filter: invert(100%);filter: invert(100%);}
.opacity {-webkit-filter: opacity(50%);filter: opacity(50%);}
.saturate {-webkit-filter: saturate(7); filter: saturate(7);}
.sepia {-webkit-filter: sepia(100%);filter: sepia(100%);}
.shadow {-webkit-filter: drop-shadow(8px 8px 10px green);filter: drop-shadow(8px 8px 10px green);}
```

### 响应式图片相册

```css
.responsive {
    padding: 0 6px;
    float: left;
    width: 24.99999%;
}

@media only screen and (max-width: 700px){
    .responsive {
        width: 49.99999%;
        margin: 6px 0;
    }
}

@media only screen and (max-width: 500px){
    .responsive {
        width: 100%;
    }
}
```

### Modal(模态)

```css
// 获取模态窗口
var modal = document.getElementById('myModal');

// 获取图片模态框，alt 属性作为图片弹出中文本描述
var img = document.getElementById('myImg');
var modalImg = document.getElementById("img01");
var captionText = document.getElementById("caption");
img.onclick = function(){
    modal.style.display = "block";
    modalImg.src = this.src;
    modalImg.alt = this.alt;
    captionText.innerHTML = this.alt;
}

// Get the <span> element that closes the modal
var span = document.getElementsByClassName("close")[0];

// When the user clicks on <span> (x), close the modal
span.onclick = function() { 
    modal.style.display = "none";
}
```

## 按钮

### 自定义按钮样式

```css
.button {
    background-color: #4CAF50;
    border: none;
    color: white;
    padding: 15px 32px;
    text-align: center;
    text-decoration: none;
    display: inline-block;
    font-size: 16px;
    margin: 4px 2px;
    cursor: pointer;
	border-radius:10px;
}
```

### 按钮边框颜色

可以使用 `border` 属性设置按钮边框颜色

```css
.button1 {
    background-color: white;
    color: black;
   border: 2px solid #4CAF50; /* Green */
}
```

### 鼠标悬停按钮样式

```css
.button {
    -webkit-transition-duration: 0.4s; /* Safari */
   transition-duration: 0.4s;
}

.button:hover {
   background-color: #4CAF50; /* Green */
    color: white;
}
```

### 按钮阴影

可以使用 `box-shadow` 属性来为按钮添加阴影

```css
.button1 {
    box-shadow: 0 8px 16px 0 rgba(0,0,0,0.2), 0 6px 20px 0rgba(0,0,0,0.19);
}

.button2:hover {
    box-shadow: 0 12px16px 0 rgba(0,0,0,0.24), 0 17px 50px 0 rgba(0,0,0,0.19);
}
```

### 禁用按钮

可以使用 `opacity` 属性为按钮添加透明度 (看起来类似"disabled" 属性效果)

**提示:** 我么可以添加 `cursor` 属性并设置为"not-allowed" 来设置一个禁用的图片

```css
.disabled {
    opacity: 0.6;
    cursor: not-allowed;
}
```

### 按钮动画

```css
.button {
  display: inline-block;
  border-radius: 4px;
  background-color: #f4511e;
  border: none;
  color: #FFFFFF;
  text-align: center;
  font-size: 28px;
  padding: 20px;
  width: 200px;
  transition: all 0.5s;
  cursor: pointer;
  margin: 5px;
}

.button span {
  cursor: pointer;
  display: inline-block;
  position: relative;
  transition: 0.5s;
}

.button span:after {
  content: '»';
  position: absolute;
  opacity: 0;
  top: 0;
  right: -20px;
  transition: 0.5s;
}

.button:hover span {
  padding-right: 25px;
}

.button:hover span:after {
  opacity: 1;
  right: 0;
}
```

