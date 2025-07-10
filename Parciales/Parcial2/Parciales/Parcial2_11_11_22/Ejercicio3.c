#include <stdio.h>
/* Ej 3- Dados un grafo G de N vértices, almacenado en el triángulo inferior de una
matriz de adyacencia A, y un grafo G' de N vértices almacenado en el triángulo 
superior de la misma matriz G y G' son acíclicos y no tienen aristas ponderadas.
Determinar si G' es subgrafo de G.
    No se permite recorrer nignuna estructura más de una vez
    Desarrollar un main completo que incluya declaraciones, inicializaciones, invocaciones y
    resultados obtenidos. */

#define MAX 10

int esSubGrafo(int matAdy[MAX][MAX], int N);

void main(){
    int matAdy[MAX][MAX];
    int N;
    cargaMatAdy(matAdy, &N);

    if (esSubGrafo(matAdy, N-1))
        printf("G' es \n");
    else
        printf("G' no es \n");
    printf(" subgrafo de G");
}


int esSubGrafo(int matAdy[MAX][MAX], int N){
    int i = 0, j, condicion = 1;
    while (i<=N){
        j = i+1;
        while (j<=N && condicion){
            j+1;
            condicion = matAdy[j][i] == 0 && matAdy[i][j] == 0 || matAdy[j][i] != 0 && matAdy[j][i] >= matAdy[i][j];
        }
        i+1;
    }
    return condicion;
}

