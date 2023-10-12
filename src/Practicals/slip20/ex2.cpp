/*
Q2:  Write  the  C-Language  menu  driven  program  to  implement  singly  linear 
linked list of integers. 
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
Node *insertAtPos(Node *head,int pos,int val)
{
    int i=1;
    Node *p1=head;
    Node *newnode=createNode(1);
    newnode->val=val;
    for(Node *temp=head;temp!=NULL;temp=temp->next)
    {
        if(i==pos){
             p1->next=newnode;
             newnode->next=temp;
        }else{
            p1=temp;
        }
        i++;
    }
    return head;
}
Node *deleteAtPos(Node *head,int pos)
{
    Node *p1=head;
    int i=1;
     for(Node *temp=head;temp!=NULL;temp=temp->next)
    {
        if(i==pos){
             p1->next=temp->next;
        }else{
            p1=temp;
        }
        i++;
    }
    return head;
}
Node *deleteAtVal(Node *head,int val)
{
    Node *p1=head;
   
     for(Node *temp=head;temp!=NULL;temp=temp->next)
    {
        if(temp->val==val){
             p1->next=temp->next;
        }else{
            p1=temp;
        }
    }
    return head;
}
Node *append(Node *head,int val)
{
    Node *newnode=createNode(1);
    newnode->val=val;
    Node *temp=head;
   for(temp=head;temp!=NULL;temp=temp->next)
   {
     if(temp->next==NULL){
        temp->next=newnode;
        break;
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
void menu()
{
    printf("1]Enter to create List\n");
    printf("2]Enter to insert Value \n");
    printf("3]Enter insert value at pos\n");
    printf("4]Enter to delete by value\n");
    printf("5]Enter to delete by position\n");
    printf("6]Enter to append element into list\n");
    printf("7]Enter to display list\n");
    printf("8]Enter to exit\n");
}

void operations()
{
    menu();
    int key;
     Node *head;
    int n,pos,val;
    while(1){
    printf("Enter a key :");
    scanf("%d",&key);
   
    switch(key)
    { 
        case 1:
           printf("Enter how many nodes wants to create :");
           scanf("%d",&n);
           head=createNode(n);
           if(head!=NULL){
           printf("List created succefully \n");
           printf("Please insert value in it\n");
           }
           else
           printf("Unable to ceate List");
        break;

        case 2:
           head=insertVal(head);
           if(head!=NULL)
           printf("value insertd  succefully \n");
           else
           printf("Unable to ceate List");
        break;
        case 3:
           printf("Enter value :");
           scanf("%d",&val);
           printf("Enter a pos :");
           scanf("%d",&pos);
           head=insertAtPos(head,pos,val);
        break;
        case 4:
           printf("Enter a pos :");
           scanf("%d",&pos);
           head=deleteAtPos(head,pos);
        break;

        case 5:
           printf("Enter value :");
           scanf("%d",&val);
           head=deleteAtVal(head,val);
        break;

        case 6:
         printf("Enter value to append  :");
           scanf("%d",&val);
           head=append(head,val);
        break;

        case 7:
        printList(head);
        break;
        case 8:
        break;
        default:
        printf("Enter a valid case \n");
    }

    }
}
int main()
{
  operations();
    return 0;
}