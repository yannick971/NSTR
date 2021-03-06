CC=gcc
CFLAGS=-W -Wall -lpthread -lrt 
EXEC=main

all: $(EXEC)

main: main.c machine.o piece.o robot_retrait.o superviseur.o Th_Robot_alimentation.o fonctions_utiles.o predicat_liste.o
	$(CC) -o main main.c machine.o piece.o robot_retrait.o superviseur.o Th_Robot_alimentation.o $(CFLAGS)
	
	
fonctions_utiles.o: fonctions_utiles.c fonctions_utiles.h
	$(CC) -o fonctions_utiles.o -c fonctions_utiles.c $(CFLAGS)

machine.o: machine.c machine.h
	$(CC) -o machine.o -c machine.c $(CFLAGS)

piece.o: piece.c piece.h
	$(CC) -o piece.o -c piece.c $(CFLAGS)

predicat_liste.o: predicat_liste.c predicat_liste.h
	$(CC) -o predicat_liste.o -c predicat_liste.c $(CFLAGS)
	
robot_retrait.o: robot_retrait.c robot_retrait.h
	$(CC) -o robot_retrait.o -c robot_retrait.c $(CFLAGS)

superviseur.o: superviseur.c superviseur.h
	$(CC) -o superviseur.o -c superviseur.c $(CFLAGS)

Th_Robot_alimentation.o: Th_Robot_alimentation.c Th_Robot_alimentation.h
	$(CC) -o Th_Robot_alimentation.o -c Th_Robot_alimentation.c $(CFLAGS)
	
	

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
