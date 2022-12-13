#include <stdio.h>
#include <stdlib.h>

struct node {
  int item;
  struct node* left;
  struct node* right;
};

// Inorder traversal
void inorderTraversal(struct node* root) {
  if (root == NULL) return;
  inorderTraversal(root->left);
  printf("%d ->", root->item);
  inorderTraversal(root->right);
}

int isBST(struct node* root) {
	static struct node *prev = NULL;
  	if(root!=NULL){
  		if(!isBST(root->left)){
  			return 0;
		}
		if(prev!=NULL && root->item <= prev->item){
			return 0;
		}
		prev = root;
		return isBST(root->right);
  	}
  	else{
  		return 1;
  	}
}

// Create a new Node
struct node* createNode(value) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->item = value;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

// Insert on the left of the node
struct node* insertLeft(struct node* root, int value) {
  root->left = createNode(value);
  return root->left;
}

// Insert on the right of the node
struct node* insertRight(struct node* root, int value) {
  root->right = createNode(value);
  return root->right;
}


void insert(struct node * root, int key){
	struct node * prev = NULL;
	while(root != NULL){
		prev = root;
		if(key==root->item){
			return;
		}
		else if(key <root->item){
			root = root->left;
		}
		else{
			root = root->right;
		}
	}
	struct node * new = createNode(key);
	if(key< prev->item){
		prev->left = new;
	}
	else{
		prev->right = new;
	}
}

struct node * inOrderPre(struct node * root){
	root = root->left;
	while(root->right != NULL){
		root = root->right;
	}
	return root;
}

struct node *deleteNode(struct node * root, int val){
	struct node * iPre;
	if(root == NULL){
		return NULL;
	}
	if(root->left == NULL && root->right == NULL){
		free(root);
		return NULL;
	}
	if(val < root->item){
		root->left = deleteNode(root->left, val);
	}
	else if(val > root->item){
		root->right = deleteNode(root->right, val);
	}
	else{
		iPre = inOrderPre(root);
		root->item = iPre->item;
		root->left = deleteNode(root->left, iPre->item);
	}
	return root;
}

int tree_height(struct node* root) {
    if (!root)
        return 0;
    else {
        int left_height = tree_height(root->left);
        int right_height = tree_height(root->right);
        if (left_height >= right_height)
            return left_height + 1;
        else
            return right_height + 1;
    }
}

void print_level(struct node* root, int level_no) {
    if (!root)
        return;
    if (level_no == 0) {
        printf("%d -> ", root->item);
    }
    else {
        print_level(root->left, level_no - 1);
        print_level(root->right, level_no - 1);
    }

}

void level_wise_display(struct node* root) {
    if (!root)
        return;
    int height = tree_height(root);
    for (int i=0; i<height; i++) {
        printf("Level %d: ", i);
        print_level(root, i);
        printf("\n");
    }
    printf("\n\n-----Complete Level Order Traversal:-----\n");
    for (int i=0; i<height; i++) {
        print_level(root, i);
    }
    printf("\n");
}

void mirror(struct node* node)
{
    if (node == NULL)
        return;
    else {
        struct node* temp;
        mirror(node->left);
        mirror(node->right);

        temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
}

int main() {
  struct node* root = createNode(5);
  
  insertLeft(root, 3);
  insertRight(root, 6);

  insertLeft(root->left, 1);
  insertRight(root->left, 4);
  
  int choice,num;
  
  do{
  	printf("\n1.Insertion   2.Delection   3.Level Wise Display   4.Mirror Image   5.Height of the Tree.   6.Exit\n");
  	printf("\nEnter no. of operation you want to perform: ");
  	scanf("%d", &choice);
  	switch(choice){
  		case 1:
  			printf("\nEnter the no. you want to insert: ");
  			scanf("%d", &num);
  			insert(root,num);
  			printf("\n%d is inserted successfully.\n",num);
  			break;
  		case 2:
  			printf("\nEnter the no. you want to delete: ");
  			scanf("%d", &num);
  			deleteNode(root,num);
  			printf("\n%d is deleted sucessfully. \n",num);
  			break;
  		case 3:
  			printf("\n");
  			level_wise_display(root);
  			printf("\n");
  			break;
  		case 4:
  			printf("\nActual inorder traversal of tree:\n");
  			inorderTraversal(root);
  			mirror(root);
  			printf("\n\nMirror inorder traversal of tree:\n");
  			inorderTraversal(root);
  			printf("\n");
  			break;
  		case 5:
  			printf("\nHeight of the tree is : %d\n", tree_height(root));
  			break;
  		case 6:
  			return 0;
  			break;
  		default:
  			printf("\nEnter valid choice code.\n");
  			break;
	  }
  	}while(choice!=6);
	
  	return 0;
}
