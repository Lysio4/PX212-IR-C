#include <stdlib.h>
#include <stdio.h>
#include "Fonctions.c"

void Objectif(**plateau){
  int CaisseRestante = 0;
  for (i = 0 ; i < largeur ; i++){
    for (j = 0 ; j < longueur ; j++){
      if (Position[i][j] == Caisse{
        CaisseRestante += 1;
      }
    }
  }
}

void FinNiveau(**plateau){
  if (CaisseRestante == 0) {
    niveau++;
    return niveau;
  }
}

int SauvegardeNiveau(**plateau){
  FILE* level = NULL;
  int i = 0, j = 0;
  level = fopen("levels.lvl", "w");
  if (level == NULL){
    return 0;
  }
  else { for (i = 0 ; i < largeur; i++){
    for (j = 0 ; j < longueur ; j++){
      fprintf(level, "%d", niveau[j][i]);
      }
      }
      fclose(level);
      return 1;
    }
  }
