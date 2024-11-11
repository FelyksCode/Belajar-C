#include <stdio.h>
#include <stdlib.h>

struct LinkedList{
    int value;
    struct LinkedList *next;
};

void insertNode(int val, struct LinkedList** head) {
    struct LinkedList* newNode = malloc(sizeof(struct LinkedList));
    newNode->value = val;
    newNode->next = *head;
    *head = newNode;
}


int main(){
    int i, j, n, data[100], maks;
    struct LinkedList *bucket[10];
    for(i=0; i<10; i++){
        bucket[i] = NULL;
    }

    printf("Masukan jumlah data yang akan di sort: "); scanf("%d",&n);
    for(i=0; i<n; i++){
        printf("Input bilangan bulat ke-%d: ", i+1); scanf("%d",&data[i]);
        if(i==0 || maks < data[i]){
            maks = data[i];
        }
    }

    int totalIterasi = 0;
    while(maks > 0){
        maks /= 10;
        totalIterasi++;
    }
    printf("\n Total iterasi yang akan dilakukan adalah: %d\n", totalIterasi);

    int pembagi = 1;
    for(i=0; i<totalIterasi; i++){
        for(j=0; j<n; j++){
            int digit = (data[j]/pembagi)%10;
            insertNode(data[j], &bucket[digit]);
        }
        pembagi *= 10;

        printf("\n================\nIterasi %d\n",i+1);
        for (j = 9; j >= 0; j--) {
            printf("Bucket[%d]: ", j);
            struct LinkedList* temp = bucket[j];
            while (temp != NULL) {
                printf("%d ", temp->value);
                temp = temp->next;
            }
            printf("\n");
        }


        int idx = 0;
        for(j=0; j<10; j++){
            struct LinkedList *temp = bucket[j];
                while(temp!=NULL){
                    data[idx]=temp->value;
                    idx++;
                    temp=temp->next;
                }
        }

        printf("isi sementara array\n");
        for (j = n - 1; j >= 0; j--) {
            printf("%d ", data[j]);
        }
        printf("\n");
        
        for(j=0; j<10; j++){
            struct LinkedList *trash, *temp = bucket[i];
            while(temp != NULL){
                trash = temp;
                temp = temp->next;
                free(trash);
            }
            bucket[j]=NULL;
        }
    }
    printf("\nHasil setelah di sort\n");
    for (j = n - 1; j >= 0; j--) {
        printf("%d ", data[j]);
    }

    return 0;
}