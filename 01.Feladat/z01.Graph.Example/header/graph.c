#include "graph.h"

#include <stdlib.h>
#include <stdio.h>

void displayGraph(struct node *adj[], int no_of_nodes)
{
    struct node *ptr;
    int i;
    for (i = 0; i < no_of_nodes; ++i)
    {
        ptr = adj[i];
        printf("\n The neightbours of node %d are:",i);

        while(ptr != NULL)
        {
            printf("\t%d", ptr->vertex);
            ptr = ptr -> next;
        }
    }

    return;
}

void deleteGraph(struct node *adj[], int no_of_nodes)
{
    int i;
    struct node *temp, *ptr;

    for (i = 0; i <= no_of_nodes; ++i)
    {
        ptr = adj[i];
        while(ptr != NULL)
        {
            temp = ptr;
            ptr = ptr -> next;
            free(temp);
        }
        adj[i] = NULL;
    }

    return;
}

void createGraph(struct node *adj[], int no_of_nodes)
{
    struct node *new_node, *last;
    int i, j, n, val;

    for(i = 0; i < no_of_nodes; ++i)
    {
        last = NULL;
        printf("\n Enter the number of neightbours of %d: ", i);
        scanf("%d", &n);

        for(j = 1; j <= n; ++j)
        {
            printf("\n Enter the neightbour %d of %d: ", j, i);
            scanf("%d", &val);
            new_node = (struct node*) malloc(sizeof(struct node));
            new_node -> vertex = val;
            new_node -> next = NULL;

            if (adj[i] == NULL)
                adj[i] = new_node;
            else
                last -> next = new_node;

            last = new_node;
        }
    }

    return;
}