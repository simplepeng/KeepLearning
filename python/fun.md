# 函数

* 使用`def`关键字定义一个函数
* 函数参数放在`()`中，`:`结尾
* 参数可以有`默认值`和`关键字`
* 也可以使用`不定长参数`，加了`*`号的参数会以`元组(tuple)`方式导入
* 加了两个星号`**`的参数会以`字典`方式导入
* 函数第一行语句可以使用文档字符串`""" """`标准函数的用途
* `return`关键字返回函数的返回值，没有返回值函数也会返回`None`
* 使用`lamda`关键字创建`匿名函数`

```python
# 定义函数
def hello():
    print("hello")
hello()

# 文档注释
def doc():
    """这是文档注释"""
    return "doc"
doc()

# 带参数，返回值
def hello2(n):
    print(n)
    return "world"
print(hello2("hello"))

# 默认参数
def hello3(name, age = 11, sex = "boy"):
    print(name)
    print(age)
    print(sex)
hello3("simple")
hello3("simple", sex = "girl", age = 30)

# 不定长参数
def hello4(*args):
    print("不定长参数 = ", args)
hello4(1, 2, 3)
# 不定长参数 =  (1, 2, 3)

# 字典参数
def hello5(**dict):
    print("字典参数 = ", dict)
hello5(a = 1, b = 2) 
# 字典参数 =  {'a': 1, 'b': 2}

```

## 匿名函数(lambda)

* 使用`lambda`关键字创建匿名函数

> lambda 参数们: 表达式

```python
sum = lambda a, b: a + b
print("sum = ",sum(1, 2))
```