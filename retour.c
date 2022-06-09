#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "retour.h"
#include "sokoban.h"

/**
*redo() permet de revenir en arrière d'une action, selon la direction du dernier mouvement.
*/
void redo(Lnode **ph, char **Plateau){
    if (*ph != NULL){
    switch((*ph)->direction){
        case Haut :
        DeplacerManu(Plateau, Bas, (*ph)->data.x, ((*ph)->data.y)-1);
        break;
        case Bas :
        DeplacerManu(Plateau, Haut, (*ph)->data.x, ((*ph)->data.y)+1);
        break;
        case Gauche :
        DeplacerManu(Plateau, Droite, ((*ph)->data.x)+1, (*ph)->data.y);
        break;
        case Droite :
        DeplacerManu(Plateau, Gauche, ((*ph)->data.x)-1, (*ph)->data.y);
        break;
    }
    suppressionTete(ph);
    }
}
