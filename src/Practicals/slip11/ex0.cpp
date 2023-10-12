#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int val;
    struct Node *next;
}Node;

Node *createNode(int n)
{
    Node *newnode=NULL,*head=NULL,*temp=NULL;
    
    for(int i=0;i<n;i++)
    {
        newnode=(Node *)malloc(sizeof(Node));
        printf("Enter a value :");
        scanf("%d",&newnode->val);
        newnode->next=NULL;
        if(head==NULL)
        {
            head=temp=newnode;
        }
        else
        {
         
         Node *temp1,*p1=head;
         int flag=0;
         int ct=0;
          for(temp1=head; temp1!=NULL; temp1=temp1->next){
           if(newnode->val>temp1->val&&temp->next==NULL)
           {
             newnode->next=temp1;
             head=newnode;
             break;
           } 
           else{
            if(newnode->val<temp1->next)
            temp1->next=newnode;
            temp1=newnode;
           
           ct++;
           }
           }
          /* if(p1->next==NULL)
           {
            p1->next=newnode;
           }*/
           //free(temp1);

        }

    }
    return head;
   
}
/*
Node *createSortedNodes(Node *head)
{

    
    return head;
}*/
void printList(Node *head)
{
    for(Node *temp=head;temp!=NULL;temp=temp->next)
    {
     printf("%d ",temp->val);
    }
    
}
int main()
{
    int n;
    printf("Enter n :");
    scanf("%d",&n);
    
    Node *head=createNode(n);

    printList(head);

    return 0;
}