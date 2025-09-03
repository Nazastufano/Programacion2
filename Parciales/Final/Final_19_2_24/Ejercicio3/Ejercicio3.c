#include "TDAArbol.h"
#include <stdio.h>

/* Ej 3.- (Utilizar TDA N-Ario) Dado un árbol A N-Ario de enteros, determinar si hay exactamente K nodos
no hoja que tienen grado igual al nivel en el que se encuentran (K es dato) */

void analizar(ARBOL A, pos P, int nivel, int K, int *cantN);

void main(){
    ARBOL A;
    int K, cantN = 0;
    A = NULL;
    cargaA(&A);
    printf("Ingrese un valor K: \n");
    scanf("%d", &K);
    
    analizar(A, raiz(A), 1, K, &cantN);
    
    if (cantN == K)
        printf("Existen exactamente K nodos no hoja que tienen grado igual al nivel en el que se encuentran \n");
    else
        printf("No hay exactamente K nodos no hoja que tienen grado igual al nivel en el que se encuentran \n");
}


void analizar(ARBOL A, pos P, int nivel, int K, int *cantN){
    pos C;
    int grado = 0;
    if (!nulo(P)){
        C = hijoMasIzq(P,A);
        
        while (!nulo(C) && *cantN <= K){
            grado++;
            
            analizar(A,C,nivel+1,K,cantN);

            C = hermanoDer(C,A);
        }
        
        if (grado > 0 && grado == nivel)
            *cantN += 1;
    }
}
