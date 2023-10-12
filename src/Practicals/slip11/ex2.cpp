/*
Q2: Write the C-Language program that adds two single variable polynomials. 
Each polynomial should be represented as a list with linked list 
implementation.
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    float coeff;
    int expo;
    struct Node *next;
}Node;
Node *createNodes(int pow)
{
    Node *head=NULL,*temp=NULL,*newnode=NULL;
    for(int i=pow;i>=0;i--){
        newnode=(Node *)malloc(sizeof(Node));
        newnode->expo=i;
        newnode->next=NULL;
        if(head==NULL)
        {
            head=temp=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
    }
    return head;
}
Node *insertVal(Node *head,int pow)
{
    int i=pow;
    for(Node *temp=head;temp!=NULL;temp=temp->next)
    {
        printf("Enter Coefficient of exp %d:",i);
        scanf("%f",&temp->coeff);
        i--;
    }
    return head;
}
Node *add(Node *h1,Node *h2,int pow)
{
    Node *h3=createNodes(pow);
    Node *temp3=h3;

    Node *temp1=h2;
    for(Node *temp=h1;temp!=NULL&&temp1!=NULL;temp=temp->next)
    {
        temp3->coeff=temp->coeff+temp1->coeff;
        temp3->expo=temp->expo;

        temp3=temp3->next;
        temp1=temp1->next;
    }
    return h3;
}
void printExp(Node *head)
{
    for(Node *temp=head;temp!=NULL;temp=temp->next)
    {
        printf("%0.1f x^%d ",temp->coeff,temp->expo);
       if(temp->next!=NULL)
        if(temp->coeff>0){
            printf("+ ");
        }
       /* else{
            printf("- ");
        }*/
    }
    printf("\n");
}
int main()
{
    int pow;
    printf("Enter degree of polynomial:");
    scanf("%d",&pow);
    printf("Foe expresion 1 :\n");
    Node *exp1=insertVal(createNodes(pow),pow);
    printExp(exp1);
    printf("Foe expresion 2 :\n");
    Node *exp2=insertVal(createNodes(pow),pow);
    printExp(exp2);
    Node *exp3=add(exp1,exp2,pow);
    printf("Addition of Expresion :");
    printExp(exp3);
    return 0;
}