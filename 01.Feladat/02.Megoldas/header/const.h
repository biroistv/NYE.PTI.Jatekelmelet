#ifndef CONST_H
#define CONST_H

#define NUMBER_OF_NODES 8 // TODO: Bemenő paraméterként megani
#define CONNECTION_CHANCE 0.70f  // TODO: Bemenő paraméterként megadni
#define output "01_graf_10_90.txt" //TODO: bemenő paraméterként megadni majd

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