/*
Q2. Write a program that copies the contents of one stack into another. Use         
stack library to perform basic stack operations. The order of two stacks        
must  be  identical.(Hint:  Use  a  temporary  stack  to  preserve  the  order).
*/
#include<stdio.h>
#include<stdlib.h>
#define N 10
typedef struct Stack
{
    int arr[N];
    int top;
}Stack;
Stack *init()
{
    Stack *st=(Stack *)malloc(sizeof(Stack));
    st->top=-1;
    return st;
}
int isFull(Stack *st)
{
    return st->top==N-1;
}
int isEmpty(Stack *st)
{
    return st->top==-1;
}
void push(Stack *st,int val)
{
     
    if(!isFull(st))
    {
        st->arr[++st->top]=val;
    }
    else{
        printf("Stack is Full :");
    }
}
int pop(Stack *st)
{
     
   if(!isEmpty(st))
    {
        return st->arr[st->top--];
    }
    else{
        printf("Stack is Empty :");
        return -1;
    }
}
int main()
{
    Stack *s1=init();
    int n=5;
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        push(s1,x);
    }
    Stack *s2=init();
    for(int i=0;i<n;i++){
        push(s2,pop(s1));
    }
    Stack *s3=init();
     for(int i=0;i<n;i++){
        push(s3,pop(s2));
    }
    printf("Elements of Stack 3 :\n");
    for(int i=0;i<n;i++){
        printf("%d \n",pop(s3));
    }
    return 1;
}