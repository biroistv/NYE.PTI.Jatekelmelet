#include "graf.h"

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>

void generatingGraph(int graphMatrix[NUMBER_OF_NODE][NUMBER_OF_NODE], int* count)
{
    while ((*count) < NUMBER_OF_TESTS)
    {   
        printf("%d. Graph generation is started!\n",*count + 1);
        perror("Simulation start");
        resetGraph(graphMatrix);
        setNodes(graphMatrix);
        printGraph(graphMatrix, (*count));
        ++(*count);
        printf("%d. Graph generation is finished!\n\n", *count);
    }

    
    return;
}

void resetGraph(int graphMatrix[NUMBER_OF_NODE][NUMBER_OF_NODE])
{
    for (int x = 0; x < NUMBER_OF_NODE; ++x)
        for (int y = 0; y < NUMBER_OF_NODE; ++y)
            graphMatrix[y][x] = 0;     

    perror("Reset the graph");

    return;
}

void setNodes(int graphMatrix[NUMBER_OF_NODE][NUMBER_OF_NODE])
{
    for (int x = 0; x < NUMBER_OF_NODE; ++x)
        for (int y = 0; y < NUMBER_OF_NODE; ++y)
        {
            if (x <= y)
                graphMatrix[x][y] = 0;
            else
            {
                if (isNeighbour())
                {
                    int weight = rand() % MAX_WEIGHT + MIN_WEIGHT;
                    graphMatrix[x][y] = weight;
                    graphMatrix[y][x] = weight;
                }
            }
        }

    perror("Setting the neighbours");

    return;
}

void printGraph(const int graphMatrix[NUMBER_OF_NODE][NUMBER_OF_NODE], const int count)
{
    
    char filename[150];
    char numbering[7];

    strcpy(filename, save_path);
    int iValue = count;
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
        perror("File open");
        int countOfNeighbours = 0;

        for (int x = 0; x < NUMBER_OF_NODE; ++x)
        {
            countOfNeighbours = 0;
            for (int y = 0; y < NUMBER_OF_NODE; ++y)
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
        perror("File closing");
    }

    perror("Printing values in the output file");
    return;
}

boolean isNeighbour() { return rand()%101 <= CONNECTION_CHANCE; }