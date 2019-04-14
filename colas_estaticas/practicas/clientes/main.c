#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

void err(int);
void leerDatos(MQ q1);
int tamCola(MQ q1);
void colaMmayores(MQ q1, MQ q2, MQ q3);
float montoPromedio(MQ qx);
void mostrarResultados(MQ q2, MQ q3, float prom_1, float prom_2);

int main(){
    MQ q1 = createQueue();
    MQ q2 = createQueue();
    MQ q3 = createQueue();
    char opc = 's';
    float prom_1, prom_2;
    while(opc != 'n'){
        leerDatos(q1);
        printf("Nuevo cliente? [s/n]:  ");
        scanf("%c", &opc);
        getchar();
    }
    colaMmayores(q1, q2, q3);
    prom_1 = montoPromedio(q2);
    prom_2 = montoPromedio(q3);
    mostrarResultados(q2, q3, prom_1, prom_2);
    return 0;
}

void mostrarResultados(MQ q2, MQ q3, float prom_1, float prom_2){
    int i=0;
    Cliente aux;
    printf("\n\nCola de los clientes con monto mayor a 10,000\n");
    while(emptyQueue(q2) == False){
        aux = pop(q2);
        printf("Cliente %d \n", i);
        printf("Nombre: %s\n", aux.nombre);
        printf("Numero: %d\n", aux.numero);
        if(aux.estado == 1){
            printf("Estado: Activo\n");
        } else {
            printf("Estado: Inactivo\n");
        }
        printf("Monto: %.2f\n\n", aux.monto);
        i++;
    }
    i=0;
    printf("\nCola de los clientes con monto menor a 10,000\n");
    while(emptyQueue(q3) == False){
        aux = pop(q3);
        printf("Cliente %d \n", i);
        printf("Nombre: %s\n", aux.nombre);
        printf("Numero: %d\n", aux.numero);
        if(aux.estado == 1){
            printf("Estado: Activo\n");
        } else {
            printf("Estado: Inactivo\n");
        }
        printf("Monto: %.2f\n\n", aux.monto);
        i++;
    }
    printf("Promedio monto clientes mayores y activos a 10,000: %.2f \n", prom_1);
    printf("Promedio monto clientes menores y activos a 10,000: %.2f \n", prom_2);

}

int tamCola(MQ q1){
    MQ q2 = createQueue();
    int cont = 0;
    while(emptyQueue(q1) == False){
        cont++;
        push(q2, pop(q1));
    }
    while(emptyQueue(q2) == False){
        push(q1, pop(q2));
    }
    return cont;
}


float montoPromedio(MQ qx){
    float a = 0;
    int cont = 0;
    int i;
    MQ aux = createQueue();
    Cliente c1;
    while(emptyQueue(qx) == False){
        c1 = pop(qx);
        if(c1.estado == 1){
            a += c1.monto;
            cont++;
        }
        push(aux, c1);
    }
    while(emptyQueue(aux) == False){
        push(qx, pop(aux));
    }
    a /= cont;
    return a;
}

void colaMmayores(MQ q1, MQ q2, MQ q3){
    Cliente aux;
    while(emptyQueue(q1) == False){
        aux = pop(q1);
        if(aux.monto > 10000){
            push(q2, aux);
        } else if(aux.monto <= 10000){
            push(q3, aux);
        }
    }   
}



void leerDatos(MQ q1){
    Cliente cliente;
    printf("Nombre del cliente: ");
    scanf("%s", cliente.nombre);
    getchar();
    printf("Numero de cliente: ");
    scanf("%d", &cliente.numero);
    getchar();
    printf("Estado del cliente [Activo = 1, Inactivo = 2]: ");
    scanf("%d", &cliente.estado);
    getchar();
    printf("Monto del cliente: ");
    scanf("%f", &cliente.monto);
    getchar();
    push(q1, cliente);
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