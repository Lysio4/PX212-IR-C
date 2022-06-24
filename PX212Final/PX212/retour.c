#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "retour.h"


void retour(char ** Plateau,Lnode **move){
  Donnee Element;
  int Xtemp=PosManu.x;
  int Ytemp=PosManu.y;
  int Compteur=0;    Element = suppressionTete(move);
  switch (Element.Deplacement){
    case UP:
      deplacerManu(Plateau, Bas,PosManu.x, PosManu.y);
      Compteur++;
      RetourMouv--;
      if(Element.Poussee){ //si élément poussé
        RetourPouss--;
        if(Plateau[Ytemp][Xtemp]==CIBLE){ //si emplacement ou été manu devenu cible
          Plateau[Ytemp][Xtemp]=CAISSESURCIBLE; //alors caisse sur cible
        }else{
          Plateau[Ytemp][Xtemp]=CAISSE; //sinon juste caisse
        }

        if(Plateau[Ytemp-1][Xtemp]==CAISSE){
          Plateau[Ytemp-1][Xtemp]=VIDE;
        }else if (Plateau[Ytemp-1][Xtemp]==CAISSESURCIBLE){
          Plateau[Ytemp-1][Xtemp]=CIBLE;
        }
      }
    break;

    case DOWN:
      deplacerManu(Plateau, Haut,PosManu.x, PosManu.y);
      Compteur++;
      RetourMouv--;
      if(Element.Poussee){ //si élément poussé
        RetourPouss--;
        if(Plateau[Ytemp][Xtemp]==CIBLE){ //si emplacement ou été manu devenu cible
          Plateau[Ytemp][Xtemp]=CAISSESURCIBLE; //alors caisse sur cible
        }else{
          Plateau[Ytemp][Xtemp]=CAISSE; //sinon juste caisse
        }
        if(Plateau[Ytemp+1][Xtemp]==CAISSE){
          Plateau[Ytemp+1][Xtemp]=VIDE;
        }else if (Plateau[Ytemp+1][Xtemp]==CAISSESURCIBLE){
          Plateau[Ytemp+1][Xtemp]=CIBLE;
        }
      }
    break;

    case LEFT:
      deplacerManu(Plateau,Droite,PosManu.x, PosManu.y );
      Compteur++;
      RetourMouv--;
      if(Element.Poussee){ //si élément poussé
        RetourPouss--;
        if(Plateau[Ytemp][Xtemp]==CIBLE){ //si emplacement ou été manu devenu cible
          Plateau[Ytemp][Xtemp]=CAISSESURCIBLE; //alors caisse sur cible
        }else{
          Plateau[Ytemp][Xtemp]=CAISSE; //sinon juste caisse
        }

        if(Plateau[Ytemp][Xtemp+1]==CAISSE){
          Plateau[Ytemp][Xtemp+1]=VIDE;
        }else if (Plateau[Ytemp][Xtemp+1]==CAISSESURCIBLE){
          Plateau[Ytemp][Xtemp+1]=CIBLE;
        }
      }
    break;

    case RIGHT:
      deplacerManu(Plateau,Gauche,PosManu.x, PosManu.y );
      Compteur++;
      RetourMouv--;
      if(Element.Poussee){ //si élément poussé
        RetourPouss--;
        if(Plateau[Ytemp][Xtemp]==CIBLE){ //si emplacement ou été manu devenu cible
          Plateau[Ytemp][Xtemp]=CAISSESURCIBLE; //alors caisse sur cible
        }else{
          Plateau[Ytemp][Xtemp]=CAISSE; //sinon juste caisse
        }

        if(Plateau[Ytemp][Xtemp-1]==CAISSE){
          Plateau[Ytemp][Xtemp-1]=VIDE;
        }else if (Plateau[Ytemp][Xtemp-1]==CAISSESURCIBLE){
          Plateau[Ytemp][Xtemp-1]=CIBLE;
        }
      }
    break;

  }
  //return Compteur;
}
