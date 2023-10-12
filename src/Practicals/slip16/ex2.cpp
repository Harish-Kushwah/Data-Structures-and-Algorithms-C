/*
Q2: Write the C-Language program to convert an infix expression of the form 
(a*(b+c)*((d-a)/b)) into its equivalent postfix notation using stack.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 20
 char Stack[N];
 int top=-1;

int isEmpty()
{
    return top==-1;
}
int isFull()
{
    return top==N-1;
}
void push(char ch)
{
    if(!isFull())
    {
       Stack[++top]=ch;
    }
    else
    printf("Stack is Full :");
}
char pop()
{
    if(!isEmpty())
    {
        return Stack[top--];
    }
}
char peek()
{
     if(!isEmpty())
    {
        return Stack[top];
    }
}
int pres(char ch)
{
    if(ch=='^')
    return 3;
    else if(ch=='/'||ch=='*')
    return 2;
    else if (ch=='+'||ch=='-')
    return 1;
    else
    return 0;
}
void toPost(char infix[])
{
    char postfix[20];
    int k=0;
    char symbol,next;
    for(int i=0;i<strlen(infix);i++)
    {
        symbol=infix[i];
        switch(symbol)
        {
            case '(':
              push(symbol);
              break;
            case ')':
              while ((next=pop())!='(')
              {
                 postfix[k++]=next;
              }
              break;
              
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
               while(!isEmpty()&&pres(symbol)<=pres(Stack[top]))
               {
                postfix[k++]=pop();
               }
               push(symbol);
               break;
              default:
              postfix[k++]=symbol;
              break;
              
        }
    }
    while(!isEmpty())
     postfix[k++]=pop();

     postfix[k]='\0';
     printf("Exp : %s",postfix);
}
int main()
{
    char infix[20];
    printf("Enter infix exp : ");
    gets(infix);
    toPost(infix);
}
/*
int pres(char ch)
{
    if(ch=='^')
    return 1;
    else if(ch=='/'||ch=='*')
    return 2;
    else if(ch=='+'||ch=='-')
    return 3;
    else
    return 0;
}
void toPost(char infix[])
{
    char postfix[20];
   char symbol,next;
   int k=0;
   for(int i=0;i<strlen(infix);i++)
   {
      symbol=infix[i];
        switch (symbol)
        {
           case '(':
             push(symbol);
            break;

            case ')':
             while((next=pop())!='('){
                postfix[k++]=next;
             }
            break;

            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
              while(!isEmpty()&&pres(symbol)<=pres(Stack[top])){
               postfix[k++]=pop();
             }
               push(symbol);
               break;              
          default:
            postfix[k++]=symbol;
        }
   }
   while(!isEmpty())
     postfix[k++]=pop();
   postfix[k]='\0';
   printf("PostFix: %s",postfix);

}*/
/*
 if(infix[i]>='0'&&infix[i]<='9'){
       pstr[k]=infix[i];
       k++;
       printf("#\n");
     }
     else if(infix[i]=='('){
        push(,infix[i]);
     }
     else if(infix[i]==')'){
        do{
            ch=pop();
            pstr[k]=ch;
            k++;
        } while (ch!='(');
     }
     else {
        if(peek()==-1)
        {
            push(,infix[i]);
        }
        else if(pres(infix[i])<=pres(peek()))
        {
            ch=pop();
            pstr[k]=ch;
            k++;
            push(,infix[i]);
        }
        else{
           push(,infix[i]);
        }
     }
     //pstr[i]=infix[i];
     len=i;
   }
   pstr[len+1]='\0';
   printf("PostFix: %s",pstr);
*/