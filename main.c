#include "fonctions_utiles.h"

int main (void)
{
	
	pthread_t Th_Dialogue;
	pthread_t Th_Robot_alimentation;
	pthread_t Th_Robot_retrait;
	pthread_t Th_Machine;
	
	int dial=0;
	int r_alim=0;
	int r_retrait=0;
	int machine[3] = 0;
	int i=0;
	
	dial = pthread_create(&Th_Dialogue, NULL, Th_Dialogue);
	r_alim = pthread_create(&Th_Robot_alimentation, NULL, Th_Robot_alimentation);
	r_retrait = pthread_create(&Th_Robot_retrait, NULL, Th_robot_retrait);
	
	
	for(i=0;i<3;i++)
	{
		
		machine[i] = pthread_create(&Th_Machine, NULL, Th_machine);
			if(!machine[i])
				printf("Creation thread machine reussi!\n");
			else
				erreur("thread machine non crée\n");
	
	}
	
	if(!dial)
		printf("Creation thread dialogue reussi!\n");
	
	if(!r_alim)
		printf("Creation thread robot alim reussi!\n");
		
	if(!r_retrait)
		printf("Creation thread robot retrait reussi!\n");
		
	return 0;

	return 0;

	//tu vois mon commentaire??

}
