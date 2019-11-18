# Python 学习笔记

## Hello World

```python
print("hello world")
```

## 注释

Python注释使用`#`符号

```python
print('hello world') #注意到 print 是一个函
# 注意到 print 是一个函数
print('hello world')
```

## 缩进

使用四个空格来缩进

## 数据类型

### 整数

```python
a = 1
```

### 浮点数

```python
b = 3.14
```

### 字符串

用单引号`''`和双引号`""`括起来的文本都是字符串，如果字符串中间包含单引号`''`,请使用双引号括起来，或者只是用转义字符`\`

```python
a = 'hello'
b = "world"

c = "hello '' world"
```

Python允许使用`'''...'''`的格式表示多行内容

```python
f = '''line1
line2
line3
'''
print(f)
```

### 布尔值

Python的布尔值用`True`和`False`表示。

```python
h = True
print(h)#True
print(3<2)#False
```

布尔值可以用`and`，`or`，`not`运算，也就是`与`，`或`，`非`

相当于其他语言中的`&&`，`||`，`!`

```python
True and True
True or False
not True
```

### 空值

空值是Python中一个特别的类型，用`None`表示。`None`并不能某些语言那样理解为`0`，因为Python中的`None`是有意义的。

### 变量

变量名必须是大小写英文、数字和`_`的组合，且不能用数字开头。

Python中的变量是可以重新赋值的。

```python
a = 1 #a是一个整数
a = "xxx" #把a变成字符串
```

## 逻辑控制

### if

```python
number = 23
guess = int(input("enter an integer :"))

if guess == number:
    print("guess == number")
elif guess < number:
    print("guess < number")
else:
     print("guess > number")

print("Done")
```

例子中的`else`块是可选的，逻辑表达式结尾必须跟上冒号`:`表示这个表达式为一个代码块。

Python 中不存在 switch 语句。你可以通过使用 if..elif..else 语句来实现同样的事 情（在某些情况下，使用一部字典能够更快速地完成）。

### while

while 语句能够让你在条件为`True`的前提下重复执行某块语句。

while 语句是 循环 （Looping） 语句的一种。 

while 语句同样可以拥有 else 子句作为可选选项。

while 语句后面同样要跟上冒号`:`

```python
number = 23
running = True
while running:
    guess = int(input('Enter an integer : '))
    if guess == number:
        print('Congratulations, you guessed it.')
        # 这将导致 while 循环中止
        running = False
    elif guess < number:
            print('No, it is a little higher than that.')
    else:
        print('No, it is a little lower than that.')
else:
        print('The while loop is over.')
# 在这里你可以做你想做的任何事
print('Done')
```

### for

`for...in` 语句是另一种循环语句，其特点是会在一系列对象上进行迭代（Iterates），意即 它会遍历序列中的每一个项目。

```python
for i in range(0,5):
    print(i)
else:
    print("the for loop is over")
```

else语句块同样是可选的

for表达式结尾同样要跟上`:`

### break

`break`语句用于退出循环，和其他语言差不多。

### continue

`continue` 语句用以告诉 Python 跳过当前循环块中的剩余语句，并继续该循环的下一次循环。

## 函数

### 函数参数

### 局部变量

### global 语句

### 默认函数值

### 关键字参数

### 可变参数

### return 语句

### 文档字符串(doc strings)

## 模块

### from...import 语句

### 模块的`__name__`

### 包

## 数据结构

### 列表-List

### 元祖-Tuple

### 字典-Dictionary

### 集合-Set

### 序列-Sequence

## 面向对象编程

### self

### 类-class

### 方法

### `__init__`方法

### 类变量与对象变量

### 继承

## 输入与输出

## 异常

### 捕获异常

### 抛出异常

### finally

### with语句




