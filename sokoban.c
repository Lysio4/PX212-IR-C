#include <stdlib.h>
#include <stdio.h>
#include "sokoban.h"

///PousserCaisse permet de gérer la poussée d'une caisse.
int PousserCaisse(char ** Plateau ,int direction, int x, int y){
  int CompteurPouss = 0;
  int CompteurMouv = 0;
  switch(direction){
    case Haut : if (Plateau[y-2][x] == VIDE && Plateau[y-1][x] == CAISSE && Plateau[y][x] == MANU){
      Plateau[y-2][x] = CAISSE;
      Plateau[y-1][x] = MANU;
      Plateau[y][x] = VIDE;
      CompteurMouv ++;
      CompteurPouss ++;
    }
    else if(Plateau[y-2][x] == CIBLE && Plateau[y-1][x] == CAISSE && Plateau[y][x] == MANU){
      Plateau[y-2][x] = CAISSESURCIBLE;
      Plateau[y-1][x] = MANU;
      Plateau[y][x] = VIDE;
      CompteurMouv ++;
      CompteurPouss ++;
    }
    else if (Plateau [y-2][x] == VIDE && Plateau [y-1][x] == CAISSE && Plateau[y][x] == MANUSURCIBLE){
      Plateau[y-2][x] = CAISSE;
      Plateau[y-1][x]= MANU;
      Plateau[y][x]= CIBLE;
      CompteurMouv ++;
      CompteurPouss ++;
    }
    else if(Plateau[y-2][x]== CIBLE && Plateau [y-1][x] == CAISSE && Plateau[y][x] == MANUSURCIBLE){
      Plateau[y-2][x] = CAISSESURCIBLE;
      Plateau[y-1][x]= MANU;
      Plateau[y][x]= CIBLE;
      CompteurMouv ++;
      CompteurPouss ++;
    }
    else if (Plateau[y-2][x] == VIDE && Plateau[y-1][x] == CAISSESURCIBLE && Plateau[y][x] == MANU){
      Plateau[y-2][x] = CAISSE;
      Plateau[y-1][x]= MANUSURCIBLE;
      Plateau[y][x]= VIDE;
      CompteurMouv ++;
      CompteurPouss ++;
    }
    else if (Plateau[y-2][x] == CIBLE && Plateau[y-1][x] == CAISSESURCIBLE && Plateau[y][x] == MANU){
      Plateau[y-2][x] = CAISSESURCIBLE;
      Plateau[y-1][x] = MANUSURCIBLE;
      Plateau[y][x] = VIDE;
      CompteurMouv ++;
      CompteurPouss ++;
    }
    else if (Plateau [y-2][x] == VIDE && Plateau [y-1][x] == CAISSESURCIBLE && Plateau[y][x] == MANUSURCIBLE){
        Plateau[y-2][x] = CAISSE;
        Plateau[y-1][x] = MANUSURCIBLE;
        Plateau[y][x] = CIBLE;
        CompteurMouv ++;
        CompteurPouss ++;
    }
    else if(Plateau[y-2][x]== CIBLE && Plateau [y-1][x] == CAISSESURCIBLE && Plateau[y][x] == MANUSURCIBLE){
        Plateau[y-2][x] = CAISSESURCIBLE;
        Plateau[y-1][x] = MANUSURCIBLE;
        Plateau[y][x] = CIBLE;
        CompteurMouv ++;
        CompteurPouss ++;
    }

    break;

    case Bas : if (Plateau[y+2][x] == VIDE && Plateau[y+1][x] == CAISSE && Plateau[y][x] == MANU){
      Plateau[y+2][x] = CAISSE;
      Plateau[y+1][x] = MANU;
      Plateau[y][x] = VIDE;
      CompteurMouv ++;
      CompteurPouss ++;
    }
    else if(Plateau[y+2][x]== CIBLE && Plateau[y+1][x] == CAISSE && Plateau[y][x] == MANU){
      Plateau[y+2][x] = CAISSESURCIBLE;
      Plateau[y+1][x] = MANU;
      Plateau[y][x] = VIDE;
      CompteurMouv ++;
      CompteurPouss ++;
    }
    else if (Plateau [y+2][x] == VIDE && Plateau [y+1][x] == CAISSE && Plateau[y][x] == MANUSURCIBLE){
      Plateau[y+2][x] = CAISSE;
      Plateau[y+1][x] = MANU;
      Plateau[y][x] = CIBLE;
      CompteurMouv ++;
      CompteurPouss ++;
    }
    else if(Plateau[y+2][x]== CIBLE && Plateau [y+1][x] == CAISSE && Plateau[y][x] == MANUSURCIBLE){
      Plateau[y+2][x] = CAISSESURCIBLE;
      Plateau[y+1][x] = MANU;
      Plateau[y][x] = CIBLE;
      CompteurMouv ++;
      CompteurPouss ++;
    }
    else if (Plateau[y+2][x] == VIDE && Plateau[y+1][x] == CAISSESURCIBLE && Plateau[y][x] == MANU){
      Plateau[y+2][x] = CAISSE;
      Plateau[y+1][x] = MANUSURCIBLE;
      Plateau[y][x] = VIDE;
      CompteurMouv ++;
      CompteurPouss ++;
    }
    else if(Plateau[y+2][x]== CIBLE && Plateau[y+1][x] == CAISSESURCIBLE && Plateau[y][x] == MANU){
      Plateau[y+2][x] = CAISSESURCIBLE;
      Plateau[y+1][x]= MANU;
      Plateau[y][x] = VIDE;
      CompteurMouv ++;
      CompteurPouss ++;
    }

    else if (Plateau [y+2][x] == VIDE && Plateau [y+1][x] == CAISSESURCIBLE && Plateau[y][x] == MANUSURCIBLE){
      Plateau[y+2][x] = CAISSE;
      Plateau[y+1][x] = MANUSURCIBLE;
      Plateau[y][x] = CIBLE;
      CompteurMouv ++;
      CompteurPouss ++;
    }

    else if(Plateau[y+2][x]== CIBLE && Plateau [y+1][x] == CAISSESURCIBLE && Plateau[y][x] == MANUSURCIBLE){
      Plateau[y+2][x] = CAISSESURCIBLE;
      Plateau[y+1][x] = MANUSURCIBLE;
      Plateau[y][x] = CIBLE;
      CompteurMouv ++;
      CompteurPouss ++;
    }

    else;

    break;

    case Gauche : if (Plateau[y][x+2] == VIDE && Plateau[y][x+1] == CAISSE && Plateau[y][x] == MANU){
      Plateau[y][x+2] = CAISSE;
      Plateau[y][x+1] = MANU;
      Plateau[y][x] = VIDE;
      CompteurMouv ++;
      CompteurPouss ++;
    }

    else if(Plateau[y][x+2] == CIBLE && Plateau[y][x+1] == CAISSE && Plateau[y][x] == MANU){
      Plateau[y][x+2] = CAISSESURCIBLE;
      Plateau[y][x+1] = MANU;
      Plateau[y][x] = VIDE;
      CompteurMouv ++;
      CompteurPouss ++;
    }

    else if(Plateau [y][x+2] == VIDE && Plateau [y][x+1] == CAISSE && Plateau[y][x] == MANUSURCIBLE){
      Plateau[y][x+2] = CAISSE;
      Plateau[y][x+1] = MANU;
      Plateau[y][x] = CIBLE;
      CompteurMouv ++;
      CompteurPouss ++;
    }

    else if(Plateau[y][x+2]== CIBLE && Plateau [y][x+1] == CAISSE && Plateau[y][x] == MANUSURCIBLE){
      Plateau[y][x+2] = CAISSESURCIBLE;
      Plateau[y][x+1] = MANU;
      Plateau[y][x] = CIBLE;
      CompteurMouv ++;
      CompteurPouss ++;
    }

    else if (Plateau[y][x+2] == VIDE && Plateau[y][x+1] == CAISSESURCIBLE && Plateau[y][x] == MANU){
      Plateau[y][x+2] = CAISSE;
      Plateau[y][x+1] = MANUSURCIBLE;
      Plateau[y][x] = VIDE;
      CompteurMouv ++;
      CompteurPouss ++;
    }
    else if(Plateau[y][x+2] == CIBLE && Plateau[y][x+1] == CAISSESURCIBLE && Plateau[y][x] == MANU){
      Plateau[y][x+2] = CAISSESURCIBLE;
      Plateau[y][x+1] = MANUSURCIBLE;
      Plateau[y][x] = VIDE;
      CompteurMouv ++;
      CompteurPouss ++;
    }

    else if (Plateau [y][x+2] == VIDE && Plateau [y][x+1] == CAISSESURCIBLE && Plateau[y][x] == MANUSURCIBLE){
      Plateau[y][x+2] = CAISSE;
      Plateau[y][x+1] = MANUSURCIBLE;
      Plateau[y][x] = CIBLE;
      CompteurMouv ++;
      CompteurPouss ++;
    }

    else if(Plateau[y][x+2] == CIBLE && Plateau [y][x+1] == CAISSESURCIBLE && Plateau[y][x] == MANUSURCIBLE){
      Plateau[y][x+2] = CAISSESURCIBLE;
      Plateau[y][x+1] = MANUSURCIBLE;
      Plateau[y][x] = CIBLE;
      CompteurMouv ++;
      CompteurPouss ++;
    }

    else;

    break;

    case Droite : if (Plateau[y][x-2] == VIDE && Plateau[y][x-1] == CAISSE && Plateau[y][x] == MANU){
      Plateau[y][x-2] = CAISSE;
      Plateau[y][x-1] = MANU;
      Plateau[y][x] = VIDE;
      CompteurMouv ++;
      CompteurPouss ++;
    }

    else if(Plateau[y][x-2]== CIBLE && Plateau[y][x-1] == CAISSE && Plateau[y][x] == MANU){
      Plateau[y][x-2] = CAISSESURCIBLE;
      Plateau[y][x-1] = MANU;
      Plateau[y][x] = VIDE;
      CompteurMouv ++;
      CompteurPouss ++;
    }

    else if(Plateau [y][x-2] == VIDE && Plateau [y][x-1] == CAISSE && Plateau[y][x] == MANUSURCIBLE){
      Plateau[y][x-2] = CAISSE;
      Plateau[y][x-1] = MANU;
      Plateau[y][x] = CIBLE;
      CompteurMouv ++;
      CompteurPouss ++;
    }

    else if(Plateau[y][x-2]== CIBLE && Plateau [y][x-1] == CAISSE && Plateau[y][x] == MANUSURCIBLE){
      Plateau[y][x-2] = CAISSESURCIBLE;
      Plateau[y][x-1] = MANU;
      Plateau[y][x] = CIBLE;
      CompteurMouv ++;
      CompteurPouss ++;
    }

    else if (Plateau[y][x-2] == VIDE && Plateau[y][x-1] == CAISSESURCIBLE && Plateau[y][x] == MANU){
      Plateau[y][x-2] = CAISSE;
      Plateau[y][x-1] = MANUSURCIBLE;
      Plateau[y][x] = VIDE;
      CompteurMouv ++;
      CompteurPouss ++;
    }

    else if(Plateau[y][x-2] == CIBLE && Plateau[y][x-1] == CAISSESURCIBLE && Plateau[y][x] == MANU){
      Plateau[y][x-2] = CAISSESURCIBLE;
      Plateau[y][x-1] = MANUSURCIBLE;
      Plateau[y][x] = VIDE;
      CompteurMouv ++;
      CompteurPouss ++;
    }

    else if (Plateau [y][x-2] == VIDE && Plateau [y][x-1] == CAISSESURCIBLE && Plateau[y][x] == MANUSURCIBLE){
      Plateau[y][x-2] = CAISSE;
      Plateau[y][x-1] = MANUSURCIBLE;
      Plateau[y][x] = CIBLE;
      CompteurMouv ++;
      CompteurPouss ++;
    }
    else if(Plateau[y][x-2]== CIBLE && Plateau [y][x-1] == CAISSESURCIBLE && Plateau[y][x] == MANUSURCIBLE){
      Plateau[y][x-2] = CAISSESURCIBLE;
      Plateau[y][x-1] = MANUSURCIBLE;
      Plateau[y][x] = CIBLE;
      CompteurMouv ++;
      CompteurPouss ++;
    }
    else;

    break;
  }
  return CompteurPouss;
}

