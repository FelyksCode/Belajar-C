#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

struct kontak{
    char nama[30];
    int noTelp;
    struct kontak *next, *prev;
};

struct kontak *penting;
char P;

void menu(){
    printf("\n1. Tampilkan Data Kontak\n2. Tambahkan Kontak\n3. Hapus kontak\n4. About me\n5. Exit\nChoice: ");
}

void printData(struct kontak *head){
    struct kontak *temp =(struct kontak*) malloc(sizeof(struct kontak));
    temp=head;
    while(temp!=NULL){
        printf("Nama      = %s\n", temp->nama);
        printf("No telpon = %d\n", temp->noTelp);
        temp=temp->next;
    }
}

void printSatu(struct kontak *head){
    struct kontak *temp =(struct kontak*) malloc(sizeof(struct kontak));
    temp=head;
    while(temp!=NULL){
        printf("Nama      = %s\n", temp->nama);
        printf("No telpon = %d\n", temp->noTelp);
        temp=temp->next;
        printf("Tambahkan kontak penting?[Y/N]\n");
        scanf("%c",penting);
        if(penting)
        getchar();
    }
}

void tambahKontak(struct kontak **head, struct kontak **tail, struct kontak **nodeBaru){
    struct kontak *temp=(struct kontak*) malloc(sizeof(struct kontak));
    temp=(*nodeBaru);
    temp->prev=temp->next=NULL;
    if(*head==NULL){
        *head=*tail=temp;
    }
    else{
        temp->prev=*tail;
        (*tail)->next=temp;

    }
        *tail=temp;
}

void deleteKontak(struct kontak **head, struct kontak **tail){
    struct kontak *temp=(struct kontak*) malloc(sizeof(struct kontak));
    if((*tail)->prev==NULL){
        *tail=*head=NULL;
    }else{
        temp=*tail;
        *tail=(*tail)->prev;
        (*tail)->next=NULL;
        free(temp);
    }
}

void showData(struct kontak **head, struct kontak **tail, struct kontak **node){
    int choice=0;
    printf("\n1.Tampil seluruh\n2.Tampil satu-satu\n3.Exit\nChoice: ");
    scanf("%d", &choice);
    fflush(stdin);
    while(choice!=3){
        switch(choice){
            case 1: //show data umum
                if(*head==NULL)
                    printf("KOSONG\n");
                else{
                    printData(*head);
                }
                printf("\n1.Tampil seluruh\n2.Tampil satu-satu\n3.Exit\nChoice: ");
                scanf("%d", &choice);
                fflush(stdin);
                break;

            case 2: //show data satusatu
                printSatu(*head);
                printf("\n1.Tampil seluruh\n2.Tampil satu-satu\n3.Exit\nChoice: ");
                scanf("%d", &choice);
                fflush(stdin);
                break;


            default:
                break;
        }
    }
}

int main(){
    int choice=0;
    struct kontak *head, *node, *tail;
    head=tail=NULL;
    node=NULL;
    char name[30];
    int number;

    menu();
    scanf("%d", &choice);
    fflush(stdin);
    while(choice!=5){
        switch (choice){
        case 1:     //Show Data
            showData(&head,&tail,&node);
            menu();
            scanf("%d", &choice);
            fflush(stdin);
            break;
        
        case 2:     //Add Data
            printf("Masukan Nama    : "); scanf("%[^\n]", name);
            getchar();
            fflush(stdin);
            printf("Masukan No Telp : "); scanf("%d", &number);
    
            node = (struct kontak*) malloc(sizeof(struct kontak));
            strcpy(node->nama,name);
            node->noTelp=number;
            printf("%s, %d\n",node->nama,node->noTelp);

            tambahKontak(&head, &tail, &node);
            printf("Selesai Menambah Kontak\n");
            menu();
            scanf("%d", &choice);
            fflush(stdin);
            break;
        
        case 3:     //Hapus Kontak
            if(head==NULL){
                printf("Kosong\n");
            }else{
                deleteKontak(&head, &tail);
                printf("Selesai Menghapus Kontak\n");
            }
            menu();
            scanf("%d", &choice);
            fflush(stdin);
            break; 

        case 4:     //Show about me
            printf("INI LAMAN ABOUT ME SAYA\n");
            menu();
            scanf("%d", &choice);
            fflush(stdin);
            break;

        default:
            break;
        }
    }


    return 0;
}