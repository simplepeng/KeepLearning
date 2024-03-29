## 变量

```c++
int a = 1;
bool is = true;
```

* 局部变量：在函数或一个代码块内部声明的变量
* 全局变量：在所有函数外部声明的变量
* 形参：在函数参数的定义中声明的变量
* 实参：调用函数传入的真正的值

当局部变量被定义时，系统不会对其初始化，必须自行对其初始化。

定义全局变量时，系统会自动初始化复制。

| 数据类型 | 初始化默认值 |
| :------- | :----------- |
| int      | 0            |
| char     | '\0'         |
| float    | 0            |
| double   | 0            |
| pointer  | NULL         |

## 常量

`常量`是固定值，在程序执行期间不会改变。所以这些固定的值，又叫做`字面量`。

* 使用 `#define` 预处理器。

* 使用 `const` 关键字。

```c++
#define identifier value
#define LENGTH 10   
#define NEWLINE '\n'
```

```c++
const type variable = value;

const int  LENGTH = 10;
const char NEWLINE = '\n';