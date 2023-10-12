/*
Q1.  Implement  a  linear  queue  library  (st_queue.h)  of  integers  using  a  static 
implementation of the queue and implementing the init(Q), add(Q) and peek(Q) 
operations.  Write  a  program  that  includes  queue  library  and  calls  different 
queue operations
*/
#include "st_queue.h"
void menu()
{
    printf("1]Enter to initialize queue\n");
    printf("2]Enter to add element in queue\n");
    printf("3]Enter To get peek element from queue\n");
    printf("4]Enter to Exit\n");
}
int main()
{
    menu();
    int key;
    Queue *Q=NULL;
    while(1){
    printf("\nEnter key :");
    scanf("%d",&key);
    if(key==1)
    {
        Q=init(Q);
        if(Q==NULL)
        {
            printf("Sorry..!! Unable to initialize Queue\n");
        }
        else{
            printf("Queue initialize Successfully\n");
        }
    }
    else if(key==2)
    {
         if(Q==NULL)
        {
            printf("Sorry..!! First initialize Queue\n");
            break;
        }
        int val;
        printf("\nEnter val :");
        scanf("%d",&val);
        add(Q,val);
    }
    else if(key==3)
    {
        if(Q==NULL)
        {
            printf("Sorry..!! First initialize Queue\n");
            break;
        }
        printf("Peek Element is : %d\n",peek(Q));
    }
    else if(key==4)
    {
        free(Q);
        exit(0);
    }
    else{
        printf("Enter Valid case\n");
    }
    }
    return 0;

}