#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "./header/konstansok.h"
#include "./header/graf.h"

/*

    FUTTATÁSHOZ SZÜKSÉGES PARANCS:

    Linux alatt:
    gcc -Wall -std=c11 -o ./main.out -g ./main.c ./header/graf.h ./header/graf.c ./header/konstansok.h -lm

    windows alatt: nem tudomm, de csak az utvonalat kell változtatni
*/

int graph[NUMBER_OF_NODE][NUMBER_OF_NODE];

int main()
{
    srand(time(NULL));
    clock_t begin = clock();

    int count = 0;
    int* pCount = &count;

    generatingGraph(graph, pCount);
    
    clock_t end = clock();

    double runningTimeInSec = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("A program befejeződött! Futási idő (sec): %1.2fs", runningTimeInSec);
    getchar();
    return 0;
}