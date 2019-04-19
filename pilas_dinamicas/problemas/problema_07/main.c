#include <stdlib.h>
#include <stdio.h>
#include "pilad.h"

void err();
void AgregarExpediente(Pila *s);
void LeerExpediente(Pila *s);
void ExpedientePorMes(Pila *s);
void ExpedientePorFecha(Pila *s);
void mostrar(Pila *x);

int main(){
    Pila *s = CrearPila();
    int opc;
    while(opc != 4){
        system("clear");
        printf("\n\n\t~ M E N U ~\n\n");
        printf("[1] Agrear expedientes.");
        printf("\n[2] Mostrar Expedientes por mes.");
        printf("\n[3] Mostrar expedientes por fecha");
        printf("\n[4] Salir.\n\nOpcion: ");
        scanf("%d", &opc);
        getchar();
        switch(opc){
            case 1:
                AgregarExpediente(s);
                break;
            case 2:
                ExpedientePorMes(s);
                break;
            case 3:
                ExpedientePorFecha(s);
                break;
        }
    }
    printf("\n\tHasta luego!\n\n");
    return 0;
}

void ExpedientePorFecha(Pila *s){
    int dia_i, dia_f, mes_i, mes_f, ano_i, ano_f;
    EXP aux;
    Pila *r = CrearPila();
    Pila *f = CrearPila();

    printf("\n\n\tExpedientes por fecha\n\n");
    printf("Fecha inicial\n");
    printf("Dia: ");
    scanf("%d", &dia_i);
    printf("Mes: ");
    scanf("%d", &mes_i);
    printf("A\164o: ");
    scanf("%d", &ano_i);
    printf("\nFecha final\n");
    printf("Dia: ");
    scanf("%d", &dia_f);
    printf("Mes: ");
    scanf("%d", &mes_f);
    printf("A\164o: ");
    scanf("%d", &ano_f);

    while(PilaVacia(s) == False){
        aux = Desapilar(s);
        Apilar(r, aux);
        if(aux.fecha.dia >= dia_i && aux.fecha.dia <= dia_f
        && aux.fecha.mes >= mes_i && aux.fecha.mes <= mes_f
        && aux.fecha.ano >= ano_i && aux.fecha.ano <= ano_f){
            Apilar(f, aux);
        }
    }
    while(PilaVacia(r) == False){
        Apilar(s, Desapilar(r));
    }
    printf("\n\tMostrando expedientes por fecha\n");
    mostrar(f);
}

void mostrar(Pila *x){
    EXP aux;
    while(PilaVacia(x) == False){
        aux = Desapilar(x);
        printf("\nNumero: %d", aux.numero);
        printf("\nTitular: %s", aux.titular);
        printf("\nTramite: %s", aux.tramite);
        printf("\nFecha");
        printf("\nDia: %d", aux.fecha.dia);
        printf("\nMes: %d", aux.fecha.mes);
        printf("\nA\164o: %d\n", aux.fecha.ano);
    }
}

void ExpedientePorMes(Pila *s){
    Pila *m = CrearPila();
    Pila *r = CrearPila();
    EXP auxiliar;
    int ms;
    system("clear");
    printf("\nDe que mes desea ver expedientes?  ");
    scanf("%d", &ms);
    getchar();
    while(PilaVacia(s) == False){
        auxiliar = Desapilar(s);
        Apilar(r, auxiliar);
        if(auxiliar.fecha.mes == ms){
            Apilar(m, auxiliar);
        }
    }
    system("clear");
    printf("\nMostrando expedientes del mes %d", ms);
    mostrar(m);
    while(PilaVacia(r) == False){
        Apilar(s, Desapilar(r));
    }
    sleep(5);
}

void AgregarExpediente(Pila *s){
    int opc=1;
    while(opc != 2){
        system("clear");
        if(opc == 1){
            LeerExpediente(s);
        }
        printf("\nDesea agregar un nuevo expediente?\n");
        printf("[1] Si\n[2] No\n\nOpcion: ");
        scanf("%d", &opc);
        getchar();
    }
}

void LeerExpediente(Pila *s){
    EXP expediente;
    printf("\n\tNuevo Expediente\n\n");
    printf("Numero: ");
    scanf("%d", &expediente.numero);
    getchar();
    printf("Titular: ");
    scanf("%s", expediente.titular);
    getchar();
    printf("Tramite: ");
    scanf("%s", expediente.tramite);
    getchar();
    printf("Fecha:\n");
    printf("Dia: ");
    scanf("%d", &expediente.fecha.dia);
    getchar();
    printf("Mes: ");
    scanf("%d", &expediente.fecha.mes);
    getchar();
    printf("a\164o: ");
    scanf("%d", &expediente.fecha.ano);
    getchar();
    Apilar(s, expediente);
}


void err(){
    printf("Algo hiciste mal kbron >:v \n");
    exit(0);
}
