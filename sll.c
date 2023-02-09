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
		while(temp -> link != NULL){
			temp = temp -> link;
		}
		
		temp -> link = newnode;
	}
}

void display( struct Node ** head){
	struct Node *temp = *head;
	if(temp == NULL)
		printf("SLL is EMPTY\n");
	else{
		printf("\nSLL IS : \n");
		while(temp != NULL){
			printf("%d\t", temp -> data);
			temp = temp -> link;
		}
		printf("\n");
	}
}

int lengthsll(struct Node * head){
	int count=0;
	struct Node * temp = head;
	while(temp!=NULL){
		count++;
		temp = temp -> link;	
	}

	//printf("--- length : %d\n",count);
	return count;
}

void insertatbeg(struct Node ** head,int key){
	struct Node * newnode;
	CreateNode(&newnode);
	if(newnode == NULL)
		printf("ALLOCATION FAILED INSERT NOT POSSIBLE\n");
		
	newnode -> data = key;
	newnode -> link = *head;
	*head = newnode;
	
	
}

int deletefirst(struct Node ** head){
	struct Node * temp = *head;
	*head = temp -> link;
	int key = temp -> data;
	free(temp);
	return key;
}

int deletelast(struct Node ** head){
	struct Node * temp = *head;
	if(head == NULL){
		printf("CANNOT DELETE\n");
		return -1;
	}
	else{
		while((temp -> link) -> link != NULL){
			temp = temp -> link;
		}
		int key = temp ->link-> data;
		free(temp -> link);
		temp->link = NULL;
		return key;
	}
}

int deleteatpos(struct Node ** head,int pos){
	int lth = lengthsll(*head);
	//printf("---%d\n",lth);
	if(head == NULL)
		printf("SLL IS EMPTY\n");
	else if(pos<1 || pos>lth)
		printf("INVALID POSITION\n");
	else if(pos == 1)
		deletefirst(head);
	else{
		struct Node * temp = *head;
		struct Node * temp1;
		int count=pos-1;
		while(count--){
			temp = temp->link;
		}
		temp1 = temp -> link;
		
		int key = temp -> data;
		temp -> link = temp -> link -> link;
		
		free(temp1);
		
		return key;
	}
}

void insertatpos(struct Node ** head,int key,int pos){
	int lth = lengthsll(*head);
	//printf("---%d\n",lth);
	if(pos<1 || pos>lth)
		printf("INVALID POSITION\n");
	else if(pos == 1)
		insertatbeg(head,key);
	else{
		int indx=1;
		struct Node * newnode;
		CreateNode(&newnode);
		if(newnode == NULL)
		printf("ALLOCATION FAILED INSERT NOT POSSIBLE\n");
		
		newnode -> data = key;
		struct Node * temp = *head;
		while(indx < pos - 1){
			temp = temp -> link;
			indx++;
		}
		newnode -> link = temp->link;
		temp -> link = newnode;
	}
}

int deletewithkey(struct Node ** head,int key){

	struct Node * temp = *head;
	if(temp->data == key)
		deletefirst(head);
	else{
		while((temp->link->data != key)&&(temp->link->link != NULL)){
			temp = temp -> link;
		}
		
		struct Node * temp1;
		temp1 = temp -> link;
			
		//int key = temp -> data;
		temp -> link = (temp -> link) -> link;
			
		free(temp1);
	}
}
void reverse(struct Node **head){
	struct Node* prev = NULL;
	struct Node* current = *head;
	struct Node* next = NULL;
	while(current != NULL){
		next = current -> link;
		current->link = prev;
		prev = current;
		current = next;
	}
	*head = prev;
}
void search1(int key,struct Node ** head){
	
	struct Node* temp = *head;

	
	int flag = 0,count = 0,pos;

		while(temp!= NULL){
		//printf("%d\t", temp -> data);
			if(temp->data == key){
				flag = 1;
				pos = count;
			}	
			count++;	
			temp = temp -> link;
		}
		
		if(flag == 1)
			printf("PRESENT AT %d\n",pos+1);
		else
			printf("NOT PRESENT\n");
	
}
void legend(){
	printf("Enter 1 for insert at end\n");
	printf("Enter 2 for insert at beginning\n");
	printf("Enter 3 for insert at position\n");
	printf("Enter 4 for delete first\n");
	printf("Enter 5 for delete last\n");
	printf("Enter 6 for delete at position\n");
	printf("Enter 7 for display SLL\n");
	printf("Enter 8 for reversing SLL\n");
	printf("Enter 9 for Searching a key\n");
	printf("Enter 10 to exit program\n");
	printf("ENTER ANY No. to display legend for program\n");
}
int Menu(struct Node ** head){
	int t;
	while(t){
		//int t;
		printf("Enter Code : ");
		scanf("%d",&t);
		int data,pos;
		int key;
		switch(t){
			case 1:
				//int key;
				printf("Enter Any value: ");
				scanf("%d",&key);
				insertatend(head,key);
				break;
			case 2:
				//int key;
				printf("Enter Any value: ");
				scanf("%d",&key);
				insertatbeg(head,key);
				break;
			case 3:
				//int key;
				printf("Enter Any value: ");
				scanf("%d",&key);
				//int pos;
				printf("ENTER POSN : ");
				scanf("%d",&pos);
				insertatpos(head,key,pos);
				break;
			case 4:
				//int data;
				data = deletefirst(head);
				printf("\nDELETED DATA: %d\n",data);
				break;
			case 5:
				//int data;
				data = deletelast(head);
				printf("\nDELETED DATA: %d\n",data);
				break;
			case 6:
				//int data;
				//int pos;
				printf("ENTER POSN : ");
				scanf("%d",&pos);
				data = deleteatpos(head,pos);
				printf("\nDELETED DATA: %d\n",data);
				break;
			case 7:
				display(head);
				break;
			case 8:
				reverse(head);
				break;
			case 9:
				printf("\nENTER KEY TO BE FOUND : ");
				scanf("%d",&key);
				search1(key,head);
				break;
				
			case 10:
				return 0;
			default:
				legend();
				break;
			
		}
	}
}


int main(){
	struct Node * head;
	head = NULL;
	
	//display(&head);
	insertatend(&head,5);
	insertatend(&head,4);
	insertatend(&head,3);
	insertatend(&head,2);
	insertatend(&head,1);
	display(&head);
	deletewithkey(&head,2);
	display(&head);
	/*insertatbeg(&head,5);
	insertatbeg(&head,8);
	display(&head);
	insertatpos(&head,10,1);
	insertatpos(&head,10,9);
	display(&head);
	deletefirst(&head);
	deletelast(&head);
	display(&head);
	reverse(&head);
	display(&head);
	search1(1,&head);
	search1(10,&head);
	search1(4,&head);*/
	//legend();
	//Menu(&head);

return 0;
}


