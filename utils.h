#ifndef _UTILS_H
#define _UTILS_H
#include "sokoban.h"
#include "game.h"

extern int CaisseRestante;
extern Coordonnees PosManu;

int Objectif(char **plateau,int Largeur, int Longueur);
void FinNiveau(int Niveau);
int SauvegardeNiveau(char **plateau,int Largeur, int Longueur);

#endif
