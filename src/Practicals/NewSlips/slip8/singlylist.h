#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int val;
    struct Node *next;
}Node;

Node *createNode(int n)
{
    Node *head=NULL,*temp=NULL,*newnode=NULL;
    for(int i=0;i<n;i++)
    {
        newnode=(Node *)malloc(sizeof(Node));
        printf("Enter value :");
        scanf("%d",&newnode->val);
        newnode->next=NULL;
        if(head==NULL)
        {
            head=temp=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
    }
    return head;
}
void display(Node *head)
{
    for(Node *temp=head;temp!=NULL;temp=temp->next)
    {
        printf("%d ",temp->val);
    }
    printf("\n");
}
Node *delateByVal(Node *head,int val)
{
    if(val==head->val)
    {
            Node *t=head;
            head=head->next;
            free(t);
  }
  else{
       Node *p1=head;
    for(Node *temp=head;temp!=NULL;temp=temp->next)
    {
        
        if(val==temp->val)
        {
            Node *t=temp;
            p1->next=temp->next;
            temp=temp->next;
            free(t);
        }
        else{
            p1=temp;
        }
    }
    }

return head;
}