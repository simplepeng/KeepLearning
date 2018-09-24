# 新元素

## 画布 元素（Canvas）

<canvas> 标签定义图形，比如图表和其他图像。该标签基于 JavaScript 的绘图 API

## 多媒体元素

* <audio> 定义音频内容
* <video> 定义视频（video 或者 movie）
* <source>  定义多媒体资源 <video> 和 <audio>
* <embed> 定义嵌入的内容，比如插件
* <track> 为诸如 <video> 和 <audio> 元素之类的媒介规定外部文本轨道

## 表单元素

* <datalist>  定义选项列表。请与 input 元素配合使用该元素，来定义 input 可能的值
* <keygen> 规定用于表单的密钥对生成器字段
* <output> 定义不同类型的输出，比如脚本的输出

## 语义和结构元素

* <article> 定义页面独立的内容区域

## 已移除的元素

- &lt;acronym&gt;
- &lt;applet&gt;
- &lt;basefont&gt;
- &lt;big&gt;
- &lt;center&gt;
- &lt;dir&gt;
- &lt;font&gt;
- &lt;frame&gt;
- &lt;frameset&gt;
- &lt;noframes&gt;
- &lt;strike&gt;
- &lt;tt&gt;

# Canvas

<canvas>元素是HTML5中的新元素，通过使用该元素，你可以在网页中绘制所需的图形

标签只是图形容器，您必须使用脚本来绘制图形,通常是*JavaScript*

## 创建canvas

一个画布在网页中是一个矩形框，通过 <canvas> 元素来绘制

默认情况下 <canvas> 元素没有边框和内容

```html
<canvas id="myCanvas" width="200" height="100"></canvas>
```

**使用样式添加边框**

```html
<canvas id="myCanvas" width="200" height="100" 
style="border:1px solid #000000;"> 
</canvas> 
```

## 使用JavaScript绘制图像

canvas 元素本身是没有绘图能力的。所有的绘制工作必须在 JavaScript 内部完成

```html
<script> 
//找到 <canvas> 元素
var c=document.getElementById("myCanvas");
//创建 context 对象
var ctx=c.getContext("2d");
//绘制一个红色的矩形
ctx.fillStyle="#FF0000"; 
ctx.fillRect(0,0,150,75); 
</script> 
```

# 内联 SVG

## 什么是 svg

- SVG 指可伸缩矢量图形 (Scalable Vector Graphics)
- SVG 用于定义用于网络的基于矢量的图形
- SVG 使用 XML 格式定义图形
- SVG 图像在放大或改变尺寸的情况下其图形质量不会有损失
- SVG 是万维网联盟的标准
- SVG 与 DOM 和 XSL 之类的 W3C 标准是一个整体

## svg的优势

与其他图像格式相比（比如 JPEG 和 GIF），使用 SVG 的优势在于

- SVG 图像可通过文本编辑器来创建和修改
- SVG 图像可被搜索、索引、脚本化或压缩
- SVG 是可伸缩的
- SVG 图像可在任何的分辨率下被高质量地打印
- SVG 可在图像质量不下降的情况下被放大

## 把svg嵌入html

```html
<!DOCTYPE html>
<html>
<body>

<svg xmlns="http://www.w3.org/2000/svg" version="1.1" height="190">
  <polygon points="100,10 40,180 190,60 10,60 160,180"
  style="fill:lime;stroke:purple;stroke-width:5;fill-rule:evenodd;">
</svg>

</body>
</html>
```

# 数学标记语言（MathML）

