# 数据类型

* int - 整型
* float - 浮点型
* complex - 复数类型
* string - 字符串
* bytes - 字节类型
* bool - 布尔类型
* list - 列表
* tuple - 元组
* dict - 字典
* set - 集合

```python
a = 1
print(a)

b = 3.14
print(b)

c = "hello"
print(c)

d = True
print(d)

# 通过 encode() 方法将字符串转换成 bytes
e = "hello".encode("UTF-8")
print(e)

#为 bytes() 方法指定字符集
e1 = bytes("hello world",encoding="UTF-8")
print(e1)
```