#include <stdlib.h>
#include <stdio.h>
#include "sokoban.h"

int PousserCAISSE(int direction, int x, int y){
  int Position[2][2];
  int CompteurPouss = 0;
  int CompteurMouv = 0;
  switch(direction){
    case Haut : if (Position[x][y-2] == VIDE && Position[x][y-1] == CAISSE && Position[x][y] == MANU){
      Position[x][y-2] = CAISSE;
      Position[x][y-1] = MANU;
      Position[x][y] = VIDE;
      CompteurMouv ++;
      CompteurPouss ++;
    }
    else if(Position[x][y-2] == CIBLE){
      Position[x][y-2] = CAISSESURCIBLE;
      Position[x][y-1] = MANU;
      Position[x][y] = VIDE;
      CompteurMouv ++;
      CompteurPouss ++;
    }
    else;

    if (Position [x][y-2] == VIDE && Position [x][y-1] == CAISSE && Position[x][y] == MANUSURCIBLE){
      Position[x][y-2] = CAISSE;
      Position[x][y-1]= MANU;
      Position[x][y]= CIBLE;
      CompteurMouv ++;
      CompteurPouss ++;
    }
    else if(Position[x][y-2]== CIBLE){
      Position[x][y-2] = CAISSESURCIBLE;
      Position[x][y-1]= MANU;
      Position[x][y]= CIBLE;
      CompteurMouv ++;
      CompteurPouss ++;
    }
    else;

    if (Position[x][y-2] == VIDE && Position[x][y-1] == CAISSESURCIBLE && Position[x][y] == MANU){
      Position[x][y-2] = CAISSE;
      Position[x][y-1]= MANUSURCIBLE;
      Position[x][y]= VIDE;
      CompteurMouv ++;
      CompteurPouss ++;
    }
    else if (Position[x][y-2] == CIBLE){
      Position[x][y-2] = CAISSESURCIBLE;
      Position[x][y-1] = MANU;
      Position[x][y] = VIDE;
      CompteurMouv ++;
      CompteurPouss ++;
    }
    else;

    if (Position [x][y-2] == VIDE && Position [x][y-1] == CAISSESURCIBLE && Position[x][y] == MANUSURCIBLE){
        Position[x][y-2] = CAISSE;
        Position[x][y-1] = MANUSURCIBLE;
        Position[x][y] = CIBLE;
        CompteurMouv ++;
        CompteurPouss ++;
    }
    else if(Position[x][y-2]== CIBLE){
        Position[x][y-2] = CAISSESURCIBLE;
        Position[x][y-1] = MANUSURCIBLE;
        Position[x][y] = CIBLE;
        CompteurMouv ++;
        CompteurPouss ++;
    }
    else;
    break;

    case Bas : if (Position[x][y+2] == VIDE && Position[x][y+1] == CAISSE && Position[x][y] == MANU){
      Position[x][y+2] = CAISSE;
      Position[x][y+1] = MANU;
      Position[x][y] = VIDE;
      CompteurMouv ++;
      CompteurPouss ++;
    }
    else if(Position[x][y+2]== CIBLE){
      Position[x][y+2] = CAISSESURCIBLE;
      Position[x][y+1] = MANU;
      Position[x][y] = VIDE;
      CompteurMouv ++;
      CompteurPouss ++;
    }

    else;

    if (Position [x][y+2] == VIDE && Position [x][y+1] == CAISSE && Position[x][y] == MANUSURCIBLE){
      Position[x][y+2] = CAISSE;
      Position[x][y+1] = MANU;
      Position[x][y] = CIBLE;
      CompteurMouv ++;
      CompteurPouss ++;
    }
    else if(Position[x][y+2]== CIBLE){
      Position[x][y+2] = CAISSESURCIBLE;
      Position[x][y+1] = MANU;
      Position[x][y] = CIBLE;
      CompteurMouv ++;
      CompteurPouss ++;
    }

    else;

    if (Position[x][y+2] == VIDE && Position[x][y+1] == CAISSESURCIBLE && Position[x][y] == MANU){
      Position[x][y+2] = CAISSE;
      Position[x][y+1] = MANUSURCIBLE;
      Position[x][y] = VIDE;
      CompteurMouv ++;
      CompteurPouss ++;
    }
    else if(Position[x][y+2]== CIBLE){
      Position[x][y+2] = CAISSESURCIBLE;
      Position[x][y+1]= MANU;
      Position[x][y] = VIDE;
      CompteurMouv ++;
      CompteurPouss ++;
    }

    else;

    if (Position [x][y+2] == VIDE && Position [x][y+1] == CAISSESURCIBLE && Position[x][y] == MANUSURCIBLE){
      Position[x][y+2] = CAISSE;
      Position[x][y+1] = MANUSURCIBLE;
      Position[x][y] = CIBLE;
      CompteurMouv ++;
      CompteurPouss ++;
    }

    else if(Position[x][y+2]== CIBLE){
      Position[x][y+2] = CAISSESURCIBLE;
      Position[x][y+1] = MANUSURCIBLE;
      Position[x][y] = CIBLE;
      CompteurMouv ++;
      CompteurPouss ++;
    }

    else;

    break;

    case Droite : if (Position[x+2][y] == VIDE && Position[x+1][y] == CAISSE && Position[x][y] == MANU){
      Position[x+2][y] = CAISSE;
      Position[x+1][y] = MANU;
      Position[x][y] = VIDE;
      CompteurMouv ++;
      CompteurPouss ++;
    }

    else if(Position[x+2][y]== CIBLE){
      Position[x+2][y] = CAISSESURCIBLE;
      Position[x+1][y] = MANU;
      Position[x][y] = VIDE;
      CompteurMouv ++;
      CompteurPouss ++;
    }

    else;

    if (Position [x+2][y] == VIDE && Position [x+1][y] == CAISSE && Position[x][y] == MANUSURCIBLE){
      Position[x+2][y] = CAISSE;
      Position[x+1][y] = MANU;
      Position[x][y] = CIBLE;
      CompteurMouv ++;
      CompteurPouss ++;
    }

    else if(Position[x+2][y]== CIBLE){
      Position[x+2][y] = CAISSESURCIBLE;
      Position[x+1][y] = MANU;
      Position[x][y] = CIBLE;
      CompteurMouv ++;
      CompteurPouss ++;
    }

    else;

    if (Position[x+2][y] == VIDE && Position[x+1][y] == CAISSESURCIBLE && Position[x][y] == MANU){
      Position[x+2][y] = CAISSE;
      Position[x+1][y] = MANUSURCIBLE;
      Position[x][y] = VIDE;
      CompteurMouv ++;
      CompteurPouss ++;
    }
    else if(Position[x+2][y] == CIBLE){
      Position[x+2][y] = CAISSESURCIBLE;
      Position[x+1][y] = MANU;
      Position[x][y] = VIDE;
      CompteurMouv ++;
      CompteurPouss ++;
    }

    else;

    if (Position [x+2][y] == VIDE && Position [x+1][y] == CAISSESURCIBLE && Position[x][y] == MANUSURCIBLE){
      Position[x+2][y] = CAISSE;
      Position[x+1][y] = MANUSURCIBLE;
      Position[x][y] = CIBLE;
      CompteurMouv ++;
      CompteurPouss ++;
    }

    else if(Position[x+2][y] == CIBLE){
      Position[x+2][y] = CAISSESURCIBLE;
      Position[x+1][y] = MANUSURCIBLE;
      Position[x][y] = CIBLE;
      CompteurMouv ++;
      CompteurPouss ++;
    }

    else;

    break;

    case Gauche : if (Position[x-2][y] == VIDE && Position[x-1][y] == CAISSE && Position[x][y] == MANU){
      Position[x-2][y] = CAISSE;
      Position[x-1][y] = MANU;
      Position[x][y] = VIDE;
      CompteurMouv ++;
      CompteurPouss ++;
    }

    else if(Position[x-2][y]== CIBLE){
      Position[x-2][y] = CAISSESURCIBLE;
      Position[x-1][y] = MANU;
      Position[x][y] = VIDE;
      CompteurMouv ++;
      CompteurPouss ++;
    }

    else;

    if (Position [x-2][y] == VIDE && Position [x-1][y] == CAISSE && Position[x][y] == MANUSURCIBLE){
      Position[x+2][y] = CAISSE;
      Position[x-1][y] = MANU;
      Position[x][y] = CIBLE;
      CompteurMouv ++;
      CompteurPouss ++;
    }

    else if(Position[x-2][y]== CIBLE){
      Position[x-2][y] = CAISSESURCIBLE;
      Position[x-1][y] = MANU;
      Position[x][y] = CIBLE;
      CompteurMouv ++;
      CompteurPouss ++;
    }

    else;

    if (Position[x-2][y] == VIDE && Position[x-1][y] == CAISSESURCIBLE && Position[x][y] == MANU){
      Position[x-2][y] = CAISSE;
      Position[x-1][y] = MANUSURCIBLE;
      Position[x][y] = VIDE;
      CompteurMouv ++;
      CompteurPouss ++;
    }

    else if(Position[x-2][y] == CIBLE){
      Position[x-2][y] = CAISSESURCIBLE;
      Position[x-1][y] = MANU;
      Position[x][y] = VIDE;
      CompteurMouv ++;
      CompteurPouss ++;
    }

    else;

    if (Position [x-2][y] == VIDE && Position [x-1][y] == CAISSESURCIBLE && Position[x][y] == MANUSURCIBLE){
      Position[x-2][y] = CAISSE;
      Position[x-1][y] = MANUSURCIBLE;
      Position[x][y] = CIBLE;
      CompteurMouv ++;
      CompteurPouss ++;
    }
    else if(Position[x-2][y]== CIBLE){
      Position[x-2][y] = CAISSESURCIBLE;
      Position[x-1][y] = MANUSURCIBLE;
      Position[x][y] = CIBLE;
      CompteurMouv ++;
      CompteurPouss ++;
    }
    else;

    break;
  }
  return 0;
}

