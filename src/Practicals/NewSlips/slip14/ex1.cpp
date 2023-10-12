#include<stdio.h>
#include<stdlib.h>

typedef struct Poly
{
    float coeff;
    int expo;
    struct Poly *next;
}Poly;

//insert nodes in sorted order
Poly *insert(Poly *head,float coeff,int expo)
{
    Poly *newnode=NULL,*temp=NULL;
    newnode=(Poly *)malloc(sizeof(Poly));
    newnode->coeff=coeff;
    newnode->expo=expo;
    newnode->next=NULL;
    int key=expo;
    if(head==NULL||key>head->expo)
    {
        newnode->next=head;
        head=newnode;
    }
    else{
        temp=head;
        while(temp->next!=NULL&&temp->next->expo>key)
        temp=temp->next;

        newnode->next=temp->next;
        temp->next=newnode;

    }
 return head;
}
Poly *createPoly(int n)
{
    float coeff;
    int expo;
    Poly *head=NULL;
    for(int i=0;i<n;i++)
    {
        printf("Enter Coeff:");
        scanf("%f",&coeff);
        printf("Enter expo :");
        scanf("%d",&expo);
        head=insert(head,coeff,expo);
    }
    return head;
}
void printList(Poly *head)
{
    if(head==NULL)
    printf("No Polynomial");
    else
    {
        for(Poly *temp=head;temp!=NULL;temp=temp->next)
        {
            printf("(%0.1f x)^%d",temp->coeff,temp->expo);
            if(temp->next!=NULL)
            printf(" + ");
        }

    }
    printf("\n");
}

Poly* add(Poly *head1,Poly *head2)
{
    Poly *head=NULL;  //polynomial 3
    Poly *p1=head1;
    Poly *p2=head2;

    while(p1!=NULL&&p2!=NULL)
    {
        if(p1->expo==p2->expo)
        {
            head=insert(head,p1->coeff+p2->coeff,p1->expo);
            p1=p1->next;
            p2=p2->next;
        }
        else if(p1->expo<p2->expo)
        {
            head=insert(head,p2->coeff,p2->expo);
            p2=p2->next;
        }
        else{
            head=insert(head,p1->coeff,p1->expo);
            p1=p1->next;
        }
    }
    while(p1!=NULL)
    {
        head=insert(head,p1->coeff,p1->expo);
        p1=p1->next;
    }
    while(p2!=NULL)
    {
        head=insert(head,p2->coeff,p2->expo);
        p2=p2->next;
    }
    return head;
}
Poly *head[10];
void multiply(Poly *head1,Poly *head2,int terms)
{
    for(int i=0;i<terms;i++){
        Poly *head[i]={NULL};
    }
    int i=0;
    for(Poly *p1=head1;p1!=NULL;p1=p1->next)
    {
        for(Poly *p2=head2;p2!=NULL;p2=p2->next)
        {
            head[i]=insert(head[i],p1->coeff*p2->coeff,p1->expo+p2->expo);
        }
        i++;
    }
    for(int i=0;i<terms;i++)
    {
        head[i+1]=add(head[i],head[i+1]);
    }
    printList(head[terms-1]);
}

void multiply1(Poly *head1,Poly *head2)
{
    Poly *head=NULL;
    int i=0;
    for(Poly *p1=head1;p1!=NULL;p1=p1->next)
    {
        for(Poly *p2=head2;p2!=NULL;p2=p2->next)
        {
            head=insert(head,p1->coeff*p2->coeff,p1->expo+p2->expo);
        }
        i++;
    }
    for(Poly *p3=head;p3->next!=NULL;)
    {
        if(p3->expo==p3->next->expo){
            p3->coeff=p3->coeff+p3->next->coeff;
            Poly *temp=p3->next;
            p3->next=p3->next->next;
            free(temp);
            temp=NULL;
        }
        else{
            p3=p3->next;
        }
    }
    printList(head);
}
int main()
{
    int n1,n2;
    printf("Number of terms of poly 1:");
    scanf("%d",&n1);
    Poly *p1=createPoly(n1);
    printList(p1);
    printf("Number of terms of poly 2:");
    scanf("%d",&n2);
    Poly *p2=createPoly(n2);
    printList(p2);
    printf("polynomial :");
    multiply1(p1,p2);
    return 0;
}