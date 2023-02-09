//quick sort algo
#include <stdio.h>
void swap(int *a,int *b){
	int c = *a;
	*a = *b;
	*b = c;
}

int partition(int a[],int l,int h){
	int p = l;
	int pivot = a[l];
	int i = l+ 1;
	int j=h;
	while(i<=j){
		while(a[i]<=pivot)
			i++;
		while(a[j]>pivot)
			j--;
		if(i<j){
			swap(&a[i],&a[j]);
		}
	}
	if(i > j){
		swap(&a[p],&a[j]);
		return j;
	}
	
}

void quick_sort(int a[], int low, int high){
	if(low<high){
		int q = partition(a,low,high);
		quick_sort(a,low,q-1);
		quick_sort(a,q+1,high);
	
	}
}

void display(int a[]){
	for(int i=0;i<10;i++)
		printf("%d  ",a[i]);
	
	printf("\n--------------------------------------\n");
}
int main(){
	int a[10] = {1,6,7,9,0,2,3,5,8,4};
	printf("The Given Array is :\n");
	display(a);
	int low=0,high=9;
	quick_sort(a,low,high);
	printf("The Sorted array is :\n");
	display(a);
	

}







