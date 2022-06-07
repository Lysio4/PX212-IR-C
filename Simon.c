#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"

int dernier_level(){
  char chaine[7] = "";
  char buf[2];
  int val =0;
  FILE* levels=NULL;
  levels=fopen("levels.lvl", "r");

  if(levels!=NULL){
    fseek(levels, -1, SEEK_END);
    while ((strcmp(chaine, ";LEVEL")) !=0){
      fseek(levels, -8, SEEK_CUR);
      fgets(chaine,7,levels);
    }
    fgetc(levels); // pour l'espace
    buf[0] = fgetc(levels);
    buf[1] = fgetc(levels);
    if (buf[1]== '\n'){ // si c'est un retour à la ligne
      val = buf[0] - '0';
      fseek(levels, -1, SEEK_CUR);// on recule le curseur de 1
    }
    else{
      val = (buf[0]-'0')*10+buf[1]-'0';
      fclose(levels);
    }
    return val;
  }
}

int trouver_level(int niveau){
  FILE* levels=NULL;
  char chaine[7] = "";
  char buf[2];
  int val =0;
  int compteur;
  levels=fopen("levels.lvl", "r");   //C'est en lecture

  if(levels!=NULL){
    while (niveau != val){ // tant que c'est pas le bon niveau

      fgets(chaine,7,levels);
        while ((strcmp(chaine, ";LEVEL")) !=0){
          fgets(chaine,7,levels);
        }
        fgetc(levels); // pour l'espace
        buf[0] = fgetc(levels);
        buf[1] = fgetc(levels);
        if (buf[1]== '\n'){ // si c'est un retour à la ligne
          val = buf[0] - '0';
          fseek(levels, -1, SEEK_CUR);// on recule le curseur de 1
        }
        else{
          val = (buf[0]-'0')*10+buf[1]-'0';
        }
      }
      fgetc(levels);
      while(fgetc(levels)==';'){
        while(fgetc(levels)!='\n'){

        }
      }

      compteur=ftell(levels);
      fclose(levels);
  }
  return compteur;
}

int taille_longueur(int niveau){
  int compteur1= 0;
  int compteur2= 0;
  int difference = 0;
  int retour_ligne = 0;
  int position = 0;

  FILE* levels=NULL;
  levels=fopen("levels.lvl", "r");
  if(levels!=NULL){
    compteur1 =trouver_level(niveau);
    difference = taille_largeur(niveau);
    compteur2 = compteur1 +difference;
  //connaitre le nombre de colonne du plateau
    fseek(levels,+compteur1,SEEK_SET);
    while(position < compteur2){
      position=ftell(levels);
      if (fgetc(levels)=='\n'){  //si c'est un retour a la ligne -> incrémentation de retour_ligne
        retour_ligne++;
      }
    }
  }
  //printf("le nombre de retour_ligne est %d\n", retour_ligne);
  fclose(levels);
  return retour_ligne;
}

int taille_largeur(int niveau){
  int compteur1= 0;
  int compteur2= 0;
  int dernier_niveau = 0;
  int difference = 0;
  FILE* levels=NULL;
  levels=fopen("levels.lvl", "r");
  //ouverture du fichier levels.lvl
  if (levels!=NULL){
    dernier_niveau=dernier_level();

    if (niveau < dernier_niveau){
      compteur1 =trouver_level(niveau);
      compteur2 =trouver_level(niveau+1);
    }
    else{
      compteur1 =trouver_level(niveau);
      //fseek(levels,-1,SEEK_END);
      while(!feof(levels)){
        fgetc(levels);
      }
      //fgetc(levels);
      compteur2 =ftell(levels);
      //printf("compteur 2 = %d\n",compteur2 );
    }
    difference= compteur2-compteur1;
    //printf("la difference est %d\n", difference);
  }
  return difference;
  fclose(levels);
}

char ** afficher_plateau(int niveau){
  int position = 0;
  int compteur1= 0;
  int compteur2= 0;
  int difference= 0;
  int retour_ligne = 0;
  int i=0;
  int indice =0;
  char **plateau;

  FILE* levels=NULL;
  levels=fopen("levels.lvl", "r");

  difference = taille_largeur(niveau);
  retour_ligne = taille_longueur(niveau);
  compteur1 =trouver_level(niveau);
  compteur2 = compteur1 + difference;

  //création du tableau
  difference= difference+1; //pour l'\0
  plateau = malloc(sizeof(char*)*(retour_ligne));//-1 parce qu'on va jusqu'a ;LEVEL donc 1 ligne en trop
  for(i=0;i<(retour_ligne);i++){
    plateau[i]=malloc(sizeof(char)*difference);
  }

  //remplir le tableau
  fseek(levels,+compteur1,SEEK_SET); // met le curseur au début du niveau dans le fichier levels.lvl
  position=ftell(levels);//connaitre la position du curseur
  while(position < (compteur2-9)){ //-9 pour enlever la ligne ;LEVEL...
    fgets(plateau[indice],difference,levels);
    indice++;
    position=ftell(levels);
    //printf("indice = %d\n",indice);
  }

  //affichage du tableau
  //printf("debut\n");
  for(int i=0;i<indice;i++){
    printf("%s",plateau[i]);
    //free(plateau[i]);
  }
  //free (plateau);
  fclose(levels);
  return plateau;
}

Coordonnees position(int niveau){
  Coordonnees position_manu;
  int longueur =0;
  int largeur =0;
  char **plateau;

  largeur = taille_largeur(niveau);
  longueur = taille_longueur(niveau);
  largeur++; //pour l'\0

  plateau = afficher_plateau(niveau);

  for(int i=0; i<longueur; i++){
    for(int j=0; j<largeur; j++){
      if (plateau[i][j]=='@'){
        position_manu.x = j;
        position_manu.y = i;
        printf("x = %d\n",position_manu.x);
        printf("y = %d\n",position_manu.y);
      }
    }
  }
  for(int i=0; i<longueur; i++){
    free(plateau[i]);
  }
  free(plateau);
  return position_manu;
}
