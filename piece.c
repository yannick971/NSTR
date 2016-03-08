#include "fonctions_utiles.h"

void *Th_piece(pthread_t code_piece, pthread_t numero_machine)
{
	pthread_mutex_t mutex_machine[3];
	pthread_mutex_t mutex_convoyeur;


	mutex_lock(mutex_machine[3]);
	mutex_lock(mutex_convoyeur);

	char *message;
	message= malloc(sizeof(char));

	send("deposer piece brute sur convoyeur\n", Th_Robot_alimentation);

	if((message == NULL) || message == "defaillance")
	{
		pthread_kill(Th_dialogue, SIGUSER1);
		erreur("arret du systeme de supervision: le robot d'alimentation ne\
		 repond pas ou bien il n'a pas pu retirer la pièce au bout de 20s.\n");
	}
	else /* thread a reçu fin depot piece brute sur convoyeur */
	{
		send("deposer piece brute sur table\n",Th_machine[1]);
		time_receive(message,sec);
	}
	if (message == NULL)
	{
		pthread_kill(Th_dialogue,SIGUSR1);
		erreur("arret du systeme de supervision: la machine n'a pas fini de\
		 retirer la piece du convoyeur apres 50sec.\n"); /*ajout num machine*/
	}	

	/*le thread a reçu fin depot piece brute sur table */

	mutex_unlock(mutex_convoyeur);
	/*time_received(message,sec);*/

	if(message == NULL)
	{
		mutex_lock(Mutex1);
		Machine_en_panne[1]= 1;
		mutex_unlock(Mutex1);
		pthread_kill(Th_dialogue, SIGUSR2);
		erreur("La machine n'a pas fini son operation d'usinage après 10 minutes\n");
	}

	/* le thread a reçu fin usinage */
	mutex_lock(mutex_convoyeur);
	send("deposer piece usinee sur convoyeur",Th_machine[1]);
	timed_received(message, sec);

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
		mutex_unlock(mutex_convoyeur);
		mutex_unlock(mutex_machine[1]);
		pthread_kill(Th_dialogue, SIGUSER2);
		printf("usinage de la piece, code piece: OK\n"); /* manque code piece*/
	}
	
	return 0;
	
}
