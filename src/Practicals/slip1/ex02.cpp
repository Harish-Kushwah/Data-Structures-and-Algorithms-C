/*
Q2:  Write  the  C-Language  program  to  Sort  a  random  array  of  n  integers 
(accept  the  value  of  n  from  user)  in  ascending  order  by  using  Counting  sort 
algorithm.
*/

#include<stdio.h>
#include<stdlib.h>
#define Max 20

int hash[Max];

void countingSort(int arr[],int n)
{
    for(int i=1;i<Max;i++)
    {
        hash[i]=hash[i]+hash[i-1];
    }

    int arr1[n];
    for(int i=0;i<n;i++)
    {
        arr1[hash[arr[i]]-1]=arr[i];
        hash[arr[i]]--;
    }
    
    for(int i=0;i<n;i++)
    {
        arr[i]=arr1[i];
    }
}
int main()
{
    int n;
    printf("Enter how many number wants to sort :");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
       arr[i]=rand()%10+1;
       hash[arr[i]]++;
    }
    countingSort(arr,n);

    printf("Array after sorting :");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }

}