#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define Max_size 20

// Stack ADT
struct stack{
	int s[Max_size];
	int top;
};
int getInput(){
	int t;
	scanf("%d",&t);
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
int push(int n,struct stack * st){
	if(isFull(st->top)){
	printf("\nCannot Push the Element\n");
		return 0;
	}
	
		
	(st->top)++;
	st->s[st->top] = n;
	return 1;
}
int peek(struct stack st){
	if(isEmpty(st.top)){
		printf("The Stack is Empty\n");
		return 0;
	}
	
	//printf(" %d \n",st.s[st.top]);
	return (st.s[st.top]);
}
int pop(struct stack * st){
	if(isEmpty(st->top)){
		printf("\nCannot Pop the Element\n");
		return 0;
	}
	(st->top)--;
	return (st->s[(st->top) + 1]);
}


// SLL
struct Node{
	int data;
	struct Node * link;
};

void CreateNode( struct Node ** head){
	*head = (struct Node *) malloc (sizeof(struct Node));
	if(*head == NULL){
		printf("ALLOCATION FAILED\n");
	}
	//else {
		//printf("NODE CREATED\n");
	//}
	//return newnode;
	
}

void insertatend( struct Node ** head, int key){
	struct Node * newnode;
	CreateNode(&newnode);
	if(newnode == NULL)
		printf("ALLOCATION FAILED INSERT NOT POSSIBLE\n");
		
	newnode -> data = key;
	newnode -> link = NULL;
	
	struct Node *temp;
	temp = *head;
	if(temp == NULL){
		*head = newnode;
	}else{
		while(temp -> link != NULL){
			temp = temp -> link;
		}
		
		temp -> link = newnode;
	}
}

void display( struct Node ** head){
	struct Node *temp = *head;
	while(temp != NULL){
		printf("%d\n", temp -> data);
		temp = temp -> link;
	}
}

int lengthsll(struct Node * head){
	int count=0;
	struct Node * temp = head;
	while(temp!=NULL){
		count++;
		temp = temp -> link;	
	}

	//printf("---%d\n",count);
	return count;
}
int savesll(struct Node * head,struct stack * st){
	struct Node * temp = head;
	while(temp!=NULL){
		push((temp->data),st);
		temp = temp -> link;	
	}
}
void join(struct Node **head,struct Node **head1){
	struct Node *temp;
	temp = *head;
	if(temp == NULL){
		*head = *head1;
	}else{
		while(temp -> link != NULL){
			temp = temp -> link;
		}
		
		temp -> link = *head1;
	}
}
void commonlink(struct Node * head,struct Node * head2){
	int cnta=0,cntb=0,flag=0;
	struct Node *temp2;
	temp2 = head2;
	while(head->link != NULL){
		cnta++;
		struct Node *temp;
		temp = head;
		
		head2 = temp2;
		//printf("-- -- %d -- -- \n",temp->data);
		while(head2->link != NULL){
			if(head2 == temp){
				cntb++;
				flag = 1;
				break;
			}
			else{
				head2 = head2->link;
				cntb++;
			}
			//printf("-  -%d-  -\n",head2->data);
		}
		if(flag == 1)
			break;
		
		cntb=0;
		head=head->link;
	}
	//if(flag == 1)
	printf("For First SLL : %d\nFor second SLL : %d\n",cnta,cntb);
}

// findJoint function
int findjoint(struct stack *st,struct stack *st1){
	int count=0;
	while(peek(*st) == peek(*st1)){
		count++;
		pop(st);
		pop(st1);
		//printf("Count = %d\n",count);
	}
	return count;
}
int main(){
	struct Node * head;
	head = NULL;
	struct Node * head1;
	head1 = NULL;
	struct Node * head2;
	head2 = NULL;

	insertatend(&head,6);
	insertatend(&head,4);
	insertatend(&head,1);
	//insertatend(&head,9);
	//insertatend(&head,8);
	insertatend(&head,2);
	insertatend(&head,3);
	//display(&head);
	printf("-------------------------\n");
	//int t = lengthsll(head);
	insertatend(&head1,1);
	insertatend(&head1,9);
	insertatend(&head1,2);
	//display(&head1);
	printf("-------------------------\n");
	join(&head,&head1);
	display(&head);
	printf("-------------------------\n");
	insertatend(&head2,7);
	insertatend(&head2,0);
	insertatend(&head2,1);
	insertatend(&head2,5);
	//display(&head2);
	printf("-------------------------\n");
	join(&head2,&head1);
	display(&head2);
	printf("-------------------------\n");
	printf("-------------------------\n");
	commonlink(head,head2);
	printf("Using stacks:\n");
	struct stack stk;
	createstack(&stk);
	struct stack stk1;
	createstack(&stk1);
	savesll(head,&stk);
	savesll(head2,&stk1);
	int c = findjoint(&stk,&stk1);
	peek(stk);
	printf("The joint is in SLL1: %d\n",(lengthsll(head))-c+1);
	printf("The joint is in SLL2: %d\n",(lengthsll(head2))-c+1);


return 0;
}
