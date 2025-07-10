#include <stdio.h>

/* 15. Codificar soluciones para los algoritmos de Kruskal y de Prim, suponiendo grafos almacenados
en matriz de adyacencia. */

#define MAX 10

void algoritmoKruskal(int matAdy[MAX][MAX], int matKru[MAX][MAX]);
void algoritmoPrim(int matAdy[MAX][MAX], int matPri[MAX][MAX]);
void inicializarMat(int mat[MAX][MAX]);
void cargarVec(int vec[MAX]);
void agregarCamino(int vcc[MAX], int V1, int V2);

void main(){
    int matAdy[MAX][MAX], matKru[MAX][MAX], matPri[MAX][MAX];

    //cargaMat(matAdy);
    algoritmoKruskal(matAdy, matKru);
    algoritmoPrim(matAdy, matPri);
}

void algoritmoKruskal(int matAdy[MAX][MAX], int matKru[MAX][MAX]){
    int vcc[MAX];
    int min, j, i, V1, V2;

    cargarVec(vcc);
    inicializarMat(matKru);
    while (!recorrerVec(vcc)){
        min = 99999;
        for (i = 0; i < MAX; i++)
            for (j = i+1; j < MAX; j++)
                if (matAdy[i][j] < min && matAdy[i][j] != 0 && vcc[i] != vcc[j]){
                    min = matAdy[i][j];
                    V1 = i;
                    V2 = j;
                }
        matKru[V1][V2] = min;
        agregarCamino(vcc,V1,V2);
    }
}

void algoritmoPrim(int matAdy[MAX][MAX], int matPri[MAX][MAX]){
    int min, i, j, V;
    int vec[MAX] = {0};
    vec[0] = 1;

    inicializarMat(matPri);
    while (!recorrerVec(vec)){
        min = 99999;
        for (i = 0; i < MAX; i++){
            if (vec[i] == 1){
                for (j = i+1; j < MAX; j++)
                    if (vec[j] == 0 && min > matAdy[i][j] && matAdy[i][j] != 0){
                        min = matAdy[i][j];
                        V = j;
                    }
            }
        }    
        matPri[i][V] = min;
        vec[V] = 1;
    }
}

void cargarVec(int vec[MAX]){
    int i;
    for (i = 0; i < MAX; i++)
        vec[i]= i;
}


int recorrerVec(int vec[MAX]){
    int i = 0;
    while (i < MAX && vec[0] == vec[i])
        i++;

    return i == MAX;
}


void agregarCamino(int vcc[MAX], int V1, int V2){
    int i;
    V1 = vcc[V1];
    V2 = vcc[V2];
    for (i = 0; i < MAX; i++)
        if (vcc[i] == V1 || vcc[i] == V2)
            vcc[i] = V1;
}

void inicializarMat(int mat[MAX][MAX]){
    int i, j;
    for (i = 0; i < MAX; i++)
        for (j = 0; j < MAX; j++)
            mat[i][j] = 0;
}