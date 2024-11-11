#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

struct Mahasiswa
{
    char nama[100];
    char jurusan[30];
    int nim;
    struct Mahasiswa *next, *prev;
};

void createNewNode(int nim, char *nama, char *jurusan, struct Mahasiswa **tail)
{
    struct Mahasiswa *newNode = (struct Mahasiswa *)malloc(sizeof(struct Mahasiswa));
    newNode->nim = nim;
    strcpy(newNode->nama, nama);
    strcpy(newNode->jurusan, jurusan);
    newNode->next = NULL;

    newNode->prev = *tail;
    (*tail)->next = newNode;
    *tail = newNode;
}

void headDeletion(struct Mahasiswa **head)
{
    struct Mahasiswa *trash = *head;
    *head = trash->next;
    (*head)->prev = NULL;
    trash->next = NULL;
    free(trash);
}

void tailDeletion(struct Mahasiswa **tail)
{
    struct Mahasiswa *trash = *tail;
    *tail = trash->prev;
    (*tail)->next = NULL;
    trash->prev = NULL;
    free(trash);
}

void middleDeletion(struct Mahasiswa **head, int target)
{
    struct Mahasiswa *trash = *head, *tempBefore, *tempAfter;
    while (trash->nim != target)
    {
        trash = trash->next;
    }

    tempBefore = trash->prev;
    tempAfter = trash->next;

    tempBefore->next = tempAfter;
    tempAfter->prev = tempBefore;

    trash->prev = NULL;
    trash->next = NULL;
    free(trash);
}

void printLinkedList(struct Mahasiswa *head)
{
    struct Mahasiswa *temp;
    temp = head;
    int i = 1;
    while (temp != NULL)
    {
        printf("Data ke %d\n", i);
        printf("NIM     : %d\n", temp->nim);
        printf("Nama    : %s\n", temp->nama);
        printf("Jurusan : %s\n\n", temp->jurusan);
        temp = temp->next;
        i++;
    }
}

int main()
{
    struct Mahasiswa *head, *node, *tail;
    head = tail = NULL;

    node = (struct Mahasiswa *)malloc(sizeof(struct Mahasiswa));
    node->nim = 14026;
    strcpy(node->nama, "James Christian Wira");
    strcpy(node->jurusan, "Informatika");

    node->next = node->prev;
    head = node;
    tail = node;

    node = (struct Mahasiswa *)malloc(sizeof(struct Mahasiswa));
    node->nim = 17492;
    strcpy(node->nama, "Matthew Evans");
    strcpy(node->jurusan, "Informatika");

    node->next = NULL;
    tail->next = node;
    tail = node;

    createNewNode(13633, "Justin Susanto", "Informatika", &tail);
    createNewNode(12335, "Vionie Laorensa", "Informatika", &tail);
    createNewNode(14045, "Mario Alexander", "Informatika", &tail);
    createNewNode(11440, "Leonardo Pratama", "Informatika", &tail);
    createNewNode(15840, "Handriki Kasa", "Informatika", &tail);
    createNewNode(15773, "Cindy Michelle", "Informatika", &tail);
    createNewNode(19587, "Aldric Leonardo", "Informatika", &tail);

    printf("All data inside linked list\n");
    printLinkedList(head);

    printf("All data after 2x head deletion\n");
    headDeletion(&head);
    headDeletion(&head);
    printLinkedList(head);

    printf("All data after 1x tail deletion\n");
    tailDeletion(&tail);
    printLinkedList(head);

    printf("All data after middle deletion (Mario Alexander - 14045)\n");
    middleDeletion(&head, 14045);
    printLinkedList(head);

    return 0;
}
