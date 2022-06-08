#ifndef _UTILS_H
#define _UTILS_H
#include "sokoban.h"
extern int Niveau;
extern int CaisseRestante;

void Objectif(char **plateau,int Largeur, int Longueur);
void FinNiveau(char **plateau);
int SauvegardeNiveau(char **plateau,int Largeur, int Longueur);

#endif
