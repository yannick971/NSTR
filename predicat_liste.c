#include "predicat_liste.h"


list supprimerElementEnTete(list liste)
{
	if(liste != NULL)
	{
		pthread* aRenvoyer = liste->next;
		free (liste);
		return aRenvoyer;
	}
	else
		return NULL;
}

list ajouterEnTete(list liste, pthread_t val)
{
	pthread_t* nouvelElement = malloc(sizeof(pthread_t));
	nouvelElement-> t = val;
	nouvelElement-> next =liste;
	return nouvelElement;
}

list ajouter_en_queue(list liste,pthread_t val)
{
	pthread_t* nouvelElement = malloc(sizeof(pthread_t));
	if(!nouvelElement) exit(EXIT_FAILURE);
	
	if(liste == NULL)
		return nouvelElement;
	else
	{
		pthread_t* temp = liste;
		while( temp -> next !=NULL)
		{
			temp = temp -> next;
		}
		
		temp -> next = nouvelElement;
		
		return liste;
}
	
