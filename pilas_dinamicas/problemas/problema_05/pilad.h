#ifndef _pilad
#define _pilad
#define True 1
#define False 0

typedef struct nodo {
    char dato;
    struct nodo *anterior;
} Nodo;

typedef struct pila {
    Nodo *tope;
} Pila;

Nodo *CrearNodo();
void DestruirNodo(Nodo *nodo);

Pila *CrearPila();
void DestruirPila(Pila *pila);

void Apilar(Pila *pila, char elem);
char Desapilar(Pila *pila);

char Ultimo(Pila *pila);
int PilaVacia(Pila *pila);

#endif