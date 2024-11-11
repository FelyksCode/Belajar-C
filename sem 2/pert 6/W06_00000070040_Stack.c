#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

struct Mahasiswa{
    char nim[13];
    char nama[50];
    char jurusan[30];
    struct Mahasiswa *next;
};

int isEmpty(struct Mahasiswa *stack){
    if(stack == NULL)
        return 1;
    return 0;
}

void push(struct Mahasiswa **stack, char nim[], char nama[], char jurusan[]){
    struct Mahasiswa *data = (struct Mahasiswa*) malloc(sizeof(struct Mahasiswa));
    strcpy(data->nim, nim);
    strcpy(data->nama, nama);
    strcpy(data->jurusan, jurusan);
    data->next=NULL;

    if(!isEmpty(*stack))data->next =*stack;
    *stack=data;
    printf("Adding %s to Stack\n", nama);
}

void pop(struct Mahasiswa **stack){
    printf("Removing Stack's top element\n");
    if(*stack == NULL){
        printf("Nothing to pop. Stack already empty\n");
    return;
    }

    struct Mahasiswa *trash = *stack;
    *stack = trash->next;
    free(trash);
    printf("Popping Stack success\n");
}

struct Mahasiswa *top(struct Mahasiswa *stack){
    if(stack==NULL) return NULL;
    return stack;
}

int main(){
    printf("STACK TUTORIAL\n");
    printf("--------------\n\n");

    printf("Initializing Stack\n\n");
    struct Mahasiswa *stackMhs;
    stackMhs=NULL;

    printf("Is Stack empty? %s\n", isEmpty(stackMhs) ? "yes" : "No");
    printf("What is the name at the top? %s\n\n", top(stackMhs)==NULL ? "No one. Stack is empty" : top(stackMhs)->nama);

    push(&stackMhs, "14026", "James Christian Wira", "Informatika");
    printf("What is the name at the top? %s\n", top(stackMhs)==NULL ? "No one. Stack is empty" : top(stackMhs)->nama);

    printf("Is Stack empty? %s\n", isEmpty(stackMhs) ? "yes" : "No");

    pop(&stackMhs);
    printf("Is Stack empty? %s\n", isEmpty(stackMhs) ? "yes" : "No");
    printf("What is the name at the top? %s\n", top(stackMhs)==NULL ? "No one. Stack is empty" : top(stackMhs)->nama);

    push(&stackMhs, "17492", "Matthew Evans", "Informatika");
    push(&stackMhs, "14045", "Michael Roni", "Informatika");
    push(&stackMhs, "10000", "Mario Alexander", "Informatika");
    printf("What is the name at the top? %s\n", top(stackMhs)==NULL ? "No one. Stack is empty" : top(stackMhs)->nama);

    pop(&stackMhs);
    printf("Is Stack empty? %s\n", isEmpty(stackMhs) ? "yes" : "No");
    printf("What is the name at the top? %s\n", top(stackMhs)==NULL ? "No one. Stack is empty" : top(stackMhs)->nama);

    pop(&stackMhs);
    printf("Is Stack empty? %s\n", isEmpty(stackMhs) ? "yes" : "No");
    printf("What is the name at the top? %s\n", top(stackMhs)==NULL ? "No one. Stack is empty" : top(stackMhs)->nama);

    pop(&stackMhs);
    printf("\n");
    pop(&stackMhs);

    return 0;
}
