#include <stdio.h>
#include <stdlib.h>
#include "gestion_plateau.h"
#include "io.h"
#include "utils.h"
#include "reset.h"
#include "pile.h"
#include "retourarriere.h"
#include "sokoban.h"

/*!Configuration des contrôles utilisés*/
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define QUIT 'e'
#define RESET 'r'
#define CANCEL 'c'


int Niveau=89;
int CaisseRestante = 0;
Coordonnees PosManu;

int main(){ /*!Fonction principale qui fait tourner le jeu
  *variables:*/
  char **Plateau = NULL;
  int Largeur =0;
  int Longueur =0;
  int GameRunning = 1;
  int Input =0;
  int i=0;
  Lnode *progression = NULL;

  /*!Init du jeu*/
  configureTerminal();
  Plateau = afficher_plateau(Niveau);
  Longueur = taille_longueur(Niveau);
  Largeur = LargeurV2(Plateau, Longueur);
  PosManu = position(Plateau, Longueur, Largeur);
  Objectif(Plateau,Largeur,Longueur);

  /*!Game Loop, ainsi que les contrôles du jeu (flèches directionnelles pour bouger, R pour quitter)*/
  while(GameRunning){ /*!C'est un Booleen*/
    printf("\e[1;1H\e[2J");
    for(i=0; i<Longueur;i++){
      printf("%s\n",Plateau[i]);
    }
    Input =litClavier();
    switch(Input){
      case UP:
        DeplacerManu(Plateau, Haut,PosManu.x, PosManu.y);
        insertionTete(&progression,PosManu,Haut,CaissePoussee);
      break;
      case DOWN:     
        DeplacerManu(Plateau, Bas,PosManu.x, PosManu.y);
        insertionTete(&progression,PosManu,Bas,CaissePoussee);
      break;
      case LEFT:
        DeplacerManu(Plateau, Gauche,PosManu.x, PosManu.y);
        insertionTete(&progression,PosManu,Gauche,CaissePoussee);
      break;
      case RIGHT:
        DeplacerManu(Plateau,Droite,PosManu.x, PosManu.y);
        insertionTete(&progression,PosManu,Droite,CaissePoussee);
      break;
      case RESET:
        reset(Niveau);
      break;
      case CANCEL:
        redo(&progression, Plateau);
      break;
      case QUIT:
        GameRunning= 0;
      break;
    }
      PosManu = position(Plateau, Longueur, Largeur);


  }

  //end execution
  for(int i=0; i<Longueur; i++){
    free(Plateau[i]);
  }
  free(Plateau);



}
