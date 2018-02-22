#include <stdio.h>
#include <stdlib.h>

#include "./header/const.h"

int main()
{
    srand(time(NULL));
    
    int starterGraphSize = 10;
    int *pStarterGraphSize = &starterGraphSize;

    short graphMatrix[NUMBER_OF_NODES][NUMBER_OF_NODES];
    Graph graphAttributes[NUMBER_OF_NODES];

    generateGraph(graphMatrix, graphAttributes , pStarterGraphSize);
    
    printf("A program lefutott, nyomj egy gombot a kilépéshez!");
    getchar();
    return 0;
}