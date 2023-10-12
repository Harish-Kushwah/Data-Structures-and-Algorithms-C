/*
Q1. Create a random array of n integers. Accept a value x from user and use      
  linear search algorithm to check whether the number is present in the     
  array or not and output the position if the number is present.
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int* createRandomArray(int n)
{
    int *arr=(int *)malloc(n*sizeof(int));
    srand(time(NULL));
    for(int i=0;i<n;i++)
    {
        arr[i]=rand()%10+1;
    }
    return arr;
}
int lsearch(int arr[],int n,int target)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==target)
        return i;
    }
    return -1;
}
void printArr(int *arr,int n)
{
    printf("Random Element Array : ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main()
{
    int n;
    printf("Enter N :");
    scanf("%d",&n);
    int target;
    printf("Enter target :");
    scanf("%d",&target);
    int *arr=createRandomArray(n);
    printArr(arr,n);
    int pos=lsearch(arr,n,target);
    if(pos!=-1)
    {
        printf("%d found at %d ",target,pos);
    }
    else{
        printf("%d is Not Found",target);
    }
    return 0;
}