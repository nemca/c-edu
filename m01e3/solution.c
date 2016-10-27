#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    void *handle;
    int (*func)(int);
    char *error;
    char *libname;

    sprintf(libname, "./%s", argv[1]);
    handle = dlopen(libname, RTLD_LAZY);
    if (!handle) {
        fputs (dlerror(), stderr);
        exit(1);
    }

    func = dlsym(handle, argv[2]);
    if ((error = dlerror()) != NULL) {
        fputs(error, stderr);
        exit(1);
    }

    int i = (int)argv[3];
    int answer = (*func)(i);
    printf("%d\n", answer);
    dlclose(handle);
}
