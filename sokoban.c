#include <stdlib.h>
#include <stdio.h>

#include "sokoban.h"

int PousserCaisse(int direction, int x, int y){
  int Position[2][2];
  switch(direction){
    case Haut : if (Position[x][y-2] == Vide && Position[x][y-1] == Caisse && Position[x][y] == Manu){
      Position[x][y-2] = Caisse;
      Position[x][y-1]= Manu;
      Position[x][y] = Vide;
    }
    else if(Position[x][y-2] == Cible){
      Position[x][y-2] = CaisseSurCible;
      Position[x][y-1] = Manu;
      Position[x][y] = Vide;
    }
    else;

    if (Position [x][y-2] == Vide && Position [x][y-1] == Caisse && Position[x][y] == ManuSurCible){
      Position[x][y-2] = Caisse;
      Position[x][y-1]= Manu;
      Position[x][y]= Cible;
    }
    else if(Position[x][y-2]== Cible){
      Position[x][y-2] = CaisseSurCible;
      Position[x][y-1]= Manu;
      Position[x][y]= Cible;
    }
    else;

    if (Position[x][y-2] == Vide && Position[x][y-1] == CaisseSurCible && Position[x][y] == Manu){
      Position[x][y-2] = Caisse;
      Position[x][y-1]= ManuSurCible;
      Position[x][y]= Vide;
    }
    else if (Position[x][y-2] == Cible){
      Position[x][y-2] = CaisseSurCible;
      Position[x][y-1] = Manu;
      Position[x][y] = Vide;
    }
    else;

    if (Position [x][y-2] == Vide && Position [x][y-1] == CaisseSurCible && Position[x][y] == ManuSurCible){
        Position[x][y-2] = Caisse;
        Position[x][y-1] = ManuSurCible;
        Position[x][y] = Cible;
    }
    else if(Position[x][y-2]== Cible){
        Position[x][y-2] = CaisseSurCible;
        Position[x][y-1] = ManuSurCible;
        Position[x][y] = Cible;
    }
    else;
    break;

    case Bas : if (Position[x][y+2] == Vide && Position[x][y+1] == Caisse && Position[x][y] == Manu){
      Position[x][y+2] = Caisse;
      Position[x][y+1] = Manu;
      Position[x][y] = Vide;
    }
    else if(Position[x][y+2]== Cible){
      Position[x][y+2] = CaisseSurCible;
      Position[x][y+1] = Manu;
      Position[x][y] = Vide;
    }

    else;

    if (Position [x][y+2] == Vide && Position [x][y+1] == Caisse && Position[x][y] == ManuSurCible){
      Position[x][y+2] = Caisse;
      Position[x][y+1] = Manu;
      Position[x][y] = Cible;
    }
    else if(Position[x][y+2]== Cible){
      Position[x][y+2] = CaisseSurCible;
      Position[x][y+1] = Manu;
      Position[x][y] = Cible;
    }

    else;

    if (Position[x][y+2] == Vide && Position[x][y+1] == CaisseSurCible && Position[x][y] == Manu){
      Position[x][y+2] = Caisse;
      Position[x][y+1] = ManuSurCible;
      Position[x][y] = Vide;
    }
    else if(Position[x][y+2]== Cible){
      Position[x][y+2] = CaisseSurCible;
      Position[x][y+1]= Manu;
      Position[x][y] = Vide;
    }

    else;

    if (Position [x][y+2] == Vide && Position [x][y+1] == CaisseSurCible && Position[x][y] == ManuSurCible){
      Position[x][y+2] = Caisse;
      Position[x][y+1] = ManuSurCible;
      Position[x][y] = Cible;
    }

    else if(Position[x][y+2]== Cible){
      Position[x][y+2] = CaisseSurCible;
      Position[x][y+1] = ManuSurCible;
      Position[x][y] = Cible;
    }

    else;

    break;

    case Droite : if (Position[x+2][y] == Vide && Position[x+1][y] == Caisse && Position[x][y] == Manu){
      Position[x+2][y] = Caisse;
      Position[x+1][y] = Manu;
      Position[x][y] = Vide;
    }

    else if(Position[x+2][y]== Cible){
      Position[x+2][y] = CaisseSurCible;
      Position[x+1][y] = Manu;
      Position[x][y] = Vide;
    }

    else;

    if (Position [x+2][y] == Vide && Position [x+1][y] == Caisse && Position[x][y] == ManuSurCible){
      Position[x+2][y] = Caisse;
      Position[x+1][y] = Manu;
      Position[x][y] = Cible;
    }

    else if(Position[x+2][y]== Cible){
      Position[x+2][y] = CaisseSurCible;
      Position[x+1][y] = Manu;
      Position[x][y] = Cible;
    }

    else;

    if (Position[x+2][y] == Vide && Position[x+1][y] == CaisseSurCible && Position[x][y] == Manu){
      Position[x+2][y] = Caisse;
      Position[x+1][y] = ManuSurCible;
      Position[x][y] = Vide;
    }
    else if(Position[x+2][y] == Cible){
      Position[x+2][y] = CaisseSurCible;
      Position[x+1][y] = Manu;
      Position[x][y] = Vide;
    }

    else;

    if (Position [x+2][y] == Vide && Position [x+1][y] == CaisseSurCible && Position[x][y] == ManuSurCible){
      Position[x+2][y] = Caisse;
      Position[x+1][y] = ManuSurCible;
      Position[x][y] = Cible;
    }

    else if(Position[x+2][y] == Cible){
      Position[x+2][y] = CaisseSurCible;
      Position[x+1][y] = ManuSurCible;
      Position[x][y] = Cible;
    }

    else;

    break;

    case Gauche : if (Position[x-2][y] == Vide && Position[x-1][y] == Caisse && Position[x][y] == Manu){
      Position[x-2][y] = Caisse;
      Position[x-1][y] = Manu;
      Position[x][y] = Vide;
    }

    else if(Position[x-2][y]== Cible){
      Position[x-2][y] = CaisseSurCible;
      Position[x-1][y] = Manu;
      Position[x][y] = Vide;
    }

    else;

    if (Position [x-2][y] == Vide && Position [x-1][y] == Caisse && Position[x][y] == ManuSurCible){
      Position[x+2][y] = Caisse;
      Position[x-1][y] = Manu;
      Position[x][y] = Cible;
    }

    else if(Position[x-2][y]== Cible){
      Position[x-2][y] = CaisseSurCible;
      Position[x-1][y] = Manu;
      Position[x][y] = Cible;
    }

    else;

    if (Position[x-2][y] == Vide && Position[x-1][y] == CaisseSurCible && Position[x][y] == Manu){
      Position[x-2][y] = Caisse;
      Position[x-1][y] = ManuSurCible;
      Position[x][y] = Vide;
    }

    else if(Position[x-2][y] == Cible){
      Position[x-2][y] = CaisseSurCible;
      Position[x-1][y] = Manu;
      Position[x][y] = Vide;
    }

    else;

    if (Position [x-2][y] == Vide && Position [x-1][y] == CaisseSurCible && Position[x][y] == ManuSurCible){
      Position[x-2][y] = Caisse;
      Position[x-1][y] = ManuSurCible;
      Position[x][y] = Cible;
    }
    else if(Position[x-2][y]== Cible){
      Position[x-2][y] = CaisseSurCible;
      Position[x-1][y] = ManuSurCible;
      Position[x][y] = Cible;
    }
    else;

    break;
  }
  return 0;
}

