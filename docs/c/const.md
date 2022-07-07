## 常量

与变量不同，存储在常量中的值在程序执行期间不可改变。这些固定的值，又叫做`字面量`。

在C中有两种方式定义常量

1. 使用 `#define` 预处理器
2. 使用 `const` 关键字

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