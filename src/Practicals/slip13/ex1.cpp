/*
Q1:    Write  the  C-Language  program  to  Sort  a  random  array  of  n  integers 
(accept  the  value  of  n  from  user)  in  descending  order  by  using  bubble  sort 
algorithm. 
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int *generateRandomArr(int n)
{
    srand(time(NULL));
    int *arr=(int *)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        arr[i]=rand()%20+1;
    }
    return arr;
}
void bubbleSort(int *arr,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++){
            if(arr[i]<arr[j])
            {
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
      }
    }
}
void printArr(int arr[],int n)
{
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");

}
int main()
{
    int n;
    printf("Enter size of array :");
    scanf("%d",&n);
    int *arr=generateRandomArr(n);
    printArr(arr,n);
    bubbleSort(arr,n);
    printf("Sorted array :");
    printArr(arr,n);
}