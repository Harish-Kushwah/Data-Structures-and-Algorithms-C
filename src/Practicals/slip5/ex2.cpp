/*
q2: Write  the  C-Language  program  which  reads  n  name  from  user  and  sort 
using merge sort technique 
*/
#include<stdio.h>
#include<string.h>
typedef struct Person
{
    char name[20];
}Person;

void merge(Person p1[],int low,int mid,int upp)
{
    int i,j,k;
    i=low;
    j=mid+1;
    k=low;
    Person b1[low+upp];
    while(i<=mid&&j<=upp){
        if(strcmp(p1[i].name,p1[j].name)==-1||(strcmp(p1[i].name,p1[j].name))==0){
            strcpy(b1[k].name,p1[i].name);
            i++;
        }
        else
        {
           strcpy(b1[k].name,p1[j].name);
            j++;
        }
        k++;
    }

    if(i>mid)
    {
        while(j<=upp){
            strcpy(b1[k].name,p1[j].name);
            j++;
            k++;
        }
    }
    else{
        while(i<=mid)
        {
            strcpy(b1[k].name,p1[i].name);
            i++;
            k++;
        }
    }
    for(k=low;k<=upp;k++){
        strcpy(p1[k].name,b1[k].name);
    }
}
void mergeSort(Person p1[],int low,int upp)
{
    if(low<upp)
    {
        int mid=(low+upp)/2;
        mergeSort(p1,low,mid);
        mergeSort(p1,mid+1,upp);
        merge(p1,low,mid,upp);
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
     mergeSort(p1,0,n-1);
     printf("Names in sorted order :\n");
     for(int i=0;i<n;i++){
        printf("%s \n",p1[i].name);
     }
}