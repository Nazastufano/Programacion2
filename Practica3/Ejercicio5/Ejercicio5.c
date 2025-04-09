#include <stdio.h>

/* 5. Determinar mediante una función “lógica” si una matriz cuadrada de dimensión NxN es
simétrica (aij = aji) con respecto a su diagonal. */

#define SIZE 5

int EsSimetrica(int [][SIZE], int, int, int);

void CargarMatriz(int [][SIZE], int *);

void main(){
    int mat[SIZE][SIZE], N;
    CargarMatriz(mat,&N);

    if (EsSimetrica(mat,N-1,N-2,N-1))
        printf("La matriz es simetrica\n");
    else
        printf("La matriz no es simetrica\n");
    
}

void CargarMatriz(int mat[][SIZE], int *N){
    int i,j;

    do{
        printf("Ingrese N de la matriz \n");
        scanf("%d", N);
    } while (*N<1 || *N>SIZE);
    
    for (i = 0; i < *N; i++)
        for (j = 0; j < *N; j++){
            printf("Ingrese el elemento: M[%d][%d]=\n",i,j);
            scanf("%d", &mat[i][j]);
        }
}

int EsSimetrica(int mat[][SIZE], int i, int j, int N){
    if (i>0){
        if (mat[i][j] == mat[j][i]){
            if (j>0){
                return EsSimetrica(mat,i,j-1,N);
            } else
                return EsSimetrica(mat,i-1,i-2,N);
        } else
            return 0;
    } else
        return 1;
    
}
