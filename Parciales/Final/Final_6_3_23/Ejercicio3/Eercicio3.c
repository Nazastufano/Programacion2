#include <stdio.h>
#include "TDANArio.h"

/* */


typedef struct nodoA{
    int dato;
    struct nodoA *izq, *der;
}nodoA;

typedef nodoA * ARBOLB;

void main(){
    ARBOLB AB;
    ARBOLN AN;
    int K;
    AB = NULL;
    AN = NULL;
    printf("Ingrese un valor de K\n");
    scanf("%d", &K);

    printf("La cantidad de arboles del bosque que contenian una cantidad de claves que estava en AN en el nivel K=%d es: %d\n", K, cantNArio(AN,raiz(AN),AB,1,K))
}

int recorrerAB(ARBOLB AB){
    if (AB != NULL){
        return 1 + recorrerAB(AB->izq) + recorrerAB(AB->der);
    } else
        return 0;
}

int recorrerBosque(ARBOLB AB, int clave){
    int cant = 0;
    while (AB != NULL){
        cant = (recorrerAB(AB->izq) + 1) == clave;
        AB = AB->der;
    }
    return cant;
}

int cantNArio(ARBOLN AN, pos P, ARBOLB AB, int nivel, int K){
    pos C;
    int cant = 0;
    if (!nulo(P) && nivel <= K){
        C = hijoMasIzq(P, AN);
        while (!nulo(C)){
            cant += cantNArio(AN,C,AB,nivel+1,K);
            C = hermanoDer(C,AN);
        }
        return nivel == K ? cant + recorrerBosque(AB, info(P,AN)) : cant;
    } else
        return cant;
    
}