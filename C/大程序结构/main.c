#include <stdio.h>
#include "add.h"

int main(int argc, char const *argv[])
{
    int sum = add(1,2);
    printf("sum == %d\n",sum);
    return 0;
}
