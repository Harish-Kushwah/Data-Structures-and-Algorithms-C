#include<stdio.h>
#include "queue.h"

int main()
{
    Queue *qu = init();
    //add 4 element into queue
    enqueue(qu,1);
    enqueue(qu,2);
    enqueue(qu,3);
    enqueue(qu,4);

   //remove  element
    printf("\nDequeued element : ");
    printf("%d " , dequeue(qu));
    printf("%d " , dequeue(qu));
   
   //prints the size
    printf("\nSize of queue : %d\n" , size(qu));
    
    //check whether queue is empty or not
    if(isEmpty(qu)==1)
    {
    printf("Queue is Empty \n");
    }
    else{
    printf("Queue is not Empty \n");

    }

    printf("\nDequeued element : ");
    printf("%d " , dequeue(qu));
    printf("%d " , dequeue(qu));

}