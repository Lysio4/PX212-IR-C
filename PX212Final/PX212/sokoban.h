#ifndef _SOKOBAN_H
#define _SOKOBAN_H
#include "gestion_plateau.h"

enum {VIDE = ' ', MANU='@', CAISSE='$', CIBLE='.', MUR='#', CAISSESURCIBLE='*', MANUSURCIBLE='!'};
enum {Haut, Bas, Droite , Gauche};

int pousserCaisse(char ** Plateau ,int direction, int x, int y);
int deplacerManu(char ** Plateau, int direction, int x, int y);

#endif
