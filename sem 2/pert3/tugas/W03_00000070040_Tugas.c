#include <stdio.h>
#include <string.h>

typedef struct personal{
    int nim;
    char name[40];
    char major[40];
    int tugas,uts,uas;
    float nilaiAkhir;
    char grade[2];
}student;


void printData(struct personal s[], int counter){
    int i;
    printf("                              List of Student Data                           \n");
    printf("-----------------------------------------------------------------------------\n");
    printf("|No.|           NIM           |         Nama           |         Major      |\n");
    printf("-----------------------------------------------------------------------------\n");
    for(i=0;i<counter;i++){
        printf("|%-3i| %-24.011d| %-23s| %-19s|\n", i+1, s[i].nim, s[i].name, s[i].major);
    }
}

void printNilai(struct personal s[], int counter){
    int i;
    printf("                              List of Student Grades                           \n");
    printf("--------------------------------------------------------------------------------------\n");
    printf("|No.|           NIM           |  Tugas  |  UTS  |  UAS   |  Nilai Akhir  |   Grade   |\n");
    printf("--------------------------------------------------------------------------------------\n");
    for(i=0;i<counter;i++){
        printf("|%-3i| %-24.011d| %-8d| %-7d| %-6d| %-15.2f| %-9s|\n", i+1, s[i].nim, s[i].tugas, s[i].uts, s[i].uas, s[i].nilaiAkhir, s[i].grade);
    }
}

void printSearch(struct personal s[], int i){
    printf("                                        Hasil Pencarian                                 \n");
    printf("----------------------------------------------------------------------------------------\n");
    printf("|     NIM     |    NAMA    |    Major    | Tugas |  UTS  |  UAS  | Nilai Akhir | Grade |\n");
    printf("----------------------------------------------------------------------------------------\n");
    
        printf("| %-12.011d| %-11s| %-12s| %-6d| %-6d| %-6d| %-12.2f| %-6s|\n", s[i].nim, s[i].name, s[i].major, s[i].tugas, s[i].uts, s[i].uas, s[i].nilaiAkhir, s[i].grade);
    
}


void insertStudent(struct personal s[], int counter){
    
    printf("     Insert Student Information      \n");
    printf("-------------------------------------\n");
    fflush(stdin);
    printf("NIM    : ");scanf("%d",&s[counter].nim);
    fflush(stdin);
    printf("Name   : ");scanf("%[^\n]",s[counter].name);
    fflush(stdin);
    printf("Major  : ");scanf("%[^\n]",s[counter].major);
    fflush(stdin);
    printf("Nilai Tugas  : ");scanf("%d", &s[counter].tugas);
    fflush(stdin);
    printf("Nilai UTS    : ");scanf("%d", &s[counter].uts);
    fflush(stdin);
    printf("Nilai UAS    : ");scanf("%d", &s[counter].uas);
}

void calculate(struct personal s[], int counter){
    int j=0,k=0,l=0;
        j= 0.3 * s[counter].tugas;    
        k= 0.3 * s[counter].uts;  
        l= 0.4 * s[counter].uas;
        s[counter].nilaiAkhir= j+k+l;
    
    if(s[counter].nilaiAkhir>=95 && s[counter].nilaiAkhir<=100)(strcat(s[counter].grade,"A+"));
    else if(s[counter].nilaiAkhir>=85 && s[counter].nilaiAkhir<=94.99)(strcat(s[counter].grade,"A"));
         else if(s[counter].nilaiAkhir>=80 && s[counter].nilaiAkhir<=84.99)(strcat(s[counter].grade,"A-"));
              else if(s[counter].nilaiAkhir>=75 && s[counter].nilaiAkhir<=79.99)(strcat(s[counter].grade,"B+"));
                   else if(s[counter].nilaiAkhir>=70 && s[counter].nilaiAkhir<=74.99)(strcat(s[counter].grade,"B"));
                        else if(s[counter].nilaiAkhir>=65 && s[counter].nilaiAkhir<=69.99)(strcat(s[counter].grade,"C"));
                             else if(s[counter].nilaiAkhir>=60 && s[counter].nilaiAkhir<=64.99)(strcat(s[counter].grade,"C-"));
                                  else if(s[counter].nilaiAkhir>=55 && s[counter].nilaiAkhir<=59.99)(strcat(s[counter].grade,"D"));
                                       else(strcat(s[counter].grade,"E"));
}

