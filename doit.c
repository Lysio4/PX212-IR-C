#include <stdio.h>
#include <stdlib.h>
#include "gestion_plateau.h"
#include "io.h"
#include "utils.h"
#include "sokoban.h"
#include "game.h"
#include "pile.h"

void retour(char ** Plateau,Lnode **move);

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define QUIT 113
#define RESTART 'r'
#define CANCEL 'c'



int CaisseRestante=0;
GameInstance Instance;
Coordonnees PosManu;

int main(){
  int GameRunning = 1;
  int Input =0;
  int i=0;
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
  FinNiveau(89);
  Dernier_Niveau=dernier_level();

  //game loop
  while(GameRunning){ //C'est un Booleen
    printf("\e[1;1H\e[2J");
    for(i=0; i<Instance.Longueur;i++){
      printf("%s",Instance.Plateau[i]);
    }
    if (CaisseRestante==0){
      printf("Gagné\n");
      if (Instance.Niveau < Dernier_Niveau){
          for(int i=0; i<Instance.Longueur; i++){
            free(Instance.Plateau[i]);
          }
          free(Instance.Plateau);
        FinNiveau(Instance.Niveau+1);
      }
      else{
        GameRunning=0;
        printf("Appuyé sur la touche q\n");
      }
    }

    Input =litClavier();
    Xtemp= PosManu.x;
    Ytemp= PosManu.y;
    printf("input %d\n",Input );
    switch(Input){
      case UP:
        Apousse = DeplacerManu(Instance.Plateau, Haut,PosManu.x, PosManu.y);
        CompteurPouss += Apousse;
        CompteurMouv++;

      break;
      case DOWN:
        Apousse=DeplacerManu(Instance.Plateau, Bas,PosManu.x, PosManu.y);
        CompteurMouv++;
        CompteurPouss += Apousse;

      break;
      case LEFT:
        printf("caisse = %d\n", CaisseRestante);
        Apousse= DeplacerManu(Instance.Plateau, Gauche,PosManu.x, PosManu.y );
        CompteurMouv++;
        CompteurPouss += Apousse;

      break;
      case RIGHT:
        Apousse = DeplacerManu(Instance.Plateau,Droite,PosManu.x, PosManu.y );
        CompteurMouv++;
        CompteurPouss += Apousse;

      break;
      case QUIT:
        CompteurMouv=CompteurMouv+CompteurPouss;
        printf("Le nombre de mouvement est: %d\n",CompteurMouv);
        printf("Le nombre de poussee est: %d\n",CompteurPouss);
        GameRunning= 0;
      break;
      case RESTART:
        for(int i=0; i<Instance.Longueur; i++){
          free(Instance.Plateau[i]);
        }
        free(Instance.Plateau);
        Instance.Plateau = afficher_plateau(Instance.Niveau);
      break;
      case CANCEL:
      printf("test2\n");
        retour(Instance.Plateau,&move);
      break;
    }

    PosManu = position(Instance.Plateau, Instance.Longueur, Instance.Largeur);

    if ((Input != CANCEL) && ((PosManu.x != Xtemp)||(PosManu.y != Ytemp))){
      printf("tessavet\n");
      insertionTete(&move,Input, Apousse);
    }

    CaisseRestante= Objectif(Instance.Plateau,Instance.Largeur,Instance.Longueur);

  }
  //end execution
  for(int i=0; i<Instance.Longueur; i++){
    free(Instance.Plateau[i]);
  }
  free(Instance.Plateau);

}

void retour(char ** Plateau,Lnode **move){
  Donnee Element;
  int Xtemp=PosManu.x;
  int Ytemp=PosManu.y;
  Element = suppressionTete(move);
  switch (Element.Deplacement){
    case UP:
      DeplacerManu(Plateau, Bas,PosManu.x, PosManu.y);
      if(Element.Poussee){
        Plateau[Ytemp][Xtemp]=CAISSE;
        if(Plateau[Ytemp-1][Xtemp]==CAISSE){
          Plateau[Ytemp-1][Xtemp]=VIDE;
        }
        else if (Plateau[Ytemp-1][Xtemp]==CAISSESURCIBLE){
          Plateau[Ytemp-1][Xtemp]=CIBLE;
        }
      }
      else if (Plateau[Ytemp][Xtemp]==CIBLE){
        if (Plateau[Ytemp-1][Xtemp]==MANUSURCIBLE){
          Plateau[Ytemp-1][Xtemp]=CIBLE;
        }
      }
      else{
          Plateau[Ytemp][Xtemp]=VIDE;
        }
    break;

    case DOWN:
      DeplacerManu(Plateau, Haut,PosManu.x, PosManu.y);
      if(Element.Poussee){
        Plateau[Ytemp][Xtemp]=CAISSE;
        if(Plateau[Ytemp+1][Xtemp]==CAISSE){
          Plateau[Ytemp+1][Xtemp]=VIDE;
        }
        else if (Plateau[Ytemp+1][Xtemp]==CAISSESURCIBLE){
          Plateau[Ytemp+1][Xtemp]=CIBLE;
        }
      }
            else if (Plateau[Ytemp][Xtemp]==CIBLE){
        if (Plateau[Ytemp+1][Xtemp]==MANUSURCIBLE){
          Plateau[Ytemp+1][Xtemp]=CIBLE;
        }
      }
      else{
        Plateau[Ytemp][Xtemp]=VIDE;
      }
    break;

    case LEFT:
      DeplacerManu(Plateau,Droite,PosManu.x, PosManu.y );
      if(Element.Poussee){
        Plateau[Ytemp][Xtemp]=CAISSE;
        if(Plateau[Ytemp][Xtemp+1]==CAISSE){
          Plateau[Ytemp][Xtemp+1]=VIDE;
        }
        else if (Plateau[Ytemp][Xtemp+1]==CAISSESURCIBLE){
          Plateau[Ytemp][Xtemp+1]=CIBLE;
        }
      }
      else if (Plateau[Ytemp][Xtemp]==CIBLE){
        if (Plateau[Ytemp][Xtemp+1]==MANUSURCIBLE){
          Plateau[Ytemp][Xtemp+1]=CIBLE;
        }
      }
      else{
        Plateau[Ytemp][Xtemp]=VIDE;
      }
    break;

    case RIGHT:
      DeplacerManu(Plateau,Gauche,PosManu.x, PosManu.y );
      if(Element.Poussee){
        Plateau[Ytemp][Xtemp]=CAISSE;
        if(Plateau[Ytemp][Xtemp-1]==CAISSE){
          Plateau[Ytemp][Xtemp-1]=VIDE;
        }
        else if (Plateau[Ytemp][Xtemp-1]==CAISSESURCIBLE){
          Plateau[Ytemp][Xtemp-1]=CIBLE;
        }
      }
            else if (Plateau[Ytemp][Xtemp]==CIBLE){
        if (Plateau[Ytemp][Xtemp-1]==MANUSURCIBLE){
          Plateau[Ytemp][Xtemp-1]=CIBLE;
        }
      }
      else{
        Plateau[Ytemp][Xtemp]=VIDE;
      }
    break;
  }
}
