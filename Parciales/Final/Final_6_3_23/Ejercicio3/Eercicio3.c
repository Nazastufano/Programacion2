#include <stdio.h>
#include "TDANArio.h"

/* Ej 3.- (Utilizar TDA N-Ario) Dados un árbol AN N-Ario de enteros y un árbol binario AB que proviene de la
transformación de un bosque de enteros, desarrollar una función int que retorne la cantidad de árboles del 
bosque que contenían una cantidad de claves que estaba en AN en el nivel K (K dato). (O sea, si la cantidad de
claves en un árbol de AB era X, X está en AN en el nivel K)
    Si la solución se resuelve mediante una función void, el puntaje obtenido no superará la mitad del asignado */

typedef struct nodoA{
    int dato;
    struct nodoA *izq, *der;
}nodoA;

typedef nodoA * ARBOLB;

int recorrerAB(ARBOLB AB);
int recorrerBosque(ARBOLB AB, ARBOLN AN, int K);
int cantNArio(ARBOLN AN, pos P, int cantN, int nivel, int K);

void main(){
    ARBOLB AB;
    ARBOLN AN;
    int K;
    AB = NULL;
    AN = NULL;
    printf("Ingrese un valor de K\n");
    scanf("%d", &K);

    printf("La cantidad de arboles del bosque que contenian una cantidad de claves que estava en AN en el nivel K=%d es: %d\n", K, recorrerBosque(AB, AN, K));
}

int recorrerAB(ARBOLB AB){
    if (AB != NULL){
        return 1 + recorrerAB(AB->izq) + recorrerAB(AB->der);
    } else
        return 0;
}

int recorrerBosque(ARBOLB AB, ARBOLN AN, int K){
    int cant = 0;
    while (AB != NULL){
        cant +=  cantNArio(AN, raiz(AN), recorrerAB(AB->izq) + 1, 1, K);
        AB = AB->der;
    }
    return cant;
}

int cantNArio(ARBOLN AN, pos P, int cantN, int nivel, int K){
    pos C;
    int cumple = 0;
    if (!nulo(P) && nivel <= K){
        C = hijoMasIzq(P, AN);
        while (!nulo(C) && !cumple){
            cumple = cantNArio(AN,C,AB,nivel+1,K);
            C = hermanoDer(C,AN);
        }
        return (cumple || (nivel == K && info(P,AN) == cantN));
    } else
        return 0;
} 