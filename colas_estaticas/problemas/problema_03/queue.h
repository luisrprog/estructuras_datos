#ifndef _queue
#define _queue
#define True 1
#define False 0
#define MAX 100

typedef struct {
    int queue[MAX];
    int first;
    int last;
    int size;
} Master_Queue;
typedef Master_Queue * MQ;

MQ createQueue();
int emptyQueue(MQ);
int next(int);
int pop(MQ);
void push(MQ, int);
int firstQueue(MQ);

#endif