#include <stdio.h>
#define CAPACITY 5

struct array{
	int arr[CAPACITY];
	int last_index;
};

int initialise(){
	return -1;
}
int getInput(){
	int n;
	scanf("%d",&n);
	return n;
}
int isFull(int last_index){
	if(last_index == CAPACITY - 1)
		return 1;
	return 0;
}
int add(struct array * a, int n){

	if(isFull(a->last_index) == 1){
		printf("ARRAY IS FULL\n");
		return 0;
	}
	
	a->arr[(a->last_index)+1] = n;
	(a->last_index)++;
	return 1;
}

int create(struct array * a){
	int n,flag;
	printf("ENTER ELEMENTS OF ARRAY : \n");
	while(1)
	{
		 n = getInput();
		 if(n == -999)
		 	break;
		 
		 flag = add(a , n);
		  
		 if(flag == 0)
		 	break;
	}
	
	return 0;
}
void display(struct array a){
	for(int i = 0; i <= a.last_index; i++)
		printf("%d	",a.arr[i]);
		
	printf("\n");
}
void length(struct array a){
	printf("%d is the Current Location of the Array. \n",(a.last_index)+1);
}
int put(struct array * a, int ele, int posn){
	if(isFull(a->last_index) == 1){
		printf("ARRAY IS FULL!!\n");
		return 0;
	}
	
	for(int i = (a->last_index);i>=posn;i--)
		a->arr[i+1] = a->arr[i];
		
	a->arr[posn] = ele;
	(a->last_index)++;
	return 1;
}
int insert(struct array * a){
	int ele,posn;
	printf("ENTER ELEMENT AND POSITION : ");
	scanf("%d %d",&ele,&posn);
	put(a,ele,posn);
}
void delete(struct array * a){
	int n;
	printf("ENTER POSN OF ELEMENT TO BE DELETED: ");
	scanf("%d",&n);
	
	for(int i = n; i <= (a->last_index);i++)
		a->arr[i] = a->arr[i+1];
	
	(a->last_index)--;
}
void copy(struct array * a, struct array * b){
	for(int i = 0; i < (a->last_index)+1 ; i++)
		b->arr[i] = a->arr[i];
	
	b->last_index = a->last_index;
}

int isEmpty(struct array a)
{
    if(a.last_index == -1)
    return 1;
    return 0;
}

int main(){
	struct array a;
	struct array b;
	a.last_index = initialise();
	create(&a);
	display(a);
	length(a);
	insert(&a);
	display(a);
	length(a);
	delete(&a);
	display(a);
	length(a);
	copy(&a,&b);
	printf("THE COPIED ARRAY IS : \n");
	display(b);

	return 0;
}
