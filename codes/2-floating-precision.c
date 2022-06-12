#include <stdio.h>

void display_double_in_binary(double f) {
   char *d = (char *)&f;
   for (int i = 0; i < sizeof(f); i++) {
      printf("%.2x ", d[i] & 0xff);
   }
   printf("\n");
}

int main() {
   double a = 0.1;
   double end = 0.3;
   printf("Term\tend = %f\tbin: ", end);
   display_double_in_binary(end);
   int round = 0;
   while (a != end) {
      if (++round == 10) { break; }
      printf("Round %d\ta = %f\tbin: ", round, a);
      display_double_in_binary(a);
      a += 0.1;
   }
   return 0;
}
