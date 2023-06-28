# Queue
[![C](https://img.shields.io/badge/language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))

This branch contains the implementation of a Queue data structure in C.
A queue is a First-In-First-Out (FIFO) data structure, where elements are added at one end called the "rear" and removed from the other end called the "front." It follows the principle of "first item in, first item out."


## Static Implementation of Queue
"static queue using an array" refers to a queue data structure where the size of the queue is fixed and determined at compile-time. It utilizes an array to store the queue elements.
```c
//Queue structure of Static 
typedef struct Queue
{
    int item[CAPACITY];
    int front;
    int rare;
}Queue;
```

### Functionality

The following table provides an overview of the functions available in the Queue implementation:

| Function          | Description                                       |Link|
|-------------------|---------------------------------------------------|-----|
|`int()`| Initialize the Queue pointer       |[click here](#init)|
|`enqueue()`| Adds an item to the rear of the queue.       |[click here](#enqueue)|
|`dequeue()`|Removes and returns the item from the front of the queue. |[click here](#dequeue)|
|`peek()`| Returns the item at the front of the queue without removing it.|[click here](#peek)|
|`isEmpty()`| Checks if the queue is empty|[click here](#isempty)|
|`size()`| Returns the number of elements in the queue.|[click here](#size)|

| File         | Description                                       |Link|
|-------------------|---------------------------------------------------|-----|
| `queue.h`          | Contain all the functions  |[click here](src/queue.h) |
| `main.c`          | Usage of all function  |[click here](src/main.c) |

---

<a name="init"></a>
#### init()

```c
//This function initialize the Queue
Queue *init()
{
   Queue *qu = (Queue *)malloc(sizeof(Queue));
   qu->front = -1;
   qu->rare = -1;
   return qu;
}

```
<a name="enqueue"></a>
#### enqueue()

```c
//add element into queue
void enqueue(Queue *qu , int val)
{
    qu->item[++qu->rare]=val;
}

```
---
<a name="dequeue"></a>
#### dequeue()

```c
//remove element from the queue
int dequeue(Queue *qu)
{
    return qu->item[++qu->front];
}
```
---

<a name="peek"></a>
#### peek()

```c
//return the first element from the queue
int peek(Queue *qu)
{
    if(!isEmpty(qu))
    return qu->item[qu->front];
}
```
---
<a name="isempty"></a>
#### isEmpty()

```c
//check whether queue is empty or not
int isEmpty(Queue *qu)
{
    return qu->front == qu->rare;
}
```
<a name ="size"></a>
#### size()

```c
//return the size of queue
int size(Queue *qu)
{
    if(qu->rare==-1)
    return 0;
    return qu->rare + 1; 
}
```
---

## Contributing

Contributions, bug reports, and suggestions are welcome! If you encounter any issues, have ideas for improvement, or would like to contribute to this project, please follow the guidelines in [CONTRIBUTE.md](https://github.com/Harish-Kushwah/Data-Structures-and-Algorithms-C/blob/Queue/contribute.md).

## License

[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](https://opensource.org/licenses/MIT)

This repository is licensed under the MIT License. See the [LICENSE](LICENSE) file for more information.

## Contact
For any questions or feedback, feel free to reach out to us at harishkushwah54321@gmail.com

