#include "TDAPila.h"
#include <stdlib.h>

void sacaP(TPila *P, TElementoP *X){
    TPila aux;
    if ((*P) != NULL){
        aux = *P;
        *X = aux->dato;
        *P = (*P)->sig;
        free(aux);
    }
}