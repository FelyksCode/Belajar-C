#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

struct Playlist{
    char singer[50];
    char song [50];
    char album [50];
    int year;
    struct Playlist *next, *prev;
};


void printLinkedList(struct Playlist *head){
    struct Playlist *temp = (struct Playlist*) malloc(sizeof(struct Playlist));
    temp=head;
     printf("Singer                  Song title              Album                   Released Year\n");
    while(temp != NULL){
        printf("%-23s\t%-23s\t%-23s\t%-10d\n", temp->singer,temp->song,temp->album,temp->year);
        temp=temp->next;
    }
}

void createNewnode(char *tempsinger[], char *tempalbum[], char *tempsong[],int tempyear, struct Playlist **tail, struct Playlist **head){
    struct Playlist *newNode; 
    newNode = (struct Playlist*) malloc(sizeof(struct Playlist));
    strcpy(newNode->singer, *tempsinger);
    strcpy(newNode->album, *tempalbum);
    strcpy(newNode->song, *tempsong);
    newNode->year=tempyear;
    newNode->next=NULL;
    newNode->prev=NULL;

    if((*head) == NULL){
        newNode->prev = NULL;
        *head = *tail = newNode;
    }
    else{
        newNode->prev = (*tail);
        (*tail)->next = newNode;
        newNode->next=NULL;
        (*tail) = newNode;
    }
    // printf("\n\n%s %s %s %d\n\n", (*head)->singer, (*head)->song, (*head)->album, (*head)->year);
    // printf("\n\n%s %s %s %d\n\n", (*tail)->singer, (*tail)->song, (*tail)->album, (*tail)->year);
}

void tailDeletion(struct Playlist **tail){
    struct Playlist *trash=*tail;
    *tail=trash->prev;
    (*tail)->next=NULL;
    trash->prev=NULL;
    free(trash);
}

void menu(){
    printf("\n\nMenu\n1. Tampilkan data\n2. Tambah data\n3. Hapus data\n4. Exit\nPilihanmu: ");
}

int main(){
    struct Playlist *head, *node, *tail, *temp;
    node = (struct Playlist*) malloc(sizeof(struct Playlist));
    head=tail=NULL;
    int opt;
    char *tempsinger = (char*) malloc(sizeof(char) * 50);
    char *tempalbum = (char*) malloc(sizeof(char) * 50);
    char *tempsong = (char*) malloc(sizeof(char) * 50);
    int tempyear;
    node=NULL;

    menu();
    scanf("%d",&opt);
        FILE *fp=fopen("playlist.txt","r");
    while(!feof(fp)){
        
        fscanf(fp,"%[^*]*%[^*]*%[^*]*%d\n", tempsinger, tempalbum, tempsong, &tempyear);
        createNewnode(&tempsinger,&tempalbum, &tempsong, tempyear, &tail, &head);
    }
    fclose(fp);

    
    while(opt != 4){
        switch (opt){
        case 1:         //show data
            printLinkedList(head);
            menu();
            scanf("%d", &opt);
            break;
        
        case 2:         //tambah data
            fflush(stdin);
            printf("Input Singer    :"); scanf("%[^\n]",tempsinger);
            fflush(stdin);
            printf("Album           :"); scanf("%[^\n]",tempalbum);
            fflush(stdin);
            printf("Title           :"); scanf("%[^\n]",tempsong);
            fflush(stdin);
            printf("Released Year   :"); scanf("%d",&tempyear);
            FILE *fw=fopen("playlist.txt","a");
            fprintf(fw,"\n%s*%s*%s*%d", tempsinger, tempalbum, tempsong, tempyear);
            fclose(fw);
            
            createNewnode(&tempsinger,&tempalbum, &tempsong, tempyear, &tail, &head);
            menu();
            scanf("%d",&opt);
            break;

        case 3:             //menghapus 1 dari belakang
            tailDeletion(&tail);
            FILE *frw=fopen("playlist.txt","w");
            node=head;
            while(node != NULL){
                fprintf(frw,"%s*%s*%s*%d\n", node->singer, node->album, node->song, node->year);
                node=node->next;
            }
            fclose(frw);

                //printf("\n\n%s %s %s %d\n\n", tail->singer, tail->song, tail->album, tail->year);

            menu();
            scanf("%d",&opt);
            break;

        case 4:         //exit;
            break;

        default:
            break;
        }
    }
    
    while(head != NULL){
        node=head;
        head=head->next;
        free(node);
    }
    return 0;
}
