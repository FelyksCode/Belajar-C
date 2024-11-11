#include <stdio.h>
//no3 Felix ivander (00000070040)
int main()
{
    int nomor=15, counter=5;

    while(nomor != 0){
        printf("%d", nomor);
        nomor = nomor - counter;
        counter--;
    }

    counter = 3;
    while(nomor != 18){
        printf("%d ", nomor);
        nomor = nomor + counter;
    }

    return 0;
}