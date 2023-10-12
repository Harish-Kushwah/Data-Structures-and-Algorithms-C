/*
Q2.  Write  a  program  that  sorts  the  elements  of  linked  list  using  bubble  sort 
technique
*/
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

Node* bubbleSort(Node *head)
{
    for(Node *temp=head;temp!=NULL;temp=temp->next)
    {
        for(Node *temp1=temp;temp1->next!=NULL;temp1=temp1->next)
        {
            if(temp1->val<temp1->next->val)
            {
              int val=temp1->val;
              temp1->val=temp1->next->val;
              temp1->next->val=val;
            }
        }
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
  printf("\n");
}

int  main()
{
  Node *head=createNode(5);
  printList(head);
  bubbleSort(head);
  printList(head);
        
}