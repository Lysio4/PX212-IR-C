#ifndef _PILE_H
#define _PILE_H

/* Ici, on est oblig� d'utiliser la notation struct xxx,
car la structure s'auto-r�f�rence!*/
typedef struct node {
		char data ;
		struct node *link ;
		} Lnode ;

void insertionTete(Lnode **ph,Coordonnees item,int direction,bool caisse);
void insertionQueue(Lnode **ph,Coordonnees item,int direction,bool caisse);
void suppressionTete(Lnode **ph);
void suppressionQueue(Lnode **ph);
void listeAffiche(Lnode * ptr);

#endif
