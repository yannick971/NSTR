#include "fonctions_utiles.h"
#include "Th_Robot_alimentation.h"

void *Th_Robot_alimentation()
{
	int horloge=0;
	void fnc_evenementielle_timerRA()
	{
		send(defaillance,x);
		erreur("arrêt du robot d'alimentation, car l operation de depot de piece a dure plus de 20sec");
	}
	
	while(1)
	{
		receive(deposer_piece_brute_sur_convoyeur);
		x=Sender;
		horloge = clock_settime(clockid, t); 
		deposer_piece_brute();
		send(fin_depot_piece_brute_sur_convoyeur, x);
	}
	
	
}
