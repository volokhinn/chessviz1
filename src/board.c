#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "check_str.h"
#include "board.h"

char **container;

char **_board() {
    int i,j;
    container = (char**)malloc(8 * sizeof(char*));
    for (i = 0; i < 8; i++) {
        container[i] = (char*)malloc(8 * sizeof(char));
        for (j = 0; j < 8; j++) {
            container[i][j] = ' ';
        }
    }
    char gl[] = {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'};
    char p = 'p';

    for (i = 0; i < 8; i++) {
        container[0][i] = gl[i];
        container[7][i] = gl[i] - 32;
        container[1][i] = p;
        container[6][i] = p - 32;
    }    
    return container; 
}

void print_new_board() {
    container = _board();
    print_board(container);
}

void print_board() {
    system("clear");
    printf("\n");
    for (int i = 0; i < 8; i++) {
        printf("\t  %s%d%s", RED, 8 - i, RESET);
        for (int j = 0; j < 8; j++) {
            printf(" %c", container[i][j]);
        }
        printf("\n");
    }
    printf("\t   %s", RED);
    for (char p = 'a'; p <= 'h'; p++) {
        printf(" %c", p);
    }
    printf("%s\n", RESET);
}

char** movePawn(char **v, int* pozition) { 
    int poz = container[pozition[1]][pozition[0]];
    container[pozition[1]][pozition[0]] = container[pozition[3]][pozition[2]];
    container[pozition[3]][pozition[2]] = poz;
    return v;
}

int board_func(char *places, int test) {
    if (strlen(places) != 5) {
        return -1;
    }
    int pozition[4];
    pozition[0] = places[0] - 96 - 1; //a
    pozition[1] = 9 - (places[1] - 48) - 1; //2
    pozition[2] = places[3] - 96 - 1; //c
    pozition[3] = 9 - (places[4] - 48) - 1; //8
    printf("\n ");
    int err = check_strokes(pozition, container);
    if (err == -1) { return -1; }

    for(int g = 0; g < 4; g++) {
        if (pozition[g] < 0 || pozition[g] > 8) {
            return -1;
        }
    }
    container = movePawn(container, pozition);
    if (test == 0) {
        print_board(container);
    }
    return 0;
}