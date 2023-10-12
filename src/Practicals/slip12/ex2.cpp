/*
Q2: Write the C-Language program that sorts the elements of linked list using 
any of sorting technique.
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
        printf("Enter val :");
        scanf("%d",&newnode->val);
        newnode->next=NULL;
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
Node *bubbleSort(Node *head)
{
    for(Node *temp=head;temp!=NULL;temp=temp->next)
    {
        for(Node *temp1=temp;temp1!=NULL;temp1=temp1->next)
        {
            if(temp1->val<temp->val)
            {
                int val=temp1->val;
                temp1->val=temp->val;
                temp->val=val;
            }
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
int main()
{
    int n;
    printf("Enter size of List: ");
    scanf("%d",&n);
    Node *head=createNode(n);
    printList(head);
    head=bubbleSort(head);
    printList(head);
}