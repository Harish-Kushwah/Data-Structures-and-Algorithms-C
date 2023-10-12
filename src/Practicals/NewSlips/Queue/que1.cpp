#include<stdio.h>
#include<stdlib.h>
#define N 3
typedef struct Queue
{
    int front;
    int rare;
    int arr[N];
}Queue;
Queue* init()
{
    Queue *q=(Queue *)malloc(sizeof(Queue));
    q->front=-1;
    q->rare=-1;
    return q;
}
int isEmpty(Queue *q)
{
    return q->front==q->rare;
}
void enQueue(Queue *q,int val)
{
    if(q->rare==N-1){
        printf("Queue is Full");
        
    }
    else
     q->arr[++q->rare]=val;   
}
int deQueue(Queue *q)
{
    if(!isEmpty(q)){
    return q->arr[++q->front];
    }
    else{
        printf("QUeue is Empty:");
        return -1;
    }
}
int main()
{
   Queue *q=init();
   enQueue(q,1);
   enQueue(q,3);
   enQueue(q,4);
    
   printf("%d\n",deQueue(q));
   printf("%d\n",deQueue(q));
   printf("%d\n",deQueue(q));
    return 0;
}