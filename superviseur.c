#include "fonctions_utiles.h"
#include "predicat_liste.h"
#include "superviseur.h"


list l;
/*bool Machine_En_Panne[3] = false;*/

void *Th_Dialogue()
{
	pthread_t Th_Piece;
	pthread_t code_piece;
	pthread_t Numero_machine = Th_machine[2];
	int piece = pthread_create(&Th_Piece, NULL,Th_piece(code_piece,Numero_machine),NULL);
	
	if(!piece)
		printf("creation thread piece reussi\n");
	
	void fonc_evenementielle_USER1 (list l)
	{

		pthread_t x;
		while( l != NULL)
		{
			/*x= l;*/
			pthread_kill(SIGKILL,x);
			erreur("fin anormale du systeme\n");
		}
	}

	void fnc_evenementielle_SIGUSER2(list l)
	{
		//~ RemoveFromListe(l, Sender);
		supprimerElementEnTete(l);
	}


 	while(1)
 	{
	 	/*Saisir_ordre_operateur(code_piece);*/
	 	/*Numero_machine = corresponce_machine_code(Th_Piece);*/
		pthread_mutex_lock(&Mutex1);
		Machine_etat= en_panne;
		pthread_mutex_unlock(&Mutex1);
		/*x= l;
		pthread_sigkill(SIGKILL,x);
		erreur("fin anormale du systeme\n");
		*/
		
		if(Machine_etat == true)
		{
			afficher("machine demandée en panne\n");
			while (l != NULL)
			 sleep (10);
			erreur("fin systeme: defaillance detecté\n");
		}
		else 
		{
			pthread_t New_thread;
			int newPiece =  pthread_create(&New_thread, NULL, Th_piece, NULL);
			if(!newPiece)
				printf("Creation thread dialogue reussi!\n");
			ajouter_en_queue(l,New_thread);
		}	
	}
}
