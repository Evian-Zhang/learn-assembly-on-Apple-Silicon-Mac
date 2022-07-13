#include <stdio.h>

int swap(int *a, int *b) {
    int sum;
    asm(
        "ldr    w9, [%1]\n\t"
        "ldr    w10, [%2]\n\t"
        "str    w9, [%2]\n\t"
        "str    w10, [%1]\n\t"
        "add    w9, w9, w10\n\t"
        "str    w9, %0"
        : "=m" (sum)
        : "r" (a), "r" (b)
        : "w9", "w10"
    );
    return sum;
}

int main() {
    int a = 1;
    int b = 2;
    int c = swap(&a, &b);
    printf("After swapping, a = %d, b = %d, a + b = %d\n", a, b, c);
    return 0;
}
