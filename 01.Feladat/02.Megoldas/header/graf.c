#include "graf.h"

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/*
    A gráf generálásáért és egyébb a gráfon végzett műveletért velelős függvény.
*/
void generateGraph(short graphMatrix[NUMBER_OF_NODES][NUMBER_OF_NODES], Graph graphAttributes[NUMBER_OF_NODES], int *pStarterGraphSize)
{
    resetGraph(graphMatrix);
    nodeAttributesReset(graphAttributes);

    //printf("\n\nKezdő gráf megadása után a mátrix:\n");
    generateStarterGraph(graphMatrix, graphAttributes, pStarterGraphSize);

    FILE* fp1 = fopen(output, "w");
    int counter = 1;

    while (*pStarterGraphSize <= NUMBER_OF_NODES)
    {
        addNode(graphMatrix, graphAttributes, pStarterGraphSize);

        ++(*pStarterGraphSize);
        
        fprintf(fp1, "%d\t%d\n", counter, getTreeCost(1, graphMatrix, graphAttributes, pStarterGraphSize));

        ++counter;
    }

    //consolePrintOut(graphMatrix, graphAttributes);

    fclose(fp1);

    return;
} // !generateGraph

/*
    Beállítja a gráf csúcsainak értékeit nullára
*/
void resetGraph(short graphMatrix[NUMBER_OF_NODES][NUMBER_OF_NODES])
{
    for (int x = 0; x < NUMBER_OF_NODES; ++x)
        for (int y = 0; y < NUMBER_OF_NODES; ++y)
        {
            graphMatrix[x][y] = (short)0;
        }

    return;
}   // !resetGraph

/*
    Részeredmények konzolra iratása
*/
void consolePrintOut(short graphMatrix[NUMBER_OF_NODES][NUMBER_OF_NODES], Graph graphAttributes[NUMBER_OF_NODES])
{
    for (int x = 0; x < NUMBER_OF_NODES; ++x)
        {
            for (int y = 0; y < NUMBER_OF_NODES; ++y)
            {
                printf("%d ", graphMatrix[x][y]);
                //printf("{s:%d,e:%1.2f} ", graphMatrix[x][y].szomszedokSzama, graphMatrix[x][y].esely);
            }

            printf("{s:%d,e:%1.3f}\n", graphAttributes[x].numberOfNeighbours, graphAttributes[x].connectionChance);
        }
    
    return;
}   // !consolePrintOut

/*
    Elkészítem a kezdő gráfot
*/
void generateStarterGraph(short graphMatrix[NUMBER_OF_NODES][NUMBER_OF_NODES], Graph graphAttributes[NUMBER_OF_NODES], int* pStarterGraphSize)
{
    //srand(time(NULL));

    for (int x = 0; x < *pStarterGraphSize; ++x)
        for (int y = 0; y < *pStarterGraphSize; ++y)
            if (x <= y)
                graphMatrix[y][x] = (short)0;
            else
            {
                if (isNeighbour(CONNECTION_CHANCE * 100))
                {
                    short weight = rand() % MAX_WEIGHT + MIN_WEIGHT;
                    graphMatrix[y][x] = weight;
                    graphMatrix[x][y] = weight;
                }
            }

    setNodeAttributes(graphMatrix, graphAttributes, pStarterGraphSize);

    return;
} // !generateStarterGraph

/*
    Megnézem az új csúcs értékeket és módosítim a meglévőket
*/
void setNodeAttributes(short graphMatrix[NUMBER_OF_NODES][NUMBER_OF_NODES], Graph graphAttributes[NUMBER_OF_NODES], int* pStarterGraphSize)
{
    for (int x = 0; x < *pStarterGraphSize; ++x)
    {
        short numberOfNeighbours = 0;

        for (int y = 0; y < *pStarterGraphSize; ++y)
            if (graphMatrix[x][y] > 0)
            {
                // graphMatrix[y][x].ertek = 0;
                ++numberOfNeighbours;  
            }

        // ESÉLY megadása a csúcspontok száma alapján
        graphAttributes[x].numberOfNeighbours = numberOfNeighbours;
    }

    for (int i = 0; i < *pStarterGraphSize; ++i)
        graphAttributes[i].connectionChance = graphAttributes[i].numberOfNeighbours * (((float)(*pStarterGraphSize) / getNeighbourSum(graphAttributes, pStarterGraphSize)) / (float)*pStarterGraphSize);

    return;
}// !setNodeAttributes

/*
    Kezdő gráf létrehozásánal használt véletlen szám generátor
*/
boolean isNeighbour(float chance) { return rand()%101 <= chance; }

/*
    Visszaadja a szomszédok összegét
*/
int getNeighbourSum(Graph graphAttributes[NUMBER_OF_NODES], int* pStarterGraphSize)
{
    int sum = 0;
    for (int i = 0; i < *pStarterGraphSize; ++i)
    {
        sum += graphAttributes[i].numberOfNeighbours;
    }

    return sum;
}   // !getNeighbourSum

void nodeAttributesReset(Graph graphAttributes[NUMBER_OF_NODES])
{
    for (int i = 0; i < NUMBER_OF_NODES; ++i)
    {
        graphAttributes[i].connectionChance = 0.f;
        graphAttributes[i].numberOfNeighbours = 0;
    }

    return;
}   // !nodeAttributesReset

void addNode(short graphMatrix[NUMBER_OF_NODES][NUMBER_OF_NODES], Graph graphAttributes[NUMBER_OF_NODES], int* pStarterGraphSize)
{
    for (int x = 0; x < *pStarterGraphSize; ++x)
        for (int y = (*pStarterGraphSize); y < *pStarterGraphSize + 1; ++y)
            if (x >= y)
                graphMatrix[x][y] = (short)0;
            else
            {
                float chance = graphAttributes[x].connectionChance;
                if (isNeighbour(chance * 100))
                {
                    short weight = rand() % MAX_WEIGHT + MIN_WEIGHT;
                    graphMatrix[x][y] = weight;
                    graphMatrix[y][x] = weight;
                }
            }

    setNodeAttributes(graphMatrix, graphAttributes, pStarterGraphSize);

    return;
}   // !addNode
/*
-----------------------------------------------------------------------------
*/

int getTreeCost(int src, short graphMatrix[NUMBER_OF_NODES][NUMBER_OF_NODES], Graph graphAttributes[NUMBER_OF_NODES], int* pStarterGraphSize)
{
    int treeCost = 0;

    for (int x = 0; x < *pStarterGraphSize; ++x)
        for (int y = 0; y < NUMBER_OF_NODES; ++y)
            if (x <= y)
            {
                //graphMatrix[y][x] = (short)0;
            }
            else
            {
                if (graphMatrix[x][y] > 0)
                    treeCost += graphMatrix[x][y];
            }

    return treeCost;
}   // !getTreeCost