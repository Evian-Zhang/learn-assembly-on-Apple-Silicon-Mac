#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef void (*func_t)(void);

int foo() {
    return 1;
}

int main() {
    int stat_loc;

    if (fork() == 0) {
        long dummy[1024];
        memcpy(dummy, foo, 1024);
        printf("Attemping to execute function in stack...\n");
        func_t func_in_stack = (func_t)&dummy;
        func_in_stack();
        printf("Successfully executed the stack!");
        exit(0);
    }
    wait(&stat_loc);
    if (WIFSIGNALED(stat_loc)) {
        printf("Segmentation fault catched when executing the stack!\n");
    }

    if (fork() == 0) {
        printf("Attemping to execute function in heap...\n");
        func_t func_in_heap = (func_t)malloc(1024);
        memcpy(func_in_heap, foo, 1024);
        func_in_heap();
        printf("Successfully executed the heap!");
        exit(0);
    }
    wait(&stat_loc);
    if (WIFSIGNALED(stat_loc)) {
        printf("Segmentation fault catched when executing the heap!\n");
    }

    return 0;
}
