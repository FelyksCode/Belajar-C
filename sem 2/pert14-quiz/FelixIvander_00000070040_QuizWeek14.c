#include <stdio.h>
#include <string.h>

struct student{
    char name[40];
    char major[40];
    int nilai;
};

void printData(struct student s[], int counter){
    int i;
    printf("-----------------------------------------------------------------------------\n");
    printf("|No.|                Nama                   |        Major        |  Nilai  |\n");
    printf("-----------------------------------------------------------------------------\n");
    for(i=0;i<counter;i++){
        printf("|%-3i| %-38s| %-20s| %-8d|\n", i+1, s[i].name, s[i].major, s[i].nilai);
    }
    printf("-----------------------------------------------------------------------------\n");
}

void shellSort(struct student student[], int n){
    int i, j, gap;
    for(gap=n/2; gap>0; gap/=2){
        for(i=gap; i<n; i++){
            struct student temp = student[i];

            for(j=i; j>=gap && strcmp(student[j - gap].name, temp.name) > 0; j-=gap){
                student[j] = student[j-gap];
            }
            student[j] = temp;
        }
    }
}

void binarySearch(struct student s[], int size, char key[]){
    int low = 0;
    int high = size - 1;
    int found = 0;

    while (low <= high) {
        int mid = (low + high) / 2;
        int result = strcmp(s[mid].name, key);

        if (result == 0) {
            printf("\nMahasiswa ditemukan!\n");
            printf("Nama: %s\n", s[mid].name);
            printf("Jurusan: %s\n", s[mid].major);
            printf("Nilai: %d\n", s[mid].nilai);
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
        printf("\nMahasiswa tidak ditemukan.\n");
    }
}

void menu(struct student students[], int counter){
    int opt,i;
        printf("\nWelcome to simple student data base (%i/100)\n", counter);
        printf("1. Show all students\n2. Cari Mahasiswa\n3. Keluar Program\nChoose: ");
        scanf("%d", &opt);
        switch(opt){
        case 1:     //show all students
            if(counter!=0 && counter<101){
                printData(students, counter);
                menu(students, counter);
                break;
            }
            else if(counter==0)(printf("\nDatabase is empty\n"));
                menu(students, counter);
                break;
            
            case 2:
                char searchKey[40];
                int found = 0;
                shellSort(students, counter);

                printf("Masukkan nama mahasiswa yang dicari: "); 
                fflush(stdin);
                scanf("%[^\n\r]", searchKey);
                binarySearch(students, counter, searchKey);
                fflush(stdin);

                menu(students, counter);
                break;

            case 3:
                printf("Terima kasih telah menggunakan aplikasi ini!" );
                break;

            default:
                break;

            }
}


int main(){
    
    struct student students[100];
    int a;
    for(a=0;a<100;a++){
        strcpy(students[a].name,"");
        strcpy(students[a].major,"");
        students[a].nilai=0;
    }

    int counter=0;
    int i =0;
    FILE *fp=fopen("database_nilai.txt","r");
    while(!feof(fp)){
        fscanf(fp,"%[^😭]😭%[^😭]😭%d\n", students[i].name, students[i].major, &students[i].nilai);
        i++;
        counter++;
    }
    fclose(fp);
    menu(students,counter);
    return 0;
}