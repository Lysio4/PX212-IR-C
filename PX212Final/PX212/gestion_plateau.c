#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestion_plateau.h"

int dernierLevel(){
  char Chaine[7] = "";
  char Buf[2];
  int Val =0;
  FILE* levels=NULL;
  levels=fopen("levels.lvl", "r");

  if(levels!=NULL){
    fseek(levels, -1, SEEK_END);
    while ((strcmp(Chaine, ";LEVEL")) !=0){
      fseek(levels, -8, SEEK_CUR);
      fgets(Chaine,7,levels);
    }
    fgetc(levels); // pour l'espace
    Buf[0] = fgetc(levels);
    Buf[1] = fgetc(levels);
    if (Buf[1]== '\n'){ // si c'est un retour à la ligne
      Val = Buf[0] - '0';
      fseek(levels, -1, SEEK_CUR);// on recule le curseur de 1
    }
    else{
      Val = (Buf[0]-'0')*10+Buf[1]-'0';
      fclose(levels);
    }
  }
  return Val;
}

int trouverLevel(int Niveau){
  FILE* levels=NULL;
  char Chaine[7] = "";
  char Buf[2];
  int Val =0;
  int Compteur;
  levels=fopen("levels.lvl", "r");   //C'est en lecture

  if(levels!=NULL){
    while (Niveau != Val){ // tant que c'est pas le bon Niveau

      fgets(Chaine,7,levels);
        while ((strcmp(Chaine, ";LEVEL")) !=0){
          fgets(Chaine,7,levels);
        }
        fgetc(levels); // pour l'espace
        Buf[0] = fgetc(levels);
        Buf[1] = fgetc(levels);
        if (Buf[1]== '\n'){ // si c'est un retour à la ligne
          Val = Buf[0] - '0';
          fseek(levels, -1, SEEK_CUR);// on recule le curseur de 1
        }
        else{
          Val = (Buf[0]-'0')*10+Buf[1]-'0';
        }
      }
      fgetc(levels);
      Compteur=ftell(levels);
      fclose(levels);
  }
  return Compteur;
}

int tailleLongueur(int Niveau){
  int Compteur1= 0;
  int Compteur2= 0;
  int Difference = 0;
  int RetourLigne = 0;
  int Position = 0;
  int DernierNiveau=0;


  DernierNiveau= dernierLevel(Niveau);

  FILE* levels=NULL;
  levels=fopen("levels.lvl", "r");
  if(levels!=NULL){
    Compteur1 =trouverLevel(Niveau);
    Difference = tailleLargeur(Niveau);
    Compteur2 = Compteur1 +Difference;
  //connaitre le nombre de colonne du Plateau
    fseek(levels,+Compteur1,SEEK_SET);
    while(Position < Compteur2){
      Position=ftell(levels);
      if (fgetc(levels)=='\n'){  //si c'est un retour a la ligne -> incrémentation de RetourLigne
        RetourLigne++;
      }
    }
  }
  if(Niveau == DernierNiveau){
    RetourLigne++;
  }
  //printf("le nombre de RetourLigne est %d\n", RetourLigne);
  fclose(levels);
  return (RetourLigne-1);
}

int tailleLargeur(int Niveau){
  int Compteur1= 0;
  int Compteur2= 0;
  int DernierNiveau = 0;
  int Difference = 0;
  FILE* levels=NULL;
  levels=fopen("levels.lvl", "r");
  //ouverture du fichier levels.lvl
  if (levels!=NULL){
    DernierNiveau=dernierLevel();

    if (Niveau < DernierNiveau){
      Compteur1 =trouverLevel(Niveau);
      Compteur2 =trouverLevel(Niveau+1);
    }
    else{
      Compteur1 =trouverLevel(Niveau);
      while(!feof(levels)){
        fgetc(levels);
      }
      Compteur2 =ftell(levels);
    }
    Difference= Compteur2-Compteur1;
  }
  fclose(levels);
  return Difference;
}

char ** afficherPlateau(int Niveau){
  int Position = 0;
  int Compteur1= 0;
  int Compteur2= 0;
  int Difference= 0;
  int RetourLigne = 0;
  int i=0;
  int j=0;
  int Indice =0;
  char **Plateau;

  //tableau de pointeur vers le premier element d'une liste de caractère
  // char *... est une chaine de caractere

  FILE* levels=NULL;
  levels=fopen("levels.lvl", "r");

  Difference = tailleLargeur(Niveau);
  RetourLigne = tailleLongueur(Niveau);
  Compteur1 =trouverLevel(Niveau);
  Compteur2 = Compteur1 + Difference;

  //création du tableau
  Difference= Difference+1; //pour l'\0
  Plateau = malloc(sizeof(char*)*(RetourLigne));//-1 parce qu'on va jusqu'a ;LEVEL donc 1 ligne en trop
  for(i=0;i<(RetourLigne);i++){
    Plateau[i]=malloc(sizeof(char)*Difference);
  }

  //remplir le tableau
  fseek(levels,+Compteur1,SEEK_SET); // met le curseur au début du Niveau dans le fichier levels.lvl
  Position=ftell(levels);//connaitre la Position du curseur
  while(Position < (Compteur2-9)&& Indice<(RetourLigne)){ //-9 pour enlever la ligne ;LEVEL...
    fgets(Plateau[Indice],Difference,levels);
    Indice++;
    Position=ftell(levels);
  }

  //affichage du tableau
  for(j=0;j<Indice;j++){
    printf("%s",Plateau[j]);
    //free(Plateau[j]);
  }
  //free (Plateau);
  fclose(levels);
  return Plateau;
}

Coordonnees position(char ** Plateau, int Longueur, int Largeur){
  Coordonnees PositionManu;
  int i=0;
  int j=0;

  for(i=0; i<Longueur; i++){
    for(j=0; j<Largeur; j++){
      if ((Plateau[i][j]=='@')||(Plateau[i][j]=='!')){
        PositionManu.x = j;
        PositionManu.y = i;
        //printf("x = %d\n",PositionManu.x);
        //printf("y = %d\n",PositionManu.y);
      }
    }
  }
  return PositionManu;
}

int largeurV2(char **Plateau, int Longueur){
  int LargeurMax =0;
  int i =0;
  int j=0;
  for(i=0;i<Longueur;i++){
    j=0;
    while(Plateau[i][j]!='\0'){
      j++;
    }
    if(j>LargeurMax){
    LargeurMax=j;
    }
  }
  return LargeurMax;
}
