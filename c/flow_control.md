# 流程控制

* 花括号`{}`以及被花括号括起来的部分被称为`快(block)`

## if语句

* if语句被称为`分支语句(branching statement)`或`选择语句(selection statement)`

```c
int main()
{
    int a = 5;
    if(a < 3)
    {
        //...
    }else if(a < 4)
    {
        //...
    }else
    {

    }
}
```

## switch-case多重选择

```c
int age = 20;
switch(age)
{
    case 1:
        break;
    case 10:
    case 11://多重标签写法
        break;
    default:

}
```

## while循环

* while语句是一种迭代语句，有时也被称为结构化语句，因为它的结构比简单的赋值表达式语句复杂。
* 使用`break`关键字退出循环。
* 使用`continue`关键字执行下一次循环。

```c
int a = 1;
while(a < 5)
{
    a++;
    printf("a = %d", a);
    if(a > 3)
        break;
    else 
        continue;
}
printf("while end");
```

* `a < 5`是while表达式的`入口条件(entry condition)`

## do-while语句

* do-while语句至少必须先执行一次循环。

```c
do {
    //提示用户输入密码
    //读取用户输入的密码
}while(用户输入的密码不等于密码)
```

## for循环

```c
int count;
for(count = 1; count <= 22; count++)
{
    printf("count = %d", count);
}
```

## 嵌套循环

* `嵌套循环(nested loop)`指在一个循环内包含另一个循环。
* 算法里经常用到嵌套循环

## goto语句

* `K&R`建议`谨慎使用，或者根本不用`goto语句，因为不使用goto语句也能实现同样的代码逻辑。