#include <stdio.h>
#include <stdlib.h>

#include "./header/const.h"

int main()
{
    srand(time(NULL));

    printf("\nSolution 2:\n\n");

    int starterGraphSize = 5;
    int *pStarterGraphSize = &starterGraphSize;

    short graphMatrix[NUMBER_OF_NODES][NUMBER_OF_NODES];
    Graph graphAttributes[NUMBER_OF_NODES];

    generateGraph(graphMatrix, graphAttributes , pStarterGraphSize);
    

    getchar();
    return 0;
}