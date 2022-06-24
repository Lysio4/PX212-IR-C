#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "pile.h"



/* Insertion en "t�te de liste" */
void insertionTete(Lnode **ph,char item, char item2){
	Lnode* node = (Lnode*) malloc(sizeof(Lnode));
	Donnee Temp;
	Temp.Deplacement = item;
	Temp.Poussee = item2;
	node->data = Temp;
	node->link = *ph;
	*ph = node;
	}

/* Insertion en "queue de liste" */
void insertionQueue(Lnode **ph,char item, char item2)	{
	Lnode* node = (Lnode*) malloc(sizeof(Lnode));
	Donnee Temp;
	Temp.Deplacement = item;
	Temp.Poussee = item2;
	node->data = Temp;
	node->link = NULL;
	Lnode* ptr;
	ptr = *ph;
	while (ptr->link != NULL)
	{
		ptr = ptr->link;
	}
	ptr->link = node;
	}

/* Suppression en "t�te de liste" */
Donnee suppressionTete(Lnode **ph){
	Donnee Retour= {0};
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

/* Suppression en "Queue" de liste" */
void suppressionQueue(Lnode **ph){
	Lnode* ptr;
	ptr = *ph;
	while (ptr != NULL)
	{
		ptr = ptr->link;
	}
	ptr->link = NULL;
	}
