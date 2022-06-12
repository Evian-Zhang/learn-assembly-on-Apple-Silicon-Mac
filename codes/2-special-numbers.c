#include <stdio.h>
#include <math.h>

float special_numbers[] = { 0.0, -0.0, INFINITY, -INFINITY, NAN, -NAN };
char *special_numbers_names[] = { "0.0", "-0.0", "INFINITY", "-INFINITY", "NAN", "-NAN" };

void display_float_in_binary(float f) {
   char *d = (char *)&f;
   for (int i = 0; i < sizeof(f); i++) {
      printf("%.2x ", d[i] & 0xff);
   }
   printf("\n");
}

int main() {
    for (int i = 0; i < 6; i++) {
        printf("Number %s\tbin: ", special_numbers_names[i]);
        display_float_in_binary(special_numbers[i]);
    }
    printf("\n");

    for (int i = 0; i < 6; i++) {
        for (int j = i; j < 6; j++) {
            printf("%s == %s:\t%d\n", special_numbers_names[i], special_numbers_names[j], special_numbers[i] == special_numbers[j]);
            printf("%s < %s:\t%d\n", special_numbers_names[i], special_numbers_names[j], special_numbers[i] < special_numbers[j]);
            printf("%s > %s:\t%d\n", special_numbers_names[i], special_numbers_names[j], special_numbers[i] > special_numbers[j]);
            printf("\n");
        }
    }

    return 0;
}
