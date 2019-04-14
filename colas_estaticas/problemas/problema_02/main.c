#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

void err(int);
void mostrar(int ultimo);
int ultimoCola(MQ q1);
void agregarDato(MQ q1);

int main(){
    MQ q1 = createQueue();
    char opc = 's';
    int ultimo;
    
    while(opc != 'n'){
        agregarDato(q1);
        getchar();
        printf("Nuevo dato? [s/n]:  ");
        scanf("%c", &opc);
    }
    ultimo = ultimoCola(q1);
    mostrar(ultimo);

    return 0;
}

void mostrar(int ultimo){
    printf("\nEl ultimo elemento agregado es -> %d \n", ultimo);
}

int ultimoCola(MQ q1){
    int ultimo;
    while(emptyQueue(q1) == False){
        ultimo = pop(q1);
    }
    return ultimo;
}

void agregarDato(MQ q1){
    int dato;
    printf("\n\tValor del nuevo dato:  ");
    scanf("%d", &dato);
    push(q1, dato);
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