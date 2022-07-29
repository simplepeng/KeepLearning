# 元组

* 元组(tuple)使用圆括号`()`标注，不是必须的，但是经常是必须的
* 元组和列表很像，但是使用场景不同。元组是不可变的(`inmutable`)，列表是可变的(`mutable`)
* 元组一般是包含异质元素类型，列表是同质元素类型
* 元组可使用解包语法

```python
tuple1 = (1,2,"3")
print(tuple1)

# 访问元素
var1 = tuple1[0]
print(var1)

# 报错，不能修改元素
tuple1[0] = "haha"
print(tuple1)

# 解包语法
x,y,z = tuple1
print(x)
print(y)
print(z)
```