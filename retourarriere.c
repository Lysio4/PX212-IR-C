#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "retourarriere.h"
#include "sokoban.h"

void redo(Lnode **ph, char **Plateau){
    if (*ph != NULL){
    switch((*ph)->direction){
        case Haut :
        if ((*ph)->deplacement == true)
        {
            //PousserCaisse(Plateau ,Bas, (*ph)->data.x, ((*ph)->data.y)+2);
            DeplacerManu(Plateau, Bas, (*ph)->data.x, ((*ph)->data.y)-1);
        }
        else {
            DeplacerManu(Plateau, Bas, (*ph)->data.x, ((*ph)->data.y)-1);
        }
        break;
        case Bas :
        if ((*ph)->deplacement == true)
        {
            //PousserCaisse(Plateau ,Haut, (*ph)->data.x, ((*ph)->data.y)-2);
            DeplacerManu(Plateau, Haut, (*ph)->data.x, ((*ph)->data.y)+1);
        }
        else{
            DeplacerManu(Plateau, Haut, (*ph)->data.x, ((*ph)->data.y)+1);
        }
        break;
        case Gauche :
        if ((*ph)->deplacement == true)
        {
            //PousserCaisse(Plateau ,Droite, ((*ph)->data.x)+1, (*ph)->data.y);
            DeplacerManu(Plateau, Droite, ((*ph)->data.x)+1, (*ph)->data.y);
        }
        else{
            DeplacerManu(Plateau, Droite, ((*ph)->data.x)+1, (*ph)->data.y);
        }
        break;
        case Droite :
        if ((*ph)->deplacement == true)
        {
            //PousserCaisse(Plateau ,Gauche, ((*ph)->data.x)-1, (*ph)->data.y);
            DeplacerManu(Plateau, Gauche, ((*ph)->data.x)-1, (*ph)->data.y); 
        }
        else{
            DeplacerManu(Plateau, Gauche, ((*ph)->data.x)-1, (*ph)->data.y); 
        }
        break;
    }
    suppressionTete(ph);
    }
}