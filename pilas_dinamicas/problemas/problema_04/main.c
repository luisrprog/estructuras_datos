#include <stdlib.h>
#include <stdio.h>
#include "pilad.h"

void err(int i);
void SolicitarCadena(char *cad);
float EvaluarCadena(Pila *s, char *cad);


int main(){
    Pila *s = CrearPila();
    char cad[100];
    SolicitarCadena(cad);
    printf("\n%s = %.2f \n\n", cad, EvaluarCadena(s, cad));
    return 0;
}

float EvaluarCadena(Pila *s, char *cad){
    int pos = 0;
    float n, a, b;
    char opc[1];
    while(cad[pos] != '\0'){
        *opc = cad[pos++];
        switch(*opc){
            case '+':
                b = Desapilar(s);
                a = Desapilar(s);
                Apilar(s, a+b);
                break;
            case '-':
                b = Desapilar(s);
                a = Desapilar(s);
                Apilar(s, a-b);
                break;
            case '*':
                b = Desapilar(s);
                a = Desapilar(s);
                Apilar(s, a*b);
                break;
            case '/':
                b = Desapilar(s);
                a = Desapilar(s);
                if(b == 0){
                    err(1);
                }
                Apilar(s, a/b);
                break;
            default:
                n = atof(opc);
                Apilar(s, n);
                break;
        }
    }
    return (Desapilar(s));
}

void SolicitarCadena(char *cad){
    int pos = 0;
    printf("Ingrese su cadena: ");
    while((cad[pos++] = getchar()) != '\n');
    cad[--pos] = '\0';
}

void err(int i){
    if(i == 1){
        printf("Divison entre cero\n");
        exit(0);
    } else {
        printf("Algo hiciste mal kbron >:v \n");
    }
    exit(0);
}
