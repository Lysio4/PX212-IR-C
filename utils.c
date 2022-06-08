#include <stdlib.h>
#include <stdio.h>
#include "utils.h"

void Objectif(char **plateau, int Largeur, int Longueur){

  int i;
  int j;
  for (i = 0 ; i < Largeur ; i++){
    for (j = 0 ; j < Longueur ; j++){
      if (plateau[j][i] == CAISSE){
        CaisseRestante += 1;
      }
    }
  }
}

void FinNiveau(char **plateau){
  if (CaisseRestante == 0) {
    Niveau++;
  }
}

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
