#include <stdio.h>

/* Ej 4.- Dado un grafo de N vértices implementado en una matriz de adyacencia, determinar mediante
una función recursiva entera si los primeros K vértices (K dato) tienen el mismo grado. */

#define MAX 10

int analisisRec(int matAdy[MAX][MAX], int i, int j, int N, int K, int grAnt, int grAct);

void main(){
    int K, N;
    int matAdy[MAX][MAX];
    cargaMat(matAdy, &N);
    do{
        printf("Ingrese un valor K menor que N=%d \n", N);
        scanf("%d", &K);
    } while (K > N && K < 0);
    if (analisisRec(matAdy,0,0,N-1,K-1, 0, 0))
        printf("Los primeros K=%d vertices tienen el mismo grado\n", K);
    else
        printf("Los primeros K=%d vertices no tienen el mismo grado\n", K);
    
}

int analisisRec(int matAdy[MAX][MAX], int i, int j, int N, int K, int grAnt, int grAct){
    if (i<=K){
        if (matAdy[i][j] != 0)
            grAct++;
        
        if (j<N)
            return analisisRec(matAdy, i, j+1, N, K, grAnt, grAct);
        else        
            return (grAnt == grAct || i == 0) && analisisRec(matAdy, i+1,0,N,K,grAct, 0);
    } else
        return 1;    
}
