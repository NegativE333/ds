#include <stdio.h>
#include <stdlib.h>

struct node{
    int item;
    struct node *left;
    struct node *right;
};

void iot(struct node *root){
    if(root==NULL) return;
    iot(root->left);
    printf("%d -> ", root->item);
    iot(root->right);
}

void preot(struct node *root){
    if(root==NULL) return;
    printf("%d -> ", root->item);
    preot(root->left);
    preot(root->right);
}

void poot(struct node * root){
    if(root== NULL) return;
    poot(root->left);
    poot(root->right);
    printf("%d -> ", root->item);
}

struct node * createNode(int value){
    struct node *newNode = malloc (sizeof(struct node));
    newNode -> item = value;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}

struct node * insertLeft(struct node * root, int value){
    root->left = createNode(value);
    return root->left;
}

struct node * insertRight(struct node * root, int value){
    root -> right = createNode(value);
    return root->right;
}

int main(){
    struct node * root = createNode(7);
    insertLeft(root, 2);
    insertRight(root, 3);

    insertLeft(root->left, 0);
    insertRight(root->left, 4);

    insertLeft(root->right, 5);
    insertRight(root->right, 6);

    insertLeft(root->left->left, 3);
    insertRight(root->left->left, 1);

    printf("The inorder traversal of the given tree is: ");
    iot(root);

    return 0;
}