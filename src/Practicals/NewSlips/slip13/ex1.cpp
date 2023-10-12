/*
Q1. Implement a stack library (ststack.h) of integers using a static 
implementation  of  the  stack  and  implementing  the  operations  like  init(S), 
S=push(S)  and  S=pop(S).  Write  a  driver  program  that  includes  stack  library 
and calls different stack operations.
*/
#include "ststack.h"
void menu()
{
    printf("1]Enter to Create stack\n");
    printf("2]Enter to push Element\n");
    printf("3]Enter to pop Element\n");
    printf("4]Enter to exit\n");

}
int main()
{
    menu();
    int key;
    Stack *stk=NULL;
    while(1){
    printf("\nEnter key :");
    scanf("%d",&key);
    if(key==1)
    {
     stk=init(stk);
     if(stk==NULL)
     {
        printf("Sorry..!! Unable to initialize\n");
     }
     else{
        printf("Stack is initialized successfully\n");
     }
    }
    else if(key==2)
    {
        int val;
        printf("Enter val:");
        scanf("%d",&val);
        push(stk,val);
    }
    else if(key==3)
    {
        printf("Pop  element is :%d",pop(stk));
    }
    else if(key==4)
    {
        break;
    }
    }
}