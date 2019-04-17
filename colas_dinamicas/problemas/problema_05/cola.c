#include <stdlib.h>
#include "cola.h"

void err();

Nodo *CrearNodo(){
    Nodo *nodo = (Nodo *)malloc(sizeof(Nodo));
    nodo->anterior = NULL;
    return nodo;
}

void DestruirNodo(Nodo* nodo){
    nodo->anterior = NULL;
    free(nodo);
}

Pila *CrearPila(){
    Pila *pila = (Pila*)malloc(sizeof(Pila));
    if(pila == NULL){
        err();
    }
    pila->tope = NULL;
    return pila;
}

void DestruirPila(Pila *pila){
    while(PilaVacia(pila) == False){
        Desapilar(pila);
    }
    free(pila);
}

void Apilar(Pila *pila, char elem){
    Nodo *nodo = CrearNodo();
    nodo->dato = elem;
    nodo->anterior = pila->tope;
    pila->tope = nodo;
}

char Desapilar(Pila *pila){
    if(PilaVacia(pila) == True){
        err();
    }
    Nodo *nodo = pila->tope;
    int elem = nodo->dato;
    pila->tope = pila->tope->anterior;
    DestruirNodo(nodo);
    return elem;
}

char Ultimo(Pila *pila){
    if(PilaVacia(pila) == True){
        err();
    }
    return pila->tope->dato;
}

int PilaVacia(Pila *pila){
    return (pila->tope == NULL) ? True : False;
}