/*
Q1.Implement a list library (doublylist.h) for a doubly linked list of integers          
with the create, display operations. Write a menu driven program to call 
these operations.
*/
#include "doublylist.h"
#include<stdio.h>
void menu()
{
    printf("1] Enter to create Doubly LL\n");
    printf("2] ENter to display Double LL\n");
    printf("3] Enter to Exit\n");
}
int main()
{
    menu();
    int n=0;
    Node *head=NULL;
    while(n!=3){
    printf("\nEnter a n :\n");
    scanf("%d",&n);
    switch(n){
     case 1:
        int no_node;
        printf("Enter a how many Nodes you wants to create :\n");
        scanf("%d",&no_node);
        head=createNode(no_node);
        head=insertVal(head);
        if(head!=0){
            printf("Linked List created Successfully:\n");
        }
        else{
            printf("Unable to create Linked List\n");
            //exit(0);
        }
    break;
    case 2:
        printf("Elements of Doubly Linked List: \n");
        printList(head);
    break;
    case 3:
        printf("Program exited Successfully:\n");
        free(head);
        //exit(0);
    break;
    default:
        printf("Enter a valid case :");
    break;
    }
  }
    return 0;
}