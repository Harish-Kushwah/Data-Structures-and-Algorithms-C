#include<stdio.h>
#include<stdlib.h>

#define CAPACITY 20

typedef struct Queue
{
    int item[CAPACITY];
    int front;
    int rare;
}Queue;


/*
`enqueue(item)`: Adds an item to the rear of the queue.
- `dequeue()`: Removes and returns the item from the front of the queue.
- `peek()`: Returns the item at the front of the queue without removing it.
- `isEmpty()`: Checks if the queue is empty.
- `size()`: Returns the number of elements in the queue.
*/

Queue *init()
{
   Queue *qu = (Queue *)malloc(sizeof(Queue));
   qu->front = -1;
   qu->rare = -1;
   return qu;
}

//add element into queue
void enqueue(Queue *qu , int val)
{
    qu->item[++qu->rare]=val;
}

//remove element from the queue
int dequeue(Queue *qu)
{
    return qu->item[++qu->front];
}

//check whether queue is empty or not
int isEmpty(Queue *qu)
{
    return qu->front == qu->rare;
}

//return the first element from the queue
int peek(Queue *qu)
{
    if(!isEmpty(qu))
    return qu->item[qu->front];
}

//return the size of queue
int size(Queue *qu)
{
    if(qu->rare==-1)
    return 0;
    return qu->rare + 1; 
}