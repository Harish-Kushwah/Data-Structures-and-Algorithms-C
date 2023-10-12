#include<stdio.h>
#include<stdlib.h>

typedef struct Stack
{
    int capacity;
    int *arr;
    int top;
}Stack;

Stack* init(int capacity)
{
    Stack *stk=(Stack*)malloc(sizeof(Stack));
    stk->top=-1;
    stk->capacity=capacity;
    stk->arr=(int *)malloc(capacity*(sizeof(int)));
    return stk;
}
int isEmpty(Stack *stk)
{
    return stk->top==-1;
}
int isFull(Stack* stk)
{
    return stk->top==stk->capacity-1;
}
void push(Stack *stk,int val)
{
    if(stk->top==stk->capacity-1)
    {
      printf("Stack is Full\n");
    }
    else{
        stk->arr[++stk->top]=val;
    }
}
int pop(Stack *stk)
{
    if(stk->top==-1)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        return stk->arr[stk->top--];
    }
}