#include <stdio.h>
#include <stdlib.h>
#include "board.h"


void help_print();
void info_print();
int board_main();

int main() {
//    int egg = 0;
    system("clear");
    char q;
    info_print();
    scanf("%c", &q);
    if (q == 's') {
        board_main();
        return 0;
    } else if (q == 'q'){
        system("clear");
        printf("%sСпасибо за игру!%s\n",RED, RESET);
        return 0;
    } else {
        system("clear");
        main();
    }
    return 0;
}

char places[6];
int exitt = 0;

int board_main() {
    system("clear");
    print_new_board();
    while (exitt == 0) {
        help_print();
        printf("          Напишите координаты фигуры и \n          куда её поставить. Например e2-e4\n");
        printf("\t%s  Ход:\n\t\t ", CYAN);
        scanf("%s", places);
        printf("%s", RESET);
        if (places[0] == 'r') {
            system("clear");
            exitt = 1;
            board_main();
        } else if (places[0] == 'q') {
            system("clear");
            printf("%sСпасибо за игру!%s\n",RED, RESET);
            return 0;
        }
        system("clear");
        exitt = board_func(places, 0);
        if (exitt == -1) {
            print_board();
            if (places[0] == 'r') {
                printf("%s\t\tПерезапущено!\n%s", GREEN, RESET);
            } else {
                printf("%s\tТакой ход невозможен!\n%s", RED, RESET);
            }
            exitt = 0;
        }
    }
    return 0;
}

                    //    scanf("%d", &egg);
                    //    if (egg == 1) {
                    //    printf("Andrey Shiryaew");

void info_print() {

    system("clear");

    printf("%s"
    "\t       ███████╗███╗  ███╗████████╗████████╗████████╗\n"
    "\t      ███╔════╝███║  ███║███╔════╝███╔════╝███╔════╝\n"
    "\t      ███║     █████████║██████╗  ████████╗████████╗\n"
    "\t      ███║     ███╔══███║███╔══╝  ╚════███║╚════███║\n"
    "\t      ╚███████╗███║  ███║████████╗████████║████████║\n"
    "\t       ╚══════╝╚══╝  ╚══╝╚═══════╝╚═══════╝╚═══════╝\n\n%s", GREEN, RESET);


    printf("%s\t\n         Выберите действие\n\n%s", GREEN, RESET);
    printf("\t    %s(s) Старт\n", CYAN);
    printf("\t    %s(q) Выход\n", CYAN);
}

void help_print() {
    printf("\t%s     (r)Вернуться\n\n%s", GRAY, RESET);
}
