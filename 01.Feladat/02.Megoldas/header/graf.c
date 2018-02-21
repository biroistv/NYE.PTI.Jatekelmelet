#include "graf.h"

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// TODO: Írni egy megszámlaló függvény ami megszámolja az egyedi előfordulásokat, C++-ban fogom

short tree[NUMBER_OF_NODES][NUMBER_OF_NODES];

/*
    A gráf generálásáért és egyébb a gráfon végzett műveletért velelős függvény.
*/
void generateGraph(short graphMatrix[NUMBER_OF_NODES][NUMBER_OF_NODES], Graph graphAttributes[NUMBER_OF_NODES], int *pStarterGraphSize)
{
    resetGraph(graphMatrix);
    nodeAttributesReset(graphAttributes);

    printf("\n\nKezdő gráf megadása után a mátrix:\n");
    generateStarterGraph(graphMatrix, graphAttributes, pStarterGraphSize);

    while (*pStarterGraphSize <= NUMBER_OF_NODES)
    {
        addNode(graphMatrix, graphAttributes, pStarterGraphSize);

        ++(*pStarterGraphSize);
        
        printf("Cost: %d\n", getTreeCost(1, graphMatrix, graphAttributes, pStarterGraphSize));
        //vizsgáljuk meg az út távolságot
        //írjuk fájlba a kapott értéket (előbb adjuk egy tömbhöz)
    }

    consolePrintOut(graphMatrix, graphAttributes);

    return;
}

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
}

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
}

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
}

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
}

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
}

void nodeAttributesReset(Graph graphAttributes[NUMBER_OF_NODES])
{
    for (int i = 0; i < NUMBER_OF_NODES; ++i)
    {
        graphAttributes[i].connectionChance = 0.f;
        graphAttributes[i].numberOfNeighbours = 0;
    }

    return;
}

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
}
/*
-----------------------------------------------------------------------------
*/

int getTreeCost(int src, short graphMatrix[NUMBER_OF_NODES][NUMBER_OF_NODES], Graph graphAttributes[NUMBER_OF_NODES], int* pStarterGraphSize)
{
    int visited[NUMBER_OF_NODES], d[NUMBER_OF_NODES], parent[NUMBER_OF_NODES];
    int i,j,k,min,u,v,cost;
    int n = getNumberOfNodes(graphAttributes, pStarterGraphSize); //ezt még majd ki kell számolnom
    for(i = 1; i<= n; i++)
    {
        d[i] = graphMatrix[src][i];
        visited[i] = 0;
        parent[i] = src;
    }

    visited[src] = 0;
    cost = 0;
    k = 1;

    for (i = 1; i < n; i++)
    {
        min = 9999;
        for (j = 1; j <= n; j++)
        {
            if (visited[j]==0 && d[j] < min)
            {
                min = d[j];
                u = j;
                cost += d[u];
            }
        }
        visited[u] = 1;
        //cost = cost + d[u];
        tree[k][1] = parent[u];
        tree[k++][2] = u;
        for ( v = 1; v <= n; v++)
        {
            if (visited[v]==0 && (graphMatrix[u][v] < d[v]))
            {
                d[v] = graphMatrix[u][v];
                parent[v] = u;
            }
        }
    }
    return cost;
}

int getNumberOfNodes(Graph graphAttributes[NUMBER_OF_NODES], int* pStarterGraphSize)
{
    int numberOfNodes = 0;

    for (int i = 0; i < *pStarterGraphSize; ++i)
        if (graphAttributes[i].numberOfNeighbours > 0)
            ++numberOfNodes;

    return numberOfNodes; 
}

// TODO: fájlba iratás