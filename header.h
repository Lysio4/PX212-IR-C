#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//io.c + touches.c
int litClavier();
int main();
void touches();

//actions.c
typedef struct node {
		char data ;
		struct node *link ;
		} Lnode ;
void insertionTete(Lnode **ph,char item);
void insertionQueue(Lnode **ph,char item);
void suppressionTete(Lnode **ph);
void suppressionQueue(Lnode **ph);
void listeAffiche(Lnode * ptr);
