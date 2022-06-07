#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//constantes
#define Taille 100
#define Largeur 100
#define Longueur 100
    enum {VIDE = ' ', MANU='@', CAISSE='$', CIBLE='.', MUR='#', CAISSESURCIBLE='&', MANUSURCIBLE='!'};
    enum {Haut, Bas, Droite , Gauche};

//Simon.c
typedef struct Coordonnees{
	int x;
	int y;
}Coordonnees;

int dernier_level();
int trouver_level(int niveau);
int taille_longueur(int niveau);
int taille_largeur(int niveau);
char ** afficher_plateau(int niveau);
Coordonnees position(int niveau);

//Fonctions.c
void Objectif(char **plateau);
void FinNiveau(char **plateau);
int SauvegardeNiveau(char **plateau);

//sokoban.c
int PousserCaisse(int direction, int x, int y);
int DeplacerManu(int direction);

//io.c + touches.c
int configureTerminal();
int litClavier();
int test();
void touches(int niveau);

//pile.c
typedef struct node {
		char data ;
		struct node *link ;
		} Lnode ;
void insertionTete(Lnode **ph,char item);
void insertionQueue(Lnode **ph,char item);
void suppressionTete(Lnode **ph);
void suppressionQueue(Lnode **ph);
void listeAffiche(Lnode * ptr);
