/*
Q2:  Write  the  C-Language  program  which  reads  n  name  from  user  and  sort 
using counting sort technique
*/

#include<stdio.h>
#include<string.h>
typedef struct Person
{
    char name[20];
}Person;

char hash1[27][20];
void countingSort(Person p1[],int n)
{
    for(int i=0;i<27;i++){
        hash1[i][1]='\0';
    }
   for(int i=0;i<n;i++){
    strcpy(hash1[p1[i].name[0]-96],p1[i].name);
   }
   
   int k=0;
   for(int i=0;i<27;i++){
    if(hash1[i][1]!='\0'){
     strcpy(p1[k].name,hash1[i]);
     k++;
    }
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
     countingSort(p1,n);
     printf("Names in sorted order :\n");
     for(int i=0;i<n;i++){
        printf("%s \n",p1[i].name);
     }
     

    return 0;
}