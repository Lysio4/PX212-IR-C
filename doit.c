#include <stdio.h>
#include <stdlib.h>
#include "gestion_plateau.h"
#include "io.h"
#include "utils.h"

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define QUIT 'r'


int Niveau=89;
int CaisseRestante = 0;
Coordonnees PosManu;

int main(){
  //variables:
  char **Plateau = NULL;
  int Largeur =0;
  int Longueur =0;
  int GameRunning = 1;
  int Input =0;
  int i=0;

  //init
  configureTerminal();
  Plateau = afficher_plateau(Niveau);
  Longueur = taille_longueur(Niveau);
  Largeur = LargeurV2(Plateau, Longueur);
  PosManu = position(Plateau, Longueur, Largeur);
  Objectif(Plateau,Largeur,Longueur);

  //game loop
  while(GameRunning){ //C'est un Booleen
    printf("\e[1;1H\e[2J");
    for(i=0; i<Longueur;i++){
      printf("%s\n",Plateau[i]);
    }
    Input =litClavier();
    switch(Input){
      case UP:
        DeplacerManu(Plateau, Haut,PosManu.x, PosManu.y);
      break;
      case DOWN:
        DeplacerManu(Plateau, Bas,PosManu.x, PosManu.y);
      break;
      case LEFT:
        DeplacerManu(Plateau, Gauche,PosManu.x, PosManu.y );
      break;
      case RIGHT:
        DeplacerManu(Plateau,Droite,PosManu.x, PosManu.y );
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
