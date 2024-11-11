#include <stdio.h>
#include <string.h>

typedef struct personal{
    char name[40];
    char major[40];
    float gpa;
}student;


void printList(struct personal s[], int counter){
    int i;
    printf("                    List of Student Information                 \n");
    printf("----------------------------------------------------------------\n");
    printf("|No.|           Nama           |         Major         |  GPA  |\n");
    printf("----------------------------------------------------------------\n");
    for(i=0;i<counter;i++){
        printf("|%-3i| %-25s| %-22s| %-6.2f|\n", i+1, s[i].name, s[i].major, s[i].gpa);
    }
}


void insertStudent(struct personal s[], int counter){
    printf("     Insert Student Information      \n");
    printf("-------------------------------------\n");
    fflush(stdin);
    printf("Name   : ");scanf("%[^\n]",s[counter].name);
    fflush(stdin);
    printf("Major  : ");scanf("%[^\n]",s[counter].major);
    printf("GPA    : ");scanf("%f", &s[counter].gpa);
}


void menu(struct personal students[], int counter){
    int opt,i;
        printf("\nWelcome to simple student data base (%i/20)\n", counter);
        printf("1. Show all students\n2. Input new student\n3. Exit\nChoose: ");
        scanf("%d", &opt);
        switch(opt){
        case 1:     //show all students

            //printf("\t\t%d\n\n", counter);
            if(counter!=0 && counter<21){
                printList(students, counter);
                menu(students, counter);
                break;
            }
            else if(counter==0)(printf("\nDatabase is empty\n"));
                menu(students, counter);
                break;


            case 2:     // input new student
                if(counter>19){
                    printf("\nDatabases is full\n");
                    menu(students, counter);
                }
                else{
                    insertStudent(students, counter);
                    ++counter;
                    fflush(stdin);
                    menu(students, counter);
                }
                break;

            case 3:
                break;

            default:
                break;

            }

}


int main(){
    student students[20];
    int counter=0;
    menu(students,counter);
    return 0;
}