///DeplacerManu permet de gérer les déplacements du manutentionnaire.
int DeplacerManu(char ** Plateau, int direction, int x, int y){
  int CompteurMouv = 0;
  int CompteurPouss=0;
  switch(direction){
    case Haut : if(Plateau[y-1][x] == VIDE && Plateau[y][x] == MANU){
        Plateau[y-1][x] = MANU;
        Plateau[y][x] = VIDE;
        CompteurMouv ++;
      }
      else if(Plateau[y-1][x] == CIBLE && Plateau[y][x] == MANU){
        Plateau[y-1][x] = MANUSURCIBLE;
        Plateau[y][x] = VIDE;
        CompteurMouv ++;
      }
      else if(Plateau[y-1][x] == VIDE && Plateau[y][x] == MANUSURCIBLE){
        Plateau[y-1][x] = MANU;
        Plateau[y][x] = CIBLE;
        CompteurMouv ++;
      }
      else if(Plateau[y-1][x] == CIBLE && Plateau[y][x] == MANUSURCIBLE){
        Plateau[y-1][x] = MANUSURCIBLE;
        Plateau[y][x] = CIBLE;
        CompteurMouv ++;
      }

    else if(Plateau[y-1][x] == MUR){
    }
    else{
      PousserCaisse(Plateau ,Haut, x, y);
      CompteurPouss++;
    }
    break;

    case Bas : if(Plateau[y+1][x] == VIDE && Plateau[y][x] == MANU){
        Plateau[y+1][x] = MANU;
        Plateau[y][x] = VIDE;
        CompteurMouv ++;
      }
      else if(Plateau[y+1][x] == CIBLE && Plateau[y][x] == MANU){
        Plateau[y+1][x] = MANUSURCIBLE;
        Plateau[y][x] = VIDE;
        CompteurMouv ++;
      }
      else if(Plateau[y+1][x] == VIDE && Plateau[y][x] == MANUSURCIBLE){
        Plateau[y+1][x] = MANU;
        Plateau[y][x] = CIBLE;
        CompteurMouv ++;
      }
      else if(Plateau[y+1][x] == CIBLE && Plateau[y][x] == MANUSURCIBLE){
        Plateau[y+1][x] = MANUSURCIBLE;
        Plateau[y][x] = CIBLE;
        CompteurMouv ++;
      }

      else if(Plateau[y+1][x] == MUR){
      }
    else{
      PousserCaisse(Plateau ,Bas, x, y);
      CompteurPouss++;
    }
    break;

    case Droite :
    if(Plateau[y][x-1] == VIDE && Plateau[y][x] == MANU){
      Plateau[y][x-1] = MANU;
      Plateau[y][x] = VIDE;
      CompteurMouv ++;
    }
    else if(Plateau[y][x-1] == CIBLE && Plateau[y][x] == MANU){
      Plateau[y][x-1] = MANUSURCIBLE;
      Plateau[y][x] = VIDE;
      CompteurMouv ++;
    }
    else if(Plateau[y][x-1] == VIDE && Plateau[y][x] == MANUSURCIBLE){
      Plateau[y][x-1] = MANU;
      Plateau[y][x] = CIBLE;
      CompteurMouv ++;
    }
    else if(Plateau[y][x-1] == CIBLE && Plateau[y][x] == MANUSURCIBLE){
      Plateau[y][x-1] = MANUSURCIBLE;
      Plateau[y][x] = CIBLE;
      CompteurMouv ++;
    }

    else if(Plateau[y][x-1] == MUR){
    }
    else{
      PousserCaisse(Plateau ,Droite, x, y);
      CompteurPouss++;
    }

    break;

    case Gauche:
    if(Plateau[y][x+1] == VIDE && Plateau[y][x] == MANU){
      Plateau[y][x+1] = MANU;
      Plateau[y][x] = VIDE;
      CompteurMouv ++;
    }
    else if(Plateau[y][x+1] == CIBLE && Plateau[y][x] == MANU){
      Plateau[y][x+1] = MANUSURCIBLE;
      Plateau[y][x] = VIDE;
      CompteurMouv ++;
    }
    else if(Plateau[y][x+1] == VIDE && Plateau[y][x] == MANUSURCIBLE){
      Plateau[y][x+1] = MANU;
      Plateau[y][x] = CIBLE;
      CompteurMouv ++;
    }
    else if(Plateau[y][x+1] == CIBLE && Plateau[y][x] == MANUSURCIBLE){
      Plateau[y][x+1] = MANUSURCIBLE;
      Plateau[y][x] = CIBLE;
      CompteurMouv ++;
    }

    else if(Plateau[y][x+1] == MUR){
    }
    else{
      PousserCaisse(Plateau ,Gauche, x, y);
      CompteurPouss++;
    }
  break;
}
  return CompteurPouss;
}
