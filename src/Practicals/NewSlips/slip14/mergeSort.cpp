#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
int partion(int arr[],int low,int upp)
{
    int pi=arr[low];
    int start=low+1;
    int end=upp;
    while(start<=end)
    {
        if(arr[start]<=pi)
        {
            start++;
        }
        if(arr[end]>pi)
        {
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
    printf("Enter N :");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    quick(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
     printf("%d ",arr[i]);
    }
}