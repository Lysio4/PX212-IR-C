#include <stdlib.h>
#include <stdio.h>
#include "utils.h"

int objectif(char **plateau, int Largeur, int Longueur){
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

int finNiveau(int Niveau){
  int GameRunning=0;
  int Dernier_Niveau=0;
  Dernier_Niveau=dernierLevel();
  if(Niveau<=Dernier_Niveau){
    if (CaisseRestante == 0) {
      Instance.Niveau = Niveau;
      Instance.Plateau = afficherPlateau(Niveau);
      Instance.Longueur = tailleLongueur(Niveau);
      Instance.Largeur = largeurV2(Instance.Plateau, Instance.Longueur);
      CaisseRestante = objectif(Instance.Plateau,Instance.Largeur,Instance.Longueur);
      PosManu = position(Instance.Plateau, Instance.Longueur, Instance.Largeur);
      GameRunning= 1;
    }
  }
  else {
    printf("Ce Niveau n'existe pas\n");
    GameRunning= 0;
  }
  return GameRunning;
}

int sauvegardeNiveau(char **plateau, int Largeur, int Longueur){
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
