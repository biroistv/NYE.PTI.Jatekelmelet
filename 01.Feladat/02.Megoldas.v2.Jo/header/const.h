#ifndef CONST_H
#define CONST_H

#define TESZTEK_SZAMA 100
#define NUMBER_OF_NODES 1000
#define STARTER_GRAPH_SIZE 3
#define CONNECTION_CHANCE 1.0f
#define save_path "/home/biro/Dokumentumok/programozas/c/NYE.PTI.Jatekelmelet/01.Feladat/02.Megoldas.v2.Jo/results/res_"

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