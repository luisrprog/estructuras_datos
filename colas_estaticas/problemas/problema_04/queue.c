#include <stdlib.h>
#include "queue.h"

void err(int);

MQ createQueue(){
    MQ queue = (MQ)malloc(sizeof(Master_Queue));
    if(queue == NULL){
        err(0); // Add memeory failed.
    }
    queue -> first = 0;
    queue -> last = 0;
    queue -> size = 0;
}

int emptyQueue(MQ q1){
    return (q1 -> size == 0) ? True : False;
}

int next(int i){
    return ((i+1)%MAX);
}

int pop(MQ q1){
    if(emptyQueue(q1) == True){
        err(1); // Empty Queue.
    }
    int n = q1 -> queue[q1 -> first];
    q1 -> first = next(q1 -> first);
    (q1 -> size)--;
    return n;
}

void push(MQ q1, int n){
    if(q1 -> size == MAX){
        err(2); // Full Queue.
    }
    q1 -> queue[q1 -> last] = n;
    q1 -> last = next(q1 -> last);
    (q1 -> size)++;
}

int firstQueue(MQ q1){
    if(emptyQueue(q1) == True){
        err(3); // Empty Queue.
    }
    return (q1 -> queue[q1 -> first]);
}