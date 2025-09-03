#include "TDAArbol.h"
#include <stdio.h>

/* Ej 4.- (Utilizar TDA N.Ario) Dado un árbol N-ario de enteros, verificar mediante una solución no void 
que haya exactamente un nodo de grado K (K es dato de entrada). */

int verifica(ARBOL A, pos P, int K);

void main(){
    ARBOL A;
    int K;
    A = NULL;
    cargaA(&A);

    printf("Ingrese un valor K \n");
    scanf("%d", &K);

    if (verifica(A,raiz(A), K) == 1)
        printf("Existe exactamente un nodo de grado K=%d\n", K);
    else
        printf("Existe mas de un nodo de grado K=%d\n", K);
}

int verifica(ARBOL A, pos P, int K){
    pos C;
    int grado = 0, cumple = 0;
    if (!nulo(P)){
        C = hijoMasIzq(P,A);
        while (!nulo(C) && cumple <= 1){
            grado++;
            cumple += verifica(A,C,K);
            C = hermanoDer(C,A);
        }
        return cumple + grado == K;
    } else
        return 0;
}