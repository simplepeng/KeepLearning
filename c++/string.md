## 字符串

* c-style字符串
* string类字符串

```c++
char * str = "abcd";
char str1[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
```

```c++
#include <string>
#include <iostream>

int main(int argc, char const *argv[])
{
    std::string a = "hello string";
    std::cout << a << std::endl;

    const char * c_str = a.c_str();
    printf("c_str == %s",c_str);

    return 0;
}
```