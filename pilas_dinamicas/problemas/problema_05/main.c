#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "cola.h"

void err();
void menu(Pila *s, Pila *t, Pila *u);
void solicitarDatos(Pila *s);
void NumeroElementos(Pila *pila);
void ElementoFondo(Pila *pila);
void CopiarPila(Pila *s, Pila *t);
void ConcatenarPilas(Pila *s, Pila *t, Pila *u);
void MostrarPila(Pila *pila, int np);

int main(){

    Pila *s = CrearPila();
    Pila *t = CrearPila();
    Pila *u = CrearPila();
    solicitarDatos(s);
    menu(s, t, u);

    return 0;
}

void MostrarPila(Pila *pila, int np){
    Pila *aux = CrearPila();
    char n;
    system("clear");
    if(np == 1){
        printf("\nMostrando Pila Original\n");
    } else if(np == 2){
        printf("\nMostrando Pila Copiada\n");
    } else {
        printf("\nMostrando Pila Concatenada\n\n");
    }
    while(PilaVacia(pila) == False){
        n = Desapilar(pila);
        printf("(%d)-> %c \n", np, n);
        Apilar(aux, n);
    }
    while(PilaVacia(aux) == False){
        Apilar(pila, Desapilar(aux));
    }
    sleep(5);
}

void ConcatenarPilas(Pila *s, Pila *t, Pila *u){
    Pila *s_aux = CrearPila();
    char n;
    while(PilaVacia(s) == False){
        n = Desapilar(s);
        Apilar(s_aux, n);
    }
    while(PilaVacia(s_aux) == False){
        n = Desapilar(s_aux);
        Apilar(u, n);
        Apilar(s, n);
    }
    while(PilaVacia(t) == False){
        n = Desapilar(t);
        Apilar(s_aux, n);
    }
    while(PilaVacia(s_aux) == False){
        Apilar(u, Desapilar(s_aux));
    }

    system("clear");
    printf("\n\n\tPilas concatenadas con exito\n");
    sleep(2);
}

void CopiarPila(Pila *s, Pila *t){
    Pila *aux = CrearPila();
    char n;
    // Si t esta lleno, entonces se vacia
    if(PilaVacia(t) == False){
        while(PilaVacia(t) == False){
            n = Desapilar(t);
        }
    }
    while(PilaVacia(s) == False){
        Apilar(aux, Desapilar(s));
    }
    while(PilaVacia(aux) == False){
        n = Desapilar(aux);
        Apilar(s, n);
        Apilar(t, n);
    }
    system("clear");
    printf("\n\n\tPila copiada con éxito\n");
    sleep(2);
}

void ElementoFondo(Pila *pila){
    char fondo;
    Pila *aux = CrearPila();
    while(PilaVacia(pila) == False){
        fondo = Desapilar(pila);
        Apilar(aux, fondo);
    }
    while(PilaVacia(aux) == False){
        Apilar(pila, Desapilar(aux));
    }
    system("clear");
    printf("\n\n\tEl elemento del fondo es: %d\n", fondo);
    sleep(2);
}

void NumeroElementos(Pila *pila){
    Pila *aux = CrearPila();
    int cont=0;
    while(PilaVacia(pila) == False){
        Apilar(aux, Desapilar(pila));
        cont++;
    }
    while(PilaVacia(aux) == False){
        Apilar(pila, Desapilar(aux));
    }
    system("clear");
    printf("\n\n\tLa pila tiene %d elementos\n", cont);
    sleep(2);
}

void solicitarDatos(Pila *s){
    char n = '1';
    while(n != '0'){
        printf("Elemento:  ");
        scanf("%c", &n);
        if(n != '0'){
            Apilar(s, n);
        }
        getchar();
    }
}

void menu(Pila *s, Pila *t, Pila *u){
    int opc=10, val;
    while(opc != 0){
        system("clear");
        printf("\n\n\t* M E N U *\n\n");
        printf("[1] Calcular el numero de elementos de una pila.\n");
        printf("[2] Consultar el elemento del fondo de la pila.\n");
        printf("[3] Copiar una pila a otra.\n");
        printf("[4] Concatenar dos pilas.\n");
        printf("[5] Mostrar Pila\n");
        printf("[0] Salir.\n\n");
        printf("\t\tOpcion:   ");
        scanf("%d", &opc);
        getchar();
        switch(opc){
            case 0:
                printf("\n\t\tHasta Luego\n");
                exit(0);
                break;
            case 2:
                printf("Pila original(1), Pila copia(2) o Pila concatenada(3)?: ");
                scanf("%d", &val);
                getchar();
                switch(val){
                    case 1:
                        ElementoFondo(s);
                        break;
                    case 2:
                        ElementoFondo(t);
                        break;
                    case 3:
                        ElementoFondo(u);
                        break;
                }
                break;
            case 1:
                printf("Pila original(1), Pila copia(2) o Pila concatenada(3)?: ");
                scanf("%d", &val);
                getchar();
                switch(val){
                    case 1:
                        NumeroElementos(s);
                        break;
                    case 2:
                        NumeroElementos(t);
                        break;
                    case 3:
                        NumeroElementos(u);
                        break;
                }
                break;
            case 3:
                CopiarPila(s, t);
                break;
            case 4:
                ConcatenarPilas(s, t, u);
                break;
            case 5:
                printf("Pila original(1), Pila copia(2) o Pila concatenada(3)?: ");
                scanf("%d", &val);
                getchar();
                switch(val){
                    case 1:
                        MostrarPila(s, 1);
                        break;
                    case 2:
                        MostrarPila(t, 2);
                        break;
                    case 3:
                        MostrarPila(u, 3);
                        break;
                }
                break;
        }
    }
}

void err(){
    printf("Algo hiciste mal kbron >:v \n");
    exit(0);
}