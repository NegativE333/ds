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

// preorderTraversal traversal
void preorderTraversal(struct node* root) {
  if (root == NULL) return;
  printf("%d ->", root->item);
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}

// postorderTraversal traversal
void postorderTraversal(struct node* root) {
  if (root == NULL) return;
  postorderTraversal(root->left);
  postorderTraversal(root->right);
  printf("%d ->", root->item);
}

// Create a new Node
struct node* createNode(int value) {
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

struct node * searchIter(struct node * root, int key){
	while(root!=NULL){
		if(key == root->item){
			return root;
		}
		else if(key < root->item){
			root = root->left;
		}
		else{
			root = root->right;
		}
	}
	return NULL;
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

int main() {
  struct node* root = createNode(5);
  insertLeft(root, 3);
  insertRight(root, 6);

  insertLeft(root->left, 1);
  insertRight(root->left, 4);

  insert(root, 2);
  inorderTraversal(root);
  
  return 0;
}
