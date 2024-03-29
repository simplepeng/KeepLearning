## 命名空间

命名空间使用`namespace`关键字定义

```c++
namespace namespace_name {
   // 代码声明
}

name::code;  // code 可以是变量或函数
//
std::cout;
std::endl;
```

可以使用`using`指令告诉后续代码使用指定的命名空间，简化调用

```c++
#include <iostream>

using namespace std; 
// 第一个命名空间
namespace first_space{
   void func(){
      cout << "Inside first_space" << endl;
   }
}
// 第二个命名空间
namespace second_space{
   void func(){
      cout << "Inside second_space" << endl;
   }
}
//使用第一个命名空间
using namespace first_space;

int main ()
{
 
   // 调用第一个命名空间中的函数
   func();
   
   return 0;
}
```

命名空间可以定义在几个不同的部分中，下面的命名空间定义可以是定义一个新的命名空间，也可以是为已有的命名空间增加新的元素：

```c++
namespace namespace_name {
   // 代码声明
}
```

命名空间可以嵌套，可以在一个命名空间中定义另一个命名空间

```c++
namespace namespace_name1 {
   // 代码声明
   namespace namespace_name2 {
      // 代码声明
   }
}
```