#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include "board.h"

#define PROF container[pozition[3]][pozition[2]] == ' '

int check_strokes(int* pozition, char** container) {
    char i = tolower(container[pozition[1]][pozition[0]]);
    int k, g1, g2;
    int xy[8][2] = {{1,-2},{1, 2},{-1,-2},{-1, 2},{2,-1},{2, 1},{-2, 1},{-2,-1}};
    switch (i) {
        case 'p': // Пешка
            g1 = pozition[3] - pozition[1]; 
            g2 = pozition[2] - pozition[0];
            if (( pow( g1, 2 ) == 1 ||pow( g1, 2 ) == 0 || pow( g1, 2 ) == 4 ) && (g2 == 0 )) {
                if (PROF) {
                    return 0;
                }
            }
            break;
        case 'r': // Ладья
            if ((pozition[1] == pozition[3] && pozition[0] != pozition[2]) && PROF) {
                return 0;
            } else if ((pozition[1] != pozition[3] && pozition[0] == pozition[2]) && PROF) {
                return 0;
            }
            break;
        case 'n': // Конь
            for (k = 0; k <= 7; k++) {
                if (pozition[0] + xy[k][0] == pozition[2]) {
                    if (pozition[1] + xy[k][1] == pozition[3]) {
                        if (PROF) {
                            return 0;
                        }
                    }
                }
            }
            break;
        case 'b': // Слон  
            if (pow(pozition[2] - pozition[0], 2) == pow(pozition[3] - pozition[1], 2)) {
                if (PROF) {
                    return 0;
                }
            }   
            break;
        case 'q': // Ферзь
            if ((pow(pozition[2] - pozition[0], 2) == pow(pozition[3] - pozition[1], 2))
            || (pozition[1] == pozition[3] && pozition[0] != pozition[2]) ||
            (pozition[1] != pozition[3] && pozition[0] == pozition[2])) {
                if (PROF) {
                    return 0;
                }
            }
            break;
        case 'k': // Король
            g1 = pozition[2] - pozition[0];
            g2 = pozition[3] - pozition[1];
            if (( pow(g1, 2) == 1 || pow(g1, 2) == 0 ) && 
            ( pow(g2, 2) == 0 || pow(g2, 2) == 1 )) {
                if (PROF) {
                return 0;
                }
            }
            break;
    }
    return -1;   
}