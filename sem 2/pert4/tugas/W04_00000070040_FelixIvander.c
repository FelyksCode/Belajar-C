#include <stdio.h>              //Felix Ivander_00000070040
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

struct Mahasiswa{
    int nim;
    char nama[100];
    char jurusan[30];
    struct Mahasiswa *next;
};

void printLinkedList(struct Mahasiswa *head){
    struct Mahasiswa *temp=(struct Mahasiswa*) malloc(sizeof(struct Mahasiswa));
    temp=head;
    int i=1;
    while(temp != NULL){
        printf("\nData ke %d\n", i);
        printf("NIM     : %011d\n", temp->nim);
        printf("Nama    : %s\n", temp->nama);
        printf("Jurusan : %s\n", temp->jurusan);
        temp=temp->next;
        i++;
    }
}

struct Mahasiswa* createNewNode(int nim, char *nama, char *jurusan){
    struct Mahasiswa *newNode=(struct Mahasiswa*) malloc(sizeof(struct Mahasiswa));
    newNode->nim=nim;
    strcpy(newNode->nama, nama);
    strcpy(newNode->jurusan, jurusan);
    newNode->next=NULL;
    return newNode;
}

struct Mahasiswa* InsertnewNode(struct Mahasiswa *head,struct Mahasiswa *node,struct Mahasiswa *tail){
    struct Mahasiswa *temp=(struct Mahasiswa*) malloc(sizeof(struct Mahasiswa));
    printf("\n\nNIM     : "); scanf("%d",&temp->nim); fflush(stdin);
    printf("Nama    : "); scanf("%[^\n]",temp->nama); fflush(stdin);
    printf("Jurusan : "); scanf("%[^\n]",temp->jurusan ); fflush(stdin);
    node=createNewNode(temp->nim,temp->nama,temp->jurusan);
    if(head==NULL){
        tail=node;
        head=tail;
    }
    else{
        if(head->next==NULL){
             tail=node;
             head->next=node;
        }else{
            struct Mahasiswa *pointer=(struct Mahasiswa*) malloc(sizeof(struct Mahasiswa));
            pointer=head;
            if(pointer->next != NULL)
                do{
                    tail=pointer;
                    pointer=pointer->next;
                }while(pointer != NULL);
                tail->next=node;
        }          
    } 
         return head; 
}

struct Mahasiswa* deleteFirstdata(struct Mahasiswa *head){
    struct Mahasiswa *temp=(struct Mahasiswa*) malloc(sizeof(struct Mahasiswa));
    temp=head;
    head=temp->next;

    free(temp);
   return head;
}

struct Mahasiswa* deletebyNim(struct Mahasiswa *head, struct Mahasiswa *tail){
    int inputnim=0;
    printf("Masukan NIM yang akan di hapus: ");
    scanf("%d", &inputnim);

    struct Mahasiswa *temp=(struct Mahasiswa*) malloc(sizeof(struct Mahasiswa));
    struct Mahasiswa *prvs=(struct Mahasiswa*) malloc(sizeof(struct Mahasiswa));
    temp=head;
    prvs=head;

    if(head->next == NULL){
        temp=head;
        head=temp->next;
        printf("\nData Deleted");
        return head;
    }

    while(temp->nim != inputnim && temp != NULL){ 
        temp=temp->next;
        if(temp->nim!=inputnim)
            break;
    }

    if(temp->nim!=inputnim)
        printf("\nData tidak ada");
    else{
        tail=temp->next;
        
        while(prvs->next->nim!=inputnim){
            prvs=prvs->next;
        }
            prvs->next=tail;
    
    free(temp);
    printf("\nData Deleted");
    }
   return head;
}


void menu(struct Mahasiswa *head,struct Mahasiswa *node,struct Mahasiswa *tail){
    
    int opt=0;
    printf("\n\n\n1. Insert New node\n2. Print linked list\n3. Delete all data\n4. Delete first data\n5. Delete data by nim\n0. Exit\nSelect option: ");
    scanf("%d",&opt);
    switch (opt){
    case 1:                         //Insert
        system("cls");
        head=InsertnewNode(head,node,tail);
        menu(head,node,tail);
        break;
    
    case 2:                         //Print
        system("cls");
        if(head != NULL)
            printLinkedList(head);
        else printf("\nThere is no Data");
        menu(head,node,tail);
        break;

    case 3:                         //Delete all data
        system("cls");
        while(head != NULL){
            node=head;
            head=head->next;
            free(node);
        }
        printf("\nDeleted All Data");
        menu(head,node,tail);
        break;

    case 4:                         //Delete first data
        system("cls");
        if(head != NULL){
            head=deleteFirstdata(head);
            printf("\nDeleted First Data");
            } else 
                printf("\nThere is no Data");
        menu(head,node,tail);
        break;

    case 5:                         //Delete data by nim
        system("cls");
        if(head != NULL){
            head=deletebyNim(head, tail);
            } else 
                printf("\nThere is no Data");
        menu(head,node,tail);
        break;

    case 0:                         //exit
        break;
    
    default:
        break;
    }

}

int main(){
    struct Mahasiswa *head=NULL, *node, *tail=NULL;
    node =(struct Mahasiswa*) malloc(sizeof(struct Mahasiswa));
    node->next=NULL;
    menu(head,node,tail);
    while(head != NULL){
        node=head;
        head=head->next;
        free(node);
    }
    return 0;
}