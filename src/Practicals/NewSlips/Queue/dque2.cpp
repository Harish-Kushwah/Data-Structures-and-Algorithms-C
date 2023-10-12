#include<stdio.h>
#define N 10
int dqueue[N];
int front=-1;
int rare=-1;
/*
in enFront() --> front--
in enRare()  --> rare++;
in deFront() --> front=(front+1)%N  --> because of circular queue
in deRare()  --> rare=(rare-1)%N    --> because of circular queue
*/
void enFront(int val)
{
   //check for full condition
   if((front==0&&rare==N-1)||(front==rare+1)){
    printf("queue if full");
   }
   else if(front==-1&&rare==-1)
   {
    front=rare=0;
    dqueue[front]=val;
   }
   else if(front==0)
   {
    front=N-1;
    dqueue[front]=val;
   }
   else{
        front--;
        dqueue[front]=val;
   }
}
void enRare(int val)
{
    if((front==0&&rare==N-1)||(front==rare+1))
    {
        printf("Queue if Full");
    }
    else if(front==-1&&rare==-1)
    {
        front=rare=0;
        dqueue[rare]=val;
    }
    else if(rare==N-1)
    {
        rare=0;
        dqueue[rare]=val;
    }
    else{
        rare++;
        dqueue[rare]=val;
    }
}
void deleteFront()
{
    if(front==-1&&rare==-1)
    {
        printf("Queue is Empty");
    }
    else if(front==rare)
    {
        printf("%d\n",dqueue[front]);
        front=rare=-1;
    }
    else {
        printf("%d\n",dqueue[front]);
        front=(front+1);
    }
}
void deleteRare()
{
    if(front==-1&&rare==-1)
    {
        printf("Queue is Empty");
    }
    else if(front==rare)
    {
        printf("%d\n",dqueue[rare]);
    }
    else{
        printf("%d\n",dqueue[rare]);
        rare=(rare-1)%N;
    }
}
void display()
{
    int i=front;
    while(i!=rare)
    {
        printf("%d ",dqueue[i]);
        i=(i+1)%N;
    }
    printf("%d ",dqueue[i]);
    printf("\n");
}
int main()
{
    enFront(1);
    enFront(2);
    display();
    enRare(4);
    enFront(9);
    display();
    deleteFront();
    display();
    enRare(7);
    display();
    deleteRare();
    display();
    enRare(8);
    enFront(5);
    display();
    return 0;
}