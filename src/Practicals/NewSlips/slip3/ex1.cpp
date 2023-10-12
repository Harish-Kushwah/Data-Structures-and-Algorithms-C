/*
Q1. Sort a random array of n integers (accept the value of n from user) in        
 ascending order  by using insertion sort algorithm. 
*/

#include<stdio.h>
void insertionSort(int arr[],int n)
{
    for(int i=1;i<n;i++)
    {
        int temp=arr[i];
        int j=i-1;
        while(j>=0 &&arr[j]>temp){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
  for(int i=0;i<n;i++)
  {
    printf("%d ",arr[i]);
  }
}
int main()
{
    int n;
    printf("Enter N :");
    scanf("%d",&n);
    int arr[20];
    printf("Enter array : ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    insertionSort(arr,n);
}