/*
Q2. Write a C program to check whether the contents of two stacks are        
   identical. Use stack library to perform basic stack operations. Neither          
   stack should be changed
*/
#include "stack.h"

int isEqual(Stack *st1,Stack *st2,int capacity)
{
    Stack *t1=init(5);
    Stack *t2=init(5);
    while(!isEmpty(st1)&&!isEmpty(st2))
    {
        push(t1,pop(st1));
        push(t2,pop(st2));
    }
    int flag=1;
    while(!isEmpty(t1)&&!isEmpty(t1))
    {
        int a=pop(t1);
        int b=pop(t2);
        if(a!=b){
            flag=0;
        }
        push(st1,a);
        push(st2,b);
    }
    return flag==1;
}
int main()
{
    int capacity;
    printf("Enter Capacity of Both stack");
    scanf("%d",&capacity);
    Stack *st1=init(capacity);
    Stack *st2=init(capacity);

    int n1;
    printf("Enter Data in stack 1:\n");
    printf("Enter how many elements wants to store :");
    scanf("%d",&n1);
    for(int i=0;i<n1;i++){
        int val;
        printf("Enter val :");
        scanf("%d",&val);
        push(st1,val);
    }
    int n2;
    printf("Enter Data in stack 1:\n");
    printf("Enter how many elements wants to store :");
    scanf("%d",&n2);
    for(int i=0;i<n2;i++){
        int val;
        printf("Enter val :");
        scanf("%d",&val);
        push(st2,val);
    }
   
    if(isEqual(st1,st2,capacity))
    {
        printf("Content Of both Stack is Equal\n");
    }
    else{
        printf("Content is different\n");
    }
}