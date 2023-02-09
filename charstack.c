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


int main(){
	struct stack stk;
	createstack(&stk);
	/*push(5,&stk);
	peek(stk);
	push(4,&stk);
	peek(stk);
	pop(&stk);
	peek(stk);
	for(int i =0;i<=10;i++){
		push(i,&stk);
		peek(stk);
	}
	printf("\n\n\n\n");
	for(int i =0;i<10;i++){
		pop(&stk);
		peek(stk);
	}*/
	peek(stk);
	push('c',&stk);
	peek(stk);
	char n = pop(&stk);
	/*printf("%c",n);*/
	peek(stk);
}






