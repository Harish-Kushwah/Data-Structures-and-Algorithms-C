/*
Q2:  Write  the  C-Language  menu  driven  program  to  implement  static  stack  of 
integers 
*/
#include<stdio.h>

#define N 10
typedef struct Stack
{
  int arr[N];
  int top;
}Stack;
Stack *initStack(Stack *s1)
{
      s1->top=-1;
      return s1;
}
int isEmpty(Stack *s1)
{
    return s1->top==-1;
}
int isFull(Stack *s1)
{
    return s1->top==N-1;
}
void push(Stack *s1,int val)
{
    if(!isFull(s1))
    s1->arr[++(s1->top)]=val;  
    else
    printf("Stack is full"); 
}
int pop(Stack *s1)
{
   if(!isEmpty(s1))
    return s1->arr[(s1->top)--];
    else
    return -1;
}

int main()
{
    Stack *s1=initStack(s1);
    push(s1,1);
    push(s1,2);
    printf("%d\n", pop(s1));
    push(s1,3);
    printf("%d\n", pop(s1));
    return 0;
}