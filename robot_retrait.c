#include "fonctions_utiles.h"
#include "robot_retrait.h"



void *Th_Robot_retrait()
{
	void fnc_evenementielle_timerRR()
	{
		send(defaillance, x);
		erreur("arret du robot de retrait, car l'aopération de retrait de piece ne s'est pas terminé avant 30 sec\n");
	}
	while(1)
	{
		receive(retirer_piece_usine_du_convoyeur);
		x=sender;
		armer_timer(timer_RR, 30);
		retirer_piece_usinee_du_convoyeur();
		desarmer_timer(timer_RR);
		send(fin_retrait_piece_usinee_du_convoyeur,x);
	}
}
