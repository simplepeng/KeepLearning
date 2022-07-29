# 模块

* python中一个模块就是`.py`结尾的python文件
* 模块中定义了一系列的的属性和方法
* 使用`import`关键字导入模块
* 使用`as`关键字给导入的模块重命名
* 一个模块只会被导入一次，不管代码中import了多少次
* 使用`from...import`可以导入模块中指定的部分
* 模块也可以使用`包级管理`

```python
# 导入模块
import module2
module2.hello()

# 导入模块-重命名
import module2 as m
m.hello()

# 导入模块中的某个方法
from module2 import hello
hello()
```