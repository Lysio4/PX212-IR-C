#ifndef _GESTION_PLATEAU_H
#define _GESTION_PLATEAU_H
#include "game.h"

int dernier_level();
int trouver_level(int niveau);
int taille_longueur(int niveau);
int taille_largeur(int niveau);
char ** afficher_plateau(int niveau);
Coordonnees position(char ** Plateau, int Longueur, int Largeur);
int LargeurV2(char **Plateau, int Longueur);



#endif
