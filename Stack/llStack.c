#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node * top = NULL;

void display(struct node *p){
	printf("Elements in stack are: ");
	while(p!=NULL){
		printf("%d ", p->data);
		p = p->next;
	}
}

int isEmpty(struct node * top){
	if(top==NULL){
		return 1;
	}
	else{
		return 0;
	}
}

int isFull(struct node *top){
	struct node * p = (struct node*) malloc(sizeof(struct node));
	if(p==NULL){
		return 1;
	}
	else{
		return 0;
	}
}

struct node * push(struct node * top, int x){
	if(isFull(top)){
		printf("Stack Overflow \n");
	}
	else{
		struct node *p = (struct node*) malloc(sizeof(struct node));
		p->data = x;
		p->next = top;
		top = p;
		return top;
	}
}

int pop(struct node * tp){
	if(isEmpty(tp)){
		printf("Stack Underflow \n");
	}
	else{
		struct node *p = tp;
		top = (tp)->next;
		int x = p->data;
		free(p);
		return x;
	}
}

int main(){
	int nos, choice, wish;
	do{
		printf("1.Push \n2.Pop");
		printf("\n");
		printf("Enter the no. of operation you want to perform: ");
		scanf("%d", &choice);
		if(choice == 1){
			int element;
			printf("Element : ");
			scanf("%d", &element);
			top = push(top, element);
			display(top);
		}
		else if(choice == 2){
			int element = pop(top);
			printf("%d is poped form the stack", element);
			printf("\n");
			display(top);
		}
		else{
			printf("Enter the valid choice code.");
		}
		printf("\n");
		printf("If you want to perform more opetations then press 1 or press 0 to exit.");
		scanf("%d", &wish);
	}while(wish == 1);
	
	return 0;
}




