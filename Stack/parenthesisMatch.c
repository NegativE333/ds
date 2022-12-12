#include <stdio.h>
#include <stdlib.h>

struct stack{
	int size;
	int top;
	char *arr;
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
	if(p->top == p->size-1){
		return 1;
	}
	else{
		return 0;
	}
}

void push(struct stack *p, char val){
	if(isFull(p)){
		printf("The stack is already full.");
	}
	else{
		p->top++;
		p->arr[p->top] = val;
	}
}

char pop(struct stack *p){
	if(isEmpty(p)){
		printf("Stack is already empty.");
		return -1;
	}
	else{
		char val = p->arr[p->top];
		p->top--;
		return val;
	}
}

int match(char a, char b){
	if(a=='{' && b=='}'){
		return 1;	
	}
	if(a=='(' && b==')'){
		return 1;	
	}
	if(a=='[' && b==']'){
		return 1;	
	}
	
	return 0;
}

int parenthesisMatch(char *exp){
	struct stack *sp;
	sp->size = 100;
	sp->top = -1;
	sp->arr = (char *) malloc (sp->size * sizeof(char));
	char poped_ch;
	
	for (int i = 0; exp[i] != '\0'; i++){
		if(exp[i] == '(' || exp[i] =='{' || exp[i] =='['){
			push(sp, exp[i]);
		}
		else if(exp[i] == ')' || exp[i] =='}' || exp[i] ==']'){
			if(isEmpty(sp)){
				return 0;
			}	
			poped_ch = pop(sp);
			if(!match(poped_ch, exp[i])){
				return 0;
			}
		}
	}
	if(isEmpty(sp)){
		return 1;
	}
	else{
		return 0;
	}
}

int main(){
	
	char * exp = "{8*9(54)";
	
	if(parenthesisMatch(exp)){
		printf("The no. of parenthesis is balanced.");
	}
	else{
		printf("The no. of parenthesis is not balanced.");
	}
}





