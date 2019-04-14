#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

void err(int);
void requestElement(MQ q1);
int sizeQueue1(MQ q1);
MQ mixQueues(MQ q1, MQ q2, int size_q1, int size_q2);
void printQueue(MQ q3);


int main(int argc, char const *argv[])
{
    MQ q1 = createQueue();
    MQ q2 = createQueue();
    MQ q3 = createQueue();
    char opc = 'y';
    int size_q1, size_q2;
    do {
        printf("\nQueue q1:\n");
        requestElement(q1);
        printf("You want to add new item? [y/n]: ");
        scanf("%c", &opc);
    } while(opc != 'n');
    opc = 'y';
    do {
        printf("\nQueue q2:\n");
        requestElement(q2);
        printf("You want to add new item? [y/n]: ");
        scanf("%c", &opc);
    } while(opc != 'n');
    size_q1 = sizeQueue1(q1);
    size_q2 = sizeQueue1(q2);
    q3 = mixQueues(q1, q2, size_q1, size_q2);
    printQueue(q3);
    return False;
}

void requestElement(MQ q1){
    int n;
    printf("Type new item: ");
    scanf("%d", &n);
    getchar();
    push(q1, n);
}

int sizeQueue1(MQ q1){
    MQ a = createQueue();
    int cont = 0;
    while(emptyQueue(q1) == False){
        cont++;
        push(a, pop(q1));
    }
    while(emptyQueue(a) == False){
        push(q1, pop(a));
    }
    return cont;
}

MQ mixQueues(MQ q1, MQ q2, int size_q1, int size_q2){
    MQ q3 = createQueue();
    int i;
    for(i=0; i<size_q1; i++){
        push(q3, pop(q1));
    }
    for(i=0; i<size_q2; i++){
        push(q3, pop(q2));
    }
    return q3;
}

void printQueue(MQ q3){
    int i;
    printf("\n\nPrinting current queue\n");
    for(i=0; i<(q3 -> size); i++){
        printf("item(%d): %d \n", i, (q3->queue[i]));
    }
}

void err(int opc){
    printf("Error -> ");
    switch (opc)
    {
        case 0:
            printf("(func createQueue): Add memory failed.\n");
            break;
        case 1:
            printf("(func pop): Empty queue.\n");
            break;
        case 2:
            printf("(func push): Full queue.\n");
            break;
        case 3:
            printf("(func firstQueue): Empty queue.\n");
            break;
    }
    exit(opc);
}