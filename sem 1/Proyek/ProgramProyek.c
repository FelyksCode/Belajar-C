#include<stdio.h>	
#include<conio.h>  	//getch()
#include<math.h>	//rng
#include<stdlib.h>	
#include<time.h>	
#include<string.h>
#define ENTER 13
#define TAB 9
#define BCKSPC 8



int game(char you, char computer)
{
    if (you == computer)
        return -1;
    else if (you == 'r' && computer == 'p')
        return 0;
            else if (you == 'p' && computer == 'r')
                return 1;
    if (you == 'r' && computer == 's')
        return 1;
    else if (you == 's' && computer == 's')
        return 0;
    if (you == 'p' && computer == 's')
        return 0;
    else if (you == 's' && computer == 'p')
        return 1;
}

// Game Code
int gameprogram()
{

	int life = 3;
    int userPoint = 0;
    while(life != 0){
            // Stores the random number
            int n;
            char you, computer, result;
			 printf("\nEnter r for ROCK, p for PAPER and s for SCISSOR\n");
            // input from the user
            scanf("%c", &you), getchar();
            srand(time(NULL));

            // Make the random number less
            // than 10, divided it by 10
            n = rand() % 10;

            if (n < 3)
                // s is denoting Rock
                computer = 'r';
            else if (n > 3 && n < 6)
                // p is denoting Paper
                computer = 'p';
            // z is denoting Scissor
            else
                computer = 's';
            // Function Call to play the game
            result = game(you, computer);
            if (result == -1) {
				system("cls");
                printf("\nGame Draw!\n");
            }
            else if (result == 1) {
                system("cls");
				printf("\nWow! You have won the game!\n");
                userPoint += 1;
            }
            else {
                system("cls");
				printf("\nOh! You have lost the game!\n");
                life -= 1;
            }
                printf("\nYou choose : %c and Computer choose : %c\n",you, computer);
                printf("\nLife = %d, Point = %d\n\n\n", life, userPoint);
			if (life==0) {
				 system("cls");
				 printf("GAME OVER!");
				 printf("\nPoint = %d\n\n\n", userPoint);
				 return 0;
			}
    }
    return 0;
}


struct user{                        //Variabel global yang dipakai ada 3
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
	char password2[50], filename[50];         //Password2 buat konfirmasi Password
    char username[50],pword[50];
    struct user usr;

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
				stpcpy(filename,user.username);
				fp=fopen(strcat(filename,".dat"),"w");
				fwrite(&user,sizeof(user),1,fp);
				fclose(fp);
			if(fwrite != 0) {
                    printf("\n\nRegistrasi berhasil, Your username is %s",user.username);
            }else printf("\n\nOops! Something went wrong :(");

                return 0;
			}
			else{
				printf("\n\nKonfirmasi password salah");
				//printf("\n\n%s \t%s", user.password, password2);
			}
		break;

		case 2:
			printf("\nMasukan username:\t");
			takeinput(username);
			printf("Masukan password:\t");
			takepassword(pword);

			fp=fopen(strcat(username,".dat"),"r");
			if(fp == NULL) printf("\n\nUser belom terdaftar!");
			else{
				fread(&usr,sizeof(struct user),1,fp);
				fclose(fp);
					//printf("\n\n%s \t%s", username, usr.username);
					//printf("\n\n%s \t%s", pword, usr.password);


					if(!strcmp(pword,usr.password)){

						system("cls");
						printf("\n|Nama panjang:\t\t%s",usr.fullname);
						printf("\n|Username:\t\t%s",usr.username);
						gameprogram();
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

