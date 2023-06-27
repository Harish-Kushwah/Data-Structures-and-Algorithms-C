#include<stdio.h>
#include<stdlib.h>

#define CAPACITY  20

typedef struct Stack
{
    int item[CAPACITY];
    int top;
}Stack;

//check whether stack is empty or not
int isEmpty(Stack *stk_ptr)
{
    return stk_ptr->top==-1;
}

//check whether stack is full or not
int isFull(Stack *stk_ptr)
{
    return stk_ptr->top==CAPACITY-1;
}

//This function initialize the stack
Stack * init()
{
    Stack *stk_ptr = (Stack*)malloc(sizeof(Stack));
    stk_ptr->top = -1;  //top initialize to -1
    return stk_ptr;
}

//to add element into stack
void push(Stack *stk_ptr ,int val)
{
    if(!isFull(stk_ptr))
    stk_ptr->item[++(stk_ptr->top)] = val;
    else
     printf("Stack is full\n");
}

//to remove element from the stack 
int pop(Stack *stk_ptr)
{
    if(!isEmpty(stk_ptr))
    return stk_ptr->item[(stk_ptr->top)--];
}

//to get top element from the stack 
int peek(Stack *stk_ptr)
{
    if(!isEmpty(stk_ptr))
    return stk_ptr->item[(stk_ptr->top)];
}
