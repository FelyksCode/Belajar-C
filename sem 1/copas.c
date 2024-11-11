#include<stdio.h>
#include<string.h>
#include<stdlib.h>


struct user {
	char phone[50];
	char ac[50];
	char password[50];
	float balance;
};

int main(){
	struct user user,usr;
	char filename[50],phone[50],password[50],phone2[50];
	FILE *fp,*fptr;
	int opt,choice;
	int amount;
	char cont = 'y';
	printf("\nWhat do you want to do?");
	printf("\n\n1.Register your account");
	printf("\n2.Login to your account");

	printf("\n\nPlease enter your choice:\t");
	scanf("%d",&opt);
	if(opt == 1){
		system("cls");
		printf("\nEnter your account number:\t");
		scanf("%s",user.ac);
		printf("Enter your phone number:\t");
		scanf("%s",user.phone);
		printf("Enter your new password:\t");
		scanf("%s",user.password);
		user.balance=0;
		stpcpy(filename,user.phone);
		fp=fopen(strcat(filename,".dat"),"w");
		fwrite(&user,sizeof(user),1,fp);
		if(fwrite != 0){
			printf("Succesfully registered");
		}
	}
	else if(opt == 2){
		system("cls");
		printf("\nPhone No.:\t");
		scanf("%s",phone);
		printf("Password:\t");
		scanf("%s",password);
		fp=fopen(strcat(phone,".dat"),"r");
		if(fp == NULL) printf("Account number not registered");
		else {
			fread(&user,sizeof(struct user),1,fp);
			fclose(fp);

				printf("\n\n%s \t%s", phone, user.phone);
				printf("\n\n%s \t%s", password, user.password);

		if(!strcmp(password,user.password)){ 
				while(cont == 'y'){
				system("cls");
				printf("\n\tWelcome %s",user.phone);
				printf("\nPress 1 for balance inquiry");
				printf("\nPress 2 for adding fund");
				printf("\nPress 3 for cash withdraw");
				printf("\nPress 4 for online transfer");
				printf("\nPress 5 for changing password\n\n");

				break;
				}
			}
		}
	return 0;
}
}