CC=gcc
CFLAGS=-W -Wall -ansi -pedantic -pthread -lrt -lthread
LDFLAGS=
EXEC=main

all: $(EXEC)

main: main.o machine.o piece.o robot_retrait.o superviseur.o Th_Robot_alimentation.o
	$(CC) -o main main.o machine.o piece.o robot_retrait.o superviseur.o Th_Robot_alimentation.o $(LDFLAGS)
	
	
	
main.o: main.c predicat_liste.h fonctions_utiles.h superviseur.h machine.h piece.h robot_retrait.h Th_Robot_alimentation.h
	$(CC) -o main.o -c main.c $(CFLAGS)
	
fonctions_utiles.o: fonctions_utiles.c
	$(CC) -o foctions_utiles.o -c fonctions_utiles.c $(CFLAGS)

machine.o: machine.c 
	$(CC) -o machine.o -c machine.c $(CFLAGS)

piece.o: piece.c piece.h
	$(CC) -o piece.o -c piece.c $(CFLAGS)

predicat_liste.o: predicat_liste.c
	$(CC) -o predicat_liste.o -c predicat_liste.c $(CFLAGS)
	
robot_retrait.o: robot_retrait.c 
	$(CC) -o robot_retrait.o -c robot_retrait.c $(CFLAGS)

superviseur.o: superviseur.c 
	$(CC) -o superviseur.o -c superviseur.c $(CFLAGS)

Th_Robot_alimentation.o: Th_Robot_alimentation.c
	$(CC) -o Th_Robot_alimentation.o -c Th_Robot_alimentation.c $(CFLAGS)
	
	

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
