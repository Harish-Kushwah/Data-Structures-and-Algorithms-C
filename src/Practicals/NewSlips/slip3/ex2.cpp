/*
Q2. Write a C program to evaluate postfix expression.

==> Algorithm
   Scan the string 
   if character is a digit then push it into the stack
   else if it is operator pop two element form the stack and apply operation on these operator
   store the result in stack
*/
#include<stdio.h>
#include<stdlib.h>
#define N 30
typedef struct Stack
{
    float arr[N];
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
void push(Stack *st,float val)
{
     
    if(!isFull(st))
    {
        st->arr[++st->top]=val;
    }
}
float pop(Stack *st)
{
     
   if(!isEmpty(st))
    {
        return st->arr[st->top--];
    }
}

void evaluate()
{
    char postfix[30];
    printf("Enter postfix exp :");
    scanf("%s",postfix);
    Stack *st=init();
    for(int i=0;postfix[i];i++)
    {
        char sym=postfix[i];

        if(sym>='0'&&sym<='9'){
            push(st,sym-'0');
        }
        else 
        {
            float b=pop(st);
            float a=pop(st);

            if(sym=='+'){
            push(st,a+b);
            }
           else if(sym=='-')
           {
            push(st,a-b);
           }
           else if(sym=='*')
           {
            push(st,a*b);
           }
           else if(sym=='/'){
            push(st,b/a);
           }
        }
    }
    printf("Ans %0.2f",pop(st));
}
int main()
{
    evaluate();
    return 0;
}