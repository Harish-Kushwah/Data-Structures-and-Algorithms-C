//create a graph using adjacency list
#include<stdio.h>
#include<stdlib.h>
#include "Queue.h"

#define N 20

typedef struct Node
{
    int val;
    struct Node *next;
}Node;

Node *insert(Node *head,int val)
{
    Node *newnode=NULL,*temp=NULL;
    newnode=(Node *)malloc(sizeof(Node));
    newnode->val=val;
    newnode->next=NULL;
    if(head==NULL)
    {
        head=temp=newnode;
    }
    else{
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
        temp=newnode;
    }
    return head;
}
Node *graph[N];
//input graph
void inputGraph()
{
     for(int i=1;i<=N;i++){
        graph[i]=NULL;
    }
    int ver,edg;
    printf("Enter total vertex :");
    scanf("%d",&ver);
    printf("Enter total edges :");
    scanf("%d",&edg);
    for(int i=1;i<=edg;i++){
        int x,y;
        printf("Enter x to y :");
        scanf("%d%d",&x,&y);
        graph[x]=insert(graph[x],y);
        graph[y]=insert(graph[y],x);
    }

}
//DFS traversal
int vis[N];
void dfs(int vertex)
{
       printf("%d ",vertex);
       vis[vertex]=1;
       for(Node *child=graph[vertex];child!=NULL;child=child->next){
            if(vis[child->val]) continue;

            dfs(child->val);
       }
}

//BSF traversal
int vis1[N];
void bfs(int source)
{
    Queue *qu=init();
    add(qu,source);
    add(qu,-1);
    vis1[source]=1;

    while (!isEmpty(qu))
    {
        int currentVertex=remove_ele(qu);
        if(currentVertex==-1){
            printf("\n");
            if(isEmpty(qu)){
                break;
            }
            else{
              add(qu,-1);
            }
        }
        else{
        printf("%d ",currentVertex);
        for(Node *child=graph[currentVertex];child!=NULL;child=child->next){
            if(!vis1[child->val]){
                add(qu,child->val);
                vis1[child->val]=1;
               
            }
        }
        }
    }   
}
