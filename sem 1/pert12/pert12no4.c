#include <stdio.h>
//no4 Felix Ivander (00000070040)
int main(){
	int  opt;
	double hasil = 0, n1, n2;
	printf("Menu \n1. pengurangan\n2. pembagian\n3. Exit\n");
	printf("pilih : "); 
    scanf("%d", &opt);
	
	input:
	printf("Input N1: "); scanf("%d", &n1);
	printf("Input N2: "); scanf("%d", &n2);
	switch(opt){
		case 1: 
			if(n1>n2){
				hasil = n1 - n2;
				printf("hasil : %d", hasil);
			}
			else{
				hasil = n2 - n1;
				printf("hasil : %d", hasil);
			}
			break;
		case 2: 
			if(n2 == 0){
				printf("input ulang\n");
				goto input;
			}
			else{
				hasil = n1 / n2;
				printf("hasil : %.2lf", hasil);
			}
			break;
		case 3:
			break;
	}
	return 0;
}