#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

void iniciaC(TCola *C){
    (*C).pri = (*C).ult = NULL;
}

int vaciaC(TCola C){
    return C.pri == NULL;
}

TElementoC consultaC(TCola C){
    if (C.pri != NULL)    
        return C.pri->dato;
}

void sacaC(TCola *C, TElementoC *x){
    nodoC *aux;
    if (C->pri != NULL){
        aux = (*C).pri;
        *x = aux->dato;
        (*C).pri = (*C).pri->sig;
        if ((*C).pri == NULL)
            (*C).ult ==NULL;
        free(aux);
    }
}

void poneC(TCola *C, TElementoC x){
    nodoC *aux;
    aux = (nodoC *)malloc(sizeof(nodoC));
    aux->dato = x;
    aux->sig = NULL;
    if (C->pri == NULL)
        (*C).pri = aux;
    else
        (*C).ult->sig = aux;
}