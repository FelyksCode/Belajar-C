#include<stdio.h>
#include<math.h>
//Latihan 3 Felix Ivander(00000070040)
int main(){
    int pH;

    printf("Masukan pH: ");
    scanf("%d", &pH);
    getchar();
    
    if(pH >7){
        if(pH <12 ) printf("\nAlkaline");
        else printf("\nVery Alkaline");
    if(pH == 7) printf("\nNeutral");
    }
    else{
        if(pH>2) printf("\nAcidic");
        else printf("\nVery Acidic");
    }
    
    return 0;

}