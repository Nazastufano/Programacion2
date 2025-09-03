#include "TDANArio.h"
#include <stdio.h>

/* Ej 3.- (Utulizar TDA N-Ario) Dados un árbol AN N-Ario de enteros y un árbol binario AB que proviene de
la transformación de un árbol general de enteros, desarrollar una función int que obtenga y devuelva la
cantidad de elementos de AN que verifican que, si su grado es G, G esta en el árbol general en un 
nivel menor a K. (K dato positivo) [Si la solución se resuelve mediante una función void, el puntaje obtenido
no superará la mitad del asignado] */

typedef struct nodo{
    int dato;
    struct nodo *izq, *der;
} nodo;

typedef nodo * ARBOLB;

int calcGrado(ARBOLB AB);
int recorrerAB(ARBOLB AB, int izq, int nivel, int K, int G);
int cantVerifican(ARBOLAN AN, pos P, ARBOLB AB, int K);

void main(){
    ARBOLAN AN;
    ARBOLB AB;
    int K;

    AB = NULL;
    AN = NULL;

    cargaAN(&AN);
    cargaAB(&AB);

    printf("Ingrese un valor K \n");
    scanf("%d", &K);

    printf("La cantidad de elementos de AN que verifican que, si su grado grado es G, G estaba en el árbol general en un nivel menor a K=%d es: %d\n", K, cantVerifican());
}

int calcGrado(ARBOLB AB){
    int grado = 0;
    while (AB != NULL){
        grado++;
        AB = AB->der;
    }
    return grado;
}

int recorrerAB(ARBOLB AB, int izq, int nivel, int K, int G){
    if (AB != NULL){
        if (nivel < K)
            if (izq && calcGrado(AB) == G)
                return 1;
            else
                return recorrerAB(AB->izq, 1, nivel+1, K, G) || recorrerAB(AB->der, 0, nivel, K, G);
        else
            return 0;
    } else
        return 0;
}

int cantVerifican(ARBOLAN AN, pos P, ARBOLB AB, int K){
    pos C;
    int gr = 0, cant = 0;
    if (!nulo(P)){
        C = hijoMasIzq(P,AN);
        while (!nulo(C)){
            gr++;
            cant += cantVerifican(AN, C, AB, K);
            C = hermanoDer(C,AN);
        }
        return cant + recorrerAB(AB->izq, 1, 1, K, gr);
    } else
        return 0;
}