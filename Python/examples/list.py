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
