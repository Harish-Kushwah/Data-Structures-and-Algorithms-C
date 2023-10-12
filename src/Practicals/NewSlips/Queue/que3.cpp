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
    newnode->next=NULL;
    if(front==NULL&&rare==NULL)
    {   
      front=rare=newnode;
    }
    else{
        rare->next=newnode;
        rare=newnode;
    }
}
int dequeue()
{
    if(front!=NULL)
    {
        Node *temp=front;
        front=front->next;
        int val=temp->val;
        free(temp);
        return val;
    }
    else
    return -1;
}
int peek()
{
    if(front!=NULL)
    return front->val;
    else
    return -1;
}
void display()
{
    for(Node *temp=front;temp!=NULL;temp=temp->next)
    {
        printf("%d ",temp->val);
    }
    printf("\n");
}
int main()
{
    enqueue(1);
    enqueue(3);
    enqueue(7);
    //printf("%d\n",dequeue());
    printf("%d\n",peek());
    display();
    enqueue(9);
    printf("%d\n",dequeue());
    display();
    //printf("%d\n",dequeue());
    //printf("%d\n",dequeue());
}