#include <stdio.h>
#define CAPACITY 10
int a[CAPACITY];

/*
--------------USER GUIDE-------------

isFULL --> This function checks the Overflow property
isEmpty --> This Funtion checks the Underflow property
create --> This function initialises both the queues
insertq1 --> This function is used to insert element in queue 1
insertq2 --> This function is used to insert element in queue 2
deleteq1 --> This function removes the element from the queue 1
deleteq2 --> This function removes the element from the queue 2
peek --> this function can be used to get the value of front in any queue
*/

typedef struct Queue{
	int rear;
	int front;
}Queue;


int isFull(Queue queue1,Queue queue2){
	if((queue1.rear == CAPACITY-1)||(queue2.rear == 0)||(queue1.rear == queue2.rear)){
		printf("Array is full(OVERFLOW)\n");//overflow
		return 1;
	}
	else
		return 0;
}
int isEmpty(Queue queue12){
	if(queue12.rear == queue12.front){
		printf("QUEUE is Empty(UNDERFLOW)\n");//underflow
		return 1;
	}
	else
		return 0;
}
void create(Queue *queue1,Queue *queue2){
	queue1->rear = 0;
	queue1->front = 0;
	queue2->rear = CAPACITY-1;
	queue2->front = CAPACITY-1;
	printf("Queue's are created\n");
}
void insertq1(Queue * queue1,Queue * queue2,int key){
	if(isFull(*queue1,*queue2)){
		printf("Cannot insert\n");
	}
	else{
		a[queue1->rear] = key;
		queue1->rear++;
	}
}
void insertq2(Queue * queue1,Queue * queue2,int key){
	if(isFull(*queue1,*queue2)){
		printf("Cannot insert\n");
	}
	else{
		a[queue2->rear] = key;
		queue2->rear--;
	}
}
int peek(Queue queue12){
	printf("The element now in front in Queue -->  %d \n",a[queue12.front]);
	return a[queue12.front];
}
int deleteq1(Queue * queue1){
	if(isEmpty(*queue1)){
		printf("Cannot Delete the element in queue1\n");
		return -999;
	}
	else{
		int key = a[queue1->front];
		(queue1->front)++;
		return key;
	}
}
int deleteq2(Queue * queue2){
	if(isEmpty(*queue2)){
		printf("Cannot Delete the element in queue2\n");
		return -999;
	}
	else{
		int key = a[queue2->front];
		(queue2->front)--;
		return key;
	}
}

int main(){
	Queue queue1;
	Queue queue2;
	create(&queue1,&queue2);
	deleteq1(&queue1);
	deleteq2(&queue2);
	insertq1(&queue1,&queue2,8);
	insertq1(&queue1,&queue2,2);
	insertq1(&queue1,&queue2,6);
	insertq1(&queue1,&queue2,5);
	
	peek(queue1);
	deleteq1(&queue1);
	peek(queue1);
	
	insertq2(&queue1,&queue2,10);	
	insertq2(&queue1,&queue2,1);
	insertq2(&queue1,&queue2,3);
	insertq2(&queue1,&queue2,0);
	
	peek(queue2);
	insertq2(&queue1,&queue2,2);
	deleteq2(&queue2);
	peek(queue2);
	insertq2(&queue1,&queue2,3);
	peek(queue2);
	
}
