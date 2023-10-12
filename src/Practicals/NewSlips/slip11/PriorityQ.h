#include<stdio.h>
#include<stdlib.h>
#define N 10
typedef struct data
{
    int prio;
    int val;
}data;

typedef struct pqueue
{
    data arr[N];
    int front;
    int rare;
}Pqueue;

Pqueue* init(Pqueue *pq)
{
    pq=(Pqueue*)malloc(sizeof(Pqueue));
    pq->front=-1;
    pq->rare=-1;
    return pq;
}
int size=0;
void enqueue(Pqueue *pq,int val,int prio)
{
    if(pq->front==0 &&pq->rare==N-1)
    {
        printf("Queue is Full");
    }
    else{
         if(pq->front==-1&&pq->rare==-1){
       pq->front=pq->rare=0;
       pq->arr[pq->rare].val=val;
       pq->arr[pq->rare].prio=prio;
      }
      else{
        pq->rare++;
        pq->arr[pq->rare].val=val;
        pq->arr[pq->rare].prio=prio;
      }
    size++;
    }
}
int dqueue(Pqueue *pq)
{
    int maxPrio=-1;
    int ind=-1;
    for(int i=0;i<=size;i++)
    {
        if(maxPrio<pq->arr[i].prio)
        {
            maxPrio=pq->arr[i].prio;
            ind=i;
        }
    }
    int val=pq->arr[ind].val;
    for(int i=ind;i<size;i++)
    {
        pq->arr[i]=pq->arr[i+1];
    }
    return val;
}