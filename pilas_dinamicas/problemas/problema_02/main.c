#include <stdlib.h>
#include <stdio.h>
#include "pilad.h"

void err();
void SolicitarDatos(Pila *s);
void MostrarDatos(Pila *s);

int main(){

    Pila *s = CrearPila();
    SolicitarDatos(s);
    MostrarDatos(s);

    return False;
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
