## 函数

`函数声明`告诉编译器函数的名称、返回类型和参数。`函数定义`提供了函数的实际主体。

`函数声明`一般放在`头文件`里面，`函数定义`实现在`cpp`中，这样编译链接后，其他文件导入`函数定义`的头文件就可以直接使用该函数。

```c++
return_type function_name( parameter list )
{
   body of the function
}
```

```c++
int max(int num1, int num2) 
{
   // 局部变量声明
   int result;
 
   if (num1 > num2)
      result = num1;
   else
      result = num2;
 
   return result; 
}
```

* 参数默认值

定义一个函数时可以给形参指定一个匹配类型的默认值

当调用函数时，如果实参的值留空，则使用这个默认值

```c++
int sum(int a, int b = 20)
{
  int result;
 
  result = a + b;
  
  return (result);
}
```

* Lambda函数

C++11 提供了对匿名函数的支持,称为 `Lambda 函数`(也叫 `Lambda 表达式`)

Lambda 表达式把函数看作对象

```c++
//有返回值得lambda
[capture](parameters)->return-type{body}
//
[](int x, int y){ return x < y ; }
```

```c++
//无返回值的lambda
[capture](parameters){body}
//
[]{ ++global_x; } 
```