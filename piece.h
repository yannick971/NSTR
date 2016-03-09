#ifndef PIECE
#define PIECE

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <signal.h>
#include <sys/errno.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>
#include <mqueue.h>


void *Th_piece(pthread_t code_piece, pthread_t numero_machine);

#endif
