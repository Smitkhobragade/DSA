#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define Max_size 30

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
		//printf("The Stack is Empty\n");
		return 0;
	}
	
	//printf(" %c \n",st.s[st.top]);
	return st.s[st.top];
}
char pop(struct stack * st){
	if(isEmpty(st->top)){
		printf("\nCannot Pop the Element\n");
		return 0;
	}
	(st->top)--;
	return (st->s[(st->top) + 1]);
}
void brcheck(struct stack * st, char a[]){
	int i=0,count =0;
	printf("The entered brackets are : \n");
	while(a[i]!='\0'){
	printf("%c ",a[i]);
		i++;
	}
	printf("\n");
	i=0;
	while(a[i]!='\0'){
		/*printf("%c\n",a[i]);
		i++;*/
		if(a[i] == '('){
			push('(',st);
			peek(*st);
		}	
		else{
			if(peek(*st) == '('){
				//printf("valid pair\n");
				//exit(0);
				count = 0;
				pop(st);
			}
			else{
			count =1;
			//printf("\n\n");
				//peek(*st);
				}
		}
		i++;
	}
	if(isEmpty(st->top)){
	if(count == 0)
		printf("VALID BRACKETS\n");
	else
		printf("Invalid Brackets\n");
	}
	else
		printf("Invalid Brackets\n");
}
int main(){
	struct stack stk;
	createstack(&stk);
	
	char str[30] = "((()))";
	brcheck(&stk,str);
	char str1[30] = "()(())())";
	brcheck(&stk,str1);
	
	
	
}






