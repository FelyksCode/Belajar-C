#include<stdio.h>
#include<math.h>
int main()
{
printf("=================Soal 1================\n");
    int x;
    x = 5 * 8 - 7 + 2 * 3 - 3 + 4 / 2 + 2;
    printf("x = 5 * 8 - 7 + 2 * 3 - 3 + 4 / 2 + 2\n");
    printf("%d\n\n", x);

printf("=================Soal 2================\n");
    int x2=14,y=5;
    printf("x=14\n y=5\n");
    y=x2++%3;
    printf(" y=x++%3 \n");
    printf("y = %d\n", y);
    printf("x = %d\n\n", x2);

printf("=================Soal 3================\n");
    int x3=3,y3=5;
    printf("x= 3 y= 5 \n");
    y3*=12/++x3;
    printf("y*=12/++x = %d\n\n", y3);

printf("=================Soal 4================\n");
    int x4=10, y4=20, z4=30;
    printf("x= 10 y= 20 z=30\n");
    x4*=y4+=++z4;
    printf("x*=y+=++z = %d\n\n", x4);

printf("=================Soal 5================\n");
    int x5=10, y5;
    printf("x=10 dan y\n");
    y5=x5++ + ++x5;
    printf("y=x++ + ++x =\n");
    printf("y = %d\n", y5);
    printf("x = %d\n\n", x5);

printf("=================Soal 6================\n");
    int x6=8, y6;
    printf("x=8 dan y\n");
    y6=~x6;
    printf("y=~x %d\n\n", y6);
return 0;
}