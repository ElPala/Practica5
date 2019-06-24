.PHONY: all semaforo
all: semaforo

semaforo: semaforo.c
	gcc -o semaforo.o -c semaforo.c

clean:
		rm semaforo.o
