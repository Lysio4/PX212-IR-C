#ifndef _UTILS_H
#define _UTILS_H

#include "game.h"
#include "gestion_plateau.h"
#include "sokoban.h"

extern int CaisseRestante;
extern Coordonnees PosManu;

int objectif(char **plateau,int Largeur, int Longueur);
int finNiveau(int Niveau);
int sauvegardeNiveau(char **plateau,int Largeur, int Longueur);

#endif
