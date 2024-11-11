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

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int *bil, int n){
    int i, j;

    for(i=1; i<n; i++){
        for(j=n-1; j>=1; j--){
            if(bil[j]>bil[j-1]){
                swap(&bil[j], &bil[j-1]);
            }
        }
    }
}

void selectionSort(int *bil, int n){
    int i, j, temp;
    for(i=0; i<n; i++){
        temp = i;

        for(j=i+1; j<n; j++){
            if(bil[j] > bil[temp]){
                temp = j;
            }
        }

        if(temp != i){
            swap(&bil[temp], &bil[i]);
        }
    }
}

void insertionSort(int *bil, int n){
    int i, j, temp;
    for(i=0; i<n; i++){
        temp = bil[i];

        for(j=i-1; j>=0 && bil[j] < temp; j--){
            bil[j+1] = bil[j];
        }
        bil[j+1]=temp;
    }
}

int main(){
    int i, n, j, *bil;
    int data[100], maks;
    struct LinkedList *bucket[10];
    for(i=0; i<10; i++){
        bucket[i] = NULL;
    }

    printf("Banyak bilangan: "); scanf("%d", &n);
    bil = malloc(sizeof(int) * n);

    for(i=0; i<n; i++){
        printf("Input bilangan ke-%d: ", i+1); scanf("%d", &bil[i]);
        data[i]=bil[i];
        if(i==0 || maks < data[i]){
            maks = data[i];
        }
    }

    bubbleSort(bil, n);

    printf("Hasil bubble sort:\n");
    for(i=0; i<n; i++){
        printf("%d ", bil[i]);
    }

    selectionSort(bil, n);

    printf("\nHasil selection sort:\n");
    for(i=0; i<n; i++){
        printf("%d ", bil[i]);
    }

    insertionSort(bil, n);

    printf("\nHasil insertion sort:\n");
    for(i=0; i<n; i++){
        printf("%d ", bil[i]);
    }



    int totalIterasi = 0;
    while(maks > 0){
        maks /= 10;
        totalIterasi++;
    }
    printf("\nTotal iterasi yang akan dilakukan adalah: %d\n", totalIterasi);

    int pembagi = 1;
    for(i=0; i<totalIterasi; i++){
        for(j=0; j<n; j++){
            int digit = (data[j]/pembagi)%10;
            insertNode(data[j], &bucket[digit]);
        }
        pembagi *= 10;

        printf("\n====\nIterasi %d\n",i+1);
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

    free(bil);

    return 0;

}