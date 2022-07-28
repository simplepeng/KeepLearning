# 字典

* 字典(dict)可以理解为`键值对的集合`，类似Java中的`HashMap`
* 使用花括号`{}`创建字典
* 使用`del`关键字删除字典中某个键值对，对不存在的key会报错
* 使用关键字`in`判断字典中是否存在某个键，`not in`则反之

```python
dict1 = {"zs":"张三","ls":"李四"}
print(dict1)

# 删除
del dict1["zs"]
print(dict1)

# 报错，不存在这个key
# del dict1["ww"]

# 新增
dict1["zs"] = "张三"
dict1["ww"] = "王五"
print(dict1)

# 判断是否存在
print("zs" in dict1)
print("zs" not in dict1)

# 排序
print(sorted(dict1))

# 转列表
print(list(dict1))
```

`dict()`函数可以直接用`键值对序列`创建字典

```python
dict2 = dict([("zs","张三"), ("ls","李四")])
```

使用`items函数`可以取出`键值对`用于循环

```python
for k,v in dict2.items():
    print(k,v)
```