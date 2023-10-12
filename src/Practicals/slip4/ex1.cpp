/*
Q1:  Write the C-Language program which accept n names of cities and a city 
name from user and use linear search algorithm to check whether the name is 
present or not.
*/

#include<stdio.h>
#include<string.h>
typedef struct Person
{
    char name[20];
}Person;

void linearSearch(Person p1[],int n)
{
    char target[20];
    printf("Enter Name to search :");
    scanf("%s",target);
    strcpy(target,strupr(target));

  int flag=0;
    for(int i=0;i<n;i++){
        if(strcmp(p1[i].name,target)==0){
           printf("Name is found:");
           flag=1;
           break;
        }
    }
    if(flag==0)
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
     linearSearch(p1,n);
}
