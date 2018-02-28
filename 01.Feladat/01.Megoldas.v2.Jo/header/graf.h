#ifndef GRAF_H
#define GRAF_H

#include "konstansok.h"

void resetGraph(int graphMatrix[NUMBER_OF_NODE][NUMBER_OF_NODE]);
void generatingGraph(int graphMatrix[NUMBER_OF_NODE][NUMBER_OF_NODE], int* count);
void setNodes(int graphMatrix[NUMBER_OF_NODE][NUMBER_OF_NODE]);
void printGraph(const int graphMatrix[NUMBER_OF_NODE][NUMBER_OF_NODE],const int count);

boolean isNeighbour();

#endif //GRAF_H