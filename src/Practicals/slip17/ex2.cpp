/*
Q2: Write the C-Language program that checks whether a string of characters 
is palindrome or not using stack
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct Stack
{
    char str[20];
    int top;
}Stack;
Stack* init()
{
    Stack *stk=(Stack *)malloc(sizeof(Stack));
    stk->top=-1;
    return stk;
}
int isEmpty(Stack *stk)
{
    return  stk->top==-1;
}
void push(Stack *stk,char ch)
{ 
     stk->str[stk->top++]=ch;
}
char pop(Stack *stk)
{
    return stk->str[--stk->top];
}
int isPalindrome(char name[])
{
    Stack *stk=init();
    for(int i=0;name[i];i++)
     push(stk,name[i]);
    while(!isEmpty(stk)){
        for(int i=0;name[i];i++){
            if(pop(stk)!=name[i])
            return 0;
        }
    }
    return 1;
}
int main()
{
    char name[20];
    printf("Enter a string :");
    scanf("%s",name);
    if(isPalindrome(name))
    printf("%s string is palindrome ",name);
    else
    printf("%s string is not palindrome ",name);
    return 0;
}