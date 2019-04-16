#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "cola.h"

void err();
void menu(Pila *s);
void NuevoProducto(Pila *s);
void SacarProducto(Pila *s);
void MostrarCesta(Pila *s);
void VaciarCesta(Pila *s);

int main(){
    Pila *s = CrearPila();
    menu(s);
    return 0;
}

void VaciarCesta(Pila *s){
    system("clear");
    printf("\n\n\tVaciando cesta...\n");
    Producto aux;
    while(PilaVacia(s) == False){
        aux = Desapilar(s);
        printf("Vaciando: %s\n", aux.nombre);
        sleep(1);
    }
    printf("\nLa cesta se ha vaciado correctamente\n");
    sleep(2);
}

void MostrarCesta(Pila *s){
    system("clear");
    printf("\n\n\tMostrando cesta actual\n\n");
    Pila *t = CrearPila();
    Producto aux;
    while(PilaVacia(s) == False){
        aux = Desapilar(s);
        printf("%s \n", aux.nombre);
        Apilar(t, aux);
    }
    while(PilaVacia(t) == False){
        Apilar(s, Desapilar(t));
    }
    sleep(1);
    printf("\nPuede seguir agregando productos en la cesta...\n");
    sleep(5);
}

void SacarProducto(Pila *s){
    system("clear");
    printf("\n\n\tSacando el ultimo producto\n");
    Producto producto = Desapilar(s);
    sleep(2);
    printf("\n%s eliminado con exito\n", producto.nombre);
    sleep(2);
}

void NuevoProducto(Pila *s){
    system("clear");
    Producto producto_nuevo;
    printf("\n\n\tProducto Nuevo\n");
    printf("\nNombre del producto: ");
    scanf("%s", producto_nuevo.nombre);
    getchar();
    Apilar(s, producto_nuevo);
    printf("\n%s agregado con exito\n", producto_nuevo.nombre);
    sleep(2);
}

void menu(Pila *s){
    int opc = 10;
    while(opc != 0){
        system("clear");
        printf("\n\t+ M E N U +\n\n");
        printf("[1] Introducir nuevo producto a la cesta.\n");
        printf("[2] Sacar ultimo producto de la cesta.\n");
        printf("[3] Mostrar los productos de la cesta actual.\n");
        printf("[4] Vaciar la cesta.\n");
        printf("[0] Terminar las compras.\n");
        printf("\nAccion a realizar:  ");
        scanf("%d", &opc);
        getchar();
        switch(opc){
            case 0:
                printf("\n\tLa compra ha finalizado.\n");
                exit(opc);
                break;
            case 1:
                NuevoProducto(s);
                break;
            case 2:
                SacarProducto(s);
                break;
            case 3:
                MostrarCesta(s);
                break;
            case 4:
                VaciarCesta(s);
                break;
        }
    }
}


void err(){
    printf("Algo hiciste mal kbron >:v \n");
    exit(0);
}