#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include "move_fig.h"

#define CONTAINER container[pozition[3]][pozition[2]] == ' '

int move_figure(int* pozition, char** container) {
    char i = tolower(container[pozition[1]][pozition[0]]);
    int k, g1, g2;
    int coordinates[8][2] = {{1,-2},{1, 2},{-1,-2},{-1, 2},{2,-1},{2, 1},{-2, 1},{-2,-1}};
    
    if( i == 'p'){//пешка
	 g1 = pozition[3] - pozition[1]; 
            g2 = pozition[2] - pozition[0];
            if (( pow( g1, 2 ) == 1 ||pow( g1, 2 ) == 0 || pow( g1, 2 ) == 4 ) && (g2 == 0 )) {
                if (CONTAINER) {
                    return 0;
                }
            } 
    }else if (i == 'r'){//Ладья
	if ((pozition[1] == pozition[3] && pozition[0] != pozition[2]) && CONTAINER) {
                return 0;
            } else if ((pozition[1] != pozition[3] && pozition[0] == pozition[2]) && CONTAINER) {
                return 0;
            } 
   }else if(i == 'h'){// Конь
       for (k = 0; k <= 7; k++) {
            if (pozition[0] + coordinates[k][0] == pozition[2]) {
                if (pozition[1] + coordinates[k][1] == pozition[3]) {
                    if (CONTAINER){
                            return 0;
                    }
                }
            }
        }
    }else if (i == 'e'){ //Слон
	if (pow(pozition[2] - pozition[0], 2) == pow(pozition[3] - pozition[1], 2)){
                if (CONTAINER) {
                    return 0;
                }
            }   
    }else if(i == 'q'){ //Ферзь
	if ((pow(pozition[2] - pozition[0], 2) == pow(pozition[3] - pozition[1], 2))
            || (pozition[1] == pozition[3] && pozition[0] != pozition[2]) ||
            (pozition[1] != pozition[3] && pozition[0] == pozition[2])) {
                if (CONTAINER) {
                    return 0;
                }
            }
     }else if(i == 'k'){ //Король
        g1 = pozition[2] - pozition[0];
            g2 = pozition[3] - pozition[1];
            if (( pow(g1, 2) == 1 || pow(g1, 2) == 0 ) && 
            ( pow(g2, 2) == 0 || pow(g2, 2) == 1 )) {
                if (CONTAINER) {
                return 0;
                }
            }
      }
      return -1;
}