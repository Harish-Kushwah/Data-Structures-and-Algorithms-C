#include<stdio.h>

#define N 5
int dq[N];
int front =-1;
int rare=-1;

int isFull()
{
    if((front==0&&rare==N-1 )||front==rare+1)
    return 1;
    return 0;
}
void enqueueFront(int val)
{
    if((front==0 && rare==N-1)||front==rare+1)
    {
        printf("Queue is Full ");
    }
    else if(front==-1 &&rare==-1){
         front=rare=0;
         dq[front]=val;
    }
    else if(front==0)
    {
        front=N-1;
        dq[front]=val;
    }
    else{
        front--;
        dq[front]=val;
    }

}
void enqueueRare(int val)
{
    if((front==0&&rare==N-1)||front==rare+1)
    {
        printf("Queue is full");

    }
    else if(front==-1 && rare==-1){
        front=rare=0;
        dq[rare]=val;
    }
    else if (rare==N-1)
    {
        rare=0;
        dq[rare]=val;
    }
    else{
        rare++;
        dq[rare]=val;

    }
}
void display()
{
   /* for(int i=front;i!=rare;i++)
    {
        if(i==N){
            i=0;
        }
        printf("%d ",dq[i]);
    }*/
    
    int i=front;
    while(i!=rare)
    {
        printf("%d ",dq[i]);
        i=(i+1)%N;
        
    }
    printf("%d ",dq[i]);
}
void dqueueFront()
{
    if(front==-1&&rare==-1)
    {
        printf("Empyt");
    }
    else if(front==rare)
    {
        printf("%d ",dq[front]);
        front=rare=-1;
    }
    /*else if(front==N-1)
    {
        printf("%d ",dq[front]);
        front=0;
    }
    else{
        printf("%d",dq[front]);
        front++;
    }*/
    else{
       
        printf("%d",dq[front]);
         front=(front+1)%N;
    }
    printf("\n");
}
void dequeueRare()
{
    if(front==-1&&rare==-1)
    {
        printf("Empty");
    }
    else if(front==rare)
    {
        printf("%d",dq[rare]);
        front=rare=-1;
    }
   /* else if(rare==0)
    {
        printf("%d",dq[rare]);
        rare=N-1;
    }
    else{
        printf("%d",dq[rare]);
        rare--;
    }*/
    else{
       
        printf("%d",dq[rare]);
         rare=(rare-1)%N;
    }
    printf("\n");
}
int main()
{

    enqueueFront(2);
    enqueueFront(3);
    dqueueFront();
    enqueueRare(4);
    enqueueRare(5);
    dequeueRare();
     dequeueRare();
     enqueueFront(6);
   // enqueueRare(3);
   display();
    return 0;
}