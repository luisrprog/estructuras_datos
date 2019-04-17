#include <stdlib.h>
#include <stdio.h>
#include "cola.h"

void err();
void SolicitarDatos(Pila *s, int p);
void MostrarDatos(Pila *s, int p);

int main(){

    Pila *s1 = CrearPila();
    Pila *s2 = CrearPila();
    SolicitarDatos(s1, 1);
    MostrarDatos(s1, 1);
    //Repetidos(s1, s2);
    MostrarDatos(s2, 2);

    return False;
}


void MostrarDatos(Pila *s, int p){
    printf("\n\tMostrando pila %d\n", p);
    while(PilaVacia(s) == False){
        printf("elem:  %d\n", Desapilar(s));
    }
}

void SolicitarDatos(Pila *s, int p){
    int x = 1;
    printf("\n\tSolicitando datos de la Pila %d\n\n", p);
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