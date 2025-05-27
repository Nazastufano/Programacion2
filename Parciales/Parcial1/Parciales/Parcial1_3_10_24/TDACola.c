#include "TDACola.h"
#include <stdlib.h>

void iniciaC(TCola *C){
    (*C).pri = C->ult = NULL;
}

void poneC(TCola *C, TElementoC x){
    nodoC *aux;
    aux = (nodoC*)malloc(sizeof(nodoC));
    aux->datos = x;
    aux->sig = NULL;
    if (C->pri == NULL)
        C->pri = aux;
    else 
        C->ult->sig = aux;
    
    C->ult = aux;
}


void sacaC(TCola *C, TElementoC *x){
    nodoC * aux;
    if (C->pri != NULL){
        *x = C->pri->datos;
        aux = C->pri;
        C->pri = C->pri->sig;
        
        if (C->pri == NULL)
            C->ult == NULL;
        free(aux);
    }   
}

int vaciaC(TCola C){
    return C.pri == NULL;
}

TElementoC consultaC(TCola C){
    if (C.pri != NULL)
        return C.pri->datos;
}