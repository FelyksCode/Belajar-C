#include <stdio.h>
#include <stdlib.h>
#include <string.h>
                                        // Felix Ivander (00000070040)
int main(){
    char platnomordepan[2], *platnomortengah;
    char platnomorbelakang[4];
    
    system("cls");

    printf("masukan plat nomor depan : \n");
    scanf("%s", platnomordepan);
    getchar();

    printf("masukan plat nomor tengah : \n");
    scanf("%s", &platnomortengah);
    getchar();


    printf("masukan plat nomor belakang : \n");
    fgets(platnomorbelakang, sizeof(platnomorbelakang), stdin);
    getchar();
        

    printf("\n");
    
    fflush(stdin);
    system("cls");
    if(platnomordepan[0] == 'A' && platnomordepan[1] == 'A'){
        printf("asal kota: meliputi Surakarta, Sukoharjo, Boyolali, Klaten, Sragen, Karanganyar, dan Wonogiri. \n");
    }   
    if(platnomordepan[0] == 'A' && platnomordepan[1] == 'D'){
        printf("asal kota: meliputi Surakarta dan Sukoharjo, Boyolali, Sragen, Karanganyar, Wonogiri, dan Klaten. \n");
    }
    if(platnomordepan[0] == 'K' && platnomordepan[1] == NULL){
        printf("asal kota: meliputi Pati, Kudus, Jepara, Rembang,  Blora, Grobogan, dan Cepu. \n");
    }
    if(platnomordepan[0] == 'R' && platnomordepan[1] == NULL){
        printf("asal kota: meliputi Banjarnegara, Banyumas, dan Purbalingga. \n");
    }
    if(platnomordepan[0] == 'G' && platnomordepan[1] == NULL){
        printf("asal kota: meliputi Brebes, Pemalang, Batang, Tegal, dan Pekalongan. \n");
    }
    if(platnomordepan[0] == 'H' && platnomordepan[1] == NULL){
        printf("asal kota: meliputi Salatiga, Semarang, Kendal, dan Demak. \n");
    }
    if(platnomordepan[0] == 'A' && platnomordepan[1] == 'B'){
        printf("asal kota: meliputi Yogyakarta, Bantul, Gunung Kidul, Sleman, dan Kulon Progo. \n");
    }
    if(platnomordepan[0] == 'D' && platnomordepan[1] == NULL){
        printf("asal kota: meliputi Bandung, Bandung Barat, dan Cimahi. \n");
    }
    if(platnomordepan[0] == 'F' && platnomordepan[1] == NULL){
        printf("asal kota: meliputi Bogor, Sukabumi, dan Cianjur. \n");
    }
    if(platnomordepan[0] == 'E' && platnomordepan[1] == NULL){
        printf("asal kota: meliputi Kuningan, Cirebon, Majalengka, dan Indramayu. \n");
    }
    if(platnomordepan[0] == 'Z' && platnomordepan[1] == NULL){
        printf("asal kota: meliputi Banjar, Garut, Ciamis, Tasikmalaya, dan sumedang. \n");
    }
    if(platnomordepan[0] == 'T' && platnomordepan[1] == NULL){
        printf("asal kota: meliputi Subang, Purwakarta, dan Karawang. \n");
    }
    if(platnomordepan[0] == 'A' && platnomordepan[1] == NULL){
        printf("asal kota: Banten. \n"); 
    }  
    if(platnomordepan[0] == 'A' && platnomordepan[1] == 'G'){
        printf("asal kota: meliputi Tulungagung, Kediri, Blitar, dan Nganjuk. \n");
    }
    if(platnomordepan[0] == 'A' && platnomordepan[1] == 'E'){
        printf("asal kota: meliputi Ngawi, Madiun, Pacitan, Ponorogo, dan Magetan. \n");
    }
    if(platnomordepan[0] == 'L' && platnomordepan[1] == NULL){
        printf("asal kota: Surabaya. \n");
    }
    if(platnomordepan[0] == 'M' && platnomordepan[1] == NULL){
        printf("asal kota: meliputi Madura, Bangkalan, Sampang, Sumenep, dan Pamekasan. \n");
    }
    if(platnomordepan[0] == 'N' && platnomordepan[1] == NULL){
        printf("asal kota: meliputi Malang, Pasuruan, Probolinggo, Batu, dan Lumajang. \n");
    }
    if(platnomordepan[0] == 'S' && platnomordepan[1] == NULL){
        printf("asal kota: meliputi Jombang, Bojonegoro, Lamongan, dan Mojokerto. \n");
    }
    if(platnomordepan[0] == 'W' && platnomordepan[1] == NULL){
        printf("asal kota: meliputi Gresik, dan Sidoarjo. \n");
    }
    if(platnomordepan[0] == 'P' && platnomordepan[1] == NULL){
        printf("asal kota: meliputi Banyuwangi, Besuki, Bondowoso, Jember, dan Situbondo. \n");
    }
    if(platnomordepan[0] == 'D' && platnomordepan[1] == 'K'){
        printf("asal kota: Bali \n");
    }
    if(platnomordepan[0] == 'E' && platnomordepan[1] == 'D'){
        printf("asal kota: meliputi Sumba Timur, dan Sumba Barat. \n");
    }
    if(platnomordepan[0] == 'E' && platnomordepan[1] == 'A'){
        printf("asal kota: meliputi Sumbawa, Bima, Dompu, dan Sumbawa Barat. \n");
    }
    if(platnomordepan[0] == 'E' && platnomordepan[1] == 'B'){
        printf("asal kota: meliputi Alor, Lembata, Sikka, Ende, Ngada, Flores Timur, Flores, Manggarai, dan Manggarai Barat. \n");
    }
    if(platnomordepan[0] == 'D' && platnomordepan[1] == 'H'){
        printf("asal kota: Rote Ndao, Kupang, Timor, Timor Tengah Selatan, dan Timor Tengah Utara. \n");
    }
    if(platnomordepan[0] == 'D' && platnomordepan[1] == 'R'){
        printf("asal kota: meliputi Lombok, Lombok Tengah, Lombok Timur, Lombok Barat, dan Mataram. \n");
    }
    if(platnomordepan[0] == 'K' && platnomordepan[1] == 'U'){
        printf("asal kota: meliputi Kalimantan Utara. \n");
    }
    if(platnomordepan[0] == 'K' && platnomordepan[1] == 'T'){
        printf("asal kota: meliputi Kalimantan Timur. \n");
    }
    if(platnomordepan[0] == 'D' && platnomordepan[1] == 'A'){
        printf("asal kota: meliputi Kalimantan Selatan. \n");
    }
    if(platnomordepan[0] == 'K' && platnomordepan[1] == 'B'){
        printf("asal kota: Kalimantan Barat. \n");
    }
    if(platnomordepan[0] == 'K' && platnomordepan[1] == 'H'){
        printf("asal kota: meliputi Kalimantan Tengah. \n");
    }
    if(platnomordepan[0] == 'D' && platnomordepan[1] == 'C'){
        printf("asal kota: meliputi Sulawesi Barat. \n");
    }
    if(platnomordepan[0] == 'D' && platnomordepan[1] == 'D'){
        printf("asal kota: meliputi Sulawesi Selatan. \n");
    }
    if(platnomordepan[0] == 'D' && platnomordepan[1] == 'N'){
        printf("asal kota: meliputi Sulawesi Tengah. \n");
    }
    if(platnomordepan[0] == 'D' && platnomordepan[1] == 'T'){
        printf("asal kota: meliputi Sulawesi Tenggara. \n");
    }
    if(platnomordepan[0] == 'D' && platnomordepan[1] == 'M'){
        printf("asal kota: meliputi Gorontalo. \n");
    }
    if(platnomordepan[0] == 'D' && platnomordepan[1] == 'L'){
        printf("asal kota: meliputi Sitaro, Talud, dan Sangihe. \n");
    }
    if(platnomordepan[0] == 'D' && platnomordepan[1] == 'B'){
        printf("asal kota: meliputi Bolaang Mongondow, Bolaang Mongondow Timur, Bolaang Mongondow Selatan, Manado, Tomohon, Minahasa, dan Bitung. \n");
    }
    if(platnomordepan[0] == 'B' && platnomordepan[1] == 'A'){
        printf("asal kota: meliputi Sumatra Barat. \n");
    }
    if(platnomordepan[0] == 'B' && platnomordepan[1] == 'B'){
        printf("asal kota: meliputi Sumatra Utara Bagian Barat. \n");
    }
    if(platnomordepan[0] == 'B' && platnomordepan[1] == NULL){
        printf("asal kota: DKI Jakarta, Bekasi, dan Depok. \n");
    }
    if(platnomordepan[0] == 'B' && platnomordepan[1] == 'D'){
        printf("asal kota: Bengkulu. \n");
    }
    if(platnomordepan[0] == 'B' && platnomordepan[1] == 'E'){
        printf("asal kota: Lampung. \n");
    }
    if(platnomordepan[0] == 'B' && platnomordepan[1] == 'G'){
        printf("asal kota: meliputi Sumatra Selatan. \n");
    }
    if(platnomordepan[0] == 'B' && platnomordepan[1] == 'H'){
        printf("asal kota: meliputi Jambi. \n");
    }
    if(platnomordepan[0] == 'B' && platnomordepan[1] == 'K'){
        printf("asal kota: meliputi Sumatra Utara Bagian Timur. \n");
    }
    if(platnomordepan[0] == 'B' && platnomordepan[1] == 'L'){
        printf("asal kota: meliputi Aceh. \n");
    }
    if(platnomordepan[0] == 'B' && platnomordepan[1] == 'M'){
        printf("asal kota: meliputi Riau. \n");
    }
    if(platnomordepan[0] == 'B' && platnomordepan[1] == 'N'){
        printf("asal kota: meliputi Bangka Belitung. \n");
    }
    if(platnomordepan[0] == 'B' && platnomordepan[1] == 'P'){
        printf("asal kota: meliputi Kepulauan Riau. \n");
    }
    if(platnomordepan[0] == 'D' && platnomordepan[1] == 'E'){
        printf("asal kota: meliputi Maluku. \n");
    }
    if(platnomordepan[0] == 'D' && platnomordepan[1] == 'G'){
        printf("asal kota: meliputi Maluku Utara. \n");
    }
    if(platnomordepan[0] == 'P' && platnomordepan[1] == 'A'){
        printf("asal kota: meliputi Papua. \n");
    }
    if(platnomordepan[0] == 'P' && platnomordepan[1] == 'B'){
        printf("asal kota: meliputi Papua Barat. \n");
    }
    
    printf("no kendaraan : %s \n", &platnomortengah);
    printf("inisial pemilik: ");
    puts(platnomorbelakang);
    

    return 0;
}