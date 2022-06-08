#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "header.h"

/* Ici, on est oblig� d'utiliser la notation struct xxx,
car la structure s'auto-r�f�rence!*/
/*typedef struct node {
		Coordonnees data ;
		int direction;
		bool deplacement;
		struct node *link ;
		} Lnode ;*/

/* Insertion en "t�te de liste" */
void insertionTete(Lnode **ph,Coordonnees item,int direction,bool caisse){
	Lnode* node = (Lnode*) malloc(sizeof(Lnode));
	node->data = item;
	node->direction = direction;
	node->deplacement = caisse;
	node->link = *ph;
	*ph = node;
	}

/* Insertion en "queue de liste" */
void insertionQueue(Lnode **ph,Coordonnees item,int direction,bool caisse)	{
	Lnode* node = (Lnode*) malloc(sizeof(Lnode));
	node->data = item;
	node->direction = direction;
	node->deplacement = caisse;
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
void suppressionTete(Lnode **ph){
	if (*ph != NULL)
	{
		*ph = (*ph)->link;
	}
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

/* Proc�dure d'affichage de la liste. Ne doit pas �tre modifi�e!!! */
void listeAffiche(Lnode * ptr){
	if ( NULL == ptr )
		printf("Liste vide!") ;
	else 
		printf("Contenu de la liste : ") ;
	while ( NULL != ptr ) 	{
		printf("%c ",ptr->data.x);
		printf("%c ",ptr->data.y);
		ptr = ptr->link ;
		}
	printf("\n") ;
	}

/* Programme principal. Ne doit pas �tre modifi�!!! */
/*int main(void) {
	Lnode *tete = NULL ;

	listeAffiche(tete) ;
	insertionTete(&tete,'a') ;
	listeAffiche(tete) ;
	insertionTete(&tete,'c') ;
	listeAffiche(tete) ;
	insertionQueue(&tete,'t') ;
	listeAffiche(tete) ;
	insertionQueue(&tete,'s') ;
	listeAffiche(tete) ;
	suppressionTete(&tete) ;
	listeAffiche(tete) ;
	suppressionTete(&tete) ;
	listeAffiche(tete) ;
	suppressionQueue(&tete) ;
	listeAffiche(tete) ;
	suppressionTete(&tete) ;
	listeAffiche(tete) ;

   return EXIT_SUCCESS;
   }	*/