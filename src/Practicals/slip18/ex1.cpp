/*
Q1:    Write  the  C-Language  program  which  Accept  n  sorted  values  in  array 
from  user.  Accept  a  value  x  from  user  and  use  binary  search  algorithm  to 
check  whether  the  number  is  present  in  sorted  array  or  not  and  output  the 
position if the number is present.
*/

#include<stdio.h>

int bsearch(int arr[] ,int n)
{
    int low=0;
    int upp=n-1;
    int mid;
    int target;
    printf("Enter a target :");
    scanf("%d",&target);
    while(low<=upp)
    {
        int mid=(low+upp)/2;
        if(arr[mid]==target){
            return 1;
        }
        else if(arr[mid]>target)
        {
            upp=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return -1;
}
void printArray(int arr[],int n)
{
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
int main()
{
     int n;
     printf("\nEnter size of array :");
     scanf("%d",&n);
    int arr[n];
    printf("Enter array :");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
     if(bsearch(arr,n)==1){
        printf("\nThe element found at  ");
     }
     else{
        printf("\nThe element is not found ");
     }

}