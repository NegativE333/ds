#include <stdio.h>
#define MAX 10

struct Q{
	int R,F;
	int data[];
};

void init(struct Q *q){
	q->F = q->R = -1;
}

int isEmpty(struct Q *q){
	if(q->F == -1){
		return 1;
	}
	else{
		return 0;
	}
}

int isFull(struct Q *q){
	if((q->R+1)%MAX == q->F){
		return 1;
	}
	else{
		return 0;
	}
}

void EnQ(struct Q *q, int x){
	if(q->R == -1){
		q->R = q->F = 0;
		q->data[q->R] = x;
	}
	else{
		q->R = (q->R+1)%MAX;
		q->data[q->R] = x;
	}
}

int DeQ(struct Q *q){
	int x;
	if(q->F == q->R){
		x = q->data[q->R];
		q->F = q->R = -1;
	}
	else{
		x = q->data[q->F];
		q->F = (q->F+1)%MAX;
	}
	return x;
}

void display(struct Q *q){
	printf("The elements in the Q are: ");
	for(int i = q->F; i<=q->R; i=(i+1)%MAX){
		printf("%d ", q->data[i]);
	}
	printf("\n");
}

int main(){
	struct Q q;
	init(&q);
	int choice;
	
	do{
		printf("1.Insert\n2.Delete\n3.Delete\n4.Exit\n");
		printf("Enter the no. of operation you want to perform: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				if(!isFull(&q)){
					int x;
					printf("Enter element: ");
					scanf("%d", &x);
					EnQ(&q, x);
				}
				break;
			case 2:
				if(!isEmpty(&q)){
					int x = DeQ(&q);
					printf("%d is deleted from the Q\n", x);
				}
				break;
			case 3:
				display(&q);
				break;
			case 4:
				return 0;
			default:
				printf("Enter valid choice code.\n");
				break;
		}
	}while(choice!=4);
	
	return 0;
}
