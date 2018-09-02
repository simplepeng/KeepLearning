# MacOS 10.10 以上解决机械键盘按键无法识别

题主的配置是 MacBook Pro ，系统10.13，机械键盘高斯87

以前装的黑苹果，系统10.10，机械键盘可以完美使用，但是现在用了MacBook Pro机械键盘确有几个键无法识别出来，就是按了没有反应，这几个可恶的键就是"Esc","BackSpace","Tab"和"Space"，使用**Karabiner-EventView**可以看到这几个键是根本没有响应按键事件。

直到我发现GitHub有一个开源项目好像可以解决这个问题，先放出github的仓库地址

[](https://github.com/thefloweringash/iousbhiddriver-descriptor-override)

但是我按照文档中的步骤安装了驱动，并且在**/System/Library/Extensions**目录下也找到了相应的驱动文件，但是上面那个几键按了还是没有反应，李时珍的皮啊！！！

然后又继续在该项目的issue中找寻答案，这还真的找到了，天不亡我啊！

[](https://github.com/thefloweringash/iousbhiddriver-descriptor-override/issues/22)

文中的大概意思就是要禁用掉[System Integrity Protection](http://arstechnica.com/apple/2015/09/os-x-10-11-el-capitan-the-ars-technica-review/8/)(SIP-系统完整性保证)，好了，接下来就是详细步骤了。

## 禁用sip

1. 开机的过程中使劲command+r，其实只用按几次就可以了
2. 实用工具里面打开终端命令行
3. 输入**csrutil disable**然后回车，看到有success字符就行
4. 输入**reboot**，然后回车，这样电脑就重启了

## 安装Noppoo的兼容驱动

[](http://thefloweringash.github.io/iousbhiddriver-descriptor-override/)

到上面网站下载最新驱动的pkg文件，然后安装重启即可。

如果需要改键的下载**Karabiner-Elements**即可，也就是上面网站中的**keyReMap4Mac**的最新版

