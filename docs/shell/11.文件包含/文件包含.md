# 文件包含

## 语法定义

和其他语言一样，Shell 也可以包含外部脚本。这样可以很方便的封装一些公用的代码作为一个独立的文件。

```shell
. filename  # 注意点号(.)和文件名中间有一空格
或
source filename
```

## 实例

include1.sh

```shell
#!/bin/bash

url="www.simplepeng.com"
```

include2.sh

```shell
#!/bin/bash

#. include1.sh
#. ./include.sh

source include1.sh
#source ./include1.sh

echo "网址 == $url"
```

> 网址 == www.simplepeng.com

