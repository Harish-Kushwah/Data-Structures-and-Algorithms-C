#include<stdio.h>
#include "stack.h"

int main()
{
    //initialize the stack
    Stack *stack = init();  

    //Add element into the stack
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);

    //check whether stack is empty or not
    if(isEmpty(stack))
     printf("Stack is Empty\n");
    else
     printf("Stack is not empty\n");

    //check whether stack is full or not
    if(isFull(stack))
     printf("Stack is full\n");
    else
     printf("Stack is not full\n");

    //pop all the element form the stack

    printf("Element of stack :\n");
    while (!isEmpty(stack))
    {
       printf("%d \n", pop(stack));
    }
    


}