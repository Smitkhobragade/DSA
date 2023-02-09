#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 10


typedef struct stack{
	int *s;
	int top;
	int maxsize;
}stack;

void extendstack(stack * s1){
	s1 -> s = (int *)realloc(s1->s,(((s1->maxsize)*1.5)*sizeof(int)));
	//s1 -> maxsize = ((s1 -> maxsize) * 3)/2;
}


int isempty(stack s1){
	if(s1.top == -1)
		return 1;
	else
		return 0;
}

int isfull(stack * s1,int max){
	if(s1->top == max-1){
		printf("The stack is now full extending the limit\n");
		extendstack(s1);
		printf("Extended the stack now\nWith Capacity: %d\n",((s1->maxsize)*3)/2);
		return 1;
	}
	else
		return 0;
}

void push(stack * s1,int data){
	isfull(s1,s1->maxsize);
	
	(s1->top)++;
	s1->s[s1->top] = data;
}

void create(stack *s1, int max){
	s1 -> maxsize = max;
	s1 -> s = (int *)malloc((s1->maxsize)*sizeof(int));
	s1 -> top = -1;
}


int peek(stack s1){
	if(isempty(s1)){
		printf("Stack is empty (Underflow)\n");
		return 0;
	}
	else{
		printf("The element is : %d\n",s1.s[s1.top]);
		return s1.s[s1.top];
	}
}


int pop(stack *s1){
	if(isempty(*s1)==1){
		printf("Cannot pop the element (stack underflow)\n");
	}
	else{
		int data = s1->s[s1->top];
		(s1->top)--;
		return data;
	}
}


int main(){
	stack stk;
	create(&stk,CAPACITY);
	peek(stk);
	for(int i=0;i<15;i++){
	push(&stk,i);
	peek(stk);	}
	push(&stk,2);
	push(&stk,10);
	for(int i =0;i<15;i++){
	pop(&stk);
	peek(stk);
	}
	pop(&stk);
	peek(stk);
	pop(&stk);
	pop(&stk);
	peek(stk);


	return 0;
}


