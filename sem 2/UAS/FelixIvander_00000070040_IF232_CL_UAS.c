#include <stdio.h>
#include <string.h>

/*
Nama    : Felix Ivander
NIM     : 00000070040
Kelas   : CL
Nilai   : 
*/

struct lagu{
    char judul[40];
    char artis[40];
    char album[40];
    int tahun;
};

void swap(struct lagu *a, struct lagu *b) {
    struct lagu temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSortTahun(struct lagu track[], int n) {
    int i, j, minIndex;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;

        for (j = i + 1; j < n; j++) {
            if (track[j].tahun < track[minIndex].tahun) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            swap(&track[i], &track[minIndex]);
        }
    }
}


void selectionSortJudul(struct lagu track[], int n){
    int i, j;
    for(i=0; i<n-1; i++){
        int minIndex = i;

        for(j=i+1; j<n; j++){
            if(strcmp(track[j].judul, track[minIndex].judul) < 0){
                minIndex = j;
            }
        }

        if(minIndex != i){
            struct lagu temp = track[i];
            track[i] = track[minIndex];
            track[minIndex] = temp;
        }
    }
}

int binarySearchTahun(struct lagu track[], int size, int key){
    int low, mid, high;

    low = 0;
    high = size-1;

    while(low <= high){
        mid = (low+high) /2;        
        if(track[mid].tahun == key) return mid;
        if(key < track[mid].tahun) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}

void binarySearchJudul(struct lagu track[], int size, char key[]){
    int low = 0;
    int high = size - 1;
    int found = 0;

    while (low <= high) {
        int mid = (low + high) / 2;
        int result = strcmp(track[mid].judul, key);

        if (result == 0) {
            printf("\nData ditemukan!\n");
            printf("Judul: %s\n", track[mid].judul);
            printf("Artis: %s\n", track[mid].artis);
            printf("Album: %s\n", track[mid].album);
            printf("Tahun: %d\n\n", track[mid].tahun);
            found = 1;
            break;
        }
        else if (result < 0) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    if (!found) {
        printf("\nData tidak ditemukan.\n");
    }
}

void printData(struct lagu temp[], int counter){
    int i;
    printf("---------------------------------------------------------------------------------------------------\n");
    printf("|                                        DATABASE MUSIC FELIX                                     |\n");
    printf("---------------------------------------------------------------------------------------------------\n");
    printf("| Title                                 | Artist               | Album                    | Year  |\n");
    printf("---------------------------------------------------------------------------------------------------\n");
    
    for(i=0;i<counter;i++){
        char truncatedArtist[40];
        if (strlen(temp[i].artis) > 17) {
            strncpy(truncatedArtist, temp[i].artis, 17);
            truncatedArtist[17] = '\0';
            strcat(truncatedArtist, "...");
        }
        else {
            strcpy(truncatedArtist, temp[i].artis);
        }
        
        char truncatedAlbum[40];
        if (strlen(temp[i].album) > 19) {
            strncpy(truncatedAlbum, temp[i].album, 19);
            truncatedAlbum[19] = '\0';
            strcat(truncatedAlbum, "...");
        }
        else {
            strcpy(truncatedAlbum, temp[i].album);
        }
        
        

        printf("| %-38s| %-21s| %-25s| %-6d|\n",  temp[i].judul, truncatedArtist, truncatedAlbum, temp[i].tahun);
    }
        printf("---------------------------------------------------------------------------------------------------\n");
}


void menu(struct lagu track[], int counter){
    int opt,i,pilihan, pilihan2;
        printf("1. Sort\n2. Search\n3. Keluar Program\n\nPilihan: ");
        scanf("%d", &opt);
        switch(opt){
            case 1:     // sort
                printf("Pilih Sort berdasarkan\n1. Judul\n2. Tahun Rilis\n\nPilihan: ");
                scanf("%d", &pilihan);  

                if (pilihan == 1) {
                    selectionSortJudul(track, counter);
                    printData(track, counter);
                }
                else if (pilihan == 2) {
                    selectionSortTahun(track, counter);
                    printData(track, counter);
                }
                else {
                    printf("Pilihan tidak valid.\n");
                }

                menu(track, counter);
                break;   
            
            case 2:
                printf("Pilih search berdasarkan\n1. Judul\n2. Tahun Rilis\n\nPilihan: ");
            char searchKeyJudul[40];
            int searchKeyTahun = 0;
            fflush(stdin);
            scanf("%d", &pilihan2);
            if (pilihan2 == 1) {
                fflush(stdin);
                printf("Masukan Judul yang ingin dicari: ");
                scanf("%[^\n]", searchKeyJudul);
                selectionSortJudul(track, counter);
                binarySearchJudul(track, counter, searchKeyJudul);
                fflush(stdin);
            }
            else if (pilihan2 == 2) {
                fflush(stdin);
                printf("Masukan Tahun yang ingin dicari: ");
                scanf("%d", &searchKeyTahun);
                selectionSortTahun(track, counter);
                
                printf("\nData ditemukan pada tahun %d:\n", searchKeyTahun);
                int found = 0;
                printf("---------------------------------------------------------------------------------------------------\n");
                printf("| Title                                 | Artist               | Album                    | Year  |\n");
                printf("---------------------------------------------------------------------------------------------------\n");
                for (int i = 0; i < counter; i++) {
                    if (track[i].tahun == searchKeyTahun) {
                        char truncatedArtist[40];
                        if (strlen(track[i].artis) > 17) {
                            strncpy(truncatedArtist, track[i].artis, 17);
                            truncatedArtist[17] = '\0';
                            strcat(truncatedArtist, "...");
                        }
                        else {
                            strcpy(truncatedArtist, track[i].artis);
                        }

                        char truncatedAlbum[40];
                        if (strlen(track[i].album) > 19) {
                            strncpy(truncatedAlbum, track[i].album, 19);
                            truncatedAlbum[19] = '\0';
                            strcat(truncatedAlbum, "...");
                        }
                        else {
                            strcpy(truncatedAlbum, track[i].album);
                        }



                        printf("| %-38s| %-21s| %-25s| %-6d|\n",  track[i].judul, truncatedArtist, truncatedAlbum, track[i].tahun);
                        found = 1;
                    }
                }
                printf("---------------------------------------------------------------------------------------------------\n");
                
                if (!found) {
                    printf("Tidak ada lagu yang ditemukan pada tahun %d.\n\n", searchKeyTahun);
                } 
                

                fflush(stdin);
            }
            else {
                    printf("Pilihan tidak valid.\n");
                }
            menu(track, counter);
            break;

            case 3:
                printf("Terima kasih telah menggunakan aplikasi ini!" );
                break;

            default:
                break;

            }
}


int main(){
    struct lagu track[100];
        int a;
        for(a=0;a<100;a++){
            strcpy(track[a].judul,"");
            strcpy(track[a].artis,"");
            strcpy(track[a].album,"");
            track[a].tahun=0;
        }

        int counter=0;
        int i =0;
        FILE *fp=fopen("database-musik.txt","r");
        while(!feof(fp)){
            fscanf(fp,"%[^*]*%[^*]*%[^*]*%d\n", track[i].judul, track[i].artis, track[i].album, &track[i].tahun);
            i++;
            counter++;
        }
        fclose(fp);
        printData(track,counter);
        menu(track,counter);
        return 0;
    return 0;
}