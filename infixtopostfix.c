#include <stdio.h>
#include <stdbool.h>
#define Max_size 10

struct stack{
	int s[Max_size];
	int top;
};
char getInput(){
	char t;
	scanf("%c",&t);
	return t;
}

bool isFull(int top){
	if(top == Max_size-1 ){
		return true;
	}
	return false;
}
bool isEmpty(int top){
	if(top == -1)
		return true;
		
	return false;
}
void createstack(struct stack * st){
	st->top = -1;
}
int push(char n,struct stack * st){
	if(isFull(st->top)){
	printf("\nCannot Push the Element\n");
		return 0;
	}
	
		
	(st->top)++;
	st->s[st->top] = n;
	return 1;
}
char peek(struct stack st){
	if(isEmpty(st.top)){
		printf("The Stack is Empty\n");
		return 0;
	}
	
	printf(" %c \n",st.s[st.top]);
	return 1;
}
char pop(struct stack * st){
	if(isEmpty(st->top)){
		printf("\nCannot Pop the Element\n");
		return 0;
	}
	(st->top)--;
	return (st->s[(st->top) + 1]);
}


void operator(char (*)str[],struct stack * st,char (*)str1[]){
	int i=0,j=0;
	while(str[i]!='\0'){
	
		if(str[i] >= 'a' && str[i]<='z'){
			str[j] = str[i];
			j++;
		}
		else
			push(str[i],stk);
	}
	while(isEmpty(stk->top)
	{
		str1[j] = pop(stk);
		j++;
	}
	
}

int main(){
	struct stack stk;	
	createstack(&stk);
	char str1[10];
	char string[10] = "H+e^l-l*o";
	
	/*for(int i = 0; string[i]!='\0';i++){
		printf(" %c ",string[i]);
	}*/
	printf("%s",str1);
	operator(&string,&stk,&str1);
	peek(stk);
	push('c',&stk);
	peek(stk);
	char n = pop(&stk);
	/*printf("%c",n);*/
	peek(stk);
}






