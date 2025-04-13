#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
void inciaP(TPila *P){
    *P = NULL;
}

void poneP(TPila *P, TElementoP x){
    TPila N;
    N = (TPila)malloc(sizeof(nodoP));
    N->dato = x;
    N->sig = *P;
    *P = N;
}

void sacaP(TPila *P, TElementoP *x){
    TPila N;
    if (*P){
        N=*P;
        *x = (*P)->dato;
        *P = (*P)->sig;
        free(N);
    }
}

TElementoP consultaP(TPila P){
    if (P)
        return P->dato;
}

int vaciaP(TPila P){
    return (P == NULL);
}