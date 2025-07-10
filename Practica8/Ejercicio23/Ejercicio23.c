#include <stdio.h>
/* 23. Desarrollar un subprograma para mostrar el camino de un vértice v a un vértice w a partir de la
matriz P generada por el algoritmo de Floyd. (v, w datos). */

#define MAX 10

void main(){
    int P[MAX][MAX];
    int V,W;
    //cargaP(P);

    mostrarCamino(P, V, W);
}

void mostrarCamino(int P[MAX][MAX], int i, int j){
    if (P[i][j] != 0)
        mostrarCamino(P, i, P[i][j]);
    
    printf("Voy al vertice: %d\n", j);
}