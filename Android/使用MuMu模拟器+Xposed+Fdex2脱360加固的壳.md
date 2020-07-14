# 使用MuMu模拟器+Xposed+Fdex2脱360加固的壳

## 资源下载

* [MuMu模拟器](http://mumu.163.com/)
* [Xposed](https://repo.xposed.info/)
* [Fdex2](https://share.weiyun.com/Ljo5h5jo)

## 安装流程

先安装好`MuMu模拟器`，在模拟器设置里面`开启ROOT权限`，并且在系统的设置里面先关闭`兼容模式`

![](https://raw.githubusercontent.com/simplepeng/ImageRepo/master/android/mumu_root.png)

接着安装`Xposed`，安装适合系统版本的Xposed插件。

![](https://raw.githubusercontent.com/simplepeng/ImageRepo/master/android/xposed_installer.png)

安装好再安装`Fdex2`，然后在`Xposed`的模块管理界面打开`Fdex2`的模板，最后记得重启系统让模块生效。

![](https://raw.githubusercontent.com/simplepeng/ImageRepo/master/android/xposed_fdex2.png)

## 开始dump dex

启动`Fdex2`，选择要抓dex的App，弹框会提示dump出来的dex会保持到哪个文件目录下，点击`OK`关闭弹框。

![](https://raw.githubusercontent.com/simplepeng/ImageRepo/master/android/dump_dex.png)

接着打开我们的目标App，待启动完成后，就可以到相应的目录下看看是否dump出了dex，如果目标App只支持arm架构，那么我们还是可以在系统设置里把`兼容模式打开`。

我们可以在模拟器安装一个`RE文件浏览器`查看目录下是否有dex，也可以用`adb`命令查看。

![](https://raw.githubusercontent.com/simplepeng/ImageRepo/master/android/dex_list.png)

接着我们只需要用`adb pull`命令导出这些dex文件到桌面，用`dex2jar`，`jd-gui`等工具就可以直接看源码了，当然很多App都做了混淆，这就要看自己的功力了。这里还有一个小技巧，一般dex文件最大的那个可能就是360加固了的那个假dex，第二大的就是真实App代码的那个dex，当然这也不绝对，所以我们还是把所有的dex文件都导出来看看。

`dex2jar`后，可以直接使用`jd-gui`工具查看源码，这些工具的下载链接会放到末尾，如果是Mac安装就更简单了，直接使用`brew`就行了。

```shell
d2j-dex2jar 5.dex
//dex2jar 5.dex -> ./5-dex2jar.jar
```

使用`jd-gui`打开5-dex2jar.jar

![](https://raw.githubusercontent.com/simplepeng/ImageRepo/master/android/dex2jar_soures.png)

* [dex2jar](https://github.com/pxb1988/dex2jar)
* [jd-gui](https://github.com/java-decompiler/jd-gui/releases)

