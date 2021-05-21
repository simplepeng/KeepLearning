# 使用FRIDA-DEXDump脱壳

[FRIDA-DEXDump](https://github.com/hluwa/FRIDA-DEXDump)

首先安装好**[ frida](https://github.com/frida/frida)**，直接使用`pip`安装就可以。

firda需要root权限，可以使用MuMu模拟器。

## 合并多dex

```python
#!/usr/bin/env python
import os, sys

path = r'/xxxx/'# 文件夹目录
files = os.listdir(path)  # 得到文件夹下的所有文件名称
out_path =r'/xxxxx/out/'  #输出文件夹
#路径上不要有中文!!!!!
s = []
for file in files:  # 遍历文件夹
    if file.find("dex") > 0:  ## 查找dex 文件
        sh = f'jadx -j 1 -r -d {out_path} {path}{file}'
        print(sh)
        os.system(sh)
```





