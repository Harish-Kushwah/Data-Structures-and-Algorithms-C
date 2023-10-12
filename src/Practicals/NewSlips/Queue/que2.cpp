#include<stdio.h>
#define N 10
int queue[N];
int front=-1;
int rare=-1;
void enqueue(int val)
{
    if(rare==N-1)
    {
        printf("Overflow");
    }
    else if(front==-1&&rare==-1)
    {
      front=rare=0;
      queue[rare]=val;    
    }
    else{
        queue[++rare]=val;
    }
}
void dequeue()
{
   if(front==rare==-1)
   {
    printf("Underflow");
   }
   else if(front==rare)
   {
    front=rare=-1;
   }
   else{
    printf("%d\n",queue[front++]);
   }
}
void display()
{
    if(front==-1 &&rare==-1)
    {
        printf("UnderFlow");
    }
    else{
        for(int i=front;i<=rare;i++)
        {
            printf("%d ",queue[i]);
        }
    }
    printf("\n");
}
void peek()
{
    if(front==-1&&rare==-1)
    printf("underflow");
    else
    printf("%d\n",queue[front]);
}
int main()
{
   enqueue(1);
   enqueue(2);
   peek();
   display();
   dequeue();
  // dequeue();
   display();
}

