#include <stdlib.h>
#include <stdio.h>
#include "cola.h"

void err();
void SolicitarDatos(Pila *s);
void MostrarDatos(Pila *s);
void Intercambio(Pila *s);

int main(){

    Pila *s = CrearPila();
    SolicitarDatos(s);
    Intercambio(s);
    MostrarDatos(s);

    return False;
}

void Intercambio(Pila *s){
    Pila *aux = CrearPila();
    int primero, ultimo = Desapilar(s);
    while(PilaVacia(s) == False){
        Apilar(aux, Desapilar(s));
    }
    primero = Desapilar(aux);
    Apilar(aux, ultimo);
    while(PilaVacia(aux) == False){
        Apilar(s, Desapilar(aux));
    }
    Apilar(s, primero);
    DestruirPila(aux);
}

void MostrarDatos(Pila *s){
    printf("\n\tMostrando pila \n");
    while(PilaVacia(s) == False){
        printf("elem:  %d\n", Desapilar(s));
    }
}

void SolicitarDatos(Pila *s){
    int x = 1;
    while(x != 0){
        printf("Nuevo elemento:  ");
        scanf("%d", &x);
        if(x != 0){
            Apilar(s, x);
        }
        getchar();
    }
}

void err(){
    printf("Algo hiciste mal kbron >:v \n");
    exit(0);
}