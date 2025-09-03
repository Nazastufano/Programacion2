#include <stdio.h>
#include "TDAArbol.h"

/* Ej 3.- (Utilizar TDA N-Ario) Dado un árbol AN N-Ario de enteros determinar mediante una función int si
algún nodo no hoja tien todos sus hijos matores a él. [Si la solución se resuelve mediante una función void,
el puntaje obtenido no superará la mitad del asignado] */

int determina(ARBOL AN, pos P);

void main(){
    ARBOLN AN;
    AN = NULL;
    if (determina(AN, raiz(AN)))
        printf("Existe algun nodo no hoja que tiene todos sus hijos mayores a el\n");
    else
        printf("No existe algun nodo no hoja que tiene todos sus hijos mayores a el\n");
}

int determina(ARBOL AN, pos P){
    pos C;
    int condicion = 1, cumple = 0;
    if (!nulo(P) && !nulo(hijoMasIzq(P,AN))){
        C = hijoMasIzq(P,AN);
        while (!nulo(C) && !cumple){
            condicion = condicion && info(P,AN) < info(C,AN);
            cumple = determina(AN,C);
            hermanoDer(C,AN);
        }
        return cumple || condicion;
    } else
        return 0;
}