#include <stdio.h>
#include "TDAPila.h"
/* 2) Resolver recursivamente En una Pila se han almacenado valores enteros, se desea saber si están
ordenados de modo ascendente. No perder la pila.
Por ejemplo:
    Pila(tope) : 1 2 7 10 Rta: OK */
void analisisRec(TPila *, int *);
void cargaP(TPila *);
void main(){
    TPila P;
    int ok = 1;

    iniciaP(&P);
    cargaP(&P);
    
    analisisRec(&P, &ok);
    if (ok)
        printf("Estan ordenadas de manera ascendentes\n");
    else
        printf("No estan ordenadas de manera ascendentes\n");
    
}
void cargaP(TPila *P){
    TElementoP elem;
    int i, N;
    do{
        printf("Ingrese cuantos elementos desea almacenar\n");
        scanf("%d", &N);
    } while (N<=0 || N>MAX);
    
    for (i = 0; i < N; i++){
        printf("Ingrese el elemento %d\n",i+1);
        scanf("%d", &elem);
        poneP(P,elem);
    }
}
void analisisRec(TPila *P, int *ok){
    TElementoP elem;
    if (!vaciaP(*P)){
        sacaP(P,&elem);
        if (!vaciaP(*P)){
            if (elem<consultaP(*P))
                analisisRec(P,ok);
            else
                *ok = 0;
        }
        poneP(P,elem);
    }
}