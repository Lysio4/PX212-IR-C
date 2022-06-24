#include <stdio.h>
#include <stdlib.h>
#include "gestion_plateau.h"
#include "io.h"
#include "utils.h"
#include "sokoban.h"
#include "game.h"
#include "retour.h"



int CaisseRestante=0;
int RetourPouss= 0;
int RetourMouv= 0;
GameInstance Instance;
Coordonnees PosManu;

int main(){
  int GameRunning = 1;
  int Input =0;
  int i=0;
  int j =0;
  int TotMouv=0;
  int TotPouss=0;
  int CompteurPouss =0;
  int CompteurMouv = 0;
  int Dernier_Niveau =0;
  int Xtemp;
  int Ytemp;
  int Apousse=0;
  Lnode *move=NULL;

  //init

  configureTerminal();
  Instance.Niveau = 0;
  Dernier_Niveau=dernierLevel();
  GameRunning= finNiveau(89);
  //game loop
  while(GameRunning){ //C'est un Booleen
    printf("\e[1;1H\e[2J");
    printf("Niveau: %d\n",Instance.Niveau);
    printf("\nAppuyer sur la touche c pour retourner en arriere\n");
    printf("Appuyer sur la touche r pour redemarrer\n");
    printf("Appuyer sur la touche q pour quitter\n");
    printf("\n");
    for(i=0; i<Instance.Longueur;i++){
      printf("%s",Instance.Plateau[i]);
    }
    TotMouv = CompteurMouv + RetourMouv;
    TotPouss = CompteurPouss + RetourPouss;
    printf("\nLe nombre de mouvement est: %d\n",TotMouv);
    printf("Le nombre de poussee est: %d\n",TotPouss);
    if (CaisseRestante==0){
      printf("\e[1;1H\e[2J");
      printf("Niveau: %d\n",Instance.Niveau);
      for(j=0;j<CompteurMouv; j++){
        suppressionTete(&move);
      }
      TotPouss=0;
      RetourPouss=0;
      CompteurPouss=0;
      TotMouv=0;
      RetourMouv=0;
      CompteurMouv=0;
      //printf("Gagné\n");
      if (Instance.Niveau < Dernier_Niveau){
          for(int i=0; i<Instance.Longueur; i++){
            free(Instance.Plateau[i]);
          }
          free(Instance.Plateau);
        finNiveau(Instance.Niveau+1);
        printf("\e[1;1H\e[2J");
        printf("Prochain Niveau: Appuyer sur la touche espace\n");
      }

      else{
        printf("\e[1;1H\e[2J");// efface le terminal
        GameRunning=0;//met la condition de jeu a 0
        printf("Fin du jeu\n");
      }
    }

    Input =litClavier();
    Xtemp= PosManu.x;
    Ytemp= PosManu.y;
    switch(Input){
      case UP:
        Apousse = deplacerManu(Instance.Plateau, Haut,PosManu.x, PosManu.y);
        CompteurPouss += Apousse;
        CompteurMouv++;

      break;
      case DOWN:
        Apousse=deplacerManu(Instance.Plateau, Bas,PosManu.x, PosManu.y);
        CompteurMouv++;
        CompteurPouss += Apousse;

      break;
      case LEFT:
        Apousse= deplacerManu(Instance.Plateau, Gauche,PosManu.x, PosManu.y );
        CompteurMouv++;
        CompteurPouss += Apousse;

      break;
      case RIGHT:
        Apousse = deplacerManu(Instance.Plateau,Droite,PosManu.x, PosManu.y );
        CompteurMouv++;
        CompteurPouss += Apousse;

      break;
      case QUIT:
      for(j=0;j<CompteurMouv; j++){
        suppressionTete(&move);
      }
        GameRunning= 0;
      break;
      case RESTART:
        if (GameRunning == 1){ // si le jeu n'est pas fini
          for(i=0; i<Instance.Longueur; i++){
            free(Instance.Plateau[i]);
          }
          free(Instance.Plateau);

          for(j=0;j<CompteurMouv; j++){
            suppressionTete(&move);
          }

          Instance.Plateau = afficherPlateau(Instance.Niveau);
          TotPouss=0;
          RetourPouss=0;
          CompteurPouss=0;
          TotMouv=0;
          RetourMouv=0;
          CompteurMouv=0;
        }
      break;

      case CANCEL:
        retour(Instance.Plateau,&move);
      break;
    }
    PosManu = position(Instance.Plateau, Instance.Longueur, Instance.Largeur);
    if ((Input != CANCEL) && ((PosManu.x != Xtemp)||(PosManu.y != Ytemp))){
      insertionTete(&move,Input, Apousse);
    }
    CaisseRestante= objectif(Instance.Plateau,Instance.Largeur,Instance.Longueur);
  }
  //end execution
  for(i=0; i<Instance.Longueur; i++){
    free(Instance.Plateau[i]);
  }
  free(Instance.Plateau);

  for(j=0;j<CompteurMouv; j++){
    suppressionTete(&move);
  }

}
