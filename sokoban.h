#ifndef _SOKOBAN_H
#define _SOKOBAN_H
#include "gestion_plateau.h"

enum {VIDE = ' ', MANU='@', CAISSE='$', CIBLE='.', MUR='#', CAISSESURCIBLE='&', MANUSURCIBLE='!'};
enum {Haut, Bas, Droite , Gauche};

int PousserCaisse(char ** Plateau ,int direction, int x, int y);
int DeplacerManu(char ** Plateau, int direction, int x, int y);

#endif
