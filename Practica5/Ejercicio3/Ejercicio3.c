#include <stdio.h>
#include "funciones.h"
/* 3. Ingresar los números de DNI de los votantes de una mesa a medida que van votando y mostrar
los últimos N (es dato) votantes
a. en orden inverso, comenzando por el último votante.
b. en el orden que sufragaron.*/
void mostrarUltimos(TPila *, int);
void mostrarEnOrden(TPila *, int);
void main(){
    TPila P;
    int dni, cant, i, N;
    iniciaP(&P);

    do{
        printf("Ingrese la cantidad de DNI que desea registrar\n");
        scanf("%d", &cant);
    } while (cant<0 || cant > MAX-1);
    
    for (i = 0; i < cant; i++){
        printf("DNI numero %d: \n", i+1);
        scanf("%d", &dni);
        poneP(&P, dni);
    }

    do{
        printf("Cuantos DNI desea mostrar? \n");
        scanf("%d", &N);
    } while (N<0 || N>P.tope+1);

    printf("Orden de pila: \n");
    mostrarUltimos(&P, N);
    printf("Orden que sufragaron: \n");
    mostrarEnOrden(&P, N);
}

void mostrarUltimos(TPila *P, int N){
    TPila aux;
    int dni, i = 0;
    
    iniciaP(&aux);

    while (!vaciaP(*P)){
        sacaP(P, &dni);
        if (i < N){
            printf("DNI %d\n", dni);
            i++;
        }
        
        poneP(&aux, dni);
    }
    
    while (!vaciaP(aux)){
        sacaP(&aux,&dni);
        poneP(P,dni);
    }
}

void mostrarEnOrden(TPila *P, int N){
    TPila aux;
    int dni, i = 0;
    
    iniciaP(&aux);
    
    while (!vaciaP(*P)){
        sacaP(P, &dni);
        poneP(&aux, dni);
    }
    
    while (!vaciaP(aux)){
        sacaP(&aux,&dni);
        poneP(P,dni);
        if (i++<N)
            printf("DNI %d\n", dni);
    }
}