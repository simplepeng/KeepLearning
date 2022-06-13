# 简介

Shell 是一个用 C 语言编写的程序，它是用户使用 Linux 的桥梁。Shell 既是一种命令语言，又是一种程序设计语言。

Shell 是指一种应用程序，这个应用程序提供了一个界面，用户通过这个界面访问操作系统内核的服务。

Ken Thompson 的 sh 是第一种 Unix Shell，Windows Explorer 是一个典型的图形界面 Shell。

## Shell 脚本

Shell 脚本（shell script），是一种为 shell 编写的脚本程序。

业界所说的 shell 通常都是指 shell 脚本，但读者朋友要知道，shell 和 shell script 是两个不同的概念。

由于习惯的原因，简洁起见，本文出现的 "shell编程" 都是指 shell 脚本编程，不是指开发 shell 自身。

Linux Shell 脚本以`.sh`结尾

## Hello World

```shell
#!/bin/bash

echo "hello world"
```

> 执行shell脚本首先要使脚本拥有可执行权限
>
> sudo chmod 775 helloworld.sh
>
> 执行shell脚本
>
>  ./helloworld.sh
>
> 或者
>
> sh helloworld.sh //这种方式不需要修改可执行权限

`#!`是一个约定的标记，它告诉系统这个脚本需要什么解释器来执行，即使用哪一种 Shell 执行该脚本。

`echo`命令用于向窗口输出文本。