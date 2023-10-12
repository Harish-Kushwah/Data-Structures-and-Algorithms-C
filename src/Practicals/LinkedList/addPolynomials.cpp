#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    float coeff;
    int expo;
    struct Node *next;
}Node;

Node *insert(Node *head,float coeff,int expo)
{
       Node *temp=NULL,*newnode=NULL;
       newnode=(Node *)malloc(sizeof(Node));   
       newnode->coeff=coeff;
       newnode->expo=expo;  
        int key=expo;
        newnode->next=NULL;
        if(head==NULL||key>head->expo)
        {
            newnode->next=head;
            head=newnode;
        }
        else{
            temp=head;
            while(temp->next!=NULL&&temp->next->expo>key)
            temp=temp->next;

            newnode->next=temp->next;
            temp->next=newnode;
        }
    return head;
}
Node *create(int n)
{
    float coeff;
    int expo;
    Node *head=NULL;
    for(int i=0;i<n;i++)
    {
        printf("Enter coeff :");
        scanf("%f",&coeff);
        printf("Enter Expo :");
        scanf("%d",&expo);
        head=insert(head,coeff,expo);
    }
    return head;
}
void printList(Node *head)
{
    if(head==NULL)
   printf("No polynomial :");
    for(Node *temp=head;temp!=NULL;temp=temp->next)
    {
        printf("(%0.1f x)^%d",temp->coeff,temp->expo);
        if(temp->next!=NULL){
            printf(" + ");
        }
    }
    printf("\n");
}
void add(Node *head1,Node *head2)
{
   Node *head=NULL;
   Node *t1=head1,*t2=head2;
   while(t1!=NULL&&t2!=NULL)
   {
        if(t1->expo==t2->expo){
            head=insert(head,t1->coeff+t2->coeff,t1->expo);
            t1=t1->next;
            t2=t2->next;
            
        }
        else if(t1->expo<t2->expo){
           head=insert(head,t2->coeff,t2->expo);
            t2=t2->next;
        }
        else if(t1->expo>t2->expo){
           head=insert(head,t1->coeff,t1->expo);
            t1=t1->next;
        }
   }
   while(t1!=NULL){
        head=insert(head,t1->coeff,t1->expo);
        t1=t1->next;
   }
   while(t2!=NULL){
        head=insert(head,t2->coeff,t2->expo);
        t2=t2->next;
   }
   
  printList(head);
}
void multiply()
int main()
{
    Node *ex1=create(2);
    printList(ex1);
    Node *ex2=create(2);
    printList(ex2);
    printf("Addition : ");
    add(ex1,ex2);
}