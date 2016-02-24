#include "fonctions_utiles.h"

int nbMachine = 3;
bool MachineEnPanne[nbMachine] = false;
pthread_mutex_t MutexMachine[nbMachine]=1;
pthread_mutex_t Mutex1 = 1;


typedef struct list_thread list_thread

struct list_thread
{
	pthread_t t;
	struct list_thread *next;

};
typedef list_thread* list;



void *Th_Dialogue()
{
	pthread_t Th_Piece;
	pthread_t Numero_machine;
	int piece;
	
	piece = pthread_create(&Th_Piece, NULL,Th_piece,NULL);
	
	if(!piece)
		printf("creation thread piece reussi\n");
		
	list ListeThreadPiece = Vide;
	
	void fonc_evenementielle_USER1 (list l)
	{
		pthread x;
		while( l != NULL)
		{
			x= l;
			pthread_sigkill(SIGKILL,x);
			erreur("fin anormale du systeme\n");
		}
	}

	void fnc_evenementielle_SIGUSER2(list l)
	{
		RemoveFromListe(Liste_ThreadPiece, Sender);
	}

 	while(1)
 	{
	 	Saire_ordre_operateur(code_piece);
	 	Numero_machine = corresponce_machine_code(Th_Piece);
 	}
	
}
