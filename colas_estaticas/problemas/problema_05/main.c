#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

void err(int);
void requestElement(MQ q1);
void printQueue(MQ q1);
MQ mixQueues(MQ q1, MQ q2, MQ q3, MQ q4);

int main(int argc, char const *argv[])
{
    MQ q1 = createQueue();
    MQ q2 = createQueue();
    MQ q3 = createQueue();
    MQ q4 = createQueue();
    MQ qa = createQueue();
    
    printf("\n\tQueue 1\n\n");
    requestElement(q1);
    printf("\n\tQueue 2\n\n");
    requestElement(q2);
    printf("\n\tQueue 3\n\n");
    requestElement(q3);
    printf("\n\tQueue 4\n\n");
    requestElement(q4);

    qa = mixQueues(q1, q2, q3, q4);
    printQueue(qa);
    return False;
}

void requestElement(MQ qx){
    char opc = 'y';
    int n;
    do{
        printf("Type new item: ");
        scanf("%d", &n);
        push(qx, n);
        getchar();
        printf("You want to add new item? [y/n]: ");
        scanf("%c", &opc);
    } while(opc != 'n');
}

MQ mixQueues(MQ q1, MQ q2, MQ q3, MQ q4){
    MQ qa = createQueue();
    MQ qb = createQueue();
    MQ qc = createQueue();
    if(q1->size > q2->size){
        while(emptyQueue(q2) != True){
            push(qa, pop(q1));
            push(qa, pop(q2));
        }
        while(emptyQueue(q1) != True){
            push(qa, pop(q1));
        }
    } else if(q1->size < q2->size){
        while(emptyQueue(q1) != True){
            push(qa, pop(q1));
            push(qa, pop(q2));
        }
        while(emptyQueue(q2) != True){
            push(qa, pop(q2));
        }
    } else if(q1->size == q2->size){
        while(emptyQueue(q1) != True){
            push(qa, pop(q1));
            push(qa, pop(q2));
        }
    }
    if(qa->size > q3->size){
        while(emptyQueue(q3) != True){
            push(qb, pop(qa));
            push(qb, pop(q3));
        }
        while(emptyQueue(qa) != True){
            push(qb, pop(qa));
        }
    } else if(qa->size < q3->size){
        while(emptyQueue(qa) != True){
            push(qb, pop(qa));
            push(qb, pop(q3));
        }
        while(emptyQueue(q3) != True){
            push(qb, pop(q3));
        }
    } else if(qa->size == q3->size){
        while(emptyQueue(qa) != True){
            push(qb, pop(qa));
            push(qb, pop(q3));
        }
    }
    if(qb->size > q4->size){
        while(emptyQueue(q4) != True){
            push(qc, pop(qb));
            push(qc, pop(q4));
        }
        while(emptyQueue(qb) != True){
            push(qc, pop(qb));
        }
    } else if(qb->size < q4->size){
        while(emptyQueue(qb) != True){
            push(qc, pop(qb));
            push(qc, pop(q4));
        }
        while(emptyQueue(q4) != True){
            push(qc, pop(q4));
        }
    } else if(qb->size == q4->size){
        while(emptyQueue(qb) != True){
            push(qc, pop(qb));
            push(qc, pop(q4));
        }
    }
    return qc;
}

void printQueue(MQ q1){
    int i;
    printf("\n\nPrinting current queue\n");
    for(i=0; i<(q1 -> size); i++){
        printf("item(%d): %d \n", i, (q1->queue[i]));
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