int DeplacerMANU(int direction){
  int y;
  int x;
  int Position[2][2];
  int CompteurMouv = 0;
  switch(direction){
    case Haut : if(Position[x][y-1] == VIDE){
      Position[x][y-1] = MANU;
      Position[x][y] = VIDE;
      CompteurMouv ++;
    }
    else if(Position[x][y-1] == CIBLE){
      Position[x][y-1] = MANUSURCIBLE;
      Position[x][y] = VIDE;
      CompteurMouv ++;
    }

    else if(Position[x][y-1] == MUR){
    }
    else{
      PousserCAISSE(Haut, x, y);
    }
    break;

    case Bas : if(Position[x][y+1] == VIDE){
      Position[x][y+1] = MANU;
      Position[x][y] = VIDE;
      CompteurMouv ++;
    }
    else if(Position[x][y+1] == CIBLE){
      Position[x][y+1] = MANUSURCIBLE;
      Position[x][y] = VIDE;
      CompteurMouv ++;
    }

    else if(Position[x][y+1] == MUR){
    }
    else{
      PousserCAISSE(Bas, x, y);
    }
    break;

    case Droite : if(Position[x+1][y] == VIDE){
      Position[x+1][y] = MANU;
      Position[x][y] = VIDE;
      CompteurMouv ++;
    }
    else if(Position[x+1][y] == CIBLE){
      Position[x][y+1] = MANUSURCIBLE;
      Position[x][y] = VIDE;
      CompteurMouv ++;
    }

    else if(Position[x+1][y] == MUR){
    }
    else{
      PousserCAISSE(Droite, x, y);
    }

    break;

    case Gauche : if(Position[x-1][y] == VIDE){
      Position[x-1][y] = MANU;
      Position[x][y] = VIDE;
      CompteurMouv ++;
    }
    else if(Position[x-1][y] == CIBLE){
      Position[x][y-1] = MANUSURCIBLE;
      Position[x][y] = VIDE;
      CompteurMouv ++;
    }

    else if(Position[x-1][y] == MUR){
    }
    else{
      PousserCAISSE(Gauche, x, y);
    }
  }
  return 0;
}
