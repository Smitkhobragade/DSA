#include <stdio.h>
#include<stdlib.h>

typedef struct array{
    int *a;
    int LastIndex;
    int size;
}array;

int isFull(array *a1, int max)
{
    if(a1->LastIndex == max-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(array a1)
{
    if(a1.LastIndex == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void create(array *a1, int max)
{
    a1->LastIndex = -1;
    a1->size = max;
    a1->a = (int*)malloc((max)*sizeof(int));
}

void add(array *a1 , int data)
{
    if(isFull(a1, a1->size) == 1)
    {
        printf("THE ARRAY IS FULL");
    }
    else{
        (a1->LastIndex)++;
        a1->a[a1->LastIndex] = data;
    }
    printf("THE ENTERED ELEMENT IS :%d\n" , data);
    printf("THE VALUE OF LAST INDEX NOW IS :%d\n", a1->LastIndex);
}

void display(array a1)
{
    printf("THE ARRAY IS  :");
    for(int i = 0; i<=a1.LastIndex;i++)
    {
        printf("%d\n" , a1.a[i]);
    }
}

int searcharr(array a1, int data)
{
    for(int i =0; i<a1.size;i++)
    {
        if(a1.a[i] == data)
        {
            return (i+1);
        }
    }
}

int lengtharr(array a1)
{
    return (a1.LastIndex)+1;
}
