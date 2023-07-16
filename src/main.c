#include "graph.h"

int main()
{
    //dynamic graph input
    inputGraph();

    //traverse the graph
    int starting_vertex;
    printf("Enter starting vertex for DFS traversal of graph :");
    scanf("%d",&starting_vertex);
    printf("DFS Traversal : ");
    dfs(starting_vertex);


    //traverse the graph
    printf("\nEnter starting vertex for BFS traversal of graph :");
    scanf("%d",&starting_vertex);
    printf("BFS Traversal : \n");
    bfs(starting_vertex);
    
}