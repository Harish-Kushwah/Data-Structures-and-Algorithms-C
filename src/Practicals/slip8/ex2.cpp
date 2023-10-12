/*
Write the C-Language program to Create a linked list of integers, reverse it 
and display reversed linked list.
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
    Node *temp=NULL,*newnode=NULL,*head=NULL;
    for(int i=0;i<n;i++){
    newnode=(Node *)malloc(sizeof(Node));
    newnode->val=0;
    newnode->next=NULL;
    if(newnode==NULL){
        printf("ERROR:no memory available \n");
        exit(0);
    }
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
Node *insertVal(Node *head)
{
    int i=1;
    for(Node *temp=head;temp!=NULL;temp=temp->next)
    {
        printf("Enter value into Node %d :",i);
        scanf("%d",&temp->val);
         i++;
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

Node *swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
Node *tail(Node *head,int pos)
{
    int i=0;
    for(Node *temp=head;temp!=NULL;temp=temp->next){
        if(i==pos)
        return temp;
    i++;
    }
}
Node *reveresList(Node *head)
{
    int count=0;
    for(Node *temp=head;temp!=NULL;temp=temp->next)
    {
     count++;
    }
    Node *temp=head;
    for(int i=0;i<=(count/2);i++){
        Node *tail1=tail(head,count-i-1);
        swap(&temp->val,&tail1->val);
        temp=temp->next;
    }
    return head;
}

int main()
{
   Node *head=createNode(5);
   head=insertVal(head);
   printList(head);
   head=reveresList(head);
   printList(head);
    return 0;
}