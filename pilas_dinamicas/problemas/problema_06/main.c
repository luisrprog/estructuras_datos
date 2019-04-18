#include <stdlib.h>
#include <stdio.h>
#include "pilad.h"

void err();
void LeeTexto(Pila *s);
void AnalizaTexto(Pila *s);
void MostrarTexto(Pila *s);

int main(){

    Pila *s = CrearPila();
    LeeTexto(s);
    AnalizaTexto(s);
    MostrarTexto(s);
    return False;
}

void MostrarTexto(Pila *s){
    Pila *aux = CrearPila();
    char letra;
    printf("\n\nResultado: ");
    while(PilaVacia(s) == False){
        Apilar(aux, Desapilar(s));
    }
    while(PilaVacia(aux) == False){
        letra = Desapilar(aux);
        printf("%c", letra);
    }
    printf("\n");
}

void AnalizaTexto(Pila *s){
    Pila *evaluar = CrearPila();
    Pila *basura = CrearPila();
    char letra;
    int cont=0, i;
    while(PilaVacia(s) == False){
        Apilar(evaluar, Desapilar(s));
    }
    while(PilaVacia(evaluar) == False){
        letra = Desapilar(evaluar);
        if(letra != '@'){
            Apilar(s, letra);
        } else{
            Apilar(basura, letra);
            Apilar(basura, Desapilar(s));
        }
    }
}

void LeeTexto(Pila *s){
    char cad[100];
    int i=0;
    printf("\nIngrese cadena post-fija:\n");
    scanf("%s", &cad);
    while(cad[i] != '\0'){
        Apilar(s, cad[i]);
        i++;
    }
}

void err(){
    printf("Algo hiciste mal kbron >:v \n");
    exit(0);
}
