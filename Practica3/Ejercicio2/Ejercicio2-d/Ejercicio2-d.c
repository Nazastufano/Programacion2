#include <stdio.h>

/* d) Desarrollar un procedimiento recursivo que devuelva en un arreglo los máximos de cada fila
de una matriz de MxN. */
#define SIZE 5

void CargarMatriz(int [][SIZE], int *, int *);
void MaxDeCadaFila(int [][SIZE], int [SIZE], int, int, int, int, int);
void MostrarVec(int [], int);
void main(){
    int vec[SIZE], mat[SIZE][SIZE], N,M;
    CargarMatriz(mat, &M, &N);
    MaxDeCadaFila(mat,vec,0,0,M-1,N-1,0);
}

void CargarMatriz(int mat[][SIZE], int *M, int *N){
    int i,j;

    do{
        printf("Ingrese M y N de la matriz \n");
        scanf("%d %d", M, N);
    } while (*N<1 || *N>SIZE || *M<1 || *M>SIZE || *N == *M);
    
    for (i = 0; i < *M; i++)
        for (j = 0; j < *N; j++){
            printf("Ingrese el elemento: M[%d][%d]=\n",i,j);
            scanf("%d", &mat[i][j]);
        }
}
void MostrarVec(int v[], int k){
    int i;
    printf("{ ");
    for ( i = 0; i < k; i++)
        printf("%d ", v[i]);

    printf("} \n");
}
void MaxDeCadaFila(int mat[][SIZE], int vec[SIZE], int i, int j, int M, int N, int max){
    if (i<=M){
        if (max<mat[i][j])
            max=mat[i][j];
        
        if (j<N)
            MaxDeCadaFila(mat,vec,i,j+1,M,N,max);
        else {
            vec[i]=max;
            MaxDeCadaFila(mat,vec,i+1,0,M,N,0);
        }
    } else
        MostrarVec(vec,i);

}