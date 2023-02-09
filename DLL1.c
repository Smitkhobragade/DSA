#include <stdio.h>
#include <stdlib.h>

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
	if(temp == NULL){
		*head = newnode;
	}else{
		while(temp -> link != NULL){
			temp = temp -> link;
		}
		
		temp -> link = newnode;
		newnode -> prev = temp;
	}
}

void insertatbeg(struct Node ** head,int key){
	struct Node * newnode;
	CreateNode(&newnode);
	if(newnode == NULL)
		printf("ALLOCATION FAILED INSERT NOT POSSIBLE\n");
		
	newnode -> data = key;
	newnode -> link = *head;
	newnode -> prev = NULL;
	(*head) -> prev = newnode;
	*head = newnode;
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

int deletefirst(struct Node ** head){
struct Node * temp = *head;
int key;
	if(*head == NULL){
		printf("CANNOT DELETE\n");
		key = -1;
	}/*else if((*head)->link == NULL){
		//struct Node * temp = *head;
		//free(temp);
		int key = (*head) -> data;
		*head = NULL;
		
		return key;*/
	else{
		key = temp -> data;
		*head = temp-> link;
		temp -> prev = NULL;
		//free(temp);
		//return key;
	
	}
	free(temp);	
	return key;
	
}

int deletelast(struct Node ** head){
	struct Node * temp = *head;
	if(head == NULL){
		printf("CANNOT DELETE\n");
		return -1;
	}
	else if((*head)->link == NULL){
		return deletefirst(head);
	}else{
		while(temp -> link != NULL){
			temp = temp -> link;
		}
		int key = temp -> data;
		temp = temp -> prev;
		free(temp -> link);
		temp->link = NULL;
		return key;
	}
}

int lengthll(struct Node * head){
	int count=0;
	struct Node * temp = head;
	while(temp!=NULL){
		count++;
		temp = temp -> link;	
	}

	//printf("--- length : %d\n",count);
	return count;
}

void insertatpos(struct Node ** head,int key,int pos){
	int lth = lengthll(*head) + 1;
	//printf("---%d\n",lth);
	if(pos<1 || pos>lth)
		printf("INVALID POSITION\n");
	else if(pos == 1)
		insertatbeg(head,key);
	else if(pos == lth)
		insertatend(head,key);
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
		newnode -> prev = temp;
		(temp -> link) -> prev = newnode;
		temp -> link = newnode;
	}
}

void displayreverse(struct Node * head){
	struct Node * temp = head;
	while(temp->link!=NULL){
		temp = temp -> link;
	}
	//temp = temp->prev;
	//printf("%d\t",(temp->data));
	while(temp!= NULL){
		printf("%d\t",(temp->data));
		temp = temp->prev;
	}
	printf("\n");
}

int deleteatpos(struct Node ** head,int pos){
	int lth = lengthll(*head);
	//printf("---%d\n",lth);
	if(head == NULL)
		printf("SLL IS EMPTY\n");
	else if(pos<1 || pos>lth)
		printf("INVALID POSITION\n");
	else if(pos == 1)
		deletefirst(head);
	else if(pos == lth)
		deletelast(head);
	else{
		struct Node * temp = *head;
		struct Node * temp1;
		int count=pos-1;
		while(count--){
			temp = temp->link;
		}
		//temp = temp -> link;
		int key = temp -> data;
		
		(temp -> prev) -> link = temp -> link;
		(temp -> link) -> prev = temp -> prev;
		free(temp);
		
		return key;
	}
}

void sort(struct Node ** head){
	struct Node * temp = *head;
	int last_index = lengthll(*head);
	int count = 0;
	
	for(int i = 0;i<last_index;i++){
		count = 0;
		temp = *head;
		for(int j = 0;j<last_index-i-1;j++){
			if((temp->data)>(temp->link)->data){
				count = 1;
				//swap(&a[j+1],&a[j]);
				int t = temp->data;
				temp->data = (temp->link)->data;
				(temp->link)->data = t;
			}
			temp = temp->link;
		}
		if(count == 0)
			break;
	}
	
	printf("\n");
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
	printf("Enter 7 for display LL\n");
	printf("Enter 8 for displaying reverse LL\n");
	printf("Enter 9 for Searching a key\n");
	printf("Enter 10 for sorting LL\n");
	printf("Enter 11 to exit program\n");
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
				displayreverse(*head);
				break;
			case 9:
				printf("\nENTER KEY TO BE FOUND : ");
				scanf("%d",&key);
				search1(key,head);
				break;
			case 10:
				sort(head);
				break;
			case 11:
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
	/*insertatend(&head,4);
	insertatend(&head,3);
	insertatend(&head,2);
	insertatend(&head,5);
	insertatbeg(&head,6);*/
	
	/*display(&head);
	deletefirst(&head);
	display(&head);
	for(int i = 0;i<5;i++){
	int data = deletefirst(&head);
	printf("\nDELETED DATA: %d\n",data);
	display(&head);
	}*/
	
	/*insertatpos(&head,10,3);
	display(&head);
	deleteatpos(&head,6);
	display(&head);
	insertatpos(&head,16,6);
	display(&head);
	insertatpos(&head,12,1);
	display(&head);
	deleteatpos(&head,7);
	display(&head);
	deleteatpos(&head,1);
	display(&head);
	deleteatpos(&head,4);
	display(&head);
	insertatpos(&head,5,1);
	display(&head);
	insertatpos(&head,9,3);
	display(&head);
	displayreverse(head);
	sort(&head);
	display(&head);
	search1(1,&head);
	search1(6,&head);*/
	legend();
	Menu(&head);

}
