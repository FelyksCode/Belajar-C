#include <stdio.h>


float num1, num2, hasil;
int operator;


float penjumlahan(){
	hasil = num1 + num2;
    printf("Hasil Penjumlahan: %.0f", hasil);
}

float pengurangan(){
	hasil = num1 - num2;
    printf("Hasil Pengurangan: %.0f", hasil);
}

float perkalian(){
	hasil = num1 * num2;
     printf("Hasil Perkalian: %.2f", hasil);
}

float pembagian(){
	hasil = num1 / num2;
    printf("Hasil Pembagian: %.2f", hasil);
}

float main(){

    printf("Menu:\n1. Penjumlahan\n2. Pengurangan\n3. Perkalian\n4. Pembagian\n");
    scanf("%d", &operator);

    printf("Masukan angka: ");
	scanf("%f", &num1);
	printf("Masukan angka: ");
	scanf("%f", &num2);

    switch (operator)
    {
    case 1:
        penjumlahan();
        break;
    case 2:
        pengurangan();
        break;
    case 3:
        perkalian();
        break;
    case 4: 
        pembagian();
        break;
    }
    return 0;
}