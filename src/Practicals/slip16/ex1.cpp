 /*
 Q1:  Write the C-Language program which accept n names of cities and a city 
name from user and use sentinel linear search algorithm to check whether the 
name is present or not.
 */
#include<stdio.h>
#include<string.h>
typedef struct Person
{
    char name[20];
}Person;

void sentialSearch(Person p1[],int n)
{
    char target[20];
    printf("Enter Name to search :");
    scanf("%s",target);
    strcpy(target,strupr(target));

    char last[20];
    strcpy(last,p1[n-1].name);
    strcpy(p1[n-1].name,target);
    int i=0;
    while(strcmp(p1[i].name,target)!=0)
    i++;

    strcpy(p1[n-1].name,last);
    if((i<n-1)||(strcmp(p1[n-1].name,target)==0))
   printf("Name is found:");
    else
    printf("Name is not found ");

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
        strcpy(p1[i].name,strupr(p1[i].name));
     }
     sentialSearch(p1,n);
}
