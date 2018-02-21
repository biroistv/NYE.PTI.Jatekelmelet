#include "graf.h"

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/*
    Ezt a függvény hívom meg a main-ből és ez csinál mindent
*/
void grafGeneralasa(int grafMatrix[CSUCSOK_SZAMA][CSUCSOK_SZAMA])
{
    grafNullazasa(grafMatrix);
    grafCsucspontokBeallitasa(grafMatrix);
    printGraf(grafMatrix);

    return;
}

/*
    Csak lenullázom a mátrix elemeit
*/
void grafNullazasa(int grafMatrix[CSUCSOK_SZAMA][CSUCSOK_SZAMA])
{
    for (int x = 0; x < CSUCSOK_SZAMA; ++x)
        for (int y = 0; y < CSUCSOK_SZAMA; ++y)
            grafMatrix[y][x] = 0;     

    return;
}

/*
    Itt generálom a gráfot a konstansok között megadott valószínuségi változóval
*/
void grafCsucspontokBeallitasa(int grafMatrix[CSUCSOK_SZAMA][CSUCSOK_SZAMA])
{
    for (int x = 0; x < CSUCSOK_SZAMA; ++x)
        for (int y = 0; y < CSUCSOK_SZAMA; ++y)
        {
            if (x <= y)
                grafMatrix[y][x] = 0;
            else
            {
                if (isSzomszed())
                {
                    int koltseg = rand() % MAXIMALIS_KOLTSEG + MINIMALIS_KOLTSEG;
                    grafMatrix[y][x] = koltseg;
                    grafMatrix[x][y] = koltseg;
                }
            }
                
        }

    return;
}

/*
    Fájlbaírja az értékeket, ezek az értékek azok, hogy mondjuk 10 szomszéddal mennyi csúcs van, 9-el. stb
*/
void printGraf(int grafMatrix[CSUCSOK_SZAMA][CSUCSOK_SZAMA])
{
    FILE* fp1 = fopen(output, "w");

    int darab = 0;

    for (int x = 0; x < CSUCSOK_SZAMA; ++x)
    {
        darab = 0;
        for (int y = 0; y < CSUCSOK_SZAMA; ++y)
        {
                if (grafMatrix[x][y] > 0)
                {
                    darab++;
                }

        }

	fprintf(fp1, "%d\n", /*((float)*/ darab /* / CSUCSOK_SZAMA)*/);

    }

    fclose(fp1);

    return;
}

/*
    itt nézem meg, hogy beleesik e abba a bizonyos valószínuségbe, iagazat ad vissza ha igen, hamisat ha nem,

    Ha igaz akkor csatlakozik valamihez, ha nem akkor nem
*/
boolean isSzomszed()
{
   int esely = rand()%101;

   return esely <= KAPCSOLODAS_ESELYE; 
}