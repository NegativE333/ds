# include <stdio.h>
# include <stdlib.h>

struct stack{
	int size;
	int top;
	int *arr;
};

int isEmpty(struct stack *p){
	if(p->top == -1){
		return 1;
	}
	else{
		return 0;
	}
}

int isFull(struct stack *p){
//	struct stack *p = (struct stack *) malloc(sizeof(struct stack));
	if(p->top==p->size-1){
		return 1;
	}
	else{
		return 0;
	}
}

void push(struct stack * p, int val){
	if(isFull(p)){
		printf("\n Stack Overflow! \n");
	}
	else{
		p->top++;
		p->arr[p->top] = val;
	}
}

void pop(struct stack *p){
	if(isEmpty(p)){
		printf("\n Stack Underflow! \n");
	}
	else{
		int val = p->arr[p->top];
		p->top--;
		printf("\n%d is poped form the stack.\n", val);
	}
}

void display(struct stack *p){
	int i;
	printf("Elements in stack are: ");
	while(i!=p->top+1){
		printf("%d ", p->arr[i]);
		i++;
	}
	printf("\n");
}

int main(){
	int choice,i;
	struct stack *s = (struct stack *) malloc(sizeof(struct stack));
	s->size = 10;
	s->top = -1;
	s->arr = (int *) malloc(s->size * sizeof(int));
	
	
	
	while(choice != 4){
		printf("\n1.Push \n2.Pop \n3.Display \n4.Exit");
		printf("\nEnter the no. of operation you want to perform: ");
		scanf("%d", &choice);
		switch (choice){
			case 1:
				printf("Element: ");
				scanf("%d", &i);
				push(s, i);
				break;
			case 2:
				pop(s);
				break;
			case 3:
				display(s);
				break;
			case 4:
				printf("Exit");
				break;
			default:
				printf("Enter valid choice code.");
		}
	}
	return 0;
}

