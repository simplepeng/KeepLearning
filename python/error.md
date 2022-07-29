# 异常处理

* 异常处理可以使用`try/except/else/finally`语句块
* 可以使用`raise`关键字抛出一个异常
* 可以继承`Exception`类自定义异常
* 使用`with`关键字使用`预定义的清理行为`

```python
# 捕获异常
try:
    10 / 1
except ZeroDivisionError:
    print("ZeroDivisionError")
else:
    print("else")
finally:
    print("finally")

# 抛出异常
def raiseFun(num):
    if num > 5:
        raise Exception("num 不能大于5")
    else:
        print("num = ", num)
# raiseFun(6)

# 自定义异常
class MyException(Exception):
    pass

# 预定义的清理行为
with open("myfile.txt") as f:
    for line in f:
        print(line, end="")
```