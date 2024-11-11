#include<stdio.h>
#include<math.h>
//Latihan 1 Felix Ivander (00000070040)
int main(){
    char name[50];
    int no1, no2, result, opt;
    printf("Hi Student!!");
    printf("\nInput Your Name: ");
    fgets(name,50,stdin);

    printf("########################################\n");

    printf("Hi %s", name);
    printf("\nMenu: ");
    printf("\n1. Penjumlahan ");
    printf("\n2. Pengurangan ");
    printf("\n3. Exit ");

    printf("\n\nMasukan no 1: ");
    scanf("%d", &no1);
    getchar();
    printf("\nMasukan no 2: ");
    scanf("%d", &no2);
    getchar();
    printf("\nMasukan menu: ");
    scanf("%d", &opt);
    getchar();

    printf("########################################\n");

    switch(opt){
        case 1:
            printf("%d + %d ", no1, no2);
            result = no1 + no2;
            printf("\nHasil Penjumlahan = %d", result);
            break;
        
        case 2:
            printf("%d - %d ", no1, no2);
            result = no1 - no2;
            printf("\nHasil Pengurangan = %d", result);
            break;
        
		case 3:
			printf("\nThank You, Have a nice day!!");
			return 0;

    }
    return 0;
}