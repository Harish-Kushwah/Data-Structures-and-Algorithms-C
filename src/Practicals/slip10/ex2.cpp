/*
Q2:  Write  the  C-Language  program  that  merges  two  ordered  linked  lists  into 
third new list. When two lists are merged the data in the resulting list are also 
ordered.  The  two  original  lists  should  be  left  unchanged.  That  is  merged  list 
should be new one. Use linked implementation. 
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int val;
    struct Node *next;
}Node;

Node *createNodes(int n)
{
    Node *head=NULL,*temp=NULL,*newnode=NULL;
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
        else{
            temp->next=newnode;
            temp=newnode;
        }
    }
    return head;
}
Node *printList(Node *head)
{
    for(Node *temp=head;temp!=NULL;temp=temp->next)
    {
        printf("%d ",temp->val);
    }
}

Node *merge(Node *list1,Node *list2)
{
    for(Node *temp=list1;temp!=NULL;temp=temp->next)
    {
        if(temp->next==NULL)
        {
            temp->next=list2;
            break;
        }
    }
    return list1;
}

int main()
{
    Node *list1=NULL,*list2=NULL,*list3=NULL;
    int n1,n2;
    printf("Enter size of list1 :");
    scanf("%d",&n1);
    list1=createNodes(n1);

    printf("Enter size of list2 :");
    scanf("%d",&n2);
    list2=createNodes(n2);
   
    printf("Merged List3 :");
    list3=merge(list1,list2);
    printList(list3);
    return 0;


}