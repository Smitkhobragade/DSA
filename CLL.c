#include <stdio.h>
#include <stdlib.h>
struct Node{
	int data;
	struct Node * link;
};

void CreateNode( struct Node ** head){
	*head = (struct Node *) malloc (sizeof(struct Node));
	if(*head == NULL){
		printf("ALLOCATION FAILED\n");
	}
	else {
		//printf("NODE CREATED\n");
	}
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
		if(temp -> link = (*head))
			temp -> link = newnode;
		else{
			while(temp->link != (*head)){
				temp = temp -> link;
			}
		
			temp -> link = newnode;
		}
	}
	newnode -> link = (*head);
}

void display( struct Node ** head){
	struct Node *temp = *head;
	if(temp == NULL)
		printf("SLL is EMPTY\n");
	else{
		printf("\nSLL IS : \n");
		while(temp->link != *head){
			printf("%d\t", temp -> data);
			temp = temp -> link;
		}
		printf("\n");
	}
}

int main(){
	struct Node * head;
	head = NULL;
	insertatend(&head,10);
	insertatend(&head,2);
	insertatend(&head,3);
	insertatend(&head,4);
	insertatend(&head,6);
	display(&head);
}


