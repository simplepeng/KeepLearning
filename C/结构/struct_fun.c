#include "struct_fun.h"
#include <stdio.h>

static void add(int x, int y)
{
    printf("sum == %d\n", x + y);
}

static const struct Interface interface = {
    add
};
