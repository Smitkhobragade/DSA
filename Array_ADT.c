#include <stdio.h>
#define CAPACITY 5

int initialise(){
	return -1;
}
int isEmpty(int last_index){
	if(last_index == -1)
		return 1;
	return 0;
}
int isFull(int last_index){
	if(last_index == CAPACITY - 1)
		return 1;
	return 0;
}
int get_input(){
	int n;
	scanf("%d",&n);
	return n;
}
int add(int arr[], int * last_index, int n){
	if(isFull(*last_index) == 1)
	{
		printf("Array is full\n");
		return 0;
	}
	
	arr[(*last_index) + 1] = n;
	(*last_index)++;
	return 1;
}
void create(int arr[], int * last_index){
	int n ,flag;
	printf("ENTER ARRAY ELEMENTS: \n");
	while(1){
		n = get_input();
		if(n == -999)
			break;
		
		flag = add(arr,last_index,n);
		
		if(flag == 0)
			break;
	}
}
void display(int arr[],int last_index){
	for(int i = 0; i <= last_index; i++)
		printf("%d\t",arr[i]);
	printf("\n");
}
void arr_length(int last_index){
	printf("%d is the current length of array\n",last_index+1);
}
int put(int arr[],int * last_index,int ele,int posn){
	if(isFull(*last_index) == 1)
	{
		printf("Array is Full can't Insert The Element\n");
		return 0;
	}
	
	for(int i = (*last_index); i >= posn; i--)
		arr[i+1] = arr[i];
	
	arr[posn] = ele;
	(*last_index)++;
	return 1;
}
int insert(int arr[],int * last_index){
	int ele,posn;
	printf("Enter the Element Followed by position: ");
	scanf("%d %d",&ele,&posn);
	put(arr,last_index,ele,posn);
}
void delete(int arr[], int *last_index){
	int x;
	printf("Enter position where you want to delete: ");
	scanf("%d",&x);
	
	for(int i = x; i <= (*last_index); i++)
		arr[i] = arr[i+1];
	
	(*last_index)--;
}



int main(){
	
	int arr[CAPACITY];
	int last_index = initialise();
	create(arr,&last_index);
	display(arr,last_index);
	arr_length(last_index);
	insert(arr,&last_index);
	display(arr,last_index);
	arr_length(last_index);
	delete(arr,&last_index);
	display(arr,last_index);
	arr_length(last_index);
	
return 0;

}
