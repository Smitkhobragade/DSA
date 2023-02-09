#include <stdio.h>

void swap(int *a,int *b){
	int t = *a;
	*a = *b;
	*b = t;
}

void Selection_sort(int a[],int  last_index){
	for(int i=0;i<last_index-1;i++){
		int min_index = i;
		for(int j = i+1; j<last_index; j++){
			if(a[min_index] > a[j])
				min_index = j;
		}
		swap(&a[i],&a[min_index]);
	}
}

void Bubble_sort(int a[],int last_index){
	int count = 0;
	
	for(int i = 0;i<last_index;i++){
		count = 0;
		for(int j = 0;j<last_index-i-1;j++){
			if(a[j]>a[j+1]){
				count = 1;
				swap(&a[j+1],&a[j]);
			}
		}
		if(count == 0)
			break;
	}
}

void Insertion_sort(int a[],int last_index){
	int key,j;
	for(int i = 0;i<last_index;i++){
		key = a[i];
		j = i - 1;
		while(j>=0 && a[j]>key){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = key;
	}
}

void display(int a[],int last_index){
	printf("\n");
	for(int i =0 ;i<last_index;i++)
		printf(" %d ",a[i]);
}


int main(){
	int arr[20] = {1,6,9,2,4,7,8,3,5,0};
	int last_index = 10;
	display(arr,last_index);
	Selection_sort(arr,last_index);
	display(arr,last_index);
	int arr1[20] = {1,6,9,2,4,7,8,3,5,0};
	display(arr1,last_index);
	Bubble_sort(arr1,last_index);
	display(arr1,last_index);
	int arr2[20] = {1,6,9,2,4,7,8,3,5,0};
	display(arr2,last_index);
	Insertion_sort(arr2,last_index);
	display(arr2,last_index);
	printf("\n");
}
