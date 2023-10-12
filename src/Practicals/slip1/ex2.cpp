/*
Q2:  Write  the  C-Language  program  to  Sort  a  random  array  of  n  integers 
(accept  the  value  of  n  from  user)  in  ascending  order  by  using  Counting  sort 
algorithm.
*/

#include<stdio.h>
#include<stdlib.h>
#define N 20
int hash1[N];
void countingSort(int arr[],int n)
{
    for(int i=0;i<=N;i++){
        hash1[i]=0;
    }
    //count each element
    for(int i=0;i<n;i++){
        hash1[arr[i]]++;
    }

    //take their cumulative sum
    for(int i=1;i<=N;i++){
        hash1[i]+=hash1[i-1];
    }

    int arr1[n];
    for(int i=n-1;i>=0;i--){
      arr1[hash1[arr[i]]-1]=arr[i];
      hash1[arr[i]]--;
    }
    for(int i=0;i<n;i++){
        arr[i]=arr1[i];
    }
}
int main()
{
   int n;
   printf("Enter size of array :");
   scanf("%d",&n);
   int arr[n];
   printf("Enter array :");
   for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
   }

   countingSort(arr,n);
   printf("Sorted array :");
   for(int i=0;i<n;i++){
    printf("%d ",arr[i]);
   }
 return 0;

}