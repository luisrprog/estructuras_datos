#ifndef _pilad
#define _pilad
#define True 1
#define False 0
#define N_GLOBAL 12


typedef struct {
    int placas;
    char estado[N_GLOBAL];
    char marca[N_GLOBAL];
    char modelo[N_GLOBAL];
    int ano;
    char nombre[N_GLOBAL];
} CAR;

typedef struct nodo {
    CAR dato;
    struct nodo *anterior;
} Nodo;

typedef struct pila {
    Nodo *tope;
} Pila;

Nodo *CrearNodo();
void DestruirNodo(Nodo *nodo);

Pila *CrearPila();
void DestruirPila(Pila *pila);

void Apilar(Pila *pila, CAR elem);
CAR Desapilar(Pila *pila);

CAR Ultimo(Pila *pila);
int PilaVacia(Pila *pila);

#endif
