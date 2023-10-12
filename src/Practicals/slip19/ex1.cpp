/*
Q1:  Write the C-Language program which Accept n values in array from user. 
Accept  a  value  x  from  user  and  use  sentinel  linear  search  algorithm  to  check 
whether  the  number  is  present  in  the  array  or  not  and  output  the  position  if 
the number is present.
*/
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define max 10

void generate(int a[],int n)
{
  int i;
  srand(time(NULL));
  for(i=0;i<n;i++){
    a[i]=rand()%10;
  }

}
void sentinelSearch(int a[],int n,int k)
{
   int i,temp,index ;
   temp=a[n-1];
   a[n-1]=k;

     i=0;
   while(a[i]!=k)
    i++;
   a[n-1]=temp;
   if(i<(n-1)||a[n-1]==k)
    printf("Searched found at index %d",i+1);
   else
    printf("Not Found");

}
int main()
{
   int a[max],k,i,n,flag=0,index;
     printf("Enter Size of array:");
     scanf("%d",&n);
     generate(a,n);
    printf("Random elements are\n");
    for(i=0;i<n;i++)
      printf("%d ",a[i]);

   printf("Enter number to search: ");
    scanf("%d",&k);
   sentinelSearch(a,n,k);
}
