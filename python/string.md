# 字符串

python使用单引号`'`或双引号`"`标记字符

```python
str1 = "hello"
str2 = 'world'

print(str1)
print(str2)
```

长字符串使用3个双引号`"""`或3个单引号`'''`包围

```python
str4 = """
nihao 
hello
world
"""

print(str4)
```

在字符串前面加上`r`开头，就变成了原始字符串，原始字符串会忽略字符串中的转移符号`\`

```python
str5 = r"\user\simple\peng"
print(str5)

str6 = r"\'user\simple"
print(str6)
```