int DeplacerManu(int direction){
  int y;
  int x;
  int Position[2][2];
  switch(direction){
    case Haut : if(Position[x][y-1] == Vide){
      Position[x][y-1] = Manu;
      Position[x][y] = Vide;
    }
    else if(Position[x][y-1] == Cible){
      Position[x][y-1] = ManuSurCible;
      Position[x][y] = Vide;
    }

    else if(Position[x][y-1] == Mur){
    }
    else{
      PousserCaisse(Haut, x, y);
    }
    break;

    case Bas : if(Position[x][y+1] == Vide){
      Position[x][y+1] = Manu;
      Position[x][y] = Vide;
    }
    else if(Position[x][y+1] == Cible){
      Position[x][y+1] = ManuSurCible;
      Position[x][y] = Vide;
    }

    else if(Position[x][y+1] == Mur){
    }
    else{
      PousserCaisse(Bas, x, y);
    }
    break;

    case Droite : if(Position[x+1][y] == Vide){
      Position[x+1][y] = Manu;
      Position[x][y] = Vide;
    }
    else if(Position[x+1][y] == Cible){
      Position[x][y+1] = ManuSurCible;
      Position[x][y] = Vide;
    }

    else if(Position[x+1][y] == Mur){
    }
    else{
      PousserCaisse(Droite, x, y);
    }

    break;

    case Gauche : if(Position[x-1][y] == Vide){
      Position[x-1][y] = Manu;
      Position[x][y] = Vide;
    }
    else if(Position[x-1][y] == Cible){
      Position[x][y-1] = ManuSurCible;
      Position[x][y] = Vide;
    }

    else if(Position[x-1][y] == Mur){
    }
    else{
      PousserCaisse(Gauche, x, y);
    }
  }
  return 0;
}
