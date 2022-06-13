# Python学习笔记

## 简介



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

```python
for i in range(0,10):
    if i == 5:
        break
    else:
        print(i)
    
print("Done")
```

### continue

`continue` 语句用以告诉 Python 跳过当前循环块中的剩余语句，并继续该循环的下一次循环。

```python
for i in range(0,10):
    if i == 5:
        continue
    else:
        print(i)

print("Done")
```

## 函数

### 定义函数

在Python中定义函数要使用`def`关键字，并且同样以冒号`:`结尾。

返回值使用`return`关键字，并且Python中的函数是可以返回多个返回值的。

```python
def fun(a):
    print(a)

fun(1)
```

### 空函数

如果一个函数暂时没想好内部的实现，可以使用`pass`关键字先占位。并且`pass`关键字也可以使用在其他语句块里面。

```python
def nop():
  pass

if age == 18:
  pass
```

缺少了`pass`的空语句块，代码运行的时候就会报语法错误。

### 检查函数参数

函数参数的数据类型检查可以使用Python的内置函数`isinstance`实现

```python
def check_args(a):
  if not isinstance(x,(int,float)):
    raise TypeError('bad operand type')
  else:
    print(a)
    
print("Done")
```

### 函数参数

* 在定义函数 时给定的名称称作“形参”（Parameters）
* 在调用函数时你所提供给函数的值称作“实参”（Arguments）

### 默认参数

设置默认参数可简化函数的调用，但是要注意下面几点

* 必选参数在前，默认参数在后
* 变化大的参数在前，变化小的参数在后

```python
def fun(a,b="hello"):
    print(a)
    print(b)

fun(1,"world")
fun(2)
```

### 关键字参数

如果你有一些具有许多参数的函数，而你又希望只对其中的一些进行指定，那么你可以通过 命名它们来给这些参数赋值。

我们使用命 名（关键字）而非位置（一直以来我们所使用的方式）来指定函数中的参数。

```python
def func(a, b=5, c=10):
	print('a is', a, 'and b is', b, 'and c is', c)
  
func(3, 7)
func(25, c=24)
func(c=50, a=100)
```

### 可变参数

可变参数就是一个函数所接受的参数是不固定的，可以是0-n个。

定义可变参数只需要在参数前面加一个`*`号，可变参数接受的是一个`tuple`。

```python
def calc(*number):
  sum = 0
  for n in number:
    sum = sum + n * n
  return sum
```

### 文档字符串(doc strings)

DocStrings 是一款你应当使用的重要工具，它能够帮 助你更好地记录程序并让其更加易于理解。

令人惊叹的是，当程序实际运行时，我们甚至可 以通过一个函数来获取文档！

```python
def print_max(x, y):
	'''Prints the maximum of two numbers.打印两个数值中的最大数。
	The two values must be integers.这两个数都应该是整数'''
	# 如果可能，将其转换至整数类型
	x = int(x)
	y = int(y)
	if x > y:
		print(x, 'is maximum')
	else:
		print(y, 'is maximum')
    
print_max(3, 5)
# 输出函数的doc
print(print_max.__doc__)
```

## 模块

### from...import 语句

### 模块的`__name__`

### 包

## 数据结构

### 列表-List

列表 是一种用于保存一系列有序项目的集合。

底层数据结构要么是数组，要么是链表。

```python
# 定义list
shoplist = ['apple','mango','banana']
print("list.len == ",len(shoplist))

print('These items are:', end=' ')
for item in shoplist:
    print(item, end=' ')
# 增加
shoplist.append("rice")
print("my shopping list is now",shoplist)
# 排序
shoplist.sort()
print("sorted list is",shoplist)
# 查找
print("the first item is",shoplist[0])
shoplist[0] = "orange"
# 更改
print("this item is",shoplist)
# 删除
del shoplist[0]
print("deled list is",shoplist)
```

### 元祖-Tuple

元组（Tuple）用于将多个对象保存到一起，和列表List类似，但是支持的功能没有List多。

元组是通过特别指定项目来定义的，在指定项目时，你可以给它们加上括号，并在括号内部 用逗号进行分隔。

```python
# 我会推荐你总是使用括号
# 来指明元组的开始与结束
# 尽管括号是一个可选选项。
# 明了胜过晦涩，显式优于隐式。
zoo = ('python', 'elephant', 'penguin')
print('Number of animals in the zoo is', len(zoo))
new_zoo = 'monkey', 'camel', zoo
print('Number of cages in the new zoo is', len(new_zoo))
print('All animals in new zoo are', new_zoo)
print('Animals brought from old zoo are', new_zoo[2])
print('Last animal brought from old zoo is', new_zoo[2][2])
print('Number of animals in the new zoo is',
	len(new_zoo)-1+len(new_zoo[2]))
```

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

## 参考书籍或文献

* 廖雪峰的Python博客
* 简明Python教程

