/*
Q2.  Read  the  data  from  the  file  “employee.txt”  and  sort  on  names  in 
alphabetical order (use strcmp) using bubble sort and selection sort
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Employee
{
    int emp_Id;
    char emp_Name[20];
}Employee;

int readFile(Employee emp[])
{
    FILE *fp=fopen("employee.txt","r");
    if(fp==NULL)
    {
        printf("Unable To open File\n");
        exit(0);
    }
    
    int i=0;
    while(!feof(fp))
    {
      fscanf(fp,"%d%s",&emp[i].emp_Id,emp[i].emp_Name);
      strupr(emp[i].emp_Name);
      i++;
    }
    return i;
}
void swap(Employee *emp,Employee*emp2)
{
    Employee ep=*emp;
    *emp=*emp2;
    *emp2=ep;
}
void bubbleSort(Employee emp[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-(i+1);j++)
        {
            int cmp=strcmp(emp[j].emp_Name,emp[j+1].emp_Name);
            if(cmp>0)
            {
                 swap(&emp[j],&emp[j+1]);
            }
        }
    }
}

void selectionSort(Employee emp[],int n)
{
    for(int i=0;i<n;i++)
    {
        Employee minEmp=emp[i];
        int index=i;
        for(int j=i;j<n;j++)
        {
           int cmp=strcmp(minEmp.emp_Name,emp[j].emp_Name);
           if(cmp>0)
           {
             minEmp=emp[j];
             index=j;
           }
        }
        swap(&emp[i],&emp[index]);
        
    }
}
void printData(Employee emp[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d %s\n",emp[i].emp_Id,emp[i].emp_Name);
    }
}
int main()
{
    Employee emp[10];
    int n=readFile(emp);
    selectionSort(emp,n);
    printData(emp,n);
}
