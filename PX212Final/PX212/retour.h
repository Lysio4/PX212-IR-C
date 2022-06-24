#ifndef _RETOUR_H
#define _RETOUR_H

#include "pile.h"
#include "sokoban.h"
#include "game.h"

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define QUIT 113
#define RESTART 'r'
#define CANCEL 'c'

extern int RetourPouss;
extern int RetourMouv;
extern Coordonnees PosManu;

void retour(char ** Plateau,Lnode **move);

#endif
