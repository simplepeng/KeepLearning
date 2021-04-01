# HenCoder-5期-学习笔记

## 02-HTTP基础

HTTP是什么？Hyper Text Transfer Protocol，超文本传输协议。

超文本是什么？在电脑中显示的，含有可以指向其他文本链接的文本。

HTTP的工作方式：发送请求 ---->  接受响应

请求报文：

* 请求行：method-path-http version 对应：GET /users HTTP/1.1
* 请求头：
  * Host: api.github.com
  * Content-Type: text/plain
  * ..... 
* Body

响应报文:

* 状态行：HTTP/1.1 200 OK 
* Headers
* Body

请求方式：

* GET：获取资源，没有请求的Body，幂等
* POST： 增加或修改资源，有Body
* PUT：修改资源，有Body ，幂等
* DELETE：删除资源，没有Body，幂等
* HEAD：跟GET类似，但是没有响应Body。主要用来获取信息 
* ..... 

状态码：对结果做出类型化描述，例如：获取成功，内容未找到

* 1xx：临时性消息
* 2xx：成功 
* 3xx：重定向
* 4xx：客户端错误
* 5xx：服务器错误