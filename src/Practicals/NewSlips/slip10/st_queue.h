#include<stdio.h>
#include<stdlib.h>
#define N 20
typedef struct Queue
{
    int arr[N];
    int front;
    int rare;
}Queue;

Queue* init(Queue *qu)
{
    qu=(Queue*)malloc(sizeof(Queue));
    qu->front=-1;
    qu->rare=-1;
    return qu;
}
void add(Queue *qu,int val)
{
    if(qu->rare==N-1)
    {
        printf("Queue is Full");
    }
    else
    if(qu->front==-1&&qu->rare==-1)
    {
        qu->front=qu->rare=0;
        qu->arr[qu->rare]=val;
    }
    else{
        qu->arr[++qu->rare]=val;
    }
}
int peek(Queue *qu)
{
    if(qu->front==-1&&qu->rare==-1)
    {
        printf("Queue is Empty\n");
    }
    else{
        return qu->arr[qu->front];
    }
}

