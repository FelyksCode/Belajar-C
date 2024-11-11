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

struct Node* minValueNode(struct Node* root) {
    struct Node* current = root;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

struct Node *deleteNode(struct Node* root, int key){
    if(root == NULL)
        return root;

    if(key < root->key)
        root->left = deleteNode(root->left, key);

    else if(key > root->key)
        root->right = deleteNode(root->right, key);

    else{
        if(root->left == NULL){
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = minValueNode(root->right);

        root->key= temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
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

    printf("Base Tree\n");
    
    printf("Preorder : "); printPreOrder(root); printf("\n");
    printf("Inorder : "); printInOrder(root);printf("\n");
    printf("Postorder : "); printPostOrder(root);printf("\n\n");

    printf("Deleting node 20\n");
    deleteNode(root, 20);
    printf("Preorder : "); printPreOrder(root); printf("\n");
    printf("Inorder : "); printInOrder(root);printf("\n");
    printf("Postorder : "); printPostOrder(root);printf("\n\n");

    printf("Deleting node 30\n");
    deleteNode(root, 30);
    printf("Preorder : "); printPreOrder(root); printf("\n");
    printf("Inorder : "); printInOrder(root);printf("\n");
    printf("Postorder : "); printPostOrder(root);printf("\n\n");

    printf("Deleting node 70\n");
    deleteNode(root, 70);
    printf("Preorder : "); printPreOrder(root); printf("\n");
    printf("Inorder : "); printInOrder(root);printf("\n");
    printf("Postorder : "); printPostOrder(root);printf("\n\n");

    return 0;
}