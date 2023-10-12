#include<stdio.h>
#define N 5
int queue[N];
int front=-1;
int rare=-1;

void enqueue(int val)
{
    if((rare+1)%N==front){
        printf("OverFlow");
    }
    else
    if(front==-1&&rare==-1)
    {
        front=rare=0;
        queue[rare]=val;
    }
    else 
    {
        
      rare=(rare+1)%N;
      queue[rare]=val;
    }
}
int dequeue()
{
    if(front==-1&&rare==-1)
    {
        printf("Underflow");
    }
    else if(front==rare){
      front=rare=-1;
    }
    else{
        
      int val= queue[front];
      front=(front+1)%N;
      return val;
    }
}
void display()
{
    for(int i=front;i!=(rare+1)%N;i++)
    {
        printf("%d ",queue[i]);
    }
    printf("\n");
}
int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
   /* printf("%d\n",dequeue());
    printf("%d\n",dequeue());
    enqueue(5);
    enqueue(6);
    printf("%d\n",dequeue());
    enqueue(7);
    enqueue(8);*/
    display();
    printf("%d\n",dequeue());
 display();
}