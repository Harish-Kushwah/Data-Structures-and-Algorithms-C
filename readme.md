# Linked List
[![C](https://img.shields.io/badge/language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))

This branch contains the implementation of a singly linked list in C. A linked list is a linear data structure where elements are stored as nodes, each containing a value and a pointer to the next node. It allows for efficient insertion and deletion at any position.


## Singly Linked List
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
| `createNode`     | Creates a new node with the given value.           |[click here](#createnode)|
|`createLinkedList`|Creates a linked list consist of N nodes.|[click here](#createlinkedlist)|
| `insertAtBeginning` | Inserts a new node at the beginning of the linked list. |[click here](#insertatbeginning)|
| `insertAtEnd`     | Inserts a new node at the end of the linked list.  |[click here](#insertatend)|
| `insertAtPosition` | Inserts a new node at a specific position in the linked list. |[click here](#insertatposition)|
| `deleteFromBeginning` | Deletes the first node from the linked list.     |[click here](#deletefrombeginning)|
| `deleteFromEnd`   | Deletes the last node from the linked list.       |[click here](#deletefromend)|
| `deleteAtPosition` | Deletes a node from a specific position in the linked list. |[click here](#deleteatposition)|
| `search`          | Searches for a given value in the linked list.     |[click here](#search)|
| `printLinkedList`         | Displays the elements of the linked list.          |[click here](#printlinkedlist)|
| `length`          | Calculates and returns the length of the linked list. |[click here](#length) |

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
---
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
---

<a name="insertatbeginning"></a>
#### insertAtBeginning()

```c
Node *insertAtBeginning(Node *head , int val)
{
    Node *new_node = createNode(val);
    new_node->next = head;
    head = new_node;
    return head; 
}
```
---
<a name="insertatend"></a>
#### insertAtEnd()

```c
Node *insertAtEnd(Node *head,int val)
{
    Node *new_node = createNode(val);
    new_node->next =NULL;

    Node *temp=NULL;
    for(temp=head;temp->next!=NULL;temp = temp->next);

    temp->next = new_node;

    return head;
    
}
```
---
<a name="insertatposition"></a>
#### insertAtPosition()

```c

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
```
---
<a name="deletefrombeginning"></a>
#### deleteFromBeginning()

```c
Node *deleteFromBeginning(Node *head)
{
    Node *temp = head;
    head = head->next;
    free(temp);
    return head;
}
```
---
<a name="deletefromend"></a>
#### deleteFromEnd()

```c
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
```
---
<a name = "deleteatpositon"></a>
### deleteAtPosition()

```c
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
```
---
<a name = "search"></a>
### search()

```c
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
```
---
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
---
<a name ="length"></a>
### length()

```c
int length(Node *head)
{
    int len=0;
    for(Node *temp=head;temp!=NULL; temp=temp->next) len++;

    return len;

}
```
---

## Contributing

Contributions, bug reports, and suggestions are welcome! If you encounter any issues, have ideas for improvement, or would like to contribute to this project, please follow the guidelines in [CONTRIBUTE.md](https://github.com/Harish-Kushwah/Data-Structures-and-Algorithms-C/blob/LinkedList/contribute.md).

## License

[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](https://opensource.org/licenses/MIT)

This repository is licensed under the MIT License. See the [LICENSE](LICENSE) file for more information.

## Contact
For any questions or feedback, feel free to reach out to us at harishkushwah54321@gmail.com

