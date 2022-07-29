# 流程控制

## if

* `if`用来判断逻辑分支结构
* if表达式不需要括号`()`
* if分支用冒号`:`标记结尾
* `elif`新增一个分支，`else`结束分支

```python
age = 3
if age < 4:
    print("age < 4")
elif age > 6:
    print("age >6")
else:
    print("age = 5")
```

## for

* `for`用来遍历元素组，也需要`:`标记结尾
* 遍历集合时，同时修改集合内容时，应该使用集合的副本
* `break`出循环，`continue`执行下一次循环
* python的循环语句支持`else`分支
    * for循环中，可迭代对象中元素全部循环完毕，执行else子句
    * while循环中，条件语句为假时，执行该子句

```python
items = ["cat", "dog", "horse"]
for w in items:
    print(w)
```

```python
users = {'Hans': 'active', 'Éléonore': 'inactive', '景太郎': 'active'}
for user, status in users.copy().items():
    if status == 'inactive':
        del users[user]
```

## while

```python
age = 1
while age < 10:
    age = age + 1
else:
    print("age > 10")
```

## range函数

`range()`函数生成数字序列，可以直接用来遍历

```python
for i in range(5):
    print(i)
```

## pass语句

pass是空语句，一般用来占位。

```python
while True:
     pass

class EmptyClass:
    pass

def fun():
    pass
```



