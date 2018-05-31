#include <stdio.h>
#include <stdlib.h>
#include "board.h"

int main() {
    system("clear");
    int k = 0,exit;
    char places[6];
    while ( k == 0) {
        char status;
        printf("\t(s) Start or (q) Quit\n");
        scanf("%c", &status);
        if (status == 's') {
            system("clear");
            print_new_board();
            while (exit == 0) {
                printf("Write coordinates or (q) to Quit:\n" );
                scanf("%s", places);
                if (places[0] == 'q') {
                    system("clear");
                    return 0;
                } else {
                    exit = board_func(places, 0);
                    if (exit == -1) {
                        print_new_board();
                        printf("\t  ERROR COORDINATES!\n");
                        exit = 0;
                    }
                }
            }
        } else  if  (status == 'q') {
            system ("clear");
            return 0;
        }
    }
    return 0;
}