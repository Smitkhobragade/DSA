#include <stdio.h>
#include <stdlib.h>
// DLL Usinng Header Node

struct Node {
	int data;
	struct Node * link;
	struct Node * prev;
};

void CreateNode(struct Node ** head){
	*head = (struct Node *) malloc (sizeof(struct Node));
	if(*head == NULL){
		printf("ALLOCATION FAILED\n");
	}
	else {
		//printf("NODE CREATED\n");
	}
}
void createHeaderNode(struct Node ** head){
	struct Node * newnode;
	CreateNode(&newnode);
	*head = newnode;
	newnode -> data = 0;
	newnode -> link = NULL;
	newnode -> prev = NULL;
	
}
void insertatend( struct Node ** head, int key){
	struct Node * newnode;
	CreateNode(&newnode);
	if(newnode == NULL)
		printf("ALLOCATION FAILED INSERT NOT POSSIBLE\n");
		
	newnode -> data = key;
	newnode -> link = NULL;
	newnode -> prev = NULL;
	
	struct Node *temp;
	temp = *head;
	if(temp -> link == NULL){
		temp -> link = newnode;
		newnode -> prev = temp;
	}else{
		temp = temp->link;
		while((temp -> link) != NULL){
			temp = temp -> link;
		}
		
		temp -> link = newnode;
		newnode -> prev = temp;
	}
	((*head) -> data)++;
}
void insertatbeg(struct Node ** head,int key){
	struct Node * newnode;
	CreateNode(&newnode);
	if(newnode == NULL)
		printf("ALLOCATION FAILED INSERT NOT POSSIBLE\n");
		
	newnode -> data = key;
	newnode -> link = (*head)->link;
	newnode -> prev = (*head);
	(*head) -> link= newnode;
	((*head)->data)++;
	//*head = newnode;
}
void display( struct Node ** head){
	struct Node *temp = *head;
	if(temp->link == NULL)
		printf("SLL is EMPTY\n");
	
		printf("SLL IS : \n");
		while(temp != NULL){
			printf("%d\t", temp -> data);
			temp = temp -> link;
		}
		printf("\n\n");
	
}
int deletefirst(struct Node ** head){
struct Node * temp = (*head)->link;
int key;
	if((*head) -> link == NULL){
		printf("CANNOT DELETE\n\n");
		key = -1;
		return key;
	}else{
		key = temp -> data;
		(*head)->link = temp-> link;
		temp -> prev = NULL;
		//free(temp);
		//return key;
	
	}
	free(temp);
	((*head)->data)--;	
	return key;
	
}
int deletelast(struct Node ** head){
	struct Node * temp = (*head);
	if(temp->link== NULL){
		printf("CANNOT DELETE\n\n");
		return -1;
	}
	else if(((temp)->link)->link == NULL){
		return deletefirst(head);
	}else{
		while(temp -> link ->link!= NULL){
			temp = temp -> link;
		}
		int key = temp -> data;
		free(temp->link);
		temp->link=NULL;
		((*head)->data)--;
		return key;
	}
}
int main(){
	struct Node * head;
	head = NULL;
	createHeaderNode(&head);
		display(&head);
	insertatend(&head,10);
		display(&head);
	insertatend(&head,8);
		display(&head);
	deletefirst(&head);
		display(&head);
	deletefirst(&head);
		display(&head);
	deletefirst(&head);
		display(&head);
	insertatbeg(&head,23);
		display(&head);
	insertatbeg(&head,5);
		display(&head);
	insertatbeg(&head,3);
		display(&head);
	deletelast(&head);
		display(&head);
	deletelast(&head);
		display(&head);
	deletelast(&head);
		display(&head);
		
}



