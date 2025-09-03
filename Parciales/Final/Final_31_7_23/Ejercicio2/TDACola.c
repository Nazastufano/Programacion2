#include "TDACola.h"

void sacaC(TCola *C, TElementoC *x){
    if ((*C).pri != -1){
        *x = (*C).datos[(*C).pri];
        if ((*C).pri == (*C).ult){
            (*C).pri = -1;
            (*C).ult = -1;
        } else if ((*C).pri == MAX -1)
            (*C).pri = 0;
        else
            (*C).pri++;
    }
}