#include <stdlib.h>
#include <stdio.h>
#include "header.h"

void Objectif(char **plateau){
  int CaisseRestante = 0;
  int i;
  int j;
  for (i = 0 ; i < Largeur ; i++){
    for (j = 0 ; j < Longueur ; j++){
      if (Position[i][j] == Caisse){
        CaisseRestante += 1;
      }
    }
  }
}

void FinNiveau(char **plateau){
  if (CaisseRestante == 0) {
    niveau++;
    return niveau;
  }
}

int SauvegardeNiveau(char **plateau){
  FILE* level = NULL;
  int i = 0, j = 0;
  level = fopen("levels.lvl", "w");
  if (level == NULL){
    return 0;
  }
  else { for (i = 0 ; i < Largeur; i++){
    for (j = 0 ; j < Longueur ; j++){
      fprintf(level, "%d", niveau[j][i]);
      }
      }
      fclose(level);
      return 1;
    }
  }
