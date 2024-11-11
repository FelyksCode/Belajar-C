//Practice 2
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void header(){
	system("cls");
	printf("==========================\n");
	printf("Sistem Login 1.0\n\n");
}

int menu(int *a, int b){
	FILE *test;
	test = fopen("Daftar User - Gilbert Evan Tilung.txt", "r+");
	
	header();
	if(b == 1){
		printf("Username atau Password salah!\n");
	}else if(test == NULL){
		printf("File tidak ditemukan!\n");
		printf("Silahkan tunggu sebentar...");
		fopen("Daftar User - Gilbert Evan Tilung.txt", "w");
		sleep(1.5);
		return 0;
	}
	printf("Silahkan pilih salah satu:\n 1. Login\n 2. Daftar\n");
	printf("\nMenu Input: ");
	scanf("%d", a);
}

int login(int *c){
	char a[90], aFile[90], ch;
	int count = 0, stateCheck = 0, bFile, b;
	FILE *baca;
	baca = fopen("Daftar User - Gilbert Evan Tilung.txt", "r+");
	
	screen:
	header();
	printf("Username Case Sensitive!");
	if(*c == 1){
		printf(" (Username atau Password salah)");
 	}
	printf("\nUsername: ");
	scanf("%s", &a);
	printf("Password: ");
	scanf("%d", &b);
	
	// how many lines
	while((ch = fgetc(baca)) != EOF){
		if(ch == '\n'){
			count++;
		}
	}
	
	fseek(baca, 0, SEEK_SET);
	for(int i=0; i<=count; i++){
		fscanf(baca, "%d#%[^\n]\n", &bFile, aFile);
		if ((bFile == b) && (strcmp(aFile, a)==0)){
			header();
			printf("Selamat Datang, %s", aFile);
			printf("\nSuccess!");
			break;
		}else if(feof(baca) && i == count){
			*c = 1;
			break;
		}
	}
}

int daftar(){
	char nama[90], password[6], a[90], b[6], ch;
	int count=0, state;
	FILE *tambah;
	tambah = fopen("Daftar User - Gilbert Evan Tilung.txt", "a+");
	
	atas:
	header();
	
	if(state == 1){
		printf("Username dan Password sudah terdaftar\n");
	}
	printf("Tulis nama yang ingin didaftar (1 kata, username case sensitive)\n");
	printf("Username: ");
	scanf("%s", nama);
	
	printf("\nTulis password yang ingin didaftar (6 Digit)\n");
	printf("Password: ");
	scanf("%s", password);
	
	while((ch = fgetc(tambah)) != EOF){
		if(ch == '\n'){
			count++;
		}
	}

	fseek(tambah, 0, SEEK_SET);
	for(int i=0; i<=count; i++){
		state == 0;
		fscanf(tambah, "%[^#]#%s", b, a);
		if((strcmp(a, nama)==0) && (strcmp(b, password)==0)){
			state = 1;
			break;
		}
	}
	
	if(state == 1){
		goto atas;
	}
	
	fprintf(tambah, "%s#%s\n", password, nama);
}

int main(){
	int menuInput = 0, stateCheck = 0;
	FILE *check;
	
	awal:
	menu(&menuInput, stateCheck);
	
	if(menuInput == 1){
		login(&stateCheck);
		if(stateCheck != 0){
			goto awal;
		}
	}else if(menuInput == 2){
		stateCheck = 0;
		daftar();
	}
}