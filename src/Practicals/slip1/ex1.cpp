/*
Q1:    Write  the  C-Language  program  for  Create  a  random  array  of  n  integers. 
Accept  a  value  x  from  user  and  use  linear  search  algorithm  to  check  whether 
the  number  is  present  in  the  array  or  not  and  output  the  position  if  the 
number is present.
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int *createRandomArray(int n)
{
    srand(time(NULL));
     int *arr=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        arr[i]=rand()%10+1;
    }

    return arr;
}

int lsearch(int *arr ,int n)
{
    int target;
    printf("\nEnter a target :");
    scanf("%d",&target);
    for(int i=0;i<n;i++){
        if(target==arr[i])
         return i;
    }
    return -1;
}
void printArray(int *arr,int n)
{
    printf("\nThe random array :");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
int main()
{
     int n;
     printf("\nEnter size of array :");
     scanf("%d",&n);
    int *arr=createRandomArray(n);
    int pos=lsearch(arr,n);
    printArray(arr,n);
     if(pos!=-1){
        printf("\nThe element found at %d ",pos);
     }
     else{
        printf("\nThe element is not found ");
     }

}