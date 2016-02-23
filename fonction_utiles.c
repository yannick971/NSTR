#include "fonctions_utiles.h"

/***************************************************************/
/*********************FONCTIONS UTILES**************************/
/***************************************************************/


int MachineEnPanne (pthread numero_machine)
{
	prntf(je sais pas\n");
}

void erreur (char message[50])
{
	fprintf(stderr, "%s\n",message[0]);
	exit(1);
}

void afficher (char message[50])
{
	fprintf(stderr, "%s\n",message[0]);
}

void usinage ()
{
	timer_t timer_usinage;
	sigset_t sig_mask;
	struct sigevent sev;
	struct sigaction sig_action;
	struct itimerspec its;
    long long freq_nanosecs;
	int tps = 600;

	sev.sigev_notify = SIGEV_SIGNAL;
    sev.sigev_signo = SIG;
    sev.sigev_value.sival_ptr = &timer_usinage;

	if(timer_create(CLOCK_REALTIME, &sev, timer_usinage)== -1)
		errExit("timer_create");

	/* Start the timer */

	sigemptyset (&sig_mask);
	sigaddset (&sig_mask, SIGRTMIN);
	sig_action.sa_handler = signal_catcher;
	sig_action.sa_flags = 0;

	if(sigaction(SIGRTMIN, &sig_action, NULL) == -1)
		printf("erreur d'initialisation d'action de signal\n");

    freq_nanosecs = tps;
    its.it_value.tv_sec = freq_nanosecs / 1000000000;
    its.it_value.tv_nsec = freq_nanosecs % 1000000000;
    its.it_interval.tv_sec = its.it_value.tv_sec;
    its.it_interval.tv_nsec = its.it_value.tv_nsec;

    if (timer_settime(timer_usinage, 0, &its, NULL) == -1)
        errExit("timer_settime");

    exit(EXIT_SUCCESS);

}

void deposer_piece ()
{
	timer_t timer_depot;
	sigset_t sig_mask;
	struct sigevent sev;
	struct sigaction sig_action;
	struct itimerspec its;
    long long freq_nanosecs;
	int tps = 20;

	sev.sigev_notify = SIGEV_SIGNAL;
    sev.sigev_signo = SIGRTMIN;
    sev.sigev_value.sival_ptr = &timer_depot;


	if(timer_create(CLOCK_REALTIME, &sev, timer_depot) == -1)

	/* Start the timer */

	sigemptyset (&sig_mask);
	sigaddset (&sig_mask, SIGRTMIN);
	sig_action.sa_handler = signal_catcher;
	sig_action.sa_flags = 0;

	if(sigaction(SIGRTMIN, &sig_action, NULL) == -1)
		printf("erreur d'initialisation d'action de signal\n");

    freq_nanosecs = tps;
    its.it_value.tv_sec = freq_nanosecs / 1000000000;
    its.it_value.tv_nsec = freq_nanosecs % 1000000000;
    its.it_interval.tv_sec = its.it_value.tv_sec;
    its.it_interval.tv_nsec = its.it_value.tv_nsec;

    if (timer_settime(timer_depot, 0, &its, NULL) == -1)
        errExit("timer_settime");

    exit(EXIT_SUCCESS);
}

void retirer_piece(mqd_t file_message)
{
	char message[25]="usinage ok, depot sur convoyeur ok";
	const struct sigevent *notification;
	
	if (mq_send(file_message, message[0], sizeof(message),1) == -1)
		printf("erreur envoie message de fin usinage \n");

	if (mq_notify(file_message, notification) == -1)
		printf("erreur envoie de signal au thread\n");

	exit(EXIT_SUCCESS);
}

void retirer_piece_du_convoyeur(mqd_t file_message)
{
	char message[25]="la piece a bien ete retire du convoyeur!";
	const struct sigevent *notification;
	
	if (mq_send(file_message, message[0], sizeof(message),1) == -1)
		printf("erreur envoie message de fin usinage \n");

	if (mq_notify(file_message, notification) == -1)
		printf("erreur envoie de signal au thread\n");

	exit(EXIT_SUCCESS);
}

pid_t correspondance_machine_code (pid_t code_piece)
{

}

void send (char message[50],pthread thread_id)
{

}

void receive()
{

}
