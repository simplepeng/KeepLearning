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
