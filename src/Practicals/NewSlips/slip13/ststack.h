#include<stdio.h>
#include<stdlib.h>
#define N 20
typedef struct Stack
{
    int arr[N];
    int top;
}Stack;

Stack* init(Stack *stk)
{
    stk=(Stack *)malloc(sizeof(Stack));
    stk->top=-1;
    return stk;
}
int isEmpty(Stack *stk)
{
    return stk->top==-1;
}
int isFull(Stack *stk)
{
    return stk->top==N-1;
}
void push(Stack *stk,int val)
{
    if(stk->top==N-1)
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
    else{
        return stk->arr[stk->top--];
    }
}
int peek(Stack *stk)
{
    if(stk->top==-1)
    {
        printf("Stack is Empty\n");
    }
    else{
        return stk->arr[stk->top];
    }
}