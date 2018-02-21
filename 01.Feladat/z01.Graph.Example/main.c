#include <stdlib.h>
#include <stdio.h>

#include "./header/graph.h"

int main()
{
    struct node *adj[10];
    int i, no_of_nodes;

    //clrscr();

    printf("\n Enter the number of nodes in G: ");
    scanf("%d", &no_of_nodes);

    for (i = 0; i < no_of_nodes; ++i)
        adj[i] = NULL;

    createGraph(adj, no_of_nodes);

    printf("\n The graph is: ");
    displayGraph(adj, no_of_nodes);

    deleteGraph(adj, no_of_nodes);

    int iExit;
    scanf("%d", &iExit);
    return 0;
}