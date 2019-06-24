
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define atomic_xchg(A,B) __asm__ __volatile__( \
                                        " lock xchg %1,%0 ;\n" \
                                        : "=ir" (A) \
                                        : "m" (B), "ir" (A) \
                                        );


typedef struct _QUEUE {
	int elements[MAXTHREAD];
	int head;
	int tail;
} QUEUE;

void _enqueue(QUEUE *q,int val);
int _dequeue(QUEUE *q);


void _enqueue(QUEUE *q,int val)
{
	q->elements[q->head]=val;
	// Incrementa al apuntador
	q->head++;
	q->head=q->head%MAXTHREAD;
}


int _dequeue(QUEUE *q)
{
	int valret;
	valret=q->elements[q->tail];
	// Incrementa al apuntador
	q->tail++;
	q->tail=q->tail%MAXTHREAD;
	return(valret);
}

int _emptyq(QUEUE *q)
{
	return(q->head==q->tail);
}


typedef struct _semaforo {
	QUEUE stoped;
  int val;
  int id;
} semaforo;



void waitsem(semaforo *s);
void signalsem(semaforo *s);
void initsem();


void waitsem(semaforo *s){

}

void signalsem(semaforo *s){

}

void initsem(semaforo *s){
}
