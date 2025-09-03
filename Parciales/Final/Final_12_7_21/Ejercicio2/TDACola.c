#include "TDACola.h"

void iniciaC(TCola *C){
    (*C).pri = (*C).ult = -1;
}

void poneC(TCola *C, TElementoC x){
    if ((*C).ult != MAX-1){
        if ((*C).pri != -1) {
            (*C).pri = 0;
            (*C).ult = 0;
        } else 
            (*C).ult++;
        
        (*C).datos[(*C).ult];
    }
    
}