#ifndef _PILE_H
#define _PILE_H

/**
*Structure utilisée dans la pile.
*/
typedef struct {
	char Deplacement;//!Le déplacement de l'item.
	char Poussee;//!Poussée ou non du personnage.
} Donnee ;

/**
*Structure de la pile pour les fonctions de retour arrière.
*/
typedef struct Liste {
	Donnee data;
		struct Liste *link ;
} Lnode ;

void insertionTete(Lnode **ph,char item, char Data2);
Donnee suppressionTete(Lnode **ph);
void listeAffiche(Lnode * ptr);

#endif
