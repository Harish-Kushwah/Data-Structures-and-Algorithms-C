/*
Q1:    Write  the  C-Language  program  to  Sort  a  random  array  of  n  integers 
(create  a  random  array  of  n  integers)  in  ascending  order  by  using  insertion 
sort algorithm. 
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int* generateRandomArr(int n)
{
    srand(time(NULL));
    int *arr=(int *)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
    {
       arr[i]=rand()%10+1;
    }
    return arr;
}

void insertionSort(int arr[],int n)
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
void printArr(int arr[],int n)
{
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main()
{
    int n;
    printf("Enter size of array :");
    scanf("%d",&n);
    int *arr=generateRandomArr(n);
    printf("Non sorted array :");
    printArr(arr,n);
    insertionSort(arr,n);
    printf("Sorted array :");
    printArr(arr,n);

    return 0;
}