#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char str1[12] = "hello";
    char str2[12] = "world";

    //复制字符串
    char str3[12];
    strcpy(str3, str1);
    printf("%s\n", str3); //hello
    //连接字符串
    strcat(str1, str2);
    printf("%s\n", str1); //helloworld
    return 0;
}
