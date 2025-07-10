#include <stdio.h>

/* Ej 3- Dada la matriz de alcance ALC de un digrafo G = (V, E) con |V|= N, obtener la cantidad
de nodos que sin tener bucle son alcanzados y alcanzan la misma cantidad de vértices.
El tratamiento de la matriz debe ser completamente recursivo.
No debe recorrer la matriz más de una vez */

#define MAX 10

void main(){
    int ALC[MAX][MAX], matAdy[MAX][MAX], N;

    //carga(matAdy, &N);
    //genera(ALC, N);
    
    printf("La cantidad de vertices sin bucle que son alcanzados y alcanzan la misma cantidad de nodos es: %d\n", cantNodos(ALC,0,0,N-1,0,0));
}

int cantNodos(int ALC[MAX][MAX], int i, int j, int N, int alcanza, int loAlcanza){
    if (i<=N){
        alcanza += ALC[i][j];
        loAlcanza += ALC[j][i];
        
        if (j<N && ALC[i][i] != 1)
            return cantNodos(ALC, i, j+1, N, alcanza, loAlcanza);
        else
            if (ALC[i][i] != 1 && alcanza == loAlcanza)
                return 1 + cantNodos(ALC, i+1, 0, N,0,0);
            else
                return cantNodos(ALC, i+1, 0, N, 0, 0);
    }
        return 0;
}
