/*
Q2. Implement a priority queue library (PriorityQ.h) of integers using a static 
implementation  of  the  queue  and  implementing  the  below  two  operations. 
Write  a  driver  program  that  includes  queue  library  and  calls  different  queue 
operations. 
1) Add an element with its priority into the queue. 
2) Delete an element from queue according to its priority.
*/

#include<stdio.h>
#include<stdlib.h>
#define N 10

typedef struct data
{
    int val;
    int prio;
}data;
typedef struct pqueue
{
   data q[N];
   int index;
}Pqueue;
void enqueue(Pqueue *pq,int val,int prio)
{
    if(pq->index==N-1){
        printf("Queue is Full\n");
    }
    else{
    pq->index++;
    pq->q[pq->index].val=val;
    pq->q[pq->index].prio=prio;
  }
}
int dequeue(Pqueue *pq)
{
    if(pq->index==-1){
        printf("Queue is Empty\n");
    }
    else{
        int maxPrio=-1;
        int in=-1;
      for(int i=0;i<=pq->index;i++)
      {
       if(maxPrio<pq->q[i].prio){
        maxPrio=pq->q[i].prio;
        in=i;
       }
      }
      int val=pq->q[in].val;
      for(int i=in;i<pq->index;i++)
      {
        pq->q[i]=pq->q[i+1];
      }
      pq->index--;
      return val;
    }
}
int main()
{
    Pqueue *pq=(Pqueue *)malloc(sizeof(Pqueue));
    pq->index=-1;

    enqueue(pq,1,4);
    enqueue(pq,2,5);
    enqueue(pq,4,1);
    printf("%d\n",dequeue(pq));
    printf("%d\n",dequeue(pq));
    printf("%d\n",dequeue(pq));
    return 0;

}