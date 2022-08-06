# 常量

`常量(constant)`与`变量(variable)`不同，存储在常量中的值在程序执行期间不可改变。这些固定的值，又叫做`字面量`。

在C中有两种方式定义常量

1. 使用 `#define` 预处理器
2. 使用 `const` 关键字，C90新增的，用于限定一个变量为只读。

* 使用`#defind`定义的常量会在编译时全部替换成实际值，这个过程被称为`编译时替换(compile-time substitution)`。
* 这样定义的常量也被称为`明示常量(manifest constant)`

```c
#include <stdio.h>

#define PI 3.14

int main(int argc, char const *argv[])
{
    printf("PI == %f\n", PI);
    //PI = 3.15; error: expression is not assignable
    return 0;
}
```

```c
#include <stdio.h>

const double PI = 3.14;

int main(int argc, char const *argv[])
{
    printf("PI == %f\n",PI);  
    //PI = 3.15;  error: cannot assign to variable 'PI' with const-qualified type 'const double'
    return 0;
}
```

注：把常量定义为大写字母形式，是一种很好的编程习惯