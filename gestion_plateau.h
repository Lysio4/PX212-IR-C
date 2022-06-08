#ifndef _GESTION_PLATEAU_H
#define _GESTION_PLATEAU_H

//Simon.c
typedef struct Coordonnees{
	int x;
	int y;
}Coordonnees;

int trouver_level(int niveau);
int taille_longueur(int niveau);
int taille_largeur(int niveau);
char ** afficher_plateau(int niveau);
Coordonnees position(char ** Plateau, int Longueur, int Largeur);
int LargeurV2(char **Plateau, int Longueur);


#endif
