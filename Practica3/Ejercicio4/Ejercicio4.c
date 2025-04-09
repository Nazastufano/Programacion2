#include <stdio.h>

/* 4. Dada una matriz A de NxM float, retornar la cantidad de veces que un valor X aparece en A
(realizar una versión void y otra int) */
#define SIZE 3
int AparicionesInt(float [][SIZE], int, int, int, int, float);
void AparicionesVoid(float [][SIZE], int, int, int, int, int, float);
void CargarMatriz(float [][SIZE], int *, int *);

void main(){
    int N,M;
    float A[SIZE][SIZE], X;
    CargarMatriz(A,&N,&M);

    printf("Ingrese el elemento X a buscar: \n");
    scanf("%f", &X);

    printf("La cantidad de apariciones del elemento X=%.2f es %d\n", X, AparicionesInt(A,0,0,N-1,M-1,X));
    AparicionesVoid(A,0,0,N-1,M-1,0,X);
}

void CargarMatriz(float mat[][SIZE], int *N, int *M){
    int i,j;

    do{
        printf("Ingrese N y M de la matriz \n");
        scanf("%d %d", N, M);
    } while (*N<1 || *N>SIZE || *M<1 || *M>SIZE || *N == *M);
    
    for (i = 0; i < *N; i++)
        for (j = 0; j < *M; j++){
            printf("Ingrese el elemento: M[%d][%d]=\n",i,j);
            scanf("%f", &mat[i][j]);
        }
}

int AparicionesInt(float A[][SIZE], int i, int j, int N, int M, float X){
    int cant = 0;
    if (i<=N){
        if (A[i][j] == X)
            cant = 1;
        if (j<M)
            return cant + AparicionesInt(A,i,j+1,N,M,X);
        else
            return cant + AparicionesInt(A,i+1,0,N,M,X);
    } else 
        return 0;
    
}

void AparicionesVoid(float A[][SIZE], int i, int j, int N, int M, int cant, float X){
    if (i<=N){
        if (A[i][j] == X)
            cant++;
        if (j<M)
            AparicionesVoid(A,i,j+1,N,M,cant,X);
        else
            AparicionesVoid(A,i+1,0,N,M,cant,X);
    } else
        printf("La cantidad de apariciones del elemento X=%.2f es %d", X,cant);
    
}