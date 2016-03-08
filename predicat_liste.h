#ifndef PREDICAT_LISTE
#define PREDICAT_LISTE

#include "predicat_liste.h"

typedef struct list_thread list_thread;
struct list_thread
{
	pthread_t t;
	struct list_thread *next;

};
typedef list_thread* list;

list supprimerElementEnTete(list liste);
list ajouterEnTete(list liste, pthread_t val);
list ajouter_en_queue(list liste,pthread_t val);

#endif
