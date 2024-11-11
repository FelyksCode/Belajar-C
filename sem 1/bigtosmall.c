#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct user{
    char name[50];
    int score;
    int i;

};

int main(){
    //int first=1, second=2, third=3 ,temp;
    int i;
    struct user user1;
    struct user user2;
    struct user user3;
    struct user user4;
    struct user user5;

    struct user users[]={user1, user2, user3, user4, user5};
    FILE *skor;

    if(i!=0)
    {   skor=fopen("skor.dat","r");
        fscanf(skor,"%d",&i);
        fclose(skor);
    };
    printf("Input name: ");
    fgets(users[i].name,50,stdin);

    printf("Input score now is ");
    scanf("%d", &users[i].score);
    i++;

    skor=fopen("skor.dat","w");
    fwprintf(users->i,sizeof(users),1,skor);
    fclose(skor);


    skor=fopen("skor.dat","a+");
		fwrite(&users,sizeof(users),1,skor);
		if(fwrite != 0){
			printf("Succesfully registered");
            
		}
    fclose(skor);    
    
    skor=fopen("skor.dat","r");
    if(skor == NULL) printf("\n\n belom terdaftar");
    else{
        fread(&users,sizeof(struct user),1,skor);
	    fclose(skor);
    }
    printf("\n%s \n%d",users->name, users->score);
    printf("\n%d", i);
    
    
    
    /**printf("First score now is ");
    scanf("%d", &first);

    printf("\nSecond score now is ");
    scanf("%d", &second);
    
    printf("\nThird score now is ");
    scanf("%d", &third);

    printf("\n\nsebelum swap \n%d \n%d \n%d", first, second, third);

    if(first < second){
     temp=first;
     first=second;
     second=temp;   
    }
    if(second < third){
        temp=second;
        second=third;
        third=temp;
    }
    if(first < second){
        temp=first;
        first=second;
        second=temp; 
    }

    printf("\n\nBig to small\n%d \n%d \n%d", first, second, third);**/

    return 0;
}