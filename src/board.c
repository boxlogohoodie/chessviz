#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "board.h"
#include "move_fig.h"

char **arr;

char **board() {
    arr = (char**) malloc(8 * sizeof(char*));
    int i,j;
    
    for (i = 0;i < 8; i++) {
        arr[i] = (char*) malloc(8 * sizeof(char));
        for (j = 0;j < 8; j++) {
            arr[i][j] = ' ';
        }
    }
    
    char g1[] = {'r','h','e','q','k','e','h','r'};
    char p = 'p';
    
    for (i = 0;i < 8; i++) {
        arr[0][i] = g1[i];
        arr[7][i] = g1[i] - 32;
        arr[1][i] = p;
        arr[6][i] = p - 32;
    }
    return arr;
}

void  print_new_board() {
    arr = board();
    print_board(arr);
}

void print_board(char **arr) {
    system("clear");
    printf("\n");
    for (int i = 0;i < 8; i++) {
        printf("\t %d", 8 - i);
        for (int j = 0;j < 8; j++) {
            printf(" %c", arr[i][j]);
        }
        printf("\n");
    }
    
    printf("\t ");
    
    for (char p = 'a'; p <= 'h'; p++) {
        printf(" %c", p);
    }
    
    printf("\n");
}

char** movePawn(char **v, int* pozition) {
    int poz = arr[pozition[1]][pozition[0]];
    arr[pozition[1]][pozition[0]] = arr[pozition[3]][pozition[2]];
    arr[pozition[3]][pozition[2]] = poz;

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
    
    int check = move_figure(pozition, arr);
    if (check == -1) {
        return -1;
    }
    
    for(int g = 0; g < 4; g++) {
        if (pozition[g] < 0 || pozition[g] > 8) {
            return -1;
        }
    }

    arr = movePawn(arr, pozition);
    if (test == 0) {
        print_board(arr);
    }
    return 0;
}

