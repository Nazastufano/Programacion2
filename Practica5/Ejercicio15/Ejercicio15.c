#include <stdio.h>
#include <string.h>
#include "TDAPila.h"
#include "TDACola.h"
/* 15. Un sistema de inscripción a una maratón toma los datos de una cola de competidores (apellido
y nombre) y genera las identificaciones apilándolas según la inicial de los apellidos. Mostrar los
datos de la pila de los apellidos que comienzan con una letra solicitada al operador. */

void apilamientoRecursivo(TPila *, TElementoC);
void cargaC(TCola *);
void acomodarPila(TCola *, TPila *, int *);
void mostrarConInicial(TPila *, char, int);
void main(){
    TCola C;
    TPila P;
    char c;
    int N = 0;

    iniciaC(&C);
    iniciaP(&P);
    cargaC(&C);
    acomodarPila(&C,&P, &N);
    printf("Ingrese una inicial para buscar apellidos:\n");
    scanf(" %c", &c);
    mostrarConInicial(&P, c, N);
}

void apilamientoRecursivo(TPila *P, TElementoC elemC){
    TElementoP elemP;

    if (!vaciaP(*P)){
        sacaP(P,&elemP);
        if (elemP.apellido[0]>elemC.apellido[0]){
            apilamientoRecursivo(P,elemC);
            poneP(P,elemP);
        } else {
            poneP(P,elemP);
            strcpy(elemP.apellido, elemC.apellido);
            strcpy(elemP.nombre,elemC.nombre);
            poneP(P, elemP);
        }
    } else {
        strcpy(elemP.apellido, elemC.apellido);
        strcpy(elemP.nombre,elemC.nombre);
        poneP(P, elemP);
    }
    
}

void cargaC(TCola *C){
    TElementoC elem;
    int res;
    do{
        printf("Ingrese el nombre del participante:\n");
        scanf("%s", elem.nombre);
        printf("Ingrese el apellido del participante:\n");
        scanf("%s", elem.apellido);
        poneC(C,elem);

        printf("desea ingresar otro participante? (0 terminar)\n");
        scanf("%d", &res);
    } while (res != 0);
}

void acomodarPila(TCola *C, TPila *P, int *N){
    TElementoC elemC;
    while (!vaciaC(*C)){
        sacaC(C,&elemC);
        apilamientoRecursivo(P,elemC);
        (*N)++;
    }
}

void mostrarConInicial(TPila *P, char c, int N){
    TElementoP elem;
    int cont = 0, encuentra = 0;
    while (!vaciaP(*P)){
        sacaP(P,&elem);
        ++cont;

        if (elem.apellido[0] == c){
            printf("%s, %s numero de identificacion %d\n", elem.apellido, elem.nombre, N - cont + 1);
            encuentra = 1;
        }
            
    }
    if (encuentra != 1)
        printf("No hay competidores con esa letra de apellido\n");
    
    
}
/*
void acomodarSinRecu(TPila *P, TElementoC elemC);
    TPila PAux;
    TElementoP elemP;

    while (!vaciaP(*P) && elemC.apellido[0]>elemP.apellido[0]){
        sacaP(P,&elemP);
        poneP(&PAux, elemP);
    }
    
    strcpy(elemP.apellido, elemC.apellido);
    strcpy(elemP.nombre,elemC.nombre);
    poneP(P, elemP);
    
    while (!vaciaP(PAux)){
        sacaP(&PAux, &elemP);
        poneP(P,elemP);
    }
*/


