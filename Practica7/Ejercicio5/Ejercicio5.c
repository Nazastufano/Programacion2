#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* 5. Desarrollar funciones para:
    A) calcular la profundidad de un árbol binario.
    b) retornar la longitud de la cadena más larga de un árbol binario de cadenas.
    c) devolver la cantidad de hijos derechos que contiene un árbol binario */

typedef int TElementoA;

typedef struct nodo{
    TElementoA dato;
    struct nodo *izq, *der;
}nodo;

typedef nodo * ARBOL;

void calcProfArb(ARBOL A, int *profundidad, int nivel);
int longitudCadMasLarga(ARBOL A);
int cantHijosDer(ARBOL A);

void main(){
    ARBOL A;
    int profundidad = 0;
    
    calcProfArb(A, &profundidad, 1);
    printf("La profundidad del arbol es: %d\n", profundidad);

    printf("La longitud de la cadena mas larga es: %d\n", longitudCadMasLarga(A));
    printf("La cantidad de hijos derechos es: %d\n", cantHijosDer(A));
}


void calcProfArb(ARBOL A, int *profundidad, int nivel){
    if (A != NULL){
        if (*profundidad < nivel)
            *profundidad = nivel-1;
        
        calcProfArb(A->izq, profundidad, nivel + 1);
        calcProfArb(A->der, profundidad, nivel + 1);
    }
}

/*
int calcProf(ARBOL A, int nivel){
    int izq, der;
    if (A != NULL){
        izq = calcProf(A->izq, nivel + 1);
        der = calcProf(A->der, nivel + 1);

        return izq < der ? der : izq;
    } else
        return nivel-1;
}
*/


int longitudCadMasLarga(ARBOL A){
    int izq, der, largo, masLarga;
    if (A != NULL){
        largo = strlen(A->dato);
        
        der = longitudCadMasLarga(A->der);
        izq = longitudCadMasLarga(A->izq);    
        
        masLarga = der > izq ? der : izq;
        
        return masLarga < largo ? largo : masLarga;
    } else
        return 0;
}


int cantHijosDer(ARBOL A){
    int cantHijos = 0;
    if (A != NULL) {
        if (A->der != NULL)
            cantHijos = 1;
        
        return cantHijos + cantHijosDer(A->izq) + cantHijosDer(A->der);
    } else
        return 0;
}
