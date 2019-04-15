#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

void err(int);
void solicitarCola(MQ q1);
char obtenerMayor(MQ q1);
void mostrar(MQ q1, char max);


int main(){
    MQ q1 = createQueue();
    char max;
    solicitarCola(q1);
    max = obtenerMayor(q1);
    mostrar(q1, max);
    return 0;
}

void mostrar(MQ q1, char max){
    printf("\n\tCola 1\n");
    while(emptyQueue(q1) == False){
        printf("Elemento:  %c\n", pop(q1));
    }
    printf("\nLa letra mayor es: %c\n", max);
}

char obtenerMayor(MQ q1){
    MQ aux = createQueue();
    char letra, mayor='a';
    while(emptyQueue(q1) == False){
        letra = pop(q1);
        push(aux, letra);
        if(letra > mayor){
            mayor = letra;
        }
    }
    while(emptyQueue(aux) == False){
        push(q1, pop(aux));
    }
    return mayor;
}

void solicitarCola(MQ q1){
    printf("\n\n\tSolicitando datos de la cola 1\n");
    char opc = 'x';
    while(opc != '0'){
        printf("Elemento:  ");
        scanf("%c", &opc);
        getchar();
        if(opc != '0'){
            push(q1, opc);
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