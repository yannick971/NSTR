#include "fonctions_utiles.h"
#include "superviseur.h"
#include "Th_Robot_alimentation.h"
#include "robot_retrait.h"
#include "machine.h"
#include "predicat_liste.h"


#define nbMachine  3



int main(void)
{		
	int dial=0;
	int r_alim=0;
	int r_retrait=0;
	int machine[3] = {0};
	int i=0;
	
	dial = pthread_create(&Th_dialogue, NULL, Th_Dialogue ,NULL);
	r_alim = pthread_create(&Th_robot_alimentation, NULL, Th_Robot_alimentation,NULL);
	r_retrait = pthread_create(&Th_robot_retrait, NULL, Th_Robot_retrait,NULL);
	
	
	for(i=0;i<3;i++)
	{
		

		machine[i] = pthread_create(&Th_machine[i], NULL, Th_Machine,NULL);

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
		
	if(pthread_join(Th_dialogue,NULL))
		perror("join dialogue\n");
	if(pthread_join(Th_robot_alimentation,NULL))
		perror("join robot alim\n");
	if(pthread_join(Th_robot_retrait,NULL))
		perror("join robot retrait\n");
		
	return 0;
}
