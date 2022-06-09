#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "pile.h"


/**
*insertionTete permet d'empiler une donnée sur une pile donnée.
*/
void insertionTete(Lnode **ph,char item, char item2){
	Lnode* node = (Lnode*) malloc(sizeof(Lnode));
	Donnee Temp;
	Temp.Deplacement = item;
	Temp.Poussee = item2;
	node->data = Temp;
	node->link = *ph;
	*ph = node;
	}

/**
*suppressionTete permet de dépiler une donnée d'une pile donnée.
*/
Donnee suppressionTete(Lnode **ph){
	Donnee Retour;
	Retour.Deplacement = -1;
	Lnode *temp;
	if (*ph != NULL)
	{
		temp = *ph;
		*ph = (*ph)->link;
		Retour = temp->data;
		free(temp);
	}
	return Retour;
	}

void listeAffiche(Lnode * ptr){
	if ( NULL == ptr )
		printf("Liste vide!") ;
	else
		printf("Contenu de la liste : ") ;
	while ( NULL != ptr ) 	{
		ptr = ptr->link ;
		}
	printf("\n") ;
	}
