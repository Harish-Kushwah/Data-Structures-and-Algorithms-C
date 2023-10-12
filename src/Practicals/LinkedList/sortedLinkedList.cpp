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
        scanf("%d,",&newnode->val);
        newnode->next=NULL;
        int key=newnode->val;

        if(head==NULL||key<head->val)
        {
            newnode->next=head;
            head=newnode;
        }
        else{
           temp=head;
           while(temp->next!=NULL&&temp->next->val<key)
             temp=temp->next;

             newnode->next=temp->next;
             temp->next=newnode;

        }
    }
    return head;
}



Node *createNode1(int n)
{
    Node *head=NULL,*newnode=NULL,*temp=NULL;
    for(int i=0;i<n;i++)
    {
        newnode=(Node *)malloc(sizeof(Node));
        printf("Enter value :");
        scanf("%d",&newnode->val);
        newnode->next=NULL;
        int key=newnode->val;

        if(head==NULL||key<head->val)
        {
            newnode->next=head;
            head=newnode;
        }
        else{
            temp=head;
            while(temp->next!=NULL&&temp->next->val<key)
            temp=temp->next;

            newnode->next=temp->next;
            temp->next=newnode;
        }
    }
    return head;
}
Node *createNode2(int n)
{
    Node *head=NULL,*newnode=NULL,*temp=NULL;
    for(int i=0;i<n;i++)
    {
        newnode=(Node *)malloc(sizeof(Node));
        printf("Enter value :");
        scanf("%d",&newnode->val);
        newnode->next=NULL;
        int key=newnode->val;

        if(head==NULL||key<head->val)
        {
            newnode->next=head;  //insert node at head
            head=newnode;
        }
        else{
            //find the right position 
            temp=head;
            while(temp->next!=NULL&&temp->next->val<key)
            temp=temp->next;

            newnode->next=temp->next;
            temp->next=newnode;
        }
    }
    return head;
}
void printfList(Node *head)
{
    for(Node *temp=head;temp!=NULL;temp=temp->next)
    {
        printf("%d ",temp->val);
    }

}
int main()
{
    Node *head=createNode2(5);
    printfList(head);
    return 0;
}