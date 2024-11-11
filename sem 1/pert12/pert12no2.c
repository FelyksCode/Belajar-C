#include <stdio.h>
//no2 Felix Ivander (00000070040) 
//Akan dijumlahkan harga yang harus dibayar 
//Dan jumlah barang nya secara otomatis dan keluar dari aplikasi jika di input -1

int barang1=0, barang2=0, opt, totalbrg1, totalbrg2, totalharga;
int main(){ 

    printf("Warung C");
    printf("\n 1.Barang 1 \t Rp. 2.000");
    printf("\n 2.Barang 2 \t Rp. 5.000");
    printf("\n ketik -1 untuk selesai memilih");
    printf("\n\n Pilihanmu:\t ");

    scanf("%d",&opt);
        if(opt != -1){
         switch(opt){
    
    case 1:  
        barang1++;
        return main();
        break;
    
    case 2:
        barang2++;
        return main();
        break;
        } }
        else{
            totalbrg1=barang1*2000;
            totalbrg2=barang2*5000;
            totalharga=totalbrg1+totalbrg2;
            printf("Total semuannya: %d",totalharga);
            }
    
    
    return 0;
}