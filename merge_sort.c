#include <stdio.h>
void merge(int A[],int l,int mid,int h){
    int s=h-l+1;
    int B[s],j=l,k=mid+1,i;
    for(i=0;k <= h && j <= mid ;i++){
        if(A[j]>A[k]){
            B[i]=A[k];
            k++;
        }
        else{
            B[i]=A[j];
            j++;
        }
    }
    while(i<s){
        if(j==mid+1){
            B[i]=A[k];
            k++;
        }
        else{
            B[i]=A[j];
            j++;
        }
        i++;
    }
    
    int x=l;
    i=0;
    while(i<s){
        A[x]=B[i];
        x++;
        i++;
    }
}
void mergeSort(int a[],int l,int h){
    if(l<h){
        int mid=(l+h)/2;
        mergeSort(a,l,mid);
        mergeSort(a,mid+1,h);
        merge(a,l,mid,h);
    }
}
void display(int a[],int x){
	for(int i=0;i<x;i++)
		printf("%d  ",a[i]);
		
	printf("\n------------------------------------\n");
}
int main(){
    int a[10]={1,8,6,4,5,2,3,9,7,0};
    int l=0,h=9;
    printf("The array is :\n");
    display(a,10);
    mergeSort(a,l,h);
    printf("The sorted array:\n");
    display(a,10);
}
