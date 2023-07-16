#include<stdlib.h>

typedef struct Queue
{
    int arr[20];
    int front,rare;
}Queue;

Queue *init()
{
    Queue *qu=(Queue *)malloc(sizeof(Queue));
    qu->front=qu->rare=1;
    return qu;
}
void add(Queue *qu,int n1)
{
    qu->arr[++qu->rare]=n1;
}
int remove_ele(Queue *qu)
{
    return qu->arr[++qu->front];
}
int isEmpty(Queue *qu)
{
    return qu->front==qu->rare;
}
