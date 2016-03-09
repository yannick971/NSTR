#include "fonctions_utiles.h"
#include "piece.h"


void *Th_piece(pthread_t code_piece, pthread_t numero_machine)
{
	pthread_mutex_t mutex_machine = PTHREAD_MUTEX_INITIALIZER;
	pthread_mutex_t mutex_convoyeur = PTHREAD_MUTEX_INITIALIZER;
	

	pthread_mutex_lock(&mutex_machine);
	pthread_mutex_lock(&mutex_convoyeur);

	char *message;
	message= malloc(sizeof(char));

	send("deposer piece brute sur convoyeur\n", Th_robot_alimentation);

	if((message == NULL) ||strcmp(message, "defaillance"))
	{
		pthread_kill(Th_dialogue, SIGUSR1);
		erreur("arret du systeme de supervision: le robot d'alimentation ne\
		 repond pas ou bien il n'a pas pu retirer la pièce au bout de 20s.\n");
	}
	else /* thread a reçu fin depot piece brute sur convoyeur */
	{
		send("deposer piece brute sur table\n",Th_machine[1]);
		receive(message,sec);
	}
	if (message == NULL)
	{
		pthread_kill(Th_dialogue,SIGUSR1);
		erreur("arret du systeme de supervision: la machine n'a pas fini de\
		 retirer la piece du convoyeur apres 50sec.\n"); /*ajout num machine*/
	}	

	/*le thread a reçu fin depot piece brute sur table */

	pthread_mutex_unlock(&mutex_convoyeur);
	/*time_received(message,sec);*/

	if(message == NULL)
	{
		pthread_mutex_lock(&Mutex1);
		Machine_etat= fonctionne;
		pthread_mutex_unlock(&Mutex1);
		pthread_kill(Th_dialogue, SIGUSR2);
		erreur("La machine n'a pas fini son operation d'usinage après 10 minutes\n");
	}

	/* le thread a reçu fin usinage */
	pthread_mutex_lock(&mutex_convoyeur);
	send("deposer piece usinee sur convoyeur",Th_machine[1]);
	received(message, sec);

	if(message == NULL)
	{
		pthread_kill(Th_dialogue, SIGUSR1);
		erreur("arret du systeme de supervision, la machine n'a pas fini de retirer la piece au bout de 50sec\n"); /*donner num machine*/
	}
	else
	{
		send("retirer piece usinee du convoyeur", Th_robot_retrait);
		timed_received(message,sec);
	}

	if(message == NULL)
	{
		pthread_kill(Th_dialogue,SIGUSR1);
		erreur("le robot de retrait n'a pas fini le retrait de la piece usine après 30 sec\n");
	}

	/*le thread a reçu fin_retrait_piece_usinee_du_convoyeur*/
	else
	{
		pthread_mutex_unlock(&mutex_convoyeur);
		pthread_mutex_unlock(&mutex_machine);
		pthread_kill(Th_dialogue, SIGUSR2);
		printf("usinage de la piece, code piece: OK\n"); /* manque code piece*/
	}
	
	return 0;
	
}
