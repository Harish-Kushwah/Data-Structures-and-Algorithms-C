/*
Q1. Read the data from file 'cities.txt' containing names of cities and their STD 
codes.  Accept  a  name  of  the  city  from  user  and  use  sentinel  linear  search 
algorithm to check whether the name is present in the file and output the STD 
code, otherwise output “city not in the list”
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Cities
{
    int STD;
    char Name[20];
}Cities;

int readFile(Cities city[])
{
    FILE *fp=fopen("cities.txt","r");
    if(fp==NULL)
    {
        printf("Unable to open file\n");
        exit(0);
    }
    int i=0;
    while(!feof(fp))
    {
        fscanf(fp,"%d%s",&city[i].STD,city[i].Name);
        strupr(city[i].Name);
        i++;
    }
    return i;
}
int sentinelSearch(Cities city[],char target[],int n)
{
    char last[20];
    strcpy(last,city[n-1].Name);
    strcpy(city[n-1].Name,target);
    int i=0;
    while(strcmp(city[i].Name,target)!=0){
        i++;
    }
    strcpy(city[n-1].Name,last);
    if(i<n-1||strcmp(city[n-1].Name,target)==0)
    {
        if(i<n-1)
        return i;
        return n-1;
    }
    else{
        return -1;
    }
}
int binSearch(Cities city[],char target[],int n)
{
    int low=0;
    int upp=n-1;
    while(low<=upp)
    {
        int mid=(upp+low)/2;
        int cmp=strcmp(target,city[mid].Name);
        if(cmp==0)
        {
            return mid;
        }
        else if(cmp>0)
        {
            low=mid+1;
        }
        else{
            upp=mid;
        }
    }
    return -1;
}
int main()
{
    Cities city[10];
    int n=readFile(city);
    char target[20];
    printf("Enter target :");
    scanf("%s",target);
    strupr(target);
    int i=binSearch(city,target,n);
    if(i==-1){
        printf("City is Not present\n");
    }
    else{
        printf("%d is STD code of city %s\n",city[i].STD,city[i].Name);
    }
}