#include "fonctions_utiles.h"

void *Th_Machine()
{
	pthread_t Sender;

	while(1)
	{
		receive("deposer piece brute sur table\n ");
		Sender = demande_usinage();
		retirer_piece_du_convoyeur();
		send("fin depot piece sur table\n",x);
		usinage();
		send("fin usinage\n",x);
		receive("deposer piece usinee sur convoyeur\n");
		deposer_piece();
		send("fin depot piece sur convoyeur", x);
	}
}
