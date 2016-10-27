#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 4)
        printf("Too few arguments\n");
        exit(1);

    void *hdl = dlopen(argv[1], RTLD_LAZY);
    if (NULL == hdl)
        printf("Error dlopen\n");
        exit(1);

    /* (void (*)(const char *)) */
    void *func = (void (*))dlsym(hdl, argv[2]);
    if (NULL == func)
        printf("Error dlsym\n");
        exit(2);

    int answer = func((int)argv[3]);
    printf("%d\n", answer);
}
