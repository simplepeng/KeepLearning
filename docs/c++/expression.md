## 逻辑控制

```c++
if(boolean_expression)
{
   // 如果布尔表达式为真将执行的语句
}
else
{
   // 如果布尔表达式为假将执行的语句
}
```

```c++
switch(expression){
    case constant-expression  :
       statement(s);
       break; // 可选的
    case constant-expression  :
       statement(s);
       break; // 可选的
  
    // 您可以有任意数量的 case 语句
    default : // 可选的
       statement(s);
}
```

## 遍历

```c++
while(condition)
{
   statement(s);
}
```

```c++
for( int a = 10; a < 20; a = a + 1 )
{
   cout << "a 的值：" << a << endl;
}
```

```c++
do
{
 cout << "a 的值：" << a << endl;
 a = a + 1;
}while( a < 20 );
```

| 控制语句                                                     | 描述                                                         |
| :----------------------------------------------------------- | :----------------------------------------------------------- |
| break 语句 | 终止 **loop** 或 **switch** 语句，程序流将继续执行紧接着 loop 或 switch 的下一条语句。 |
| continue 语句 | 引起循环跳过主体的剩余部分，立即重新开始测试条件。           |
| goto 语句 | 将控制转移到被标记的语句。但是不建议在程序中使用 goto 语句。 |