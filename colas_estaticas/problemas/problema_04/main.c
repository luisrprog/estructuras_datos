#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

void err(int);
void requestElement(MQ q1);
void printQueue(MQ q1);
MQ mixQueues(MQ q1, MQ q2);

int main(int argc, char const *argv[])
{
    MQ q1 = createQueue();
    MQ q2 = createQueue();
    MQ q3 = createQueue();
    char opc = 'y';
    printf("\n\tQueue 1\n\n");
    do {
        requestElement(q1);
        printf("You want to add new item? [y/n]: ");
        scanf("%c", &opc);
    } while(opc != 'n');
    opc = 'y';
    printf("\n\tQueue 2\n\n");
    do {
        requestElement(q2);
        printf("You want to add new item? [y/n]: ");
        scanf("%c", &opc);
    } while(opc != 'n');
    q3 = mixQueues(q1, q2);
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

MQ mixQueues(MQ q1, MQ q2){
    MQ q3 = createQueue();
    if(q1->size > q2->size){
        while(emptyQueue(q2) != True){
            push(q3, pop(q1));
            push(q3, pop(q2));
        }
        printf("\nTermina primer while, cuando q1 > q2\n");
        while(emptyQueue(q1) != True){
            push(q3, pop(q1));
        }
        printf("Termina segundo while, cuando q1 > q2\n");
    } else if(q1->size < q2->size){
        while(emptyQueue(q1) != True){
            push(q3, pop(q1));
            push(q3, pop(q2));
        }
        printf("\nTermina primer while, cuando q2 > q1\n");
        while(emptyQueue(q2) != True){
            push(q3, pop(q2));
        }
        printf("Termina segundo while, cuando q2 > q1\n");
    } else if(q1->size == q2->size){
        while(emptyQueue(q1) != True){
            push(q3, pop(q1));
            push(q3, pop(q2));
        }
    }
    return q3;
}

void printQueue(MQ q1){
    int i = 0;
    printf("\n\nPrinting current queue\n");
    while(emptyQueue(q1) == False){
        i++;
        printf("item(%d): %d \n", i, pop(q1));
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