#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int score=0, add;
    char user[50];
    FILE *top;
    
    printf("\nInput user: ");
    fgets(user,50,stdin);
    printf("your ID is %s", user);

    printf("your score now is %d", score);
    printf("\npress number to +");
    scanf("%d", &add);
    score+=add;
    printf("your score now is %d", score);
    

    
    top=fopen("score.dat","w");
				fwrite(&score,sizeof(score),1,top);
				if(fwrite != 0) printf("\n\nYour score is %d",score);
				else printf("\n\nOops! Something went wrong :(");
				fclose(top);



    return 0;
}