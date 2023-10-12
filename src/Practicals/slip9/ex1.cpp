/*
Q1:    Write  the  C-Language  program  to  Sort  a  random  array  of  n  integers 
(create  a  random  array  of  n  integers)  in  ascending  order  by  using  insertion 
sort algorithm.
*/
#include<stdio.h>


void insertionSort(int arr[],int n )
{
    for(int i=1;i<n;i++){
        int temp=arr[i];
        int j=i-1;
        while(j>=0&&arr[j]>temp)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}

int main()
{

    int n;
    printf("Enter a n :");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    insertionSort(arr,n);
    printf("Sorted array :");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}