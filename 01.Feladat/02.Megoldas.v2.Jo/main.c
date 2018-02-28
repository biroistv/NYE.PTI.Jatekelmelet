#include <stdio.h>
#include <stdlib.h>

#include <time.h>

#include "./header/const.h"
#include "./header/graf.h"

int main()
{
    srand(time(NULL));
    
    int starterGraphSize = STARTER_GRAPH_SIZE;
    int *pStarterGraphSize = &starterGraphSize;

    short graphMatrix[NUMBER_OF_NODES][NUMBER_OF_NODES];
    Graph graphAttributes[NUMBER_OF_NODES];

    generateGraph(graphMatrix, graphAttributes , pStarterGraphSize);
    
    printf("A program lefutott, nyomj egy gombot a kilépéshez!");
    getchar();
    return 0;
}