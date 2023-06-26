#include<stdlib.h>
#include<stdio.h>
typedef struct Node
{
    int val;
    struct Node *next;
}Node;


Node *createNode(int val)
{
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->next = NULL;
    new_node->val = val;
    return new_node;

}
Node *createLinkedList()
{
    int n;
    Node *temp = NULL,*new_node = NULL ,*head=NULL;
    printf("Enter how many node wants to create :");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
       int val;
       printf("Enter data into node :");
       scanf("%d",&val);

       new_node = createNode(val);

       if(head==NULL)
       {
        head = temp=new_node;
       }
       else{
        temp->next = new_node;
        temp = new_node; 
       }

    }
 
    return head;
}

void printLinkedList(Node *head)
{
    printf("Linked list data :");
    for(Node *temp = head; temp!=NULL; temp =temp->next)
    {
        printf("%d " , temp->val);
    }
}