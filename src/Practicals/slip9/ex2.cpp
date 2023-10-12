/*
Q2: Write the C-Language menu driven program to create, display, insert and 
delete node in doubly linked list of integers.
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int val;
    struct Node *left;
    struct Node *right;
}Node;

Node *createNode(int n)
{
    Node *temp=NULL,*head=NULL,*newnode=NULL;
    for(int i=0;i<n;i++)
    {
        newnode=(Node*)malloc(sizeof(Node));
        newnode->val=0;
        newnode->left=NULL;
        newnode->right=NULL;
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
Node *insertVal(Node *head)
{
    for(Node *temp=head;temp!=NULL;temp=temp->right)
    {
        printf("Enter a value :");
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
Node *deleteAtPos(Node *head,int pos)
{
    int i=1;
    Node *p1=head;
    for(Node *temp=head;temp!=NULL;temp=temp->right)
    {
        if(i==pos)
        {
             p1->right=temp->right;
             temp=temp->right;
             temp->left=p1;
        }
        else{
            p1=temp;
        }
        i++;
    }
    return head;
}

void menu()
{
    printf("1]Enter to create List\n");
    printf("2]Enter to insert Value \n");
    printf("3]Enter to delete by position\n");
    printf("4]Enter to display list\n");
    printf("5]Enter to exit\n");
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
        break;
        case 3:
           printf("Enter a pos :");
           scanf("%d",&pos);
           head=deleteAtPos(head,pos);
        break;

        case 4:
        printList(head);
        break;
        case 5:
        exit(0);
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