# Stack
[![C](https://img.shields.io/badge/language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))

This branch contains the implementation of a stack data structure in C.
A stack is a Last-In-First-Out (LIFO) data structure, where elements are added and removed from the same end called the "top." It follows the principle of "last item in, first item out."


## Static Implementation of Stack
"static stack using an array" refers to a stack data structure where the size of the stack is fixed and determined at compile-time. It utilizes an array to store the stack elements.
```c
//Stack structure of Static 
typedef struct Stack
{
    int item[CAPACITY];
    int top;
}Stack;
```

### Functionality

The following table provides an overview of the functions available in the linked list implementation:

| Function          | Description                                       |Link|
|-------------------|---------------------------------------------------|-----|
|`init()`| Initializes the stack pointer          |[click here](#init)|
|`push(item)`| Adds an item to the top of the stack           |[click here](#push)|
|`pop()`| Removes and returns the item from the top of the stack.|[click here](#pop)|
|`peek()`|Returns the item at the top of the stack without removing it|[click here](#peek)|
|`isEmpty()`|Return 1 if stack is empty else returns 0|[click here](#isempty)|
|`isFull()`|Return 1 if stack is full else returns 0|[click here](#isfull)|

| File         | Description                                       |Link|
|-------------------|---------------------------------------------------|-----|
| `stack.h`          | Contain all the functions  |[click here](src/stack.h) |
| `main.c`          | Usage of all function  |[click here](src/main.c) |

---

<a name="init"></a>
#### init()

```c
//This function initialize the stack
Stack * init()
{
    Stack *stk_ptr = (Stack*)malloc(sizeof(Stack));
    stk_ptr->top = -1;  //top initialize to -1
    return stk_ptr;
}

```
<a name="push"></a>
#### push()

```c
//to add element into stack
void push(Stack *stk_ptr ,int val)
{
    if(!isFull(stk_ptr))
    stk_ptr->item[++(stk_ptr->top)] = val;
    else
     printf("Stack is full\n");
}

```
---
<a name="pop"></a>
#### pop()

```c
//to remove element from the stack 
int pop(Stack *stk_ptr)
{
    if(!isEmpty(stk_ptr))
    return stk_ptr->item[(stk_ptr->top)--];
}
```
---

<a name="peek"></a>
#### peek()

```c
//to get top element from the stack 
int peek(Stack *stk_ptr)
{
    if(!isEmpty(stk_ptr))
    return stk_ptr->item[(stk_ptr->top)];
}
```
---
<a name="isempty"></a>
#### isEmpty()

```c
//check whether stack is empty or not
int isEmpty(Stack *stk_ptr)
{
    return stk_ptr->top==-1;
}
```
<a name ="isfull"></a>
#### isFull()
```c
//check whether stack is full or not
int isFull(Stack *stk_ptr)
{
    return stk_ptr->top==CAPACITY-1;
}
```
---

## Contributing

Contributions, bug reports, and suggestions are welcome! If you encounter any issues, have ideas for improvement, or would like to contribute to this project, please follow the guidelines in [CONTRIBUTE.md](https://github.com/Harish-Kushwah/Data-Structures-and-Algorithms-C/blob/Stack/contribute.md).

## License

[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](https://opensource.org/licenses/MIT)

This repository is licensed under the MIT License. See the [LICENSE](LICENSE) file for more information.

## Contact
For any questions or feedback, feel free to reach out to us at harishkushwah54321@gmail.com

