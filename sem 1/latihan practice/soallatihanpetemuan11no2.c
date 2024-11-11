//Number 2 Felix Ivander(00000070040)
#include <stdio.h>
int main() {
   int n, j, bintang;
   printf("n: ");
   scanf("%d", &bintang);
   for (n = bintang; n >= 1; --n) {
      for (j = 1; j <= n; ++j) {
         printf("* ");
      }
      printf("\n");
   }
   return 0;
}