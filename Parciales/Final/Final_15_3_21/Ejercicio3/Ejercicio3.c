#include "TDAArbol.h"
#include <stdio.h>

/* Ej 3.- (Utilizar TDA N-Ario) Se tiene un ABB AB (sin elementos repetidos) y un árbol N-ario AN; ambos
de enteros. Desarrollar una solución que obtenga qué porcentaje de los elementos de AN que tienen
grado impar están en AB en un nivel menor a K (K dato de entrada). */

typedef struct nodoA{
    int dato;
    struct nodoA *izq, *der;
}nodoA;

typedef nodoA * ARBOLB;

int estaEnABB(ARBOLB AB, int nivel, int K, int clave);
void obtenerPorcen(ARBOLN AN, pos P, ARBOLB AB, int K, int *totalN, int *totalCumplen);

void main(){
    ARBOLB AB;
    ARBOLN AN;
    int K, totalN = 1, totalCumplen = 0;

    AB = NULL;
    AN = NULL;
    printf("Ingrese un nivel K \n");
    scanf("%d", &K);

    obtenerPorcen(AN, raiz(AN), AB, K, &totalN, &totalCumplen);

    printf("El promedio de elementos de AN que tienen grado impar que estan en AB en un nivel menor a K=%d es: %.2f%%\n", K, (float)(totalCumplen*100)/totalN);
}

int estaEnABB(ARBOLB AB, int nivel, int K, int clave){
    if (AB != NULL && nivel < K){
        if (clave < AB->dato)
            return estaEnABB(AB->izq, nivel+1, K, clave);
        else if (clave > AB->dato)
            return estaEnABB(AB->der, nivel +1, K, clave);
        else
            return 1;
    } else 
        return 0;
}

void obtenerPorcen(ARBOLN AN, pos P, ARBOLB AB, int K, int *totalN, int *totalCumplen){
    pos C;
    int gr = 0;
    if (!nulo(P)){
        C = hijoMasIzq(P,AN);

        while (!nulo(C)){
            gr++;
            obtenerPorcen(AN,C,AB, K, totalN, totalCumplen);
            C = hermanoDer(C,AN);
        }

        *totalN += gr;
        
        if (gr % 2 == 1 && estaEnABB(AB, 1, K, info(P,AN)))
            *totalCumplen += 1;
    }
}
