#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

void err(int);
void requestElement(MQ q1);
void printQueue(MQ q1);

int main(int argc, char const *argv[])
{
    MQ q1 = createQueue();
    char opc = 'y';
    do {
        requestElement(q1);
        printf("You want to add new item? [y/n]: ");
        scanf("%c", &opc);
    } while(opc != 'n');
    printQueue(q1);
    return False;
}

void requestElement(MQ q1){
    int n;
    printf("Type new item: ");
    scanf("%d", &n);
    getchar();
    push(q1, n);
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