# 集合

* 集合(set)是一个无序的不重复的元素列表
* 类似Java总的`Set`
* 可以使用`set()`函数和大括号`{}`创建集合
* 创建空集合只能用`set`函数，`{}`用来创建空字典

```python
set1 = {"apple", "orange", "pear", "apple"}
print(set1)

print("apple" in set1)

set2 = set("apple")
print(set2)

set1.add("banana")
print(set1)

set1.remove("banana")
print(set1)

# 报错，没有这个元素
# set1.remove("cat")
```