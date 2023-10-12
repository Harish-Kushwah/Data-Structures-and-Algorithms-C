/*
Q1:    Write  the  C-Language  program  to  Sort  a  random  array  of  n  integers 
(accept  the  value  of  n  from  user)  in  ascending  order  by  using  bubble  sort 
algorithm.
*/

#include<stdio.h>

int swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
int bubbleSort(int arr[],int n)
{
    for(int i=0;i<n;i++){
        for(int j=0;j<n-(i+1);j++){
            if(arr[j]<arr[j+1]);
            swap(&arr[j],&arr[j+1]);
        }
    }
}

int main()
{
    int n;
    printf("Enter size of array :");
    scanf("%d",&n);
    int arr[n];
    printf("Enter a array :");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    bubbleSort(arr,n);
    printf("Sorted array :");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}