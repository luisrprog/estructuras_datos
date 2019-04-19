#ifndef _pilad
#define _pilad
#define True 1
#define False 0
#define TAM 20

typedef struct {
    int dia;
    int mes;
    int ano;
} FECH;

typedef struct {
    int numero;
    char titular[TAM];
    char tramite[TAM];
    FECH fecha;
} EXP;

typedef struct nodo {
    EXP dato;
    struct nodo *anterior;
} Nodo;

typedef struct pila {
    Nodo *tope;
} Pila;

Nodo *CrearNodo();
void DestruirNodo(Nodo *nodo);

Pila *CrearPila();
void DestruirPila(Pila *pila);

void Apilar(Pila *pila, EXP elem);
EXP Desapilar(Pila *pila);

EXP Ultimo(Pila *pila);
int PilaVacia(Pila *pila);

#endif
