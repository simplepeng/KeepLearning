# 输入和输出

## echo命令

`echo`指令用于输出字符串

```shell
echo string
```

### 显示普通字符串

```shell
echo "hello world"
```

这里的双引号可以省略

> hello world

### 显示转义字符串

```shell
echo "\"hello world\"
```

> "hello world"

### 显示变量

`read `命令从标准输入中读取一行,并把输入行的每个字段的值指定给 shell 变量

```shell
#! /bin/bash

read var
echo "var == ${var}"
```

> sh read.sh
> hello 			# 标准输入
> var == hello	# 输出

### 换行\不换行

```shell
echo "hello \n"
echo "world"

echo "hello \c"
echo "world"

echo ""
echo "hello"
echo "world"
```

> hello
>
> world
> hello world
>
> hello
> world

### 输出结果重定向到文件

```shell
echo "hello world" > filename
```

### 原样输出字符串，不转义

使用单引号

```shell
echo '$name\"'
```

> $name\\"

### 显示命令执行结果

```shell
echo `date`
```

> 2018年10月22日 星期一 15时26分29秒 CST

**注意：**执行命令用的反引号，不是单引号

## printf命令

printf 命令模仿 C 程序库（library）里的 printf() 程序。

printf 由 POSIX 标准所定义，因此使用 printf 的脚本比使用 echo 移植性好。

默认 printf 不会像 echo 自动添加换行符，我们可以手动添加 \n。

```shell
printf format-string  [arguments...]
```

- **format-string:** 为格式控制字符串
- **arguments:** 为参数列表。

```shell
#! /bin/bash

printf "%s\n" "hello"
printf "%d\n" 10
printf "%c\n" 'a'
printf "%f\n" 11.11
```

> hello
> 10
> a
> 11.110000

## 重定向

| 命令            | 说明                                               |
| --------------- | -------------------------------------------------- |
| command > file  | 将输出重定向到 file。                              |
| command < file  | 将输入重定向到 file。                              |
| command >> file | 将输出以追加的方式重定向到 file。                  |
| n > file        | 将文件描述符为 n 的文件重定向到 file。             |
| n >> file       | 将文件描述符为 n 的文件以追加的方式重定向到 file。 |
| n >& m          | 将输出文件 m 和 n 合并。                           |
| n <& m          | 将输入文件 m 和 n 合并。                           |
| << tag          | 将开始标记 tag 和结束标记 tag 之间的内容作为输入。 |

**注意：**文件描述符 `0 `通常是`标准输入（STDIN）`，`1` 是`标准输出（STDOUT`），`2 `是`标准错误输出（STDERR）`

### /dev/null 文件

如果希望执行某个命令，但又不希望在屏幕上显示输出结果，那么可以将输出重定向到 /dev/null

```shell
$ command > /dev/null
```

/dev/null 是一个特殊的文件，写入到它的内容都会被丢弃。

如果尝试从该文件读取内容，那么什么也读不到。

但是 /dev/null 文件非常有用，将命令的输出重定向到它，会起到"禁止输出"的效果。如果希望屏蔽 stdout 和 stderr，可以这样写：

```shell
# 如果希望屏蔽 stdout 和 stderr，可以这样写：
command > /dev/null 2>&1
# 0 是标准输入（STDIN），
# 1 是标准输出（STDOUT），
# 2 是标准错误输出（STDERR）
```

