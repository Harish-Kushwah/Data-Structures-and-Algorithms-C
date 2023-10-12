/*
Q1. Implement a list library (singlylist.h) for a singly linked list of integer 
    With the operations create, delete specific element and display. Write a        
    menu driven program to call these operations
*/
#include "singlylist.h"
void menu()
{
    printf("1]Enter to create Node\n");
    printf("2]Enter to delete Node\n");
    printf("3]Enter to display List\n");
    printf("4]Enter to Exit\n");
}
int main()
{
    Node *head=NULL;
    menu();
    while(1){
    int key;
    printf("Enter Key:");
    scanf("%d",&key);
    if(key==1)
    {
        int n;
        printf("Enter How many Nodes wants to create :");
        scanf("%d",&n);
        head=createNode(n);
        if(head==NULL){
            printf("Sorry..!! Unable to create List\n");
        }
        else{
            printf("List created Successfully\n");
        }
    }
    else if(key==2)
    {
        int val;
        printf("Enter value for delete :");
        scanf("%d",&val);
        head=delateByVal(head,val);
        if(head==NULL){
            printf("Sorry..!! Unable to delete\n");
        }
        else{
            printf("Target value deleted Successfully\n");
        }
    }
    else if(key==3)
    {
        printf("Linked List is :\n");
        display(head);

    }
    else if(key==4){
        exit(0);
    }
    else{
        printf("Enter a valid key\n");
    }
  } 
    return 0;
}