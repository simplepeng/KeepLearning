# 类和对象

* 使用`class`关键字定义一个类
* `__init__`是类的构造方法
* python支持`多继承`，父类写在类名`()`中，并且先后顺序对子类也有影响
* 类方法也是使用`def`关键字定义，并且第一个参数都是`self`
* `self`表示类的实例对象
* 和其他语音一样，可以在子类中复写父类的方法，也可以使用`super`调用父类的方法
* `__`两个下划线开头的属性和函数，被定义为私有方法，只能在类中调用。
* python也支持`运算符重载`

```python
# 类和对象
class MyClass:
    """这是一个类"""
    a = "hello"
    b = 28

    # 类初始化方法，也可以叫构造方法
    def __init__(self) -> None:
        print("init")

    def hello(self):
        print(self.a)
        print(self.b)

object = MyClass()
object.hello()


class MyClass2:
    """这是一个类"""
    a = "hello"
    b = 28

    # 传递构造参数
    def __init__(self, name) -> None:
        print("init")
        print(name)

    def hello(self):
        print("MyClass2 hello")
        print(self.a)
        print(self.b)

object2 = MyClass2("simple")
object2.hello()

# 继承，python支持多继承
class MyClass3(MyClass2, MyClass):
    _private = 1

    def __init__(self) -> None:
        print("MyClass3 init")

o3 = MyClass3()
o3.hello()

print(isinstance(o3, MyClass3))
print(issubclass(MyClass, MyClass3))
print(issubclass(MyClass3, MyClass2))

class MyClass4:
    __a = 1

    def __hello():
        print("MyClass4 __hello")

o4 = MyClass4()
# 报错
# o4.__a
# o4.__hello()
```