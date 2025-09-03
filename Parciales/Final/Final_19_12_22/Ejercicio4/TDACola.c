#include "TDACola.h"

void iniciaC(TCola *C){
    (*C).pri = (*C).ult = -1;
}

void poneC(TCola *C, TElementoC x){
    if (!((*C).ult != MAX-1 && (*C).pri == 0 || (*C).ult +1 == (*C).pri)){
        if ((*C).pri == -1){
            (*C).pri = 0;
            (*C).ult = 0;
        } else if ((*C).ult == MAX -1)
            (*C).ult = 0;
        else
            (*C).ult++;
        (*C).dato[(*C).ult] = x;
    }    
}

void sacaC(TCola *C, TElementoC *x){
    if ((*C).pri != -1){
        *x = (*C).dato[(*C).pri];
        if ((*C).pri == (*C).ult)
            iniciaC(C);
        else if ((*C).pri == MAX -1)
            (*C).pri = 0;
        else
            (*C).pri++;
    }
}