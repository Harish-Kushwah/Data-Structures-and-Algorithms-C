/*
Q2. Implement a priority queue library (PriorityQ.h) of integers using a static 
implementation  of  the  queue  and  implementing  the  below  two  operations. 
Write  a  driver  program  that  includes  queue  library  and  calls  different  queue 
operations.
 1) Add an element with its priority into the queue.    
 2) Delete an element from queue according to its priority.
*/
#include "PriorityQ.h"
int main()
{
   Pqueue *pq=init(pq);
   enqueue(pq,1,2);
   enqueue(pq,2,4);
   enqueue(pq,4,1);
   printf("%d\n",dqueue(pq));
   printf("%d\n",dqueue(pq));
   printf("%d\n",dqueue(pq));


}