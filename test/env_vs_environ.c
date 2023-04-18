#include <stdio.h>
#include <unistd.h>

extern char **environ;

int main(int argc, char *argv[], char *env[]) {
    printf("Address of env (third parameter of main): %p\n", env);
    printf("Address of environ (global variable): %p\n", environ);

    if (env == environ) {
        printf("env and environ have the same address.\n");
    } else {
        printf("env and environ have different addresses.\n");
    }

    return 0;
}

