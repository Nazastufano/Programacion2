#include <stdio.h>

/* 4. Desarrollar un subprograma que reciba como parámetro una matriz de adyacencia que
representa un digrafo sin aristas ponderadas y retorne en la misma matriz el grafo subyacente. */

void main(){
    int matAdy[10][10];

    //cargarMatAdy(matAdy);

    pasarAGrafoSubya(matAdy);
}


void pasarAGrafoSubya(int matAdy[10][10]){
    int i, j;

    for (i = 0; i < 10; i++)
        for (j = i + 1; j < 10; j++)
            if (matAdy[i][j] == 1 || matAdy[j][i] == 1)
                matAdy[i][j] = matAdy[j][i] = 1;
}

/*
void pasarAGrafoSubya(int matAdy[10][10]){
    int i, j;

    for (i = 0; i < 10; i++)
        for (j = 0; j < 10; j++)
            if (matAdy[i][j] == 1)
                matAdy[j][i] = 1;
}
*/