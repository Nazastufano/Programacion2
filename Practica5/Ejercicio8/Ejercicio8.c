#include <stdio.h>
#include "funciones.h"
/* 8. Transformar, mediante un subprograma recursivo, una pila de manera que tenga los mismos
datos pero cambiados de signo. */

void mostrarPila(TPila *P);
void cambiarSigno(TPila *P);

void main(){
    TPila P;
    TElementoP elem;
    int i, N;
    iniciaP(&P);
    
    do{
        printf("Ingrese la cantidad de datos que desea almacenar\n");
        scanf("%d", &N);
    } while (N<1 || N>MAX);
    
    for (i = 0; i < N; i++){
        printf("Ingrese el elemento %d: \n",i+1);
        scanf("%d", &elem);
        poneP(&P, elem);
    }
    
    mostrarPila(&P);
    printf("\n");
    cambiarSigno(&P);

    mostrarPila(&P);
}

void mostrarPila(TPila *P){
    TElementoP elem;
    if (!vaciaP(*P)){
        sacaP(P,&elem);
        printf("%d \n", elem);
        mostrarPila(P);
        poneP(P,elem);
    }
}

void cambiarSigno(TPila *P){
    TElementoP elem;
    if (!vaciaP(*P)){
        sacaP(P,&elem);
        cambiarSigno(P); 
        poneP(P,elem * (-1));
    }
}