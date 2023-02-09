#include <stdio.h>

void swap(int *a,int *b){
	int t = *a;
	*a = *b;
	*b = t;
}
void display(int *a,int n){
	for(int i=0;i<n;i++)
		printf(" %d ",a[i]);
	
	printf("\n");
}
int partition(int a[],int low,int high){
	int pivot = a[high];
	int i = low-1 ;
	
	for(int j=low;j<=high - 1;j++){
		if(a[j] < pivot){
			i++;
			swap(&a[i],&a[j]);
		}
	}
	swap(&a[i+1],&a[high]);
	return i+1;
}
void quick_sort(int a[],int low,int high){
	if(low < high){
		int q = partition(a,low,high);
		
		quick_sort(a,low,q-1);
		quick_sort(a,q+1,high);
	}
}

int main(){
	int a[10] = {10,19,0,26,6,11,20};
	int n = 7,low = 0;
	int high = n - 1;
	display(a,n);
	quick_sort(a,low,high);
	printf("Sorted array is : \n");
	display(a,n);
}
