#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestion_plateau.h"

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
  }
  return val;
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
  int dernier_niveau=0;


  dernier_niveau= dernier_level(niveau);

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
  if(niveau == dernier_niveau){
    retour_ligne++;
  }
  //printf("le nombre de retour_ligne est %d\n", retour_ligne);
  fclose(levels);
  return (retour_ligne-1);
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
  fclose(levels);
  return difference;
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
  char *p =NULL;
  //char *poubelle;

  FILE* levels=NULL;
  levels=fopen("levels.lvl", "r");
  //poubelle=malloc(sizeof(char)*difference);

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
  while(position < (compteur2-9)&& indice<(retour_ligne)){ //-9 pour enlever la ligne ;LEVEL...
    fgets(plateau[indice],difference,levels);
    if ((p = strchr(plateau[indice], '\n')) != NULL){
      *p = '\0';
    }
    indice++;
    position=ftell(levels);
  }

  //affichage du tableau
  for(int i=0;i<indice;i++){
    printf("%s",plateau[i]);
    //free(plateau[i]);
  }
  //free (plateau);
  //free (poubelle);
  fclose(levels);
  return plateau;
}

Coordonnees position(char ** Plateau, int Longueur, int Largeur){
  Coordonnees position_manu;

  for(int i=0; i<Longueur; i++){
    for(int j=0; j<Largeur; j++){
      if (Plateau[i][j]=='@'||Plateau[i][j]=='!'){
        position_manu.x = j;
        position_manu.y = i;
        printf("x = %d\n",position_manu.x);
        printf("y = %d\n",position_manu.y);
      }
    }
  }
  return position_manu;
}

int LargeurV2(char **Plateau, int Longueur){
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
