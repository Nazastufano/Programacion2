#include "TDACola.h"

int vaciaC(TCola C){
    return C.pri == -1;
}

void sacaC(TCola *C, TElementoC *x){
    if ((*C).pri != -1){
        *x = (*C).dato[(*C).pri];

        if ((*C).pri == (*C).ult){
            (*C).pri = -1;
            (*C).ult = -1;
        } else
            (*C).pri++;
    }
    
}