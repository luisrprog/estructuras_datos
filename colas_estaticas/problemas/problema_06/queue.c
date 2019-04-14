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

Customer pop(MQ q1){
    if(emptyQueue(q1) == True){
        err(1); // Empty Queue.
    }
    Customer c1 = q1 -> customer[q1 -> first];
    q1 -> first = next(q1 -> first);
    (q1 -> size)--;
    return c1;
}

void push(MQ q1, Customer c1){
    if(q1 -> size == MAX){
        err(2); // Full Queue.
    }
    q1 -> customer[q1 -> last] = c1;
    q1 -> last = next(q1 -> last);
    (q1 -> size)++;
}

Customer firstQueue(MQ q1){
    if(emptyQueue(q1) == True){
        err(3); // Empty Queue.
    }
    return (q1 -> customer[q1 -> first]);
}