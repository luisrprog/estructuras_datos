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
    printf("Resultado: \n\n");
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
    Pila *aux = CrearPila();
    Pila *basura = CrearPila();
    while(PilaVacia(s) == False){
        if(Ultimo(s) == '@'){
            Apilar(basura, Desapilar(s));
            Apilar(basura, Desapilar(s));
        } else {
            Apilar(aux, Desapilar(s));
        }
    }
    while(PilaVacia(aux) == False){
        Apilar(s, Desapilar(aux));
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
