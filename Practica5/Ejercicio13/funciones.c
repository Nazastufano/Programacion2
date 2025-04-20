#include "funciones.h"

void iniciaC(TColaC *C){
    (*C).pri = (*C).ult =-1; 
}

void poneC(TColaC *C, TElementoC x){
    if (!((*C).ult == MAX-1 && (*C).pri == 0 || (*C).ult+1 == (*C).pri)){
        if ((*C).pri == -1){
            (*C).pri = 0;
            (*C).ult = 0;
        } else if ((*C).ult == MAX -1)
            (*C).ult = 0;
        else
            (*C).ult +=1;
        
        (*C).datos[(*C).ult] = x;
    }
}

void sacaC(TColaC *C, TElementoC *x){
    if ((*C).pri != -1){
        *x = (*C).datos[(*C).pri];
        
        if (((*C).pri == (*C).ult))
            iniciaC(C);
        else if((*C).pri == MAX -1)
            (*C).pri = 0;
        else
            (*C).pri += 1;
    }
    
}

TElementoC consultaC(TColaC C){
    if (C.pri !=-1)
        return C.datos[C.pri];
}

int vaciaC(TColaC C){
    return C.pri ==-1;
}