[MathML](https://baike.baidu.com/item/%E6%95%B0%E5%AD%A6%E7%BD%AE%E6%A0%87%E8%AF%AD%E8%A8%80/656305?fr=aladdin&fromid=10813966&fromtitle=MathML) 与 HTML相似度很高，但是比较繁琐。它继承了角括号和双标签（<标签>内容</标签>）的用法

HTML5 可以在文档中使用 MathML 元素，对应的标签是 <math>...</math>

MathML 是数学标记语言，是一种基于XML（标准通用标记语言的子集）的标准，用来在互联网上书写数学符号和公式的置标语言

```html
<!DOCTYPE html><html>
   <head>
      <meta charset="UTF-8">
      <title>W3Cschool在线教程(w3cschool.cn)</title>
   </head>
	
   <body>
	
      <math xmlns="http://www.w3.org/1998/Math/MathML">
		
         <mrow>
            <msup><mi>a</mi><mn>2</mn></msup>
            <mo>+</mo>
				
            <msup><mi>b</mi><mn>2</mn></msup>
            <mo>=</mo>
				
            <msup><mi>c</mi><mn>2</mn></msup>
         </mrow>
			
      </math>
		
   </body>
</html>
```

# 拖放

# 地理定位（Geolocation）

HTML5 Geolocation（地理定位）用于定位用户的位置

Geolocation 通过请求一个位置信息，用户同意后，浏览器会返回一个包含经度和维度的位置信息

## 使用地理定位

请使用 getCurrentPosition() 方法来获得用户的位置

```javascript
<script>
var x=document.getElementById("demo");
function getLocation()
  {
  if (navigator.geolocation)
    {
    navigator.geolocation.getCurrentPosition(showPosition);
    }
  else{x.innerHTML="该浏览器不支持获取地理位置。";}
  }
function showPosition(position)
  {
  x.innerHTML="Latitude: " + position.coords.latitude + 
  "<br>Longitude: " + position.coords.longitude; 
  }
</script>
```

## 处理错误和拒绝

getCurrentPosition() 方法的第二个参数用于处理错误。它规定当获取用户位置失败时运行的函数

```javascript
function showError(error)
  {
  switch(error.code) 
    {
    case error.PERMISSION_DENIED:
      x.innerHTML="用户拒绝对获取地理位置的请求。"
      break;
    case error.POSITION_UNAVAILABLE:
      x.innerHTML="位置信息是不可用的。"
      break;
    case error.TIMEOUT:
      x.innerHTML="请求用户地理位置超时。"
      break;
    case error.UNKNOWN_ERROR:
      x.innerHTML="未知错误。"
      break;
    }
  }
```

## getCurrentPosition 返回数据

| 属性                    | 描述                   |
| ----------------------- | ---------------------- |
| coords.latitude         | 十进制数的纬度         |
| coords.longitude        | 十进制数的经度         |
| coords.accuracy         | 位置精度               |
| coords.altitude         | 海拔，海平面以上以米计 |
| coords.altitudeAccuracy | 位置的海拔精度         |
| coords.heading          | 方向，从正北开始以度计 |
| coords.speed            | 速度，以米/每秒计      |
| timestamp               | 响应的日期/时间        |

# 视频（video)

 ```html
<video width="320" height="240" controls>
  <source src="movie.mp4" type="video/mp4">
  <source src="movie.ogg" type="video/ogg">
您的浏览器不支持Video标签。
</video>
 ```

元素支持多个 元素. 元素可以链接不同的视频文件。浏览器将使用第一个可识别的格式

## 使用DOM进行控制 video 标签

```html
<!DOCTYPE html> 
<html> 
<body> 

<div style="text-align:center"> 
  <button onclick="playPause()">播放/暂停</button> 
  <button onclick="makeBig()">放大</button>
  <button onclick="makeSmall()">缩小</button>
  <button onclick="makeNormal()">普通</button>
  <br> 
  <video id="video1" width="420">
    <source src="/statics/demosource/mov_bbb.mp4" type="video/mp4">
    <source src="/statics/demosource/mov_bbb.ogg" type="video/ogg">
    您的浏览器不支持 HTML5 video 标签。
  </video>
</div> 

<script> 
var myVideo=document.getElementById("video1"); 

function playPause()
{ 
if (myVideo.paused) 
  myVideo.play(); 
else 
  myVideo.pause(); 
} 

function makeBig()
{ 
myVideo.width=560; 
} 

function makeSmall()
{ 
myVideo.width=320; 
} 

function makeNormal()
{ 
myVideo.width=420; 
} 
</script> 

</body> 
</html>
```

# 音频（Audio）

```html
<audio controls> 
  <source src="horse.ogg" type="audio/ogg"> 
  <source src="horse.mp3" type="audio/mpeg"> 
您的浏览器不支持 audio 元素。 
</audio>
```

 [control 属性](https://www.w3cschool.cn/jsref/prop-audio-controls.html)供添加播放、暂停和音量控件

在<audio> 与 </audio> 之间你需要插入浏览器不支持的<audio>元素的提示文本 

<audio> 元素允许使用多个 <source> 元素. <source> 元素可以链接不同的音频文件，浏览器将使用第一个支持的音频文件

# Input 类型

## 新的input类型

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

## input 类型：color

从拾色器中选择一个颜色

```html
选择你喜欢的颜色: <input type="color" name="favcolor">
```

## input 类型：date

```html
生日: <input type="date" name="bday">
```

## input 类型：datetime

datetime 类型允许你选择一个日期（UTC 时间）

```html
生日 (日期和时间): <input type="datetime" name="bdaytime">
```

## input类型：datetime-local

datetime-local 类型允许你选择一个日期和时间 (无时区)

```html
生日 (日期和时间): <input type="datetime-local" name="bdaytime">
```

## input类型：email

email 类型用于应该包含 e-mail 地址的输入域

在提交表单时，会自动验证 email 域的值是否合法有效

```html
E-mail: <input type="email" name="email">
```

## input 类型：month

month 类型允许你选择一个月份

```html
生日 (月和年): <input type="month" name="bdaymonth">
```

## input类型：number

number 类型用于应该包含数值的输入域

您还能够设定对所接受的数字的限定

```html
数量 ( 1 到 5 之间 ): <input type="number" name="quantity" min="1" max="5">
```

- max- 规定允许的最大值
- min - 规定允许的最小值
- step - 规定合法的数字间隔（如果 step="3"，则合法的数是 -3,0,3,6 等）
- value - 规定默认值

## input类型：range

range 类型用于应该包含一定范围内数字值的输入域

range 类型显示为滑动条

```html
<input type="range" name="points" min="1" max="10">
```

- max - 规定允许的最大值
- min - 规定允许的最小值
- step - 规定合法的数字间隔
- value - 规定默认值

## input 类型：search

search 类型用于搜索域，比如站点搜索或 Google 搜索

```html
Search Google: <input type="search" name="googlesearch">
```

## input 类型：tel

 ```html
电话号码: <input type="tel" name="usrtel">
 ```

## input 类型：time

time 类型允许你选择一个时间

```html
选择时间: <input type="time" name="usr_time">
```

## input 类型：url

url 类型用于应该包含 URL 地址的输入域

在提交表单时，会自动验证 url 域的值

```html
添加您的主页: <input type="url" name="homepage">
```

## input 类型：week

week 类型允许你选择周和年

```html
选择周: <input type="week" name="week_year">
```

# 表单元素

HTML5 有以下新的表单元素:

- [datalist](https://www.w3cschool.cn/htmltags/tag-datalist.html)
- [keygen](https://www.w3cschool.cn/htmltags/tag-keygen.html)
- [output](https://www.w3cschool.cn/html5/html5-output.html)

## detalist 元素

<datalist> 元素规定输入域的选项列表

<datalist> 属性规定 form 或 input 域应该拥有自动完成功能。当用户在自动完成域中开始输入时，浏览器应该在该域中显示填写的选项

使用 <input> 元素的列表属性与 <datalist> 元素绑定

```html
<!DOCTYPE html>
<html>
<head> 
<meta charset="utf-8"> 
<title>W3Cschool(w3cschool.cn)</title> 
</head>
<body>

<form action="/statics/demosource/demo-form.php" method="get">
<input list="browsers" name="browser">
<datalist id="browsers">
  <option value="Internet Explorer">
  <option value="Firefox">
  <option value="Chrome">
  <option value="Opera">
  <option value="Safari">
</datalist>
<input type="submit">
</form>

<p><strong>注意:</strong> Internet Explorer 9（更早IE版本），Safari不支持 datalist 标签。</p>

</body>
</html>
```

## keygen 元素

<keygen> 元素的作用是提供一种验证用户的可靠方法

<keygen>标签规定用于表单的密钥对生成器字段

当提交表单时，会生成两个键，一个是私钥，一个公钥

私钥（private key）存储于客户端，公钥（public key）则被发送到服务器。公钥可用于之后验证用户的客户端证书（client certificate）

```html
<form action="demo_keygen.asp" method="get">
用户名: <input type="text" name="usr_name">
加密: <keygen name="security">
<input type="submit">
</form>
```

## output 元素

<output> 元素用于不同类型的输出，比如计算或脚本输出

```html
<form oninput="x.value=parseInt(a.value)+parseInt(b.value)">0
<input type="range" id="a" value="50">100 +
<input type="number" id="b" value="50">=
<output name="x" for="a b"></output>
</form>
```

# Web 存储

在HTML5之前，主要是使用cookies存储，cookies的缺点有：需要在请求头上带着数据，存储大小不过，在4k之内

HTML5 web 存储，一个比cookie更好的本地存储方式

## localStorage 和 sessionStorage

客户端存储数据的两个对象为:

- localStorage - 没有时间限制的数据存储
- sessionStorage - 针对一个 session 的数据存储

在使用 web 存储前,应检查浏览器是否支持 localStorage 和sessionStorage:  

```html
if(typeof(Storage)!=="undefined"){        
  // 是的! 支持 localStorage  sessionStorage 对象!         
  // 一些代码.....         
 }        
else{        
  // 抱歉! 不支持 web 存储。         
}
```

## localStorage 对象

localStorage 对象存储的数据没有时间限制。第二天、第二周或下一年之后，数据依然可用

```html
<!DOCTYPE html>
<html>
<head> 
<meta charset="utf-8"> 
<title>W3Cschool在线教程(w3cschool.cn)</title> 
</head>
<body>

<div id="result"></div>
<script>
if(typeof(Storage)!=="undefined")
{
  localStorage.sitename="W3Cschool在线教程";
  document.getElementById("result").innerHTML="网站名：" + localStorage.sitename;
}
else
{
  document.getElementById("result").innerHTML="对不起，您的浏览器不支持 web 存储。";
}
</script>

</body>
</html>
```

移除 localStorage 中的 "lastname" :

```html
localStorage.removeItem("lastname");
```

不管是 localStorage，还是 sessionStorage，可使用的API都相同，常用的有如下几个（以localStorage为例）：

- 保存数据：localStorage.setItem(key,value);
- 读取数据：localStorage.getItem(key);
- 删除单个数据：localStorage.removeItem(key);
- 删除所有数据：localStorage.clear();
- 得到某个索引的key：localStorage.key(index);

## sessionStorage  对象

sessionStorage 方法针对一个 session 进行数据存储。当用户关闭浏览器窗口后，数据会被删除。

```html
if (sessionStorage.clickcount) 
  { 
  sessionStorage.clickcount=Number(sessionStorage.clickcount)+1; 
  } 
else 
  { 
  sessionStorage.clickcount=1; 
  } 
document.getElementById("result").innerHTML="在这个会话中你已经点击了该按钮 " + sessionStorage.clickcount + " 次 ";
```

 # Web SQL

Web SQL 是在浏览器上模拟数据库，可以使用JS来操作SQL完成对数据的读写

Web SQL 数据库 API 并不是 HTML5 规范的一部分，但是它是一个独立的规范，引入了一组使用 SQL 操作客户端数据库的 APIs

## 核心方法

1. **openDatabase**：这个方法使用现有的数据库或者新建的数据库创建一个数据库对象
2. **transaction**：这个方法让我们能够控制一个事务，以及基于这种情况执行提交或者回滚。
3. **executeSql**：这个方法用于执行实际的 SQL 查询

## 打开数据库

使用 openDatabase() 方法来打开已存在的数据库，如果数据库不存在，则会创建一个新的数据库，使用代码如下

```ht
var db = openDatabase('mydb', '1.0', 'Test DB', 2 * 1024 * 1024);
```

openDatabase() 方法对应的五个参数说明：

1. 数据库名称
2. 版本号
3. 描述文本
4. 数据库大小
5. 创建回调

第五个参数，创建回调会在创建数据库后被调用

## 执行查询操作

```html
var db = openDatabase('mydb', '1.0', 'Test DB', 2 * 1024 * 1024);
db.transaction(function (tx) {  
   tx.executeSql('CREATE TABLE IF NOT EXISTS LOGS (id unique, log)');
});
```

## 插入数据

```javascript
var db = openDatabase('mydb', '1.0', 'Test DB', 2 * 1024 * 1024);
db.transaction(function (tx) {  
  tx.executeSql('CREATE TABLE IF NOT EXISTS LOGS (id unique, log)');
  tx.executeSql('INSERT INTO LOGS 
                        (id,log) VALUES (?, ?'), [e_id, e_log];
});
```

## 读取数据

```javascript
db.transaction(function (tx) {
   tx.executeSql('SELECT * FROM LOGS', [], function (tx, results) {
      var len = results.rows.length, i;
      msg = "查询记录条数: " + len + "";
      document.querySelector('#status').innerHTML +=  msg;
      for (i = 0; i < len; i++){
         alert(results.rows.item(i).log );
      }
	
   }, null);
});
```

## 删除记录

```javascript
db.transaction(function(tx) {
    tx.executeSql('DELETE FROM LOGS WHERE id=?', [id]);
});
```

## 更新记录

```javascript
db.transaction(function(tx) {
    tx.executeSql('UPDATE LOGS SET log=\'www.w3cschool.cn\' WHERE id=?', [id]);
});
```

# 应用程序缓存

使用 HTML5，通过创建 cache manifest 文件，可以轻松地创建 web 应用的离线版本。这意味着，你可以在没有网络连接的情况下进行访问

## 什么是应用程序缓存

HTML5 引入了应用程序缓存，这意味着 web 应用可进行缓存，并可在没有因特网连接时进行访问

应用程序缓存为应用带来三个优势：

1. 离线浏览 - 用户可在应用离线时使用它们
2. 速度 - 已缓存资源加载得更快
3. 减少服务器负载 - 浏览器将只从服务器下载更新过或更改过的资源

## Cache Manifest 基础

如需启用应用程序缓存，请在文档的<html> 标签中包含 [manifest 属性](https://www.w3cschool.cn/htmltags/att-html-manifest.html)

```html
<!DOCTYPE HTML>        
<html manifest="demo.appcache">        
...        
</html>
```

每个指定了 manifest 的页面在用户对其访问时都会被缓存。如果未指定 manifest 属性，则页面不会被缓存（除非在 manifest 文件中直接指定了该页面）

manifest 文件的建议的文件扩展名是：".appcache"

manifest 文件需要配置正确的 MIME-type，即 "text/cache-manifest"。必须在 web 服务器上进行配置

## Manifest 文件

manifest 文件是简单的文本文件，它告知浏览器被缓存的内容（以及不缓存的内容）

manifest 文件可分为三个部分：

- *CACHE MANIFEST* - 在此标题下列出的文件将在首次下载后进行缓存
- *NETWORK* - 在此标题下列出的文件需要与服务器的连接，且不会被缓存
- *FALLBACK* - 在此标题下列出的文件规定当页面无法访问时的回退页面（比如 404 页面）

### CACHE MAIFEST

第一行，CACHE MANIFEST，是必需的：

```
CACHE MANIFEST        
/theme.css        
/logo.gif        
/main.js
```

### NETWORK

下面的 NETWORK 小节规定文件 "login.php" 永远不会被缓存，且离线时是不可用的：

```
NETWORK:        
login.php
```

可以使用星号来指示所有其他其他资源/文件都需要因特网连接：

```
NETWORK:        
*
```

### FALLBACK

下面的 FALLBACK 小节规定如果无法建立因特网连接，则用 "offline.html" 替代 /html5/ 目录中的所有文件：

```
FALLBACK:       
/html/ /offline.html
```

**注意:** 第一个 URI 是资源，第二个是替补。

## 更新缓存

一旦应用被缓存，它就会保持缓存直到发生下列情况：

- 用户清空浏览器缓存
- manifest 文件被修改（参阅下面的提示）
- 由程序来更新应用缓存

# Web Workers

## 什么是 Web Workers

当在 HTML 页面中执行脚本时，页面的状态是不可响应的，直到脚本已完成

web worker 是运行在后台的 JavaScript，独立于其他脚本，不会影响页面的性能。您可以继续做任何愿意做的事情：点击、选取内容等等，而此时 web worker 在后台运行

## 检查浏览器是否支持Web Workers

在创建 web worker 之前，请检测用户的浏览器是否支持它

```javascript
if(typeof(Worker)!=="undefined")
   {
   // 是的! Web worker 支持!
   // 一些代码.....
   }
 else
   {
   // //抱歉! Web Worker 不支持
   } 
```

## 创建Web Worker 文件

必须为外部 JavaScript 文件

```javascript
var i=0;

 function timedCount()
 {
 i=i+1;
 postMessage(i);
 setTimeout("timedCount()",500);
 }

 timedCount();
```

## 创建 Web Worker 对象

下面的代码检测是否存在 worker，如果不存在，- 它会创建一个新的 web worker 对象，然后运行 "demo_workers.js" 中的代码

```javascript
 if(typeof(w)=="undefined")
   {
   w=new Worker("demo_workers.js");
   }
```

向 web worker 添加一个 "onmessage" 事件监听器

```javascript
 w.onmessage=function(event){
 document.getElementById("result").innerHTML=event.data;
 };
```

## 终止 Web Worker

当我们创建 web worker 对象后，它会继续监听消息（即使在外部脚本完成之后）直到其被终止为止

```javascript
 w.terminate(); 
```

## Web Worker 和 DOM

由于 web worker 位于外部文件中，它们无法访问下例 JavaScript 对象：

- [window 对象](https://www.w3cschool.cn/javascript_guide/javascript_guide-9f8e269x.html)
- [document 对象](https://www.w3cschool.cn/jsref/dom-obj-document.html)
- parent 对象


# WebSocket

WebSocket是HTML5开始提供的一种在单个 TCP 连接上进行全双工通讯的协议

在WebSocket API中，浏览器和服务器只需要做一个握手的动作，然后，浏览器和服务器之间就形成了一条快速通道。两者之间就直接可以数据互相传送

浏览器通过 JavaScript 向服务器发出建立 WebSocket 连接的请求，连接建立以后，客户端和服务器端就可以通过 TCP 连接直接交换数据

当你获取 Web Socket 连接后，你可以通过 **send()** 方法来向服务器发送数据，并通过 **onmessage** 事件来接收服务器返回的数据

```javascript
var Socket = new WebSocket(url, [protocal] );
```

第一个参数 url, 指定连接的 URL。第二个参数 protocol 是可选的，指定了可接受的子协议

## 属性

| Socket.readyState     | **readyState** 表示连接状态，可以是以下值：0 - 表示连接尚未建立。1 - 表示连接已建立，可以进行通信。2 - 表示连接正在进行关闭。3 - 表示连接已经关闭或者连接不能打开。 |
| --------------------- | ------------------------------------------------------------ |
| Socket.bufferedAmount | 只读属性 **bufferedAmount** 已被 send() 放入正在队列中等待传输，但是还没有发出的 UTF-8 文本字节数。 |

## 事件

| 事件    | 事件处理程序     | 描述                       |
| ------- | ---------------- | -------------------------- |
| open    | Socket.onopen    | 连接建立时触发             |
| message | Socket.onmessage | 客户端接收服务端数据时触发 |
| error   | Socket.onerror   | 通信发生错误时触发         |
| close   | Socket.onclose   | 连接关闭时触发             |

## 方法

| 方法           | 描述             |
| -------------- | ---------------- |
| Socket.send()  | 使用连接发送数据 |
| Socket.close() | 关闭连接         |

## 实例

```html
<!DOCTYPE HTML>
<html>
   <head>
   <meta charset="utf-8">
   <title>W3Cschool教程(w3cschool.cn)</title>
	
      <script type="text/javascript">
         function WebSocketTest()
         {
            if ("WebSocket" in window)
            {
               alert("您的浏览器支持 WebSocket!");
               
               // 打开一个 web socket
               var ws = new WebSocket("ws://localhost:9998/echo");
				
               ws.onopen = function()
               {
                  // Web Socket 已连接上，使用 send() 方法发送数据
                  ws.send("发送数据");
                  alert("数据发送中...");
               };
				
               ws.onmessage = function (evt) 
               { 
                  var received_msg = evt.data;
                  alert("数据已接收...");
               };
				
               ws.onclose = function()
               { 
                  // 关闭 websocket
                  alert("连接已关闭..."); 
               };
            }
            
            else
            {
               // 浏览器不支持 WebSocket
               alert("您的浏览器不支持 WebSocket!");
            }
         }
      </script>
		
   </head>
   <body>
   
      <div id="sse">
         <a href="javascript:WebSocketTest()">运行 WebSocket</a>
      </div>
      
   </body>
</html>
```

