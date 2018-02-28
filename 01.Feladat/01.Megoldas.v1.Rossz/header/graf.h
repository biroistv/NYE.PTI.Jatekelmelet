#ifndef GRAF_H
#define GRAF_H

#include "konstansok.h"

void grafNullazasa(int grafMatrix[CSUCSOK_SZAMA][CSUCSOK_SZAMA]);
void grafGeneralasa(int grafMatrix[CSUCSOK_SZAMA][CSUCSOK_SZAMA]);
void grafCsucspontokBeallitasa(int grafMatrix[CSUCSOK_SZAMA][CSUCSOK_SZAMA]);
void printGraf(int grafMatrix[CSUCSOK_SZAMA][CSUCSOK_SZAMA]);

boolean isSzomszed();

#endif //GRAF_H