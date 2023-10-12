#include<stdlib.h>
#include<stdio.h>
typedef struct Node
{
    struct Node* left;
    struct Node* right;
    int val;
}Node;

Node *createNode(int n)
{
    Node *head=NULL,*temp=NULL,*newnode=NULL;
    for(int i=0;i<n;i++){
       newnode=(Node*)malloc(sizeof(Node));
       newnode->left=NULL;
       newnode->right=NULL;
       newnode->val=0;
       if(head==NULL)
       {
        head=temp=newnode;
       }
       else{
          temp->right=newnode;
          newnode->left=temp;
          temp=newnode;
       }
    }
    return head;
}
Node* insertVal(Node *head)
{
    for(Node *temp=head;temp!=NULL;temp=temp->right)
    {
      printf("Enter val :");
      scanf("%d",&temp->val);  
    }
    return head;
}
void printList(Node *head)
{
    for(Node *temp=head;temp!=NULL;temp=temp->right)
    {
        printf("%d ",temp->val);
    }
}