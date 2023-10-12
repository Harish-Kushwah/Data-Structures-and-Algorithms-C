/*
Q1. Read the data from file 'cities.txt' containing names of cities and their STD
codes. Accept a name of the city from user and use sentinel linear search
algorithm to check whether the name is present in the file and output the STD
code, otherwise output “city not in the list”.
*/
#include<stdio.h>
#include<string.h>
typedef struct City
{
    int STD;
    char Name[20];
}City;
void sentiSearch(City c[], char uname[],int n)
{
   char last[20];
   strcpy(last,c[n-1].Name);

   strcpy(c[n-1].Name,uname);
   int i=0;
   while(strcmp(uname,c[i].Name)!=0){
    i++;
   }
   strcpy(c[n-1].Name,last);
    if(i<n-1||strcmp(last,uname)==0){
        printf("Name if found\n");
       printf("%d %s :",c[i].STD,c[i].Name);
    }
    else{
        printf("City Name is Not Found");
   }

}
void bubbleSort(City c[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<(n-(i+1));j++)
        {
            int cmp=strcmp(c[j].Name,c[j+1].Name);
            if(cmp>0)
            {
                City C=c[j];
                c[j]=c[j+1];
                c[j+1]=C;
            }
        }
    }
}
int main()
{
   FILE *fp=fopen("cities.txt","r");
   City c[10];
   int i=0;
   while(!feof(fp)){
   fscanf(fp,"%d%s",&c[i].STD,c[i].Name);
   strupr(c[i].Name);
   i++;
   }
   /*char uname[20];
   printf("Enter Name of City :");
   scanf("%s",uname);
   strupr(uname);*/
  // sentiSearch(c,uname,i);
  bubbleSort(c,i);
  for(int j=0;j<i;j++)
  {
    printf("%d %s\n",c[j].STD,c[j].Name);
  }
   return 0;

}
