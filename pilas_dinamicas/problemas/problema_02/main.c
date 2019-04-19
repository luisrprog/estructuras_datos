#include <stdlib.h>
#include <stdio.h>
#include "pilad.h"

void err();
void SolicitarA(Pila *a);
void VerRepetidos(Pila *a, Pila *b);
void Mostrar(Pila *a, Pila *b);


int main(){
    Pila *a = CrearPila();
    Pila *b = CrearPila();
    SolicitarA(a);
    VerRepetidos(a, b);
    Mostrar(a, b);
    return 0;
}

void Mostrar(Pila *a, Pila *b){
    Pila *aux = CrearPila();
    system("clear");
    printf("\n\tPila A (original)\n");
    while(PilaVacia(a) == False){
        Apilar(aux, Desapilar(a));
    }
    while(PilaVacia(aux) == False){
        printf("%c", Desapilar(aux));
    }
    printf("\n\n\tPila B (repetidos)\n");
    while(PilaVacia(b) == False){
        printf("%c", Desapilar(b));
    }
    printf("\n\n");
}


void VerRepetidos(Pila *a, Pila *b){
    Pila *aux = CrearPila();
    Pila *copia = CrearPila();
    char c, x;
    while(PilaVacia(a) == False){
        c = Desapilar(a);
        Apilar(aux, c);
        Apilar(copia, c);
    }
    while(PilaVacia(aux) == False){
        Apilar(a, Desapilar(aux));
    }
    int cont=0;
    while(PilaVacia(a) == False){
        c = Desapilar(a);
        while(PilaVacia(a) == False){
            if(Ultimo(a) == c){
                x = Desapilar(a);
                cont++;
            } else {
                Apilar(aux, Desapilar(a));
            }
        }
        if(cont != 0){
            Apilar(b, c);
        }
        cont = 0;
        while(PilaVacia(aux) == False){
            Apilar(a, Desapilar(aux));
        }
    }
    while(PilaVacia(a) == False){
        c = Desapilar(a);
    }
    while(PilaVacia(copia) == False){
        Apilar(a, Desapilar(copia));
    }
}

void SolicitarA(Pila *a){
    printf("\n\tSolicitando pila A\n");
    char cad[100];
    int i=0;
    printf("Ingrese cadena: \n");
    scanf("%s", cad);
    while(cad[i] != '\0'){
        Apilar(a, cad[i]);
        i++;
    }
}

void err(){
    printf("Algo hiciste mal kbron >:v \n");
    exit(0);
}
