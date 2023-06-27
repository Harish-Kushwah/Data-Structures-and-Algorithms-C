#include<stdio.h>
#include "linkedlist.h"

int main()
{
    //create a linked list
    Node * head = createLinkedList();

    //insert node at beginning
    //new_node created with value 10 and added at the beginning
    head = insertAtBeginning(head,10);

    //prints after inserting node
    printf("\nLinked list data after after inserting node at beginning \n");
    printLinkedList(head);

    //insert node at End
    //new_node created with value 7 and added at the end
    head = insertAtEnd(head,7);

    //prints after inserting node
    printf("\nLinked list data after after inserting node at End \n");
    printLinkedList(head);

 
    //Insert node at any postion
    printf("\nInsert at position\n ");
    int position = 0;
    int val = 12;
    head = insertAtPosition(head,position,val);
    printLinkedList(head);   

    //delete node from the beginning
    printf("\nAfter deleting node from the beginning \n");
    head = deleteFromBeginning(head);
    printLinkedList(head);

    //delete node from the end
    printf("\nAfter deleting node from the end \n");
    head = deleteFromEnd(head);
    printLinkedList(head);

    //Delete at any postion
    printf("\nDelete at position\n ");
    position = 2;
    head = deleteAtPosition(head,position);
    printLinkedList(head); 

     
    //search element in the linked list
    int key = 10;
    search(head,key);

    // prints the elements of linked list
    printLinkedList(head);

   //find the length of the Linked List 
   int len = length(head);
   printf("Total length of the Linked List : %d" ,len);

}
