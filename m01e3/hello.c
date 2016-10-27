#include <stdio.h>
#include "hello.h"

void hello_message(const char *name)
{
    printf("Hello %s!\n", name);
}

int hello_int(int i)
{
    return i * 2;
}
