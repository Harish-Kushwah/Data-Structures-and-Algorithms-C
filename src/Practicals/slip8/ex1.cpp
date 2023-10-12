/*
Q1:    Write  the  C-Language  program  to  Sort  a  random  array  of  n  integers 
(accept  the  value  of  n  from  user)  in  descending    order  by  using  bubble  sort 
algorithm. 
*/
#include<stdio.h>
void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
void bubbleSort(int arr[],int n)
{
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
           if(arr[j]<arr[j+1])
           swap(&arr[j],&arr[j+1]);
        }
    }
}
int main()
{
  int n;
  printf("Enter n :");
  scanf("%d",&n);
  int arr[n];
  printf("Enter array :");
  for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
  }
  bubbleSort(arr,n);
  printf("Sorted array :");
  for(int i=0;i<n;i++){
   printf("%d ",arr[i]);
  }
    return 0;
}