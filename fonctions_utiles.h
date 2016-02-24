#ifndef FONCTIONS_UTILES

#include <pthread.h>
#include <semaphore.h>
#include <signal.h>
#include <sys/errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>
#include <mqueue.h>

#include "predicat_liste.h"
#include "superviseur.h"
#include "machine.h"
#include "piece.h"
#include "Th_Robot_alimentation.h"
#include "robot_retrait.h"




enum etat
{
	en_panne,
	fonctionne
};

int MachineEnPanne (pid_t numero_machine);

void send(char message[50],pthread_t thread_id);

void erreur (char message[50]);

void afficher(char message[50]);

void armer_timer (time_t timer_id, int temps);

void desarmer_timer (time_t timer_id);

void usinage();

void receive();

void retirer_piece(mqd_t file_message);

void retirer_piece_du_convoyeur(mqd_t file_message);

void deposer_piece();

pid_t correspondance_machine_code(pid_t code_piece);

pthread_t demande_usinage();


#endif
