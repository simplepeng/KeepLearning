# Shell工具

## cut

cut命令从文件的每一行剪切字节、字符和字段并将这些字节、字符和字段输出。

基本用法：cut [选项参数] filename

说明：默认分隔符是制表符

选项参数说明：

| 选项参数 | 功能                         |
| -------- | ---------------------------- |
| -f       | 列号，提取第几列             |
| -d       | 分隔符，按照指定分隔符分割列 |

```shell
//cut.txt
dong shen
guan zhen
wo  wo
lai  lai
le  le
```

```shell
cut -d " " -f 1 cut.txt
```

> dong
>
> guan
>
> wo
>
> lai
>
> le

## sed

sed是一种`流`编辑器，它一次处理一行内容。处理时，把当前处理的行存储在临时缓冲区中，称为“模式空间”，接着用sed命令处理缓冲区中的内容，处理完成后，把缓冲区的内容送往屏幕。接着处理下一行，这样不断重复，直到文件末尾。**文件内容并没有改变**，除非你使用重定向存储输出。

基本用法：sed [选项参数] ‘command’ filename

选项参数说明：

| 选项参数 | 功能                                |
| -------- | ----------------------------------- |
| -e       | 直接在指令列模式上进行sed的动作编辑 |

命令功能描述：

| 命令 | 功能描述                                |
| ---- | --------------------------------------- |
| a    | 新增，a的后面可以接字符串，在下一行出现 |
| d    | 删除                                    |
| s    | 查找并替换                              |
