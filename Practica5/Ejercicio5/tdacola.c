#include "tdacola.h"
#include <stdio.h>

void iniciac(TCOLA *C){
    (*C).pri = (*C).ult =-1;
}

void ponec(TCOLA *C, TELEMENTOC x){
    if ((*C).ult != MAX-1){
        if ((*C).pri == -1)
            (*C).pri = 0;
        (*C).datos[++((*C).ult)] = x;
    }
}

void sacac(TCOLA *C, TELEMENTOC *x){
    if ((*C).pri != -1){
        *x = (*C).datos[(*C).pri];
        if ((*C).pri == (*C).ult)
            iniciac(C);
        else
            (*C).pri +=1;
    }
}

TELEMENTOC consultac(TCOLA C){
    if (C.pri != -1)
        return(C.datos[C.pri]);
}

int vaciac(TCOLA C){
    return (C.pri == -1);
}