void shellSort(struct personal student[], int n){
    int i, j, gap;
    for(gap=n/2; gap>0; gap/=2){
        for(i=gap; i<n; i++){
            struct personal temp = student[i];

            for(j=i; j>=gap && student[j-gap].nim > temp.nim; j-=gap){
                student[j] = student[j-gap];
            }
            student[j] = temp;
        }
    }
}

int binarySearch(struct personal student[], int size, int key){
    int low, mid, high;

    low = 0;
    high = size-1;

    while(low <= high){
        mid = (low+high) /2;

        if(student[mid].nim == key) return mid;
        if(key < student[mid].nim) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}

void menu(struct personal students[], int counter){
    int opt,i;
        shellSort(students, counter);
        printf("\nWelcome to simple student data base (%i/100)\n", counter);
        printf("1. Show all students\n2. Show student grades\n3. Input new student\n4. Show Student Detail\n5. Exit\nChoose: ");
        scanf("%d", &opt);
        switch(opt){
        case 1:     //show all students

            //printf("\t\t%d\n\n", counter);
            if(counter!=0 && counter<101){
                printData(students, counter);
                menu(students, counter);
                break;
            }
            else if(counter==0)(printf("\nDatabase is empty\n"));
                menu(students, counter);
                break;

        case 2:     //show all grades
            //printf("\t\t%d\n\n", counter);
            if(counter!=0 && counter<101){
                printNilai(students, counter);
                menu(students, counter);
                break;
            }
            else if(counter==0)(printf("\nDatabase is empty\n"));
                menu(students, counter);
                break;

            case 3:     // input new student
                if(counter>99){
                    printf("\nDatabases is full\n");
                    menu(students, counter);
                }
                else{
                    insertStudent(students, counter);
                    calculate(students, counter);
                    FILE *fws=fopen("dataMahasiswa.txt","a+");
                    fprintf(fws, "\n%.011d#%s#%s",students[counter].nim, students[counter].name, students[counter].major);
                    fclose(fws);

                    FILE *fwn=fopen("nilaiMahasiswa.txt", "a+");
                    fprintf(fwn,"\n%.011d#%d#%d#%d#%f#%s",students[counter].nim,students[counter].tugas,students[counter].uts,students[counter].uas,students[counter].nilaiAkhir,students[counter].grade);
                    fclose(fwn);
                    ++counter;
                    fflush(stdin);
                    menu(students, counter);
                }
                break;
            
            case 4:
                int searchKey;
                int found = 0;
                // printf("%d",counter);
                shellSort(students, counter);
                printData(students, counter);
                printf("Masukkan nim yang dicari: "); scanf("%d", &searchKey);

                found = binarySearch(students, counter, searchKey);
                
                if(found != -1){
                    printSearch(students, found);
                }else{
                    printf("NIM %d tidak ditemukan",searchKey);
                }
                fflush(stdin);
                menu(students, counter);
                break;

            case 5:
                break;

            default:
                break;

            }
}


int main(){
    student students[100];
    int a;
    for(a=0;a<100;a++){
        students[a].nim=0;
        strcpy(students[a].major,"");
        strcpy(students[a].name,"");
        students[a].tugas=0;
        students[a].uts=0;
        students[a].uas=0;
        students[a].nilaiAkhir=0;
        strcpy(students[a].grade,"");
    }

    int counter=0;
    int i =0;
    FILE *fp=fopen("dataMahasiswa.txt","r");
    while(!feof(fp)){
        fscanf(fp,"%d#%[^#]#%s", &students[i].nim, students[i].name, students[i].major);
        i++;
        counter++;
    }
    fclose(fp);

    counter=0;
    i=0;
    FILE *fnilai=fopen("nilaiMahasiswa.txt","r");
    while(!feof(fnilai)){
        fscanf(fnilai,"%d#%d#%d#%d#%f#%s", &students[i].nim, &students[i].tugas, &students[i].uts, &students[i].uas, &students[i].nilaiAkhir, students[i].grade);
        i++;
        counter++;
    }
    fclose(fnilai);
    menu(students,counter);
    return 0;
}