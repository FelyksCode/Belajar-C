#include <stdio.h>

int main(){
                //Latihan 4 Felix Ivander(00000070040)
    int watts;
    printf("int watts: ");
    scanf("%d", &watts);

    switch(watts){
        case 15: printf("Lumens in is 125"); break;
        case 25 : printf("Lumens in is 215"); break;
        case 40 : printf("Lumens in is 500"); break;
        case 60 : printf("Lumens in is 880"); break;
        case 75 : printf("Lumens in is 100"); break;
        case 100 : printf("Lumens in is 1675"); break;
        default: printf("Lumens in -1 ");
    } 

    return 0;
}