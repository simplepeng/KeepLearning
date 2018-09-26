#include <stdio.h>

int main(int argc, char const *argv[])
{
    
    printf("File :%s\n", __FILE__ );//File :preprocessor_macro.c
    printf("Date :%s\n", __DATE__ );//Date :Sep 26 2018
    printf("Time :%s\n", __TIME__ );//Time :11:24:59
    printf("Line :%d\n", __LINE__ );//Line :9
    printf("ANSI :%d\n", __STDC__ );//ANSI :1

    return 0;
}
