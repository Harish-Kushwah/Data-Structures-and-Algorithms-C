# Graph
[![C](https://img.shields.io/badge/language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))

This branch contains the implementation of Dynamic a Graph in C. A Graph is a Non linear data structure where elements are stored as nodes, each containing a value and a pointer next node.


## Graph
A Graph is a Non linear data structure consisting of a collection of nodes, where each node contains a value and a pointer to next node
```c
//Node structure of Graph 
typedef struct Node
{
    int val;
    struct Node *next;
}Node;
```

### Functionality

The following table provides an overview of the functions available in the Graph implementation:

| Function          | Description                                       |Link|
|-------------------|---------------------------------------------------|-----|
| `insert`          | Insert the node into graph. |[click here](#insert) |
| `inputGraph`     | Input the graph the Graph           |[click here](#inputgraph)|
|`DFS`|Depth First Search Traversal of Graph.|[click here](#dfs)|
|`BFS`|BFS Traversal of Graph.|[click here](#bsf)|



| File         | Description                                       |Link|
|-------------------|---------------------------------------------------|-----|
| `graph.h`          | Contain all the functions  |[click here](src/graph.h) |
| `queue.h`          | Contain all the functions  |[click here](src/queue.h) |
| `main.c`          | Usage of all function  |[click here](src/main.c) |

---
<a name="insert"></a>
#### insert()

```c
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
```
---
<a name="inputgraph"></a>
#### inputGraph()

```c
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
```
---

<a name="dfs"></a>
#### dfs()

```c
void dfs(int vertex)
{
       printf("%d ",vertex);
       vis[vertex]=1;
       for(Node *child=graph[vertex];child!=NULL;child=child->next){
            if(vis[child->val]) continue;

            dfs(child->val);
       }
}

```
---
<a name="bsf"></a>
#### bsf()

```c
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
```
---

## Contributing

Contributions, bug reports, and suggestions are welcome! If you encounter any issues, have ideas for improvement, or would like to contribute to this project, please follow the guidelines in [CONTRIBUTE.md](https://github.com/Harish-Kushwah/Data-Structures-and-Algorithms-C/blob/Tree/contribute.md).

## License

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

This repository is licensed under the MIT License. See the [LICENSE](LICENSE) file for more information.

## Contact
For any questions or feedback, feel free to reach out to us at harishkushwah54321@gmail.com

