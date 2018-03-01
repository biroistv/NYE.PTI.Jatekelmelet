#ifndef GRAF_H
#define GRAF_H

#include "const.h"

/*
    Ez a függbény generálja le a gráfot
*/
void generateGraph(short graphMatrix[NUMBER_OF_NODES][NUMBER_OF_NODES], Graph graphAttributes[NUMBER_OF_NODES], int* pStarterGraphSize);

void resetGraph(short graphMatrix[NUMBER_OF_NODES][NUMBER_OF_NODES]);

void generateStarterGraph(short graphMatrix[NUMBER_OF_NODES][NUMBER_OF_NODES], Graph graphAttributes[NUMBER_OF_NODES], int* pStarterGraphSize);

void setNodeAttributes(short graphMatrix[NUMBER_OF_NODES][NUMBER_OF_NODES], Graph graphAttributes[NUMBER_OF_NODES], int* pStarterGraphSize);

void addNode(short graphMatrix[NUMBER_OF_NODES][NUMBER_OF_NODES], Graph graphAttributes[NUMBER_OF_NODES], int* pStarterGraphSize);

boolean isNeighbour(float chance);

int getNeighbourSum(Graph graphAttributes[NUMBER_OF_NODES], int* pStarterGraphSize);

int getTreeCost(int src, short graphMatrix[NUMBER_OF_NODES][NUMBER_OF_NODES], Graph graphAttributes[NUMBER_OF_NODES], int* pStarterGraphSize); 

void nodeAttributesReset(Graph graphAttributes[NUMBER_OF_NODES]);

int getNumberOfNodes(Graph graphAttributes[NUMBER_OF_NODES], int* pStarterGraphSize);

void printGraph(short graphMatrix[NUMBER_OF_NODES][NUMBER_OF_NODES], int num);

#endif //GRAF_H