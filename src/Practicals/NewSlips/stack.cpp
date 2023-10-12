#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Max 20
typedef struct Stack
{
    char arr[Max];
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
    return stk->top==-1;
}
int isFull(Stack *stk)
{
    return stk->top==Max-1;
}
void push(Stack *stk,char val)
{
   if(!isFull(stk)){
   stk->arr[++stk->top]=val;
   }
   else{
    printf("Stack is Full :\n");
   }
}
char pop(Stack *stk)
{
   if(!isEmpty(stk)){
   return stk->arr[stk->top--];
   }
   else{
    printf("Stack is empty\n");
    return -1;
   }
}
int peek(Stack *stk)
{
    return stk->arr[stk->top];
}

void isPalli(Stack *stk)
{
    char Name[20];
    printf("Enter Name :");
    scanf("%s",Name);
    for(int i=0;Name[i];i++)
    {
        push(stk,Name[i]);
    }
    int i=0;
    int flag=0;
    while(!isEmpty(stk))
    {
        char ch=pop(stk);
       if(Name[i]!=ch)
       {
        flag=1;
         break;
       }
       i++;

    }
    if(flag==0){
        printf("Plaindrom");
    }
    else{
        printf("Not Plalindrom");
    }

}

int main()
{
    Stack *stk=init();
    isPalli(stk);
 



}