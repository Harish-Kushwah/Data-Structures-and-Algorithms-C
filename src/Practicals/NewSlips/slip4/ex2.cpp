/*
Q2. Write a program to reverse the elements of a queue using queue library.        
Implement basic queue operations init, enqueue, dequeue.
*/
#include<stdio.h>
#include<stdlib.h>

#define N 10
typedef struct Queue
{
    int front;
    int rare;
    int arr[N];
}Queue;
Queue* init()
{
    Queue *q=(Queue*)malloc(sizeof(Queue));
    q->front=-1;
    q->rare=-1;
    return q;
}
int isFull(Queue *q)
{
    return q->rare==N-1;
}
int isEmpty(Queue *q){
    return q->front==q->rare;
}
void enQueue(Queue *q,int val)
{
    if(!isFull(q)){
        q->arr[++q->rare]=val;
    }
    else{
        printf("Queue is Full :");
    }
}

typedef struct Stack
{
    int arr[N];
    int top;
}Stack;
Stack *init1()
{
    Stack *st=(Stack *)malloc(sizeof(Stack));
    st->top=-1;
    return st;
}
void push(Stack *st,int val)
{
    if(st->top!=N-1)
    st->arr[++st->top]=val;
}
int pop(Stack *st)
{
    if(st->top!=-1)
    return st->arr[st->top--];
    return -1;
}

int deQueue(Queue *q)
{
    if(!isEmpty(q)){
        return q->arr[++q->front];
    }
    else{
        printf("Queue is Empty");
        return -1;
    }
}
int main()
{
    Queue *q1=init();
    printf("Enter element in the Queue :\n");
    int n;
    printf("Enter N:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x;
        printf("Enter element no %d :",i+1);
        scanf("%d",&x);
        enQueue(q1,x);
    }
    Stack *s2=init1();
    
    for(int i=0;i<n;i++){
        push(s2,deQueue(q1));
    }
    for(int i=0;i<n;i++){
        enQueue(q1,pop(s2));
    }   
    for(int i=0;i<n;i++){
        printf("%d \n",deQueue(q1));
    }
    return 0;
}
