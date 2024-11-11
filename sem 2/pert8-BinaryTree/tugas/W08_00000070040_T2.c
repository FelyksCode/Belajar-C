#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>


struct Node{
    char key;
    struct Node *left, *right;
};

struct variable{
    char var;
    struct variable *next, *prev;
};

struct operasi{
    char oper;
    struct operasi *next, *prev;
};

void checkNode(struct Node *node, struct operasi **stackOp, struct variable **stackVar, struct operasi **tailOp, struct variable **tailVar ){
    if(node != NULL){
        if(node->key == '*' || node->key == '+' || node->key == '-' || node->key == '/' || node->key == '%'){
            pushOper(stackOp, node->key, tailOp);
        }else{
            pushVar(stackVar, node->key, tailVar);
        }
        checkNode(node->left, stackOp, stackVar, tailOp, tailVar);
        checkNode(node->right, stackOp, stackVar, tailOp, tailVar);
    }
}

struct Node *newNode(int item){
    struct Node *temp = (struct Node*) malloc(sizeof(struct Node));
    temp->key=item;
    temp->left = temp->right=NULL;
    return temp;
}

struct Node *insertCompleteBinaryTree(struct Node *root, char key){
    if(root == NULL) {
        return newNode(key);
    } else {
        // Create a queue to perform level-order traversal
        struct Node **queue = (struct Node **) malloc(sizeof(struct Node *));
        int front = 0, rear = 0;
        queue[rear++] = root;

        while(front < rear) {
            struct Node *current = queue[front++];

            // Check if the left child is empty
            if(current->left == NULL) {
                current->left = newNode(key);
                free(queue);
                return root;
            } else {
                queue = (struct Node **) realloc(queue, (rear + 1) * sizeof(struct Node *));
                queue[rear++] = current->left;
            }

            // Check if the right child is empty
            if(current->right == NULL) {
                current->right = newNode(key);
                free(queue);
                return root;
            } else {
                queue = (struct Node **) realloc(queue, (rear + 1) * sizeof(struct Node *));
                queue[rear++] = current->right;
            }
        }

        free(queue);
        return root;
    }
}

int isEmptyVar(struct variable *stack){
    if(stack == NULL)
        return 1;
    return 0;
}

void pushVar(struct variable **stack, char n, struct variable **tail){
    struct variable *data = (struct variable*) malloc(sizeof(struct variable));
    data->var=n;
    data->prev=data->next=NULL;

    if(*stack==NULL) *tail=data;
    if(!isEmptyVar(*stack)){
        (*stack)->prev=data;
        data->next = *stack;
    }
    *stack=data;
    printf("Adding %c to stackVar\n", n);
}

int isEmptyOper(struct operasi *stack){
    if(stack == NULL)
        return 1;
    return 0;
}

void pushOper(struct operasi **stack, char n, struct operasi **tail){
    struct operasi *data = (struct operasi*) malloc(sizeof(struct operasi));
    data->oper=n;
    data->prev=data->next=NULL;
    if(*stack==NULL) *tail=data;
    if(!isEmptyVar(*stack)){
        (*stack)->prev=data;
        data->next = *stack;
    }
    *stack=data;
    printf("Adding %c to stackOp\n", n);
}

void peekOper(struct operasi *stack) {
    if (!isEmptyOper(stack)) {
        printf("%c ", stack->oper);
        
    } else {
        printf("Error: stackOp is empty.\n");
    }
}

void peekVar(struct variable *stack) {
    if (!isEmptyVar(stack)) {
        printf("%c ", stack->var);
        
    } else {
        printf("Error: stackVar is empty.\n");
    }
}

void peekSelangSeling(struct variable *sVar, struct operasi *sOp){
    int sem = 1;
    while(sem != 0){
        if(sVar!=NULL){
            peekVar(sVar);
            sVar=sVar->prev;
        } 
        else --sem;
        
        if(sOp!=NULL){
            peekOper(sOp);
            sOp=sOp->prev;
        } 
        else --sem;
    }
}

int main(){
    struct Node *root = NULL;
    struct operasi *stackOp = NULL, *tailOp= NULL;
    struct variable *stackVar = NULL, *tailVar= NULL;
    // - ∗ + a b c d
    // ∗ + a b + c d
    //  + / a b / c d
    // Constructing the expression tree
    root = insertCompleteBinaryTree(root, '-');
    insertCompleteBinaryTree(root, '*');
    insertCompleteBinaryTree(root, '+');
    insertCompleteBinaryTree(root, 'a');
    insertCompleteBinaryTree(root, 'b');
    insertCompleteBinaryTree(root, 'c');
    insertCompleteBinaryTree(root, 'd');
    system("cls");
    printf("Infix Expression: \n");
    checkNode(root, &stackOp, &stackVar, &tailOp, &tailVar);
    peekSelangSeling(tailVar, tailOp);
    printf("\n");

    return 0;
}
