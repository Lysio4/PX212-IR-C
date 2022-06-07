#include <stdlib.h>
#include <stdio.h>
#include "header.h"

int ascii_touche;

void touches(){
  configureTerminal();
    ascii_touche = litClavier();
    switch(ascii_touche){
        case 1: //up arrow A
        printf("Flèche haut\n");
        break;
        case 2: //down arrow B
        printf("Flèche bas\n");
        break;
        case 3: //right arrow C
        printf("Flèche droite\n");
        break;
        case 4: //left arrow D
        printf("Flèche gauche\n");
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
        //case 13: //enter
        //break;
    }
}

int main(){
  printf("Je code le Sokoban OMEGALUL\n");
  while (true) {
    touches();
  }
  return 0;
}
