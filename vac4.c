
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

	printf("---%d\n",count);
	return count;
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


return 0;
}
