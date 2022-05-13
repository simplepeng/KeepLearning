#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    FILE *file;
    //打开文件
    file = fopen("hello.txt", "w+");
    //写入文件
    int result = fputc('a', file);
    if (result != EOF)
    {
        printf("写入字符成功 result == %d\n", result);
    }
    result = fputs("hello world", file);
    if (result != EOF)
    {
        printf("写入字符串成功 result == %d\n", result);
    }
    //关闭文件
    fclose(file);
    return 0;
}
