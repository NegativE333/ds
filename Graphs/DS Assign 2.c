#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node {
	int data;
	struct node *next;
};

struct node *createNode(struct node *head){
	int data;
	printf("Enter element: ");
	scanf("%d", &data);
	struct node *p = (struct node *) malloc(sizeof(struct node));
	p -> data = data;
	p -> next = NULL;
	struct node *ptr;
	if(head == NULL){
		head = p;
		ptr =head;
		return head;
	}
	else{
		ptr -> next = p;
		ptr = p;
		return head;
	}
}

void display(struct node *p){
	printf("Linked List is: ");
	while(p!=NULL){
		printf("%d ", p->data);
		p = p -> next;
	}
};

void FrontBackSplit(struct node *p, float i){
	int a = ceil(i/2);
	int q = i-a;
//	int front[a];
//	int back[q];
	printf("\n");
	printf("Front List: ");
	for(int i = 0; i<a; i++){
		printf("%d ", p->data);
		//front[i] = p->data;
		p = p->next;
		//printf("%d ", front[i]);
	}
	printf("\n");
	printf("Back List: ");
	for(int i = 0; i<q; i++){
		printf("%d ", p->data);
		//back[i] = p->data;
		p = p->next;
		//printf("%d ", back[i]);
	}
}


int main(){
	float len;
	printf("Enter the no of nodes you want in linked list: ");
	scanf("%f", &len);
	struct node*head=NULL;
	for(int i = 0; i<len; i++){
		head = createNode(head);
	}
	printf("\n");
	display(head);
	printf("\n");
	FrontBackSplit(head, len);
	printf("\n");
	return 0;
}
