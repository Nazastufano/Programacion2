#include <stdio.h>

/* 6. Dada una matriz de NxM enteros, determinar si la suma de los elementos de cada fila es mayor
a la suma de los elementos de la fila anterior. Para la primera fila se debe cumplir que la suma
de sus elementos sea par. */
#define SIZE 5
void CargarMatriz(int [][SIZE], int *, int *);
int AnalisisMat(int [][SIZE], int, int, int, int, int, int);

void main(){
    int mat[SIZE][SIZE], N,M;
    CargarMatriz(mat,&N,&M);

    if (AnalisisMat(mat,0,0,N-1,M-1,0,0))
        printf("La suma de los elementos de cada fila es mayor a la suma de los anteriores, y la suma de la primera fila es par\n");
    else
        printf("La suma de los elementos de la primera fila no es par, o la suma de los elementos de la fila anterior es mayor");
}

void CargarMatriz(int mat[][SIZE], int *N, int *M){
    int i,j;

    do{
        printf("Ingrese N y M de la matriz \n");
        scanf("%d %d", N, M);
    } while (*N<1 || *N>SIZE || *M<1 || *M>SIZE || *N == *M);
    
    for (i = 0; i < *N; i++)
        for (j = 0; j < *M; j++){
            printf("Ingrese el elemento: M[%d][%d]=\n",i,j);
            scanf("%d", &mat[i][j]);
        }
}

int AnalisisMat(int mat[][SIZE], int i, int j, int N, int M, int suma, int sumaAnt){
    if (i<=N){
        suma += mat[i][j];
        if (j<M)
            return AnalisisMat(mat,i,j+1,N,M, suma, sumaAnt);
        else if ((suma > sumaAnt && i>0) || (i == 0 && suma % 2 == 0))
            return AnalisisMat(mat,i+1,0,N,M,0,suma);
        else
            return 0;
    } else
        return 1;
}