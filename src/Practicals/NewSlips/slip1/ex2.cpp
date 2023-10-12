/*
Q2. Write a program that sorts the elements of linked list using any of sorting   
technique.
*/
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
      newnode->next=NULL;
      printf("Enter a val :");
      scanf("%d",&newnode->val);
      
      if(head==NULL)
      {
        head=temp=newnode;
      }
      else{
        temp->next=newnode;
        temp=newnode;
      }
    }
    return head;
}
void printList(Node *head)
{
    for(Node *temp=head;temp!=NULL;temp=temp->next)
    {
        printf("%d ",temp->val);
    }
    printf("\n");
}
void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
Node* bubbleSort(Node *head)
{
    for(Node *temp=head;temp!=NULL;temp=temp->next)
    {
        for(Node *temp1=temp;temp1!=NULL;temp1=temp1->next)
        {
            if(temp->val<temp1->val)
            {
                swap(&temp->val,&temp1->val);
            }
        }
    }
    return head;
}
int main()
{
    int n;
    printf("Enter how many nodes wants to create :");
    scanf("%d",&n);
    Node *head=createNode(n);
    printList(head);
    head=bubbleSort(head);
    printList(head);

}