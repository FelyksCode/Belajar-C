#include <stdio.h>
#include <string.h>
int main() {
char id[15]; // no5 Felix Ivander (0000070040)
int opt;

printf("Selamat Datang di WinWin Doorprize\nPengambilan hadiah dapat digunakan dengan menunjukan No_IDCard\n");
printf("Menu: \n  1. Ambil Hadiah\n  2. Info pemenang Dan hadiah\n  3. Exit\n");
printf("Input Menu: \n");
scanf("%d", &opt);
if (opt == 1){
    printf("#Ambil Hadiah\nMasukkan No IDCard: (5 digit) ");
    scanf("%s", &id);
    if (strcmp(id, "0001A") == 0){
        printf("Selamat anda memenangkan hadiah Kulkas!");
    }
    else if (strcmp(id, "1010B") == 0){
        printf("Selamat anda memenangkan hadiah TV!");
    }
    else if (strcmp(id, "1001C") == 0){
        printf("Selamat anda memenangkan hadiah Smartphone!");
    }
    else {
        printf("\nMaaf, Anda belum beruntung.");
    }

}
if (opt == 2){
    printf("#Info Pemenang\nBudi: ID 0001A\nAlex: ID 1010B\nSander: ID 1001C");
}
if (opt == 3){
    printf("#Exit\nHave a nice day!!!");
}
return 0;
}