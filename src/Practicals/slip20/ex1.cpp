/*
Q1:    Write  the  C-Language  program  to  Sort  a  random  array  of  n  integers 
(accept  the  value  of  n  from  user)  in  ascending  order  by  using  selection  sort 
algorithm.
*/

#include<stdio.h>
void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
void selectionSort(int arr[],int n)
{
  for(int i=0;i<n;i++)
  {
    int min=arr[i];
    int index=i;
    for(int j=i+1;j<n;j++){
        if(arr[j]<min){
            min=arr[j];
            index=j;
        }
    }
    swap(&arr[i],&arr[index]);
  }

}
int main()
{
    int n;
    printf("Enter size of array :");
    scanf("%d",&n);
    int arr[n];
    printf("Enter a array :");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    selectionSort(arr,n);
    printf("Sorted array :");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }

    return 0;
}