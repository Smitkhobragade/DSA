#include <stdio.h>
#define cap 10

void swap(int *a,int *b){
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int a[],int low,int high){
	int p=low;
    int pivot=a[low];
    int i=low+1;
    int j=high;
    while(i>j){
        while(i<=high && a[i]<=pivot)
            i++;
        while(a[j]>pivot)
            j--;
        if(i<j)
            swap(&a[i],&a[j]);
    }
    swap(&a[p],&a[j]);
    return j;
}

void quicksort(int a[],int low, int high){
	if(low < high){
		int q = partition(a,low,high);
		quicksort(a,low,q-1);
		quicksort(a,q+1,high);
	}
}
void display(int a[]){
	printf("\n");
	for(int i = 0; i < cap; i++){
		printf(" %d ",a[i]);
	}
}
int main(){
	int arr[cap] = {4,1,3,6,2,8,9,0,5,7};
	display(arr);
	int low = 0, high = 9;
	quicksort(arr,low,high);
	display(arr);
	
	return 0 ;
}
