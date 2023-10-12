/*
Q2 :Write  the  C-Language  program  which  reads  n  name  from  user  and  sort 
using quick sort techniquc
*/
#include<stdio.h>
#include<string.h>
typedef struct Person
{
    char name[20];
}Person;

void swap(Person *x,Person *y)
{
    Person temp=*x;
    *x=*y;
    *y=temp;
}
int partion(Person p1[],int low,int upp)
{
   char pi[20];
   strcpy(pi,p1[low].name); 
   int start=low;
   int end=upp;
   while(start<end)
   {
      while((strcmp(p1[start].name,pi)==0)||(strcmp(p1[start].name,pi))<0){
        start++;
      }
      
      while(strcmp(p1[end].name,pi)>0){
        end--;
      }
      if(start<end){
        swap(&p1[start],&p1[end]);
      }
   }
   swap(&p1[low],&p1[end]);
   return end;
}
void quick(Person p1[],int low,int upp)
{
    if(low<upp)
    {
        int pi=partion(p1,low,upp);
        quick(p1,low,pi-1);
        quick(p1,pi+1,upp);
    }
}

int main()
{
   int n;
     printf("\nEnter n :");
     scanf("%d",&n);
     Person p1[n];
    
     for(int i=0;i<n;i++){
        printf("Enter name :");
        scanf("%s",p1[i].name);
        strcpy(p1[i].name,strlwr(p1[i].name));
     }
     quick(p1,0,n-1);
     printf("Names in sorted order :\n");
     for(int i=0;i<n;i++){
        printf("%s \n",p1[i].name);
     }
}