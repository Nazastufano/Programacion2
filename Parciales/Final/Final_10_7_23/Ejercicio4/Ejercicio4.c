#include <stdio.h>
/* Ej 4.- Dado un grafo acíclico de N vértices (numerados de 1 a N) con aristas ponderadas almacenado en
la mitad inferior de una matriz de adyacencia, determinar si todos los vértices pares (2, 4, etc) tienen el
mismo grado. [No se permite el uso de estructuras auxiliares] */

#define MAX 5

void main(){
    int matAdy[MAX][MAX];
    int N;

    cargarMatAdy(matAdy, &N);

    if (verifica(matAdy, N-1))
        printf("Todos los vertices pares tienen el mismo grado. \n");
    else
        printf("No todos los vertices pares tienen el mismo grado. \n");
}

int verifica(int matAdy[MAX][MAX], int N){
    int grado, gradoComp = 0, cumple = 1;
    int i, j, k = 1;

    while (k<N && cumple){
        grado = 0;
        for (j = 0; j < k-1; j++)
            grado += matAdy[k][j] != 0;
            
        for (i = k+1; i < N; i++)
            grado += matAdy[i][k] != 0;
        
        if (k == 1)
            gradoComp = grado;
        
        cumple = gradoComp != grado;

        k += 2;
    }
    return cumple;
}