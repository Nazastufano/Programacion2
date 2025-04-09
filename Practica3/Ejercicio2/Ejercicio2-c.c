#include <stdio.h>
/* c) Crear una función recursiva que busque el elemento mínimo de una matriz cuadrada. */

#define SIZE 5
int MinMatriz(int [][SIZE], int, int, int, int);
void CargarMatriz(int [][SIZE], int *);
void main(){
    int mat[SIZE][SIZE], N;
    CargarMatriz(mat, &N);
    printf("El minimo de la matriz es: %d", MinMatriz(mat,0,0,N-1,mat[0][0]));
}

void CargarMatriz(int mat[][SIZE], int *N){
    int i,j;

    do{
        printf("Ingrese el N de la matriz \n");
        scanf("%d", N);
    } while (*N<1 || *N>SIZE);
    
    for (i = 0; i < *N; i++)
        for (j = 0; j < *N; j++){
            printf("Ingrese el elemento: M[%d][%d]=\n",i,j);
            scanf("%d", &mat[i][j]);
        }
            
}

int MinMatriz(int mat[][SIZE], int i, int j, int N, int min){
    if (i<=N){
        if (min>mat[i][j])
            min = mat[i][j];
        
        if (j<N)
            return MinMatriz(mat,i,j+1,N,min);
        else
            return MinMatriz(mat,i+1,0,N,min);
    } else
        return min;
}