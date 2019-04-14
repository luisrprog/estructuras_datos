#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

void err(int);
void pedirDatos(MQ q1, int cola);
void interseccion(MQ q1, MQ q2, MQ q3);
void resultados(MQ q1, MQ q2, MQ q3);

int main(){
    MQ q1 = createQueue();
    MQ q2 = createQueue();
    MQ q3 = createQueue();
    pedirDatos(q1, 1);
    pedirDatos(q2, 2);

    interseccion(q1, q2, q3);
    resultados(q1, q2, q3);

    return 0;
}

void resultados(MQ q1, MQ q2, MQ q3){
    printf("\n\n\tResultados\n");
    printf("\nCola A: ");
    while(emptyQueue(q1) == False){
        printf("%d ", pop(q1));
    }
    printf("\nCola B: ");
    while(emptyQueue(q2) == False){
        printf("%d ", pop(q2));
    }
    printf("\nCola C: ");
    while(emptyQueue(q3) == False){
        printf("%d ", pop(q3));
    }
}

void interseccion(MQ q1, MQ q2, MQ q3){
    MQ a_q1 = createQueue();
    MQ a_q2 = createQueue(); 
    int aux, aux1;
    while(emptyQueue(q1) == False){
        while(emptyQueue(q2) == False){
            if(firstQueue(q1) == firstQueue(q2)){
                aux = pop(q2);
                push(q3, aux);
                push(a_q2, aux);
            } else {
                aux = pop(q2);
                push(a_q2, aux);
            }

        }
        aux1 = pop(q1);
        push(a_q1, aux1);
        while(emptyQueue(a_q2) == False){
            push(q2, pop(a_q2));
        }
    }
    while(emptyQueue(a_q1) == False){
        push(q1, pop(a_q1));
    }
}

void pedirDatos(MQ q1, int cola){
    int opc = 1;
    printf("\n\tSolicitando datos de la cola ");
    if(cola == 1){
        printf("A\n");
    } else {
        printf("B\n");
    }
    while(opc != 0){
        printf("\nDigite un elemento:  ");
        scanf("%d", &opc);
        if(opc != 0){
            push(q1, opc);
        }
        getchar();
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
}/*luisfdev*/