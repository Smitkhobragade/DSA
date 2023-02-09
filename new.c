#include <stdio.h>
#include <time.h>
#define MAX_SIZE 1000000

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

int main()
{
    int n, i, step = 10;
    int a[MAX_SIZE];
    double duration;
    clock_t start, end; // typedef of a numeric type: represent running time
    printf("MERGE SORT\n");
    printf("n   time \n");
    for (n = 0; n <= 10000; n += step)
    {
        for (i = 0; i < n; i++)
        {
            a[i] = n - i;
        }
        start = clock(); // returns processor clock time since the program is started
        int low=0,high=n-1;
	mergeSort(a,low,high);
        end = clock();
        duration = (((double)(end - start)) / CLOCKS_PER_SEC); // no. of clock ticks per second
        printf("%d   %lf\n", n, duration);
        if (n == 100)
            step = 100;
        if (n == 1000)
            step = 1000;
    }
    return 0;
}

