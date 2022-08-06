# 流程控制

* 花括号`{}`以及被花括号括起来的部分被称为`快(block)`

## if判断

```c
int main()
{
    int a = 5;
    if(a < 4)
    {
        //...
    }
    else
    {
        //...
    }
}
```

## while循环

* while语句是一种迭代语句，有时也被称为结构化语句，因为它的结构比简单的赋值表达式语句复杂。

```c
int a = 1;
while(a < 5)
{
    a++;
    printf("a = %d", a);
}
printf("while end");
```

## for循环

```c
int a = 1;
for(a)
```