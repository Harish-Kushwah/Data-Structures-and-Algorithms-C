# Linked List
This branch contains the implementation of a singly linked list in C. A linked list is a linear data structure where elements are stored as nodes, each containing a value and a pointer to the next node. It allows for efficient insertion and deletion at any position.


##Singly Linked List
A singly linked list is a data structure consisting of a collection of nodes, where each node contains a value and a pointer to the next node
```c
//Node structure of Singly Linked List 
typedef struct Node
{
    int val;
    struct Node *next;
}Node;
```

### Functionality

The following table provides an overview of the functions available in the linked list implementation:

| Function          | Description                                       |Link|
|-------------------|---------------------------------------------------|-----|
| `createNode`      | Creates a new node with the given value.           |[click here](#createnode)|
|`createLinkedList`|Creates a linked list consist of N nodes.|[click here](#createlinkedlist)|
| `insertAtBeginning` | Inserts a new node at the beginning of the linked list. |[click here](src/linkedlist.h)|
| `insertAtEnd`     | Inserts a new node at the end of the linked list.  |[click here](src/linkedlist.h)|
| `insertAtPosition` | Inserts a new node at a specific position in the linked list. |[click here](src/linkedlist.h)|
| `deleteFromBeginning` | Deletes the first node from the linked list.     |[click here](src/linkedlist.h)|
| `deleteFromEnd`   | Deletes the last node from the linked list.       |[click here](src/linkedlist.h)|
| `deleteAtPosition` | Deletes a node from a specific position in the linked list. |[click here](src/linkedlist.h)|
| `search`          | Searches for a given value in the linked list.     |[click here](src/linkedlist.h)|
| `printLinkedList`         | Displays the elements of the linked list.          |[click here](#printlinkedlist)|
| `length`          | Calculates and returns the length of the linked list. |[click here](src/linkedlist.h) |

| File         | Description                                       |Link|
|-------------------|---------------------------------------------------|-----|
| `linkedlist.h`          | Contain all the functions  |[click here](src/linkedlist.h) |
| `main.c`          | Usage of all function  |[click here](src/main.c) |

---
<a name="createnode"></a>
#### createNode()

```c
Node *createNode(int val)
{
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->next = NULL;
    new_node->val = val;
    return new_node;

}
```
<a name="createlinkedlist"></a>
#### createLinkedList()
```c
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

```
<a name ="printlinkedlist"></a>
### printLinkedList()
```c
void printLinkedList(Node *head)
{
    printf("Linked list data :");
    for(Node *temp = head; temp!=NULL; temp =temp->next)
    {
        printf("%d " , temp->val);
    }
}
```

