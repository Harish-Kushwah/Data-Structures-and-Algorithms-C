/*
Q1. Read the ‘n’ numbers from user and sort using bubble sort. 
*/
#include<stdio.h>
void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
int* bubbleSort(int arr[],int n)
{
    for(int i=0;i<n;i++){
        for(int j=0;j<(n-(i+1));j++){
            if(arr[j]<arr[j+1])
            swap(&arr[j],&arr[j+1]);
        }
    }
    return arr;
}
int main()
{
    int n;
    printf("Enter size of N :");
    scanf("%d",&n);
    int arr[10];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int *ar1=bubbleSort(arr,n);
    for(int i=0;i<n;i++){
       printf("%d ",ar1[i]);
    }
}