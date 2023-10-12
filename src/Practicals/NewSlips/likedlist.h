#include<stdio.h>
#include<stdlib.h>
struct Node
{
  int val;
  struct Node *next;
};
struct Node* createNode(int n)
{
  struct Node *head=NULL;
  struct Node *newnode=NULL;
  struct Node *temp=NULL;
  
  for(int i=0;i<n;i++){
    newnode=(struct Node *)malloc(sizeof(struct Node ));
    printf("Enter value :");
    scanf("%d",&newnode->val);
    newnode->next=NULL;

    if(head==NULL)
    {
      head=newnode;
      temp=newnode;
    }
    else{
      temp->next=newnode;
      temp=newnode;
    }
  }
  return head;
}
struct Node* insertAtPos(struct Node *head,int pos)
{
    int i=0;
    struct Node *p1=head;
    struct Node *ball=createNode(1);
    for(struct Node *temp=head;temp!=NULL;temp=temp->next)
    {
        if(i==pos)
        {
           p1->next=ball;
           ball->next=temp;
        }
        else{
            p1=temp;
        }
        i++;

    }
    return head;
}
void printList(struct Node *head)
{
  struct Node *temp=head;
  while(temp!=NULL)
  {
    printf("%d ",temp->val);
    temp=temp->next;
  }
}