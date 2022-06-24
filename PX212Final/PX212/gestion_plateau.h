#ifndef _GESTION_PLATEAU_H
#define _GESTION_PLATEAU_H
#include "game.h"

int dernierLevel();
int trouverLevel(int Niveau);
int tailleLongueur(int Niveau);
int tailleLargeur(int Niveau);
char ** afficherPlateau(int niveau);
Coordonnees position(char ** Plateau, int Longueur, int Largeur);
int largeurV2(char **Plateau, int Longueur);



#endif
