/*
Q2:  Write  the  C-Language  program  to  Sort  a  random  array  of  n  integers 
(create  a  random  array  of  n  integers)  in  ascending  order  by  using  recursive 
Quick sort algorithm. 
*/

#include<stdio.h>

void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
int partion(int arr[],int low,int upp)
{
   int pi=arr[low]; 
   int start=low;
   int end=upp;
   while(start<end)
   {
      while(arr[start]<=pi){
        start++;
      }
      while(arr[end]>pi){
        end--;
      }
      if(start<end)
      {
        swap(&arr[start],&arr[end]);
      }
   }
   swap(&arr[low],&arr[end]);
   return end;


}
void quick(int arr[],int low,int upp)
{

    if(low<upp)
    {
      int pi=partion(arr,low,upp);
      quick(arr,low,pi-1);
      quick(arr,pi+1,upp);

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
    quick(arr,0,n-1);
    printf("Sorted array :");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}