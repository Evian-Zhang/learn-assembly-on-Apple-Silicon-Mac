#include <stdio.h>

int main() {
    long a = 0x0123456789abcdef;
    printf("Storing 0x0123456789abcdef into memory is: ");
    char *s = (char *)&a;
    for (int i = 0; i <sizeof(a); i++) {
        printf("%.2x ", s[i] & 0xff);
    }
    printf("\n");

    return 0;
}
