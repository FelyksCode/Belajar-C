#include <stdio.h>
// no 1 Felix Ivander (00000070040)
int main(){
    int p, l, i, j;
    printf("Input Panjang: ");
    scanf("%d",&p);

    printf("\n Input Lebar: ");
    scanf("%d",&l);

    for(i=1; i<= l; i++){
        for(j=1; j<= p; j++){
            if(i == 1 || i == l || j == 1 || j == p){
                printf("*");
            }
            else(printf(" "));
        }
        printf("\n");
    }


    return 0;
}