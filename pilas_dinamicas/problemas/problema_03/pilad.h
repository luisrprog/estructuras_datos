#ifndef _pilad
#define _pilad
#define True 1
#define False 0

typedef struct {
    char nombre[20];
}Producto;

typedef struct nodo {
    Producto producto;
    struct nodo *anterior;
} Nodo;

typedef struct pila {
    Nodo *tope;
} Pila;

Nodo *CrearNodo();
void DestruirNodo(Nodo *nodo);

Pila *CrearPila();
void DestruirPila(Pila *pila);

void Apilar(Pila *pila, Producto producto);
Producto Desapilar(Pila *pila);

Producto Ultimo(Pila *pila);
int PilaVacia(Pila *pila);

#endif