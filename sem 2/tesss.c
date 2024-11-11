#include <stdio.h>

union tes{
    short a;
    int x;
    char c;
};


int main() {
    int x = 5; // non-pointer variable
    int *p = &x; // pointer variable

    printf("Value of x: %d\n", x);
    printf("Value of *p: %d\n", *p);
    printf("Address of x: %p\n", &x);
    printf("Value of p: %p\n\n\n\n\n\n", p);

    union tes *coba;
    coba->a= 5;
    coba->c='b';
    coba->x= 200;
    printf("Value of a: %d\n", coba->a);
    printf("Value of x: %d\n", coba->x);
    printf("Value of c: %c\n", coba->c);


    return 0;
}