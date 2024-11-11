#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

struct Node{
    int key;
    struct Node *left, *right;
};

void printInOrder(struct Node *node){
    if(node != NULL){
        printInOrder(node->left);
        printf("%d ", node->key);
        printInOrder(node->right);
    }
}

void printPreOrder(struct Node *node){
    if(node != NULL){
        printf("%d ", node->key);
        printPreOrder(node->left);
        printPreOrder(node->right);
    }
}

void printPostOrder(struct Node *node){
    if(node != NULL){
        printPostOrder(node->left);
        printPostOrder(node->right);
        printf("%d ", node->key);
    }
}



struct Node *newNode(int item){
    struct Node *temp = (struct Node*) malloc(sizeof(struct Node));
    temp->key=item;
    temp->left = temp->right=NULL;
    return temp;
}

struct Node *insert(struct Node *node, int key){
    if(node == NULL) return newNode(key);
    if(key < node->key) node->left=insert(node->left,key);
    else if(key> node->key) node->right= insert(node->right, key);
    return node;
}

int main(){
    struct Node *root = NULL;

    root = insert(root,50);
    insert(root,50);
    insert(root,30);
    insert(root,20);
    insert(root,40);
    insert(root,70);
    insert(root,60);
    insert(root,80);

    printf("Binary Tree in PreOrder : ");printPreOrder(root);printf("\n");
    printf("Binary Tree in InOrder : ");printInOrder(root);printf("\n");
    printf("Binary Tree in PostOrder : ");printPostOrder(root);printf("\n");
    
    return 0;
}