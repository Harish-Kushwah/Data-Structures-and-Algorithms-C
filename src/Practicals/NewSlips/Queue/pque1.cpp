#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int val;
    struct Node *next;
}Node;
 Node *front=NULL;
Node* insert(Node *head,int val)
{
    Node *newnode=(Node *)malloc(sizeof(Node));
    newnode->val=val;
    newnode->next=NULL;
    int key=val;
    if(head==NULL||key>head->val)
    {
        newnode->next=head;
        head=newnode;
    }
    else{
        Node *temp=head;
        while(temp->next!=NULL &&temp->next->val>key)
            temp=temp->next;

        newnode->next=temp->next;
        temp->next=newnode;
    }
    return head;
}
void push(int val)
{
   /* Node *head=NULL;
    for(int i=0;i<n;i++)
    {
       int val;
       printf("Enter val :");
       scanf("%d",&val);
       head=insert(head,val);
    }
    return head;*/
    front=insert(front,val);
}
int pop()
{
    Node *temp=front;
    int val=front->val;
    front=front->next;
    free(temp);
    return val;
}
void printList(Node *head)
{
    for(Node *temp=head;temp!=NULL;temp=temp->next)
    {
        printf("%d ",temp->val);
    }
    printf("\n");
}
int main()
{
   
    push(1);
    push(10);
    push(9);
    push(2);
    printf("%d\n",pop());
    printf("%d\n",pop());
    printf("%d\n",pop());
  
    return 0;
}