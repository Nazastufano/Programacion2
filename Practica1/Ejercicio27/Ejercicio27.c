#include <stdio.h>
#include <stdlib.h>

/* 27. Desarrollar una función que a partir de una matriz de NxM elementos enteros, devuelva en un
arreglo de structs, fila, columna y valor de las componentes de la matriz divisibles por N+M */

#define SIZE 5
typedef struct {
    int posI, posJ, val;
} datosMatriz;

typedef datosMatriz *pDatosMat;

void CargarMatriz(int [][SIZE], int *, int *);
void AnalizarMatriz(int [][SIZE],int,int, int *,pDatosMat);
void MuestraArreglo(pDatosMat, int);
void main(){
    int N, M, k=0, mat[SIZE][SIZE];
    pDatosMat pMat;
    
    CargarMatriz(mat,&N,&M);
    pMat = (pDatosMat)malloc(N*M*sizeof(datosMatriz));
    AnalizarMatriz(mat,N,M,&k,pMat);
    MuestraArreglo(pMat, k);
    free(pMat);
}

void CargarMatriz(int mat[SIZE][SIZE], int *N, int *M){
    int i,j;
    do{
        printf("Ingrese N: \n");
        scanf("%d", N);
        printf("Ingrese M: \n");
        scanf("%d", M);
    } while (*N >= SIZE || *M >= SIZE);
    for (i = 0; i < *N; i++) 
        for (j = 0; j < *M; j++){
            printf("Ingrese la posicion [%d][%d] ", i,j);
            scanf("%d", &mat[i][j]);
        }
}

void AnalizarMatriz(int mat[SIZE][SIZE],int N,int M,int *k, pDatosMat pMat){
    int i,j;
    for (i = 0; i < N; i++)
        for (j = 0; j < M; j++)
            if (mat[i][j] % (N+M) == 0){
                (pMat + *k)->posI = i;
                (pMat + *k)->posJ = j;
                (pMat + *k)->val = mat[i][j];
                *k = *k + 1;
            }
}

void MuestraArreglo(pDatosMat pMat, int k){
    int i;
    for (i = 0; i < k; i++)
        printf("i: %d, j:%d, valor:%d \n", (pMat+i)->posI, (pMat+i)->posJ, (pMat+i)->val);
}