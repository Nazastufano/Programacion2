#include "TDAPila.h"

void sacaP(TPilaP *P, TElementoP *x){
    if ((*P).tope != -1)
        *x = (*P).datos[(*P).tope--];
}

