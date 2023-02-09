#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 10

typedef struct array{
	int *a;
	int last_index;
	int max_size;	
}array;

void extend(array *a1){
	a1 -> a = (int *) realloc( a1 -> a, ((a1->max_size)+5)*sizeof(int));
	(a1 -> max_size) += 5;
	printf("Array extended\n");
}
void isfull(array *a1){
	if(a1 -> last_index == (a1 -> max_size) -1)
		extend(a1);
}
void insert(array *a1,int key){
	isfull(a1);
	a1 -> a[a1->last_index] = key;
	(a1 -> last_index)++;
}
void display(array a1){
	printf("\n");
	for(int i =0;i<(a1.last_index);i++)
		printf("%d\t",a1.a[i]);
	printf("\n");
}
void create(array *a1,int max){
	a1 -> max_size = max;
	a1 -> last_index = 0;
	a1 -> a = (int *) calloc(CAPACITY,sizeof(int));
	
	//if(a1->a == NULL)
		//printf("Array Not Created\n");
}
void sort(array *a1,array *s1){
	for(int i =0;i<(a1 -> last_index);i++){
		int count =1;
		for(int j=i+1;j<(a1 -> last_index);j++){
			if(a1 -> a[i] < a1 -> a[j])
				count = 0;
		}
		if(count == 1)
			insert(s1,a1->a[i]);	
	}
	
		/*if (a1->a[i] > a1->a[i+1])
			insert(s1,a1->a[i]);
	insert(s1,a1->a[(a1->last_index)-1]);*/
}

int main(){
	
	array arr;
	array sorted;
	create(&sorted,CAPACITY);
	create(&arr,CAPACITY);
	for(int i=0;i<20;i++)
		insert(&arr,(rand()%100)+1);
		
	//insert(&arr,i+10);
	
	sort(&arr,&sorted);
	printf("The Given data of Buildings is : (Heights)\n");
	display(arr);
	printf("The Buildings that will be able to see the SUNSET are :\n");
	display(sorted);
	
	
	
	return 0;
	
}

