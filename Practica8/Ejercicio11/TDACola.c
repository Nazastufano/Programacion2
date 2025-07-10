#include "TDACola.h"

void iniciaC(TCola *C){
    (*C).pri = (*C).ult = -1;
}

void poneC(TCola *C, TElementoC x){
    if ((*C).ult != MAX -1){
        if ((*C).pri == -1)
            (*C).pri = 0;

        (*C).dato[++(*C).ult] = x;
    }
}

void sacaC(TCola *C, TElementoC *x){
    if ((*C).pri != -1){
        *x = (*C).dato[(*C).pri];
        
        if ((*C).pri == (*C).ult)
            iniciaC(C);
        else 
            (*C).pri++;
    }
}

TElementoC consultaC(TCola C){
    if (C.pri != -1)
        return C.dato[C.pri];
}

int vaciaC(TCola C){
    return C.pri == -1;
}