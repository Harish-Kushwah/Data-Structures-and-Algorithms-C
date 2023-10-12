/*
Q2:  Write  the  C-Language  program  to  Sort  a  random  array  of  n  integers 
(accept  the  value  of  n  from  user)  in  ascending  order  by  using  a  recursive 
Merge sort algorithm
*/


#include<stdio.h>

void merge(int arr[],int low,int mid,int upp)
{
    int i=low;
    int j=mid+1;
    int k=low;
    int b[low+upp];
    while(i<=mid&&j<=upp)
    {
        if(arr[i]<=arr[j]){
            b[k]=arr[i];
            i++;
        }
        else{
            b[k]=arr[j];
            j++;
        }
        k++;
    }
    if(i>mid)
    {
        while(j<=upp){
            b[k]=arr[j];
            j++;
            k++;
        }
    }
    else{
        while(i<=mid){
            b[k]=arr[i];
            i++;
            k++;
     }
    }
    for(k=low;k<=upp;k++){
      arr[k]=b[k];
    }
}
void mergeSort(int arr[],int low,int upp)
{
    if(low<upp)
    {
        int mid=(low+upp)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,upp);
        merge(arr,low,mid,upp);
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

  mergeSort(arr,0,n-1);
  
  printf("Sorted array :");
  for(int i=0;i<n;i++){
   printf("%d ",arr[i]);
  }
    return 0;
}