#include <stdio.h>
#include<math.h>
int main() {
   //int / long (bilangan bulat): 2 3 5 6 8         int: %d | long %l
    //float / double (bilangan desimal): 3.14       float: %f | double: %lf
    //char kata: a b c 1 2 @ !                      char: %c
    //char kata[10]: hello                          string: %s
    //bool : true (1,5,-1) / false (0)
   // printf() displays the string inside quotation
   double a=5,b=10;
   double hasil;
   hasil=a+b;
   printf("a + b = %d\n",hasil);
   hasil=a-b;
   printf("a - b = %.2lf\n",hasil);
   hasil=a*b;
   printf("a * b = %.2lf\n",hasil);
   hasil=a/b;
   printf("a / b = %.2lf\n",hasil);
   hasil=10%2;
   printf("10 % 2 = %d\n",hasil);
   hasil+=a;
   printf("hasil + a = %.2lf\n",hasil);
   hasil=pow(a,b);
   printf("a ^ b = %.2lf\n",hasil);
   

   
   hasil=a++;
   printf("a = %.2lf\n",hasil);
   printf("a sekarang = %.2lf\n", a);
   return 0;
}