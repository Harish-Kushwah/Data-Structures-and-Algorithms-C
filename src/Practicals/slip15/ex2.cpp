/*
Q2: Write the C-Language program that reverses a string of characters using static 
stack.
*/

#include<stdio.h>
#define N 10
typedef struct Stack
{
     char string[N];
     int top;
}Stack;

int isEmpty(Stack *s1)
{
    return s1->top==-1;
}
int isFull(Stack *s1)
{
    return s1->top==N-1;
}
Stack* initStack(Stack *s1)
{
    s1->top=-1;
    return s1;
}
void push(Stack *s1,char ch)
{
  if(!isFull(s1))
   s1->string[++(s1->top)]=ch;
   else
   printf("Stack is Full\n");
}
char pop(Stack *s1)
{
    if(!isEmpty(s1)){
     return s1->string[(s1->top)--];
    }
    else
    return -1;
}

int main()
{
    Stack *s1=initStack(s1);
    char str[10];
    printf("Enter String :");
    scanf("%s",str);
    
    int i;
    for(i=0;str[i];i++){
        push(s1,str[i]);
    }
    for(int j=0;j<i;j++)
    {
        str[j]=pop(s1);
    }
    printf("Reverse String :%s",str);
    
}