/*
Q2. Implement a priority queue library (PriorityQ.h) of integers using a static 
implementation  of  the  queue  and  implementing  the  below  two  operations. 
Write  a  driver  program  that  includes  queue  library  and  calls  different  queue 
operations. 
1) Add an element with its priority into the queue. 
2) Delete an element from queue according to its priority.
*/
#include "PriorityQ.h"

void menu()
{
    printf("1]Enter to Enqueue \n");
    printf("2]Enter to dequeue \n");
    printf("3]Enter to Exit");
}
int main()
{
    Pqueue *pq=init();
    menu();
    while(1)
    {
        int key;
        printf("Enter key :");
        scanf("%d",&key);
        if(key==1)
        {
            int val,prio;
            printf("Enter value :");
            scanf("%d",&val);
            printf("Enter it's priority:");
            scanf("%d",&prio);
            enqueue(pq,val,prio);
        }
        else if(key==2)
        {
            printf("%d is Dequeued Element",dequeue(pq));
        }
        else{
            exit(0);
        }
        
    }
    return 0;

}