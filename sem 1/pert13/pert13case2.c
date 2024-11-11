#include<stdio.h>
#include<conio.h>
#include<string.h>
#define ENTER 13
#define TAB 9
#define BCKSPC 8

struct user{                        
	char fullname[50];
	char password[50];
	char username[50];
	
};

void takeinput(char ch[50]){            //Modul Input
	fgets(ch,50,stdin);
	ch[strlen(ch) - 1] = 0; 
}

char generateUsername(char fullname[50],char username[50]){ // Modul membuat username dari nama panjang
	                //fullname: Felix Ivander
	for(int i=0;i<strlen(fullname);i++){
		if(fullname[i] == ' ' || fullname[i] == '\0') break;
		else username[i] = fullname[i];
	}
}

void takepassword(char pwd[50]){        //Modul Input Password
	int i;
	char ch;
	while(1){
		ch = getch();
		if(ch == ENTER || ch == TAB){
			pwd[i] = '\0';
			break;
		}else if(ch == BCKSPC){
			if(i>0){
				i--;
				printf("\b \b");
			}
		}else{
			pwd[i++] = ch;
			printf("* \b");
		}
	}
}


int main(){                             
	FILE *fp;                               //Declare File?
	int opt;
	struct user user;
	char password2[50];        //Password2 buat konfirmasi Password
	
	printf("\n\t----------Menu Awal----------");
	printf("\nPilihlah salah satu dari dibawah ini");
	printf("\n1.Registrasi");
	printf("\n2.Login");
	printf("\n3.Exit");
	
	printf("\n\nPilihanmu:\t");
	scanf("%d",&opt);
	fgetc(stdin);
	
	switch(opt){
		case 1:
			system("cls");
			printf("Masukan Nama Panjang:\t");
			takeinput(user.fullname);
			printf("Masukan password:\t");
			takepassword(user.password);
			printf("\nKonfirmasi password:\t");
			takepassword(password2);
			
			if(!strcmp(user.password,password2)){
				generateUsername(user.fullname,user.username);
				
				fp=fopen("data.txt","w+");
				fwrite(&user,sizeof(user),1,fp);
				if(fwrite != 0) printf("\n\nRegistrasi berhasil, Your username is %s",user.username);
				else printf("\n\nOops! Something went wrong :(");
				fclose(fp);
			}
			else{
				printf("\n\nKonfirmasi password salah");
			}
		break;
		
		case 2:

			char username[50],pword[50];
			struct user usr;
			

			printf("\nMasukan username:\t");
			takeinput(username);
			printf("Masukan password:\t");
			takepassword(pword);
			
			fp=fopen("data.txt","r");
			if(fp == NULL) printf("\n\nUser belom terdaftar!");
			else{
				fread(&usr,sizeof(struct user),1,fp);
				fclose(fp);
				//printf("\n\n%s \t%s", username, usr.username);
				//printf("\n\n%s \t%s", pword, usr.password);

			
					if(!strcmp(pword,usr.password)){
			
						system("cls");
						
						printf("\nLogin Berhasil");
						printf("\n|Username:\t\t%s",username);
						
					}
					else {
						printf("\n\nPassword Salah!");
					}

			}
			
			break;
			
		case 3:
			printf("\t\t\tBye Bye :)");
			return 0;
			
	}
	
	
	
	return 0;
}