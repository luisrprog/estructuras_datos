#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "queue.h"

void err(int);
void nuevoCliente(MQ q1); // Correcta
int clientesAtendidos(MQ q1); // Correcta
void promedioAtencion(MQ q1); // Correcta
void clientesTiempo(MQ q1); // Correcta



int main(){
    srand(time(NULL));
    MQ q1 = createQueue();
    int opc = 1, cA;
    while(opc != 2){
        nuevoCliente(q1);
        printf("\nCliente nuevo? si=1, no=2:  ");
        scanf("%d", &opc);
        getchar();
    }

    cA = clientesAtendidos(q1);
    promedioAtencion(q1);
    clientesTiempo(q1);
    return 0;
}


void clientesTiempo(MQ q1){
    MQ q2 = createQueue();
    Customer cliente, c_rapido, c_lento;
    int rapido = 0, lento = 20;
    while(emptyQueue(q1) == False){
        cliente = pop(q1);
        if(cliente.time > rapido){
            c_rapido = cliente;
            rapido = c_rapido.time;
        }
        push(q2, cliente);
    }
    while(emptyQueue(q2) == False){
        cliente = pop(q2);
        if(cliente.time < lento){
            c_lento = cliente;
            lento = c_lento.time;
        }
    }
    printf("\nEl cliente atendido mas lento:\n");
    printf("Nombre: %s\n", c_rapido.name);
    printf("Id: %d\n", c_rapido.id);
    printf("Tiempo de espera: %d\n", c_rapido.time);
    printf("\nEl cliente atendido mas rapido:\n");
    printf("Nombre: %s\n", c_lento.name);
    printf("Id: %d\n", c_lento.id);
    printf("Tiempo de espera: %d\n", c_lento.time);
}


void promedioAtencion(MQ q1){
    int promedio = 0, cont = 1;
    Customer cliente;
    MQ q2 = createQueue();
    printf("Promedio de espera:\n");
    while(emptyQueue(q1) == False){
        cliente = pop(q1);
        promedio += cliente.time;
        promedio /= 2;
        cliente.time = promedio;
        push(q2, cliente);
        printf("Cliente %d: %d\n", cont++, promedio);
    }
    while(emptyQueue(q2) == False){
        push(q1, pop(q2));
    }
}


// funcion que devuelve el tamaño de la cola
int clientesAtendidos(MQ q1){
    int cont = 0;
    MQ q2 = createQueue();

    while(emptyQueue(q1) == False){
        push(q2, pop(q1));
        cont++;
    }
    while(emptyQueue(q2) == False){
        push(q1, pop(q2));
    }
    printf("\nNumero de clientes atendidos: %d\n", cont);
    return cont;
}




void nuevoCliente(MQ q1){
    Customer cliente;
    printf("Nombre del cliente: ");
    scanf("%s", cliente.name);
    getchar();
    printf("ID del cliente: ");
    scanf("%d", &cliente.id);
    (cliente.id) += 1000;
    cliente.time = rand()%20;
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