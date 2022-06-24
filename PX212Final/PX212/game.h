#ifndef _GAME_H
#define _GAME_H

typedef struct Coordonnees{
	int x;
	int y;
}Coordonnees;

typedef struct {
  int Niveau;
  int Largeur;
  int Longueur;
  char ** Plateau;
}GameInstance;

extern GameInstance Instance;

#endif
