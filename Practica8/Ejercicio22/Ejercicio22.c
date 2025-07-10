#include <stdio.h>
/* 22. Desarrollar un subprograma para mostrar el camino del vértice origen al vértice v (dato) a partir
del vector P generado por el algoritmo de Dijkstra. */

#define MAX 10

void mostrarCaminoRec(int P[MAX], int v);

void main(){
    int P[MAX];
    int v;
    printf("Ingrese un vertice de origen: \n");
    scanf("%d", &v);
    //cargaP(matAdy, P);

    mostrarCaminoRec(P,v);
}

void mostrarCaminoRec(int P[MAX], int v){
    if (P[v] != 0)
        mostrarCaminoRec(P, P[v]);
    
    printf("Voy al vertice: %d\n", v);
}

