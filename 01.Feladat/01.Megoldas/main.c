#include <stdlib.h>
#include <stdio.h>

#include "./header/konstansok.h"
#include "./header/graf.h"

/*

    FUTTATÁSHOZ SZÜKSÉGES PARANCS:

    Linux alatt:
    gcc -Wall -std=c11 -o ./main.out -g ./main.c ./header/graf.h ./header/graf.c ./header/konstansok.h

    windows alatt: nem tudomm, de csak az utvonalat kell változtatni
*/

int Graf[CSUCSOK_SZAMA][CSUCSOK_SZAMA];

int main()
{
    srand(time(NULL));

    grafGeneralasa(Graf);
    
    //getchar();
    return 0;
}