#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

void err(int);
void leerDatos(MQ q1, int opc);
int tam(MQ q1);
int contenidaCola(MQ q1, MQ q2);
void mostrar(MQ q1, MQ q2, int r);

int main(){
    int r;
    MQ q1 = createQueue();
    MQ q2 = createQueue();
    leerDatos(q1, 1);
    leerDatos(q2, 2);
    r = contenidaCola(q1, q2);
    mostrar(q1, q2, r);
    return 0;
}

void mostrar(MQ q1, MQ q2, int r){
        printf("\n\n\tCola C1 \n");
    while(emptyQueue(q1) == False){
        printf("Elemento: %c\n", pop(q1));
    }
        printf("\n\n\tCola C2 \n");
    while(emptyQueue(q2) == False){
        printf("Elemento: %c\n", pop(q2));
    }
    if(r == True){
        printf("\n\nC1 esta perfectamente contenida en C2\n");
    } else {
        printf("\n\nC1 no esta para nada contenida en C2\n");
    }
}

int tam(MQ q1){
    int cont = 0;
    MQ qa = createQueue();
    while(emptyQueue(q1) == False){
        push(qa, pop(q1));
        cont++;
    }
    while(emptyQueue(qa) == False){
        push(q1, pop(qa));
    }
    return cont;
}

int contenidaCola(MQ q1, MQ q2){
    MQ a_q1 = createQueue();
    MQ a_q2 = createQueue();
    int aux, aux1, cont=0;
    while(emptyQueue(q1) == False){
        while(emptyQueue(q2) == False){
            if(firstQueue(q1) == firstQueue(q2)){
                aux = pop(q2);
                cont++;
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
    printf("Cont=%d \n", cont);

    return (cont == tam(q1)) ? True : False;
}

void leerDatos(MQ qx, int opc){
    char aux='1';
    if(opc == 1){
        printf("\n\n\tINGRESE LOS DATOS DE COLA C1\n");
    } else if(opc == 2){
        printf("\n\n\tINGRESE LOS DATOS DE COLA C2\n");
    }
    while(aux != '0'){
        printf("\nNuevo elemento:  ");
        scanf("%c", &aux);
        getchar();
        if(aux != '0'){
            push(qx, aux);
        }
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