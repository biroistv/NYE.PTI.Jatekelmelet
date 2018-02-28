#include "graf.h"

#include <stdlib.h>
#include "stdio.h"
#include <string.h>

void generateGraph(short graphMatrix[NUMBER_OF_NODES][NUMBER_OF_NODES], Graph graphAttributes[NUMBER_OF_NODES], int *pStarterGraphSize)
{

    for (int i = 0; i < 100; ++i)
    {
        printf("%d.\n",i + 1);
        *pStarterGraphSize = STARTER_GRAPH_SIZE;
        resetGraph(graphMatrix);
        nodeAttributesReset(graphAttributes);

        generateStarterGraph(graphMatrix, graphAttributes, pStarterGraphSize);      

        perror("Starting add new nodes");
        while (*pStarterGraphSize <= NUMBER_OF_NODES)
        {
            ++(*pStarterGraphSize);
            addNode(graphMatrix, graphAttributes, pStarterGraphSize);
        }
        perror("Finishing add new nodes");

        printGraph(graphMatrix, i);

        printf("\n");
    }

    return;
} // !generateGraph

void resetGraph(short graphMatrix[NUMBER_OF_NODES][NUMBER_OF_NODES])
{
    for (int x = 0; x < NUMBER_OF_NODES; ++x)
        for (int y = 0; y < NUMBER_OF_NODES; ++y)
            graphMatrix[x][y] = (short)0;

    perror("Resetting graph");
    return;
}   // !resetGraph

void consolePrintOut(short graphMatrix[NUMBER_OF_NODES][NUMBER_OF_NODES], Graph graphAttributes[NUMBER_OF_NODES])
{
    for (int x = 0; x < NUMBER_OF_NODES; ++x)
        {
            for (int y = 0; y < NUMBER_OF_NODES; ++y)
            {
            }

            printf("{s:%d,e:%1.3f}\n", graphAttributes[x].numberOfNeighbours, graphAttributes[x].connectionChance);
        }
    
    return;
}   // !consolePrintOut

void generateStarterGraph(short graphMatrix[NUMBER_OF_NODES][NUMBER_OF_NODES], Graph graphAttributes[NUMBER_OF_NODES], int* pStarterGraphSize)
{
    for (int x = 0; x < *pStarterGraphSize; ++x)
        for (int y = 0; y < *pStarterGraphSize; ++y)
            if (y > x)
            {
                if (isNeighbour(CONNECTION_CHANCE * 100))
                {
                    short weight = rand() % MAX_WEIGHT + MIN_WEIGHT;
                    graphMatrix[x][y] = weight;
                    graphMatrix[y][x] = weight;
                }
            }
    
    setNodeAttributes(graphMatrix, graphAttributes, pStarterGraphSize);

    perror("Starting the 'starter graph' generator");

    return;
} // !generateStarterGraph

void setNodeAttributes(short graphMatrix[NUMBER_OF_NODES][NUMBER_OF_NODES], Graph graphAttributes[NUMBER_OF_NODES], int* pStarterGraphSize)
{
    for (int x = 0; x < *pStarterGraphSize; ++x)
    {
        short numberOfNeighbours = 0;

        for (int y = 0; y < *pStarterGraphSize; ++y)
            if (graphMatrix[x][y] > 0)
            {
                ++numberOfNeighbours;  
            }

        graphAttributes[x].numberOfNeighbours = numberOfNeighbours;
    }

    for (int i = 0; i < *pStarterGraphSize; ++i)
        graphAttributes[i].connectionChance = graphAttributes[i].numberOfNeighbours * (((float)(*pStarterGraphSize) / getNeighbourSum(graphAttributes, pStarterGraphSize)) / (float)*pStarterGraphSize);

    return;
}// !setNodeAttributes

boolean isNeighbour(float chance) { return rand()%101 <= chance; }

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

    perror("Resetting node attributes");
    return;
}   // !nodeAttributesReset

void addNode(short graphMatrix[NUMBER_OF_NODES][NUMBER_OF_NODES], Graph graphAttributes[NUMBER_OF_NODES], int* pStarterGraphSize)
{
    boolean gotANeighbour = False;
    int x = 0;

    while (!gotANeighbour)
    {
         x = rand()%*pStarterGraphSize;

        if (isNeighbour((graphAttributes[x].connectionChance * 100)))
            {
                short weight = rand() % MAX_WEIGHT + MIN_WEIGHT;
                graphMatrix[x][*pStarterGraphSize-1] = weight;
                graphMatrix[*pStarterGraphSize-1][x] = weight;

                gotANeighbour = True;
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

// TODO: Nem a mátrix bejárásával visszakapni a szomszédok számát hanem a node attribútumokból
void printGraph(short graphMatrix[NUMBER_OF_NODES][NUMBER_OF_NODES], int num)
{
    char filename[150];
    char numbering[7];

    strcpy(filename, save_path);
    int iValue = num;
    snprintf(numbering, sizeof(numbering), "%d", iValue);
    strcat(filename, numbering);
    strcat(filename, ".txt"); 
    
    FILE* fp1 = fopen(filename, "w");
    
    if (fp1 == NULL) 
    {
        perror("Error printed by perror");
    } 
    else 
    {
        perror("Opening the output file");
        int countOfNeighbours = 0;

        for (int x = 0; x < NUMBER_OF_NODES; ++x)
        {
            countOfNeighbours = 0;
            for (int y = 0; y < NUMBER_OF_NODES; ++y)
            {
                    if (graphMatrix[x][y] > 0)
                    {
                        countOfNeighbours++;
                    }
            }

        //float value = ((float)countOfNeighbours  / NUMBER_OF_NODE);

        fprintf(fp1, "%d\n", countOfNeighbours);
        }

        fclose(fp1);
        perror("Closing the output file");
    }

    perror("Printing values in the output file");
    return;
}