#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 //practice 8 Felix Ivander (00000070040)
int main(){
    char studentName, *studentID;

    system("cls");

    printf("Enter Student Name : ");
    scanf("%[^\n]", &studentName);
    
    printf("Enter Student ID : ");
    scanf("%s", &studentID);
    getchar();
    
    system("cls");
    
    printf("%s#%s\n\n",&studentName, &studentID);
    
    printf("Enter Student Name : %s\n", &studentName);    
    
    printf("Enter Student ID : %s\n", &studentID);

    return 0;
}