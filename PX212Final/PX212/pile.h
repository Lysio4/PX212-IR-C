#ifndef _PILE_H
#define _PILE_H

/* Ici, on est oblig� d'utiliser la notation struct xxx,
car la structure s'auto-r�f�rence!*/
typedef struct {
	char Deplacement;
	char Poussee;
} Donnee ;

typedef struct Liste {
	Donnee data;
		struct Liste *link ;
} Lnode ;

void insertionTete(Lnode **ph,char item, char Data2);
void insertionQueue(Lnode **ph,char item, char Data2);
Donnee suppressionTete(Lnode **ph);
void suppressionQueue(Lnode **ph);
void listeAffiche(Lnode * ptr);

#endif
