#include <stdio.h>
#include <stdlib.h>
#include <string.h>
                                        // Felix Ivander (00000070040)
int main(){
    char tanggal[8];
    system("cls");

    printf("masukan tanggal\n ddmmyyyy: ");
    scanf("%s", tanggal);
    
    getchar();
    
    printf("tanggal: %.2s\n", tanggal);

    tanggal[0]=tanggal[2];
    tanggal[1]=tanggal[3];
    
    if(tanggal[0]=='0' && tanggal[1]=='1'){
        printf("bulan : januari\n");
    }
    if(tanggal[0]=='0' && tanggal[1]=='2'){
        printf("bulan : februari\n");
    }
    if(tanggal[0]=='0' && tanggal[1]=='3'){
        printf("bulan : maret\n");
    }
    if(tanggal[0]=='0' && tanggal[1]=='4'){
        printf("bulan : april\n");
    }
    if(tanggal[0]=='0' && tanggal[1]=='5'){
        printf("bulan : mei\n");
    }
    if(tanggal[0]=='0' && tanggal[1]=='6'){
        printf("bulan : juni\n");
    }
    if(tanggal[0]=='0' && tanggal[1]=='7'){
        printf("bulan : juli\n");
    }
    if(tanggal[0]=='0' && tanggal[1]=='8'){
        printf("bulan : agustus\n");
    }
    if(tanggal[0]=='0' && tanggal[1]=='9'){
        printf("bulan : september\n");
    }
    if(tanggal[0]=='1' && tanggal[1]=='0'){
        printf("bulan : oktober\n");
    }
    if(tanggal[0]=='1' && tanggal[1]=='1'){
        printf("bulan : november\n");
    }
    if(tanggal[0]=='1' && tanggal[1]=='2'){
        printf("bulan : desember\n");
    }
    //printf("bulan: %.2s\n", tanggal);
    

    tanggal[0]=tanggal[4];
    tanggal[1]=tanggal[5];
    tanggal[2]=tanggal[6];
    tanggal[3]=tanggal[7];
    printf("tahun: %.4s\n", tanggal);

    return 0;
}