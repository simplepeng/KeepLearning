## 异常处理

c++异常处理主要使用三个关键字`try`，`catch`和`throw`

```c++
try
{
   // 保护代码
}catch( ExceptionName e1 )
{
   // catch 块
}catch( ExceptionName e2 )
{
   // catch 块
}catch( ExceptionName eN )
{
   // catch 块
}
```

### 定义新的异常

通过继承`std::exception`来新建异常类，通过重写`what`函数来返回异常原因。

```c++
#include <iostream>
#include <exception>

using namespace std;

class CustomException : public exception
{
    public:
    const char *what() const throw()
    {
        return "This is CustomException";
    }
};

int main(int argc, char const *argv[])
{
    try
    {
        throw CustomException();
    }
    catch (CustomException &e)
    {
        cout << e.what() << endl;
    }
    return 0;
}
```