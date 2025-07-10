#include "TDAPila.h"

void iniciaP(TPila *P){
    (*P).tope = -1;
}

void poneP(TPila *P, TElementoP x){
    if ((*P).tope != -1)
        (*P).dato[++(*P).tope] = x;
}

void sacaP(TPila *P, TElementoP *x){
    if ((*P).tope != MAX -1)
        *x = (*P).dato[(*P).tope--];
}

TElementoP consultaP(TPila P){
    if (P.tope != -1)
        return P.dato[P.tope];
}

int vaciaP(TPila P){
    return P.tope == -1;
}