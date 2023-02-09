//#include <stdio.h>
//#define SIZE 3

//matrix ADT
#include <stdio.h>
#define cap 3
struct matrix{
    int a[cap][cap];
    int lastrow_index;
    int lastcol_index;
};

void intialise(struct matrix *a){
    a->lastrow_index=-1;    
    a->lastcol_index=-1;       

}
int getinput(){
    int x;
    scanf("%d",&x);
    return x;
}

int create(struct matrix *a){

    printf("\nENTER ELEMENTS: \n");
    while(a->lastrow_index<cap && a->lastcol_index<cap){
    
  		for(a->lastrow_index = 0;a->lastrow_index<cap;a->lastrow_index++){
  
			for(a->lastcol_index = 0;a->lastcol_index<cap;a->lastcol_index++){
				a->a[a->lastrow_index][a->lastcol_index] = getinput();
			}
        } 
    }
}
int display(struct matrix *a){
	printf("\n");
    for(int i = 0;i<cap;i++){
        for(int j = 0; j<cap;j++){
            printf("%d\t",a->a[i][j]);
            
        }
        printf("\n");
    }
}
int sum(struct matrix arr1, struct matrix arr2, struct matrix * result){
	for(int i = 0;i<cap;i++){
		for(int j = 0; j<cap;j++){
            //printf("%d\t",a->a[i][j]);
            result->a[i][j] = arr1.a[i][j] + arr2.a[i][j];
        }
	}
	printf("\nTHE SUM OF TWO MATRICES\n ");
return 0;
}
void transpose(struct matrix arr1,struct matrix * result){
	for(int i = 0;i<cap;i++){
		for(int j = 0; j<cap;j++){
		    //printf("%d\t",a->a[i][j]);
			result->a[i][j] = arr1.a[j][i];
		}
	}
	printf("\nTHE Transpose of matrix is \n ");
}
void Multiplication(struct matrix arr1 ,struct matrix arr2 ,struct matrix * result){
	for(int i = 0; i<cap; i++){
		for(int j = 0; j<cap; j++){
			result->a[i][j] = 0;
			for(int k = 0 ; k<cap; k++){
				result->a[i][j] = result->a[i][j] + arr1.a[i][k] * arr2.a[k][j];
			}
		}
	}
	
	printf("\nTHE MULTIPLICATION OF TWO MATRICES IS : \n");
}
int main(){
    struct matrix arr1,arr2,result;
    intialise(&arr1);
    intialise(&arr2);
    intialise(&result);
    create(&arr1);
    display(&arr1);
    create(&arr2);
    display(&arr2);
    sum(arr1,arr2 ,&result);
    display(&result);
    transpose(arr1,&result);
    display(&result);
    Multiplication(arr1,arr2,&result);
    display(&result);
//    printf("%d",arr1.lastrow_index);
    
    return 0;
}
