/*
Q2.Read  the  data  from  the  file  and  sort  on  names  in  alphabetical  order  (use 
strcmp)  using Counting  sort,  Merge  sort  and  write the sorted data to  another 
file 'sortedemponname.txt'    

*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Employee
{
    int Id;
    char Name[20];
}Employee;

int readFile(Employee emp[])
{
    FILE *fp=fopen("employee.txt","r");
    if(fp==NULL)
    {
        printf("Unable to open file\n");
        exit(0);
    }
    int i=0;
    while(!feof(fp))
    {
        fscanf(fp,"%d%s",&emp[i].Id,emp[i].Name);
        i++;
    }
    return i;
}
void writeFile(Employee emp[],int n)
{
    FILE *fp=fopen("sortedEmp.txt","w");
    if(fp==NULL)
    {
        printf("Unable to open file\n");
    }
    for(int i=0;i<n;i++)
    {
        fprintf(fp,"%d\t%s\n",emp[i].Id,emp[i].Name);
    }
}
void merge(Employee emp[],int low,int mid,int upp)
{
    int i=low;
    int j=mid+1;
    int k=low;
    Employee b[low+upp];
    while(i<=mid&&j<=upp)
    {
        int cmp=strcmp(emp[i].Name,emp[j].Name);
        int cmp1=strcmp(emp[j].Name,emp[i].Name);
        if(cmp==0||cmp<0)
        {
            b[k]=emp[i];
            i++;
            k++;
        }
        if(cmp1==0||cmp1<0)
        {
            b[k]=emp[j];
            k++;
            j++;
        }
    }
    if(i>mid)
    {
        while(j<=upp)
        {
            b[k]=emp[j];
            k++;
            j++;
        }
    }
    else{
        while(i<=mid)
        {
            b[k]=emp[i];
            i++;
            k++;
        }
    }
    for(k=low;k<=upp;k++)
    {
        emp[k]=b[k];
    }
}
void mergeSort(Employee emp[],int low,int upp)
{
    if(low<upp)
    {
        int mid=(low+upp)/2;
        mergeSort(emp,low,mid);
        mergeSort(emp,mid+1,upp);
        merge(emp,low,mid,upp);
    }
}
int main()
{
    Employee emp[10];
   int n=readFile(emp);
    mergeSort(emp,0,n-1);
    writeFile(emp,n);
}