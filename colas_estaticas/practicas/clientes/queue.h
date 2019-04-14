#ifndef _queue
#define _queue
#define True 1
#define False 0
#define MAX 100

typedef struct{
	char nombre[MAX];
	int numero;
	int estado;
	float monto;
}Cliente;

typedef struct {
    Cliente queue[MAX];
    int first;
    int last;
    int size;
} Master_Queue;
typedef Master_Queue * MQ;

MQ createQueue();
int emptyQueue(MQ);
int next(int);
Cliente pop(MQ);
void push(MQ, Cliente);
Cliente firstQueue(MQ);

#endif