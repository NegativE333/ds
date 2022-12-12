# include <stdio.h>
# include <string.h>

char s[25] = {'\0'};
int top = -1;
char ch;

void push(char ele){
	if(top == 24){
		printf("\nStack Overflow\n");
	}
	else{
		top++;
		s[top] = ele;
	}
}
char pop(){
	if(top == -1){
		printf("\nStack Underflow");
	}
	else{
		ch = s[top];
		top--;
	}
	return ch;
}

int isOperand(char ele){
	if((ele>='A'&&ele<='Z') || (ele>='a'&&ele<='z')){
		return 1;
	}
	else{
		return 0;
	}
}

void main(){
	char postfix[25] = {'\0'};
	char ele;
	printf("\n Enter Postfix Expression: ");
	scanf("%s", postfix);
	printf("\n Postfix expression is %s", postfix);
	int i,j;
	while(i<strlen(postfix)){
		ele=postfix[i];
		if(isOperand(ele)){
			push(ele);
			push(' ');
		}
		else{
			for(j=top-1;j>=0;j--){
				if(s[j]== ' '){
					s[j] = ele;
					break;
				}
			}
		}
		i++;
	}
	printf("\n Infix expression is %s", s);
}
