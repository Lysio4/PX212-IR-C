#include <stdlib.h>
#include <stdio.h>
#include "header.h"

#define NIV 50

int PousserCaisse(int direction, int x, int y);
int DeplacerManu(int direction);

int ascii_touche;
Coordonnees points;

void touches(int niveau){
  configureTerminal();
  int x;
  int y;
    ascii_touche = litClavier();
    switch(ascii_touche){
        case 1: //up arrow A
        //printf("Flèche haut\n");
        points = position(niveau);
        x = points.x;
        y = points.y;
        PousserCaisse(Haut, x, y);
        break;
        case 2: //down arrow B
        //printf("Flèche bas\n");
        break;
        case 3: //right arrow C
        //printf("Flèche droite\n");
        break;
        case 4: //left arrow D
        //printf("Flèche gauche\n");
        break;
        case 8: //delete
        printf("Delete\n");
        break;
        case 10: //entrée
        printf("Entrée\n");
        break;
        default:
        printf("Autre\n");
        break;
    }
}

int main(){
  printf("Je code le Sokoban OMEGALUL\n");
  while (true) {
    touches(NIV);
  }
  return 0;
}
