#include <stdio.h>

/* 11. Retornar el valor mínimo de un ABB. */

typedef struct nodo{
    int dato;
    struct nodo *izq, *der;
}nodo;

typedef nodo * ARBOL;

int valorMinABB(ARBOL ABB);

void main(){
    ARBOL ABB;
    ABB = NULL;
    //cargaA(&ABB);

    printf("El valor minimo del arbol es: %d\n", valorMinABB(ABB));
}

int valorMinABB(ARBOL ABB){
    ARBOL aux = ABB;
    
    while (aux->izq != NULL)
        aux = aux->izq;
    
    return ABB->dato;
}