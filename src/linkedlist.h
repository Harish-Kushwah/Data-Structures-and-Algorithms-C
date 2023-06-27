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
int length(Node *head)
{
    int len=0;
    for(Node *temp=head;temp!=NULL; temp=temp->next) len++;

    return len;

}
Node *insertAtBeginning(Node *head , int val)
{
    Node *new_node = createNode(val);
    new_node->next = head;
    head = new_node;
    return head; 
}

Node *insertAtEnd(Node *head,int val)
{
    Node *new_node = createNode(val);
    new_node->next =NULL;

    Node *temp=NULL;
    for(temp=head;temp->next!=NULL;temp = temp->next);

    temp->next = new_node;

    return head;
    
}

Node *insertAtPosition(Node *head,int pos ,int val)
{
      int len = length(head);

      if(pos<0 || pos >len){
        printf("Enter valid postion");
        return NULL;
      }

      if(pos==0){
        return insertAtBeginning(head,val);
      }
      else if(pos == len){
        return insertAtEnd(head,val);
      }

      Node *new_node = createNode(val);
      int count=0;
      Node *previous_node=head;
      for(Node *temp = head;temp!=NULL; temp= temp->next){
        if(pos == count){
            previous_node->next = new_node;
            new_node->next=temp;
            break;
        }
        else{
          previous_node = temp;
        }

        count++;
      }
      return head;
}

Node *deleteFromBeginning(Node *head)
{
    Node *temp = head;
    head = head->next;
    free(temp);
    return head;
}
Node *deleteFromEnd(Node *head)
{
    Node *temp = head;
    for(temp=head; temp->next!=NULL;temp=temp->next)
    {
        if(temp->next->next==NULL)
        {
           
            temp->next=NULL;
            free(temp->next);
            break;
        }
    }
    return head;
}

Node *deleteAtPosition(Node *head,int pos)
{
      int len = length(head);

      if(pos<=0 || pos >len){
        printf("Enter valid postion");
        return NULL;
      }

      if(pos==1){
        return  deleteFromBeginning(head);
      }
      else if(pos == len){
        return deleteFromEnd(head);
      }

      int count=1;
      Node *previous_node=head;
      for(Node *temp = head;temp!=NULL; temp= temp->next){
        if(pos == count){
            previous_node->next =temp->next;
            break;
        }
        else{
          previous_node = temp;
        }
        count++;
      }
      return head;
}

void search(Node *head , int key)
{
    int flag =0;
    for(Node *temp = head; temp!=NULL; temp = temp->next)
    {
        if(temp->val==key)
        {
            printf("\n%d found in List\n",key);
            flag=1;
            break;
        }
    }
    if(flag==0){
        printf("\n%d not found  list\n",key);
    }
}
void printLinkedList(Node *head)
{
    printf("Linked list data :");
    for(Node *temp = head; temp!=NULL; temp =temp->next)
    {
        printf("%d " , temp->val);
    }

    printf("\n");
}