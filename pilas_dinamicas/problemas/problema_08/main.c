#include <stdlib.h>
#include <stdio.h>
#include "pilad.h"

void err();
void menu(Pila *s);
int tam(Pila *s);
void IngresarVehiculo(Pila *s);
void SacarVehiculo(Pila *s);
void MostrarCompleto(Pila *s);
void MostrarPlacas(Pila *s);

int main(){
    Pila *s = CrearPila();
    menu(s);
    return 0;
}

void menu(Pila *s){
    int opc;
    while(opc != 0){
        system("clear");
        printf("\n\n\t~ E S T A C I O N A M I E N T O ~\n\n");
        printf("[1] Entra un nuevo vehiculo.\n");
        printf("[2] Sale un vehiculo.\n");
        printf("[3] Ver estacionamiento actual (placas)\n");
        printf("[4] Ver estacionamiento actual (todos los datos)\n");
        printf("[0] Finaliza el turno.\n\n");
        printf("Opcion:  ");
        scanf("%d", &opc);
        switch(opc){
            case 0:
                printf("\n\tHasta luego!\n\n");
                break;
            case 1:
                if(tam(s) == 8){
                    printf("\nEstacionamiento lleno\n");
                    getchar();
                    getchar();
                } else {
                    IngresarVehiculo(s);
                }
                break;
            case 2:
                if(tam(s) == 0){
                    printf("\nEstacionamiento vacio\n");
                    getchar();
                    getchar();
                } else {
                    SacarVehiculo(s);
                }
                break;
            case 3:
                MostrarPlacas(s);
                break;
            case 4:
                MostrarCompleto(s);
                break;
        }
    }
}

void MostrarPlacas(Pila *s){
    CAR carro;
    Pila *aux = CrearPila();
    int i=tam(s);
    while(PilaVacia(s) == False){
        carro = Desapilar(s);
        Apilar(aux, carro);
        printf("\n\tVehiculo (%d)", i);
        printf("\n-> Placas: %d", carro.placas);
        i--;
    }
    getchar();
    getchar();
    while(PilaVacia(aux) == False){
        Apilar(s, Desapilar(aux));
    }
}

void MostrarCompleto(Pila *s){
    CAR carro;
    Pila *aux = CrearPila();
    int i=tam(s);
    while(PilaVacia(s) == False){
        carro = Desapilar(s);
        Apilar(aux, carro);
        printf("\n\tVehiculo (%d)", i);
        printf("\n-> Placas: %d", carro.placas);
        printf("\n-> Estado: %s", carro.estado);
        printf("\n-> Marca: %s", carro.marca);
        printf("\n-> Modelo: %s", carro.modelo);
        printf("\n-> A\1640: %d", carro.ano);
        printf("\n-> Propietario: %s\n", carro.nombre);
        i--;
    }
    while(PilaVacia(aux) == False){
        Apilar(s, Desapilar(aux));
    }
    getchar();
    getchar();
}

void SacarVehiculo(Pila *s){
    system("clear");
    int placa;
    Pila *aux = CrearPila();
    Pila *salida = CrearPila();
    CAR carro;
    printf("\n\n\t~ Sacando vehiculo ~\n\n");
    printf("Placas: ");
    scanf("%d", &placa);
    getchar();
    while(PilaVacia(s) == False){
        carro = Desapilar(s);
        if(carro.placas == placa){
            Apilar(aux, carro);
        } else {
            Apilar(salida, carro);
        }
    }
    while(PilaVacia(salida) == False){
        Apilar(s, Desapilar(salida));
    }
    printf("\nHa salido los autos con placa %d:\n", placa);
    MostrarCompleto(aux);
}

int tam(Pila *s){
    Pila *aux = CrearPila();
    int cont = 0;
    while(PilaVacia(s) == False){
        Apilar(aux, Desapilar(s));
        cont++;
    }
    while(PilaVacia(aux) == False){
        Apilar(s, Desapilar(aux));
    }
    return cont;
}

void IngresarVehiculo(Pila *s){
    system("clear");
    CAR carro;
    printf("\n\n\t~ Ingresando nuevo vehiculo ~\n\n");
    printf("Placas: ");
    scanf("%d", &carro.placas);
    getchar();
    printf("Estado [3 letras]: ");
    scanf("%s", carro.estado);
    getchar();
    printf("Marca: ");
    scanf("%s", carro.marca);
    getchar();
    printf("Modelo: ");
    scanf("%s", carro.modelo);
    getchar();
    printf("A\164o: ");
    scanf("%d", &carro.ano);
    getchar();
    printf("Nombre del propietario: ");
    scanf("%s", carro.nombre);
    getchar();
    Apilar(s, carro);
    printf("\nEl vehiculo a ingresado con exito\n");
    getchar();
}

void err(){
    printf("Algo hiciste mal kbron >:v \n");
    exit(0);
}
