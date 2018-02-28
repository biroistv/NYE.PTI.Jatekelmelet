#ifndef CONST_H
#define CONST_H

#define NUMBER_OF_NODES 150
#define STARTER_GRAPH_SIZE 5
#define CONNECTION_CHANCE 1.0f
#define output "./weights_1000.txt"

#define MIN_WEIGHT 1
#define MAX_WEIGHT 9

/*
   Logikai típus
*/
#define True 1
#define False 0
typedef int boolean;

/*
    Csúcs típus az adatok
*/
typedef struct Graph
{
    short numberOfNeighbours;
    float connectionChance;
}Graph;

#endif //CONST_H