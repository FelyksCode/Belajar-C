#include <stdio.h>
#include <ctype.h>
#include <string.h>

void upcase(char *word){
    int i=0;
    char ch;
    while(word[i]!='\0'){
        ch= word[i];
        putchar(toupper(ch));
        i++;
    }
}

void lowcase(char *word){
    int i=0;
    char ch;
    while(word[i]!='\0'){
        ch= word[i];
        putchar(tolower(ch));
        i++;
    }
}

void switchcase(char *word){
    char ch;
    for(int i=0; word[i]; i++){
        if(islower(word[i])){
            word[i] = toupper(word[i]);
        } else if(isupper(word[i])){
            word[i]=tolower(word[i]);
        }
    }
}


int main(){
    int pilihan;
    char word[30];
    printf("1. Uppercase \n2. Lowercase\n3.Switching\n4.Keluar\nPilihan : ");
    scanf("%d",&pilihan);
    switch (pilihan)
    {
    case 1: //Upercase
        printf("Masukan kata: ");
        fflush(stdin);
        fgets(word, 30, stdin);
        upcase(word);
        break;
    
    case 2: //lowercase
        printf("Masukan kata: ");
        fflush(stdin);
        fgets(word, 30, stdin);
        lowcase(word);
        break;

    case 3: //switchcase
        printf("Masukan kata: ");
        fflush(stdin);
        fgets(word, 30, stdin);
        switchcase(word);
        printf("\n%s",word);
        break;

    case 4:
        break;
    
    default:
        break;
    }

    return 0;
}


