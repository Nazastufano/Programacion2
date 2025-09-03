#include <stdio.h>

/* Ej 4.- Se tiene un digrrafo G = (V,E) con V=|N| y aristas ponderadas, almacenado en una matriz de adyacencia y
un ABB de enteros. Determinar de forma recursiva sobre la matriz, si para cada vértice de G que tenga bucle
se verifica que su grado de entrada se encuentra en ABB. Definir tipos. */

#define MAX 10

typedef struct nodoA{
    int dato;
    struct nodoA *izq, *der;
}nodoA;

typedef nodoA * ARBOL;

int verifica(ARBOL ABB, int matAdy[MAX][MAX], int i, int j, int N, int grado);
int buscarA(ARBOL ABB, int grado);

void main(){
    ARBOL ABB;
    int matAdy[MAX][MAX], N;

    ABB = NULL;

    cargaABB(&ABB);
    cargarMat(matAdy, &N);

    if (verifica(ABB, matAdy, 0,0,N-1, 0))
        printf("Para cada vertice de G que tenga bucle se verifica que su grado de entrada se encuentra en ABB \n");
    else 
        printf("No cumple que para cada vertice de G que tenga bucle se verifica que su grado de entrada se encuentra en ABB");
}

int verifica(ARBOL ABB, int matAdy[MAX][MAX], int i, int j, int N, int grado){
    if (i<=N){
        if (matAdy[i][i] != 0){
            grado += matAdy[j][i] != 0;
            if (j<N)
                return verifica(ABB, matAdy, i, j+1, N, grado);
            else 
                return buscarA(ABB, grado) && verifica(ABB, matAdy, i+1, 0, N, 0);
        } else
            return verifica(ABB, matAdy, i+1, 0, N, 0);
    } else
        return 1;
}

int buscarA(ARBOL ABB, int grado){
    if (ABB != NULL){
        if (grado < ABB->dato)
            return buscarA(ABB->izq, grado);
        else if (grado > ABB->dato)
            return buscarA(ABB->der, grado);
        else
            return 1;
    } else
        return 0;   
}