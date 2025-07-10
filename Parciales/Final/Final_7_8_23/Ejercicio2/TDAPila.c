#include "TDAPila.h"

void poneP(TPila *P, TElementoP x){
    if ((*P).tope != MAX-1)
        (*P).datos[++(*P).tope] = x;
}

void sacaP(TPila *P, TElementoP *x){
    if ((*P).tope != -1)
        *x = (*P).datos[(*P).tope--];
}