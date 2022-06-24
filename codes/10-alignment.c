#include <stdio.h>

struct AlignedStruct {
    short a;
    char b;
    int c;
};

int main() {
    struct AlignedStruct aligned_struct;
    printf("sizeof(short) is %lu, sizeof(char) is %lu, sizeof(int) is %lu, but sizeof(struct AlignedStruct) is %lu\n", sizeof(short), sizeof(char), sizeof(int), sizeof(struct AlignedStruct));
    printf("Inside struct AlignedStruct, short a is at pos %ld, char b is at pos %ld, int c is at pos %ld\n", (void *)&aligned_struct.a - (void *)&aligned_struct, (void *)&aligned_struct.b - (void *)&aligned_struct, (void *)&aligned_struct.c - (void *)&aligned_struct);

    return 0;
}
