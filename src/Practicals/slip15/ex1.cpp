/*
Q1:  Write the C-Language program which accept n names of cities and a city 
name  from user  and  use  binary  search algorithm  to  check  whether  the  name 
is present or not.
*/

#include<stdio.h>
#include<string.h>

typedef struct Person
{
    char Name[20];
}Person;
int binSearch(Person p1[],char target[],int n)
{
    int low=0;
    int upp=n-1;
    while(low<upp)
    {
        int mid=(low+upp)/2;
        int cmp=strcmp(p1[mid].Name,target);
        if(cmp==0){
        return 1;
        }
        else if(cmp<0)
        {
           low=mid+1;
        }
        else{
            upp=mid-1;
        }
    }
    return 0;
}
int main()
{
    int n;
    printf("Enter N:");
    scanf("%d",&n);
    Person p1[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter a Name :");
        scanf("%s",p1[i].Name);
        strcpy(p1[i].Name,strupr(p1[i].Name));
    }
    char target[20];
    printf("Enter target :");
    scanf("%s",target);
    strcpy(target,strupr(target));
    int found=binSearch(p1,target,n);
    printf("%d",found);
   
}