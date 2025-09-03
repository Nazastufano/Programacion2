#include "TDAArbol.h"
#include <stdio.h>

/* Ej 3.- (Utilizar TDA N-Ario) Se tiene un árbol N-Ario de enteros positivos, hallar mediante una función recursiva
int el valor de la menor clave no hoja del nivel, si no existe ninguna devolver -1. */

int existe(ARBOLN A, pos P, int nivel, int K);

void main(){
    ARBOLN A;
    int K, res;

    A = NULL;
    cargar(&A);
    printf("Ingrese un valor K \n");
    scanf("%d", &K);
    res = existe(A, raiz(A), 1, K);
    if (res == -1)
        printf("No existe ningun nodo de valor minimo antes del nivel K=%d\n", K);
    else
        printf("El valor de la menor clave no hoja del nivel K=%d es: %d\n", K, res);
}

int existe(ARBOLN A, pos P, int nivel, int K){
    pos C;
    int valor = -1, valorMin = 99999;
    if (!nulo(P) && nivel<=K && !nulo(hijoMasIzq(P,A))){
        C = hijoMasIzq(P,A);
        while (!nulo(C)){
            valor = existe(A,C,nivel+1,K); 

            valorMin = (valor != -1 && valorMin > valor) ? valor : valorMin;

            C = hermanoDer(C,A);
        }
        return nivel == K ? info(P,A) : valorMin;
    } else
        return -1;
}