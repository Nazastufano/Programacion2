#include <stdio.h>

/* 13. Generar un arreglo de caracteres con el contenido de las claves de un ABB. Los elementos del
arreglo deben quedar ordenados descendentemente. */

#define MAX 50

typedef struct nodo{
    char dato;
    struct nodo *izq, *der;
} nodo;

typedef nodo * ARBOL;

void generarVec(ARBOL ABB, char vec[MAX], int *i);

void main(){
    ARBOL ABB;
    char vec[MAX];
    int pos = 0;
    ABB = NULL;
    //cargarABB(&ABB);

    generarVec(ABB, vec, &pos);
}

void generarVec(ARBOL ABB, char vec[MAX], int *i){
    if (ABB != NULL){
        generarVec(ABB->der, vec, i);
        vec[*i] = ABB->dato;
        (*i)++;
        generarVec(ABB->izq,vec, i);
    }
}