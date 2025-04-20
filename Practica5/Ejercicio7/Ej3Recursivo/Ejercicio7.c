#include <stdio.h>
#include "funciones.h"
/* 3. Ingresar los números de DNI de los votantes de una mesa a medida que van votando y mostrar
los últimos N (es dato) votantes
a. en orden inverso, comenzando por el último votante.
b. en el orden que sufragaron.*/
void mostrarUltimos(TPila *, int, int);
void mostrarEnOrden(TPila *, int, int);
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
    mostrarUltimos(&P,0, N);
    printf("Orden que sufragaron: \n");
    mostrarEnOrden(&P,0, N);
}

void mostrarUltimos(TPila *P, int i, int N){
    TElementoP elem;
    if (!vaciaP(*P)){
        sacaP(P, &elem);
        if (i<N){
            
            printf("%d \n", elem);
            mostrarUltimos(P,i+1,N);
            
        }   
        poneP(P,elem);  
    }
}

void mostrarEnOrden(TPila *P, int i, int N){
    TElementoP elem;
    if (!vaciaP(*P)){
        sacaP(P, &elem);
        mostrarEnOrden(P,i+1,N);
        if (P->tope+1 < N)
            printf("%d \n", elem);
        
        poneP(P,elem);  
    }
}