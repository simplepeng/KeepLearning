## 函数

函数是一组一起执行一个任务的语句。每个 C 程序都至少有一个函数，即主函数 `main()`。

```c
返回类型 函数名(参数列表)
{
  //一系列执行语句
}
```

```c
int max(int num1,int num2)
{
  int result;
  if(num1 > num2)
  {
    result = num1; 
  }else
  {
    result = num2;
  }
  return result;
}
```