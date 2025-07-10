#include <stdio.h>
#include "TDANArio.h"

/* Ej 2- (Utilizar TDA N-ario) Dado un árbol N-Ario de enteros determinar mediante una
función int, si existe algún nodo (no hoja) que verifique que el grado de todos sus hijos es creciente.
Si la solucón es void, el puntaje obtenido será no mayor a 1,75p */

int calcGrado(ARBOL A, pos P);
int existe(ARBOL A, pos P);

void main(){
    ARBOL A;
    //carga(&A);
    if (existe(A, raiz(A)))
        printf("El arbol tiene ");
    else
        printf("El arbol no tiene ");

    printf("un nodo (no hoja) que el grado de todos sus hijos es creciente \n");
}

int calcGrado(ARBOL A, pos P){
    int grado = 0;
    pos C;
    if (!nulo(P)){
        C = hijoMasIzq(P,A);
        while (!nulo(C)){
            grado++;
            C = hermanoDer(C,A);
        }
        return grado;
    } else
        return -1;
}

int existe(ARBOL A, pos P){
    int grado, gradoAnt;
    pos C, H;

    if (!nulo(P)){
        H = C = hijoMasIzq(P,A);
        if (!nulo(C)){
            gradoAnt = -1;
            grado = calcGrado(A,C);

            while (!nulo(C) && gradoAnt < grado){
                gradoAnt = grado;
                C = hermanoDer(C,A);
                grado = calcGrado(A,C);
            }

            if (nulo(C))
                return 1;
            else
                return existe(A,H) || existe(A, hermanoDer(P,A));
        } else
            return existe(A, hermanoDer(P,A));
    } else
        return 0;
}