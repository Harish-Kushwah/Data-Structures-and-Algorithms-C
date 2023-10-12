#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int val;
    struct Node *next;
}Node;

Node *front=NULL;
Node *rare=NULL;

void enqueue(int val)
{
    Node *newnode=(Node *)malloc(sizeof(Node));
    newnode->val=val;
    newnode->next=front;
    if(front==NULL&&rare==NULL)
    {
        front=rare=newnode;
    }
    else{
        rare->next=newnode;
        rare=newnode;
    }
}
void dequeue()
{
    Node *temp=front;
    if(front==NULL&&rare==NULL)
    {
        printf("Empty Queue");
    }
    else if(front==rare){  //if only one node is present
         front=rare=NULL;
         free(temp);
    }
    else{
        front=front->next;
        rare->next=front;
        free(temp);
    }
}