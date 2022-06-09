#include <stdlib.h>
#include <stdio.h>
#include "utils.h"
#include "gestion_plateau.h"

///Objectif() permet de définir les conditions de victoire.
int Objectif(char **plateau, int Largeur, int Longueur){
  int i;
  int j;
  int _CaisseRestante = 0;//convention variable interne
  for (i = 0 ; i < Largeur ; i++){
    for (j = 0 ; j < Longueur ; j++){
      if (plateau[j][i] == CAISSE){
        _CaisseRestante ++;
      }
    }
  }
  return _CaisseRestante;
}

///Permet de gérer la fin du niveau et de savoir lorsqu'il est résolu.
void FinNiveau(int Niveau){
  if (CaisseRestante == 0) {
    Instance.Niveau = Niveau;
    Instance.Plateau = afficher_plateau(Niveau);
    Instance.Longueur = taille_longueur(Niveau);
    Instance.Largeur = LargeurV2(Instance.Plateau, Instance.Longueur);
    CaisseRestante = Objectif(Instance.Plateau,Instance.Largeur,Instance.Longueur);
    PosManu = position(Instance.Plateau, Instance.Longueur, Instance.Largeur);
  }
}

///Permet de sauvegarder la progression dans un niveau.
int SauvegardeNiveau(char **plateau, int Largeur, int Longueur){
  FILE* level = NULL;
  int i = 0, j = 0;
  level = fopen("levels.lvl", "w");
  if (level == NULL){
    return 0;
  }
  else { for (i = 0 ; i < Largeur; i++){
    for (j = 0 ; j < Longueur ; j++){
      fprintf(level, "%d", plateau[j][i]);
      }
      }
      fclose(level);
      return 1;
    }
  }
