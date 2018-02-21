#ifndef GRAPH_H
#define GRAPH_H

struct node
{
    char vertex;
    /*
        Súlyozott csúcspont esetén
        int vertex;
        int weight;
    */
    struct node *next;
};

struct node *gnode;

void displayGraph(struct node *adj[], int no_of_nodes);
void deleteGraph(struct node *adj[], int no_of_nodes);
void createGraph(struct node *adj[], int no_of_nodes);

#endif //GRAPH_H