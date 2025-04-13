#include <stdio.h>

/* e) Dado dos arreglos de enteros A y B ordenados ascendentemente, mezcle ambos arreglos en
otro C manteniendo el orden pero sin pasar los elementos repetidos. */
#define SIZE 5
void CargaArregloInt(int [SIZE], int *);
void OrdenamientoRec(int [], int [], int[], int, int, int, int, int);
void MostrarElemArreglo(int [], int, int); 
void main(){
    int N,M;
    int A[SIZE] = {0}, B[SIZE], C[2*SIZE];
    CargaArregloInt(A,&N);
    CargaArregloInt(B,&M);
    OrdenamientoRec(A,B,C,0,0,-1,N,M);
}

void CargaArregloInt(int V[SIZE], int *N){
    int i;
    
    do{
        printf("Ingrese el cuantos elementos va a tener el arreglo: (MAX = 5) \n");
        scanf("%d", N);
    } while (*N > SIZE || *N < 1);

    for (i = 0; i < *N; i++){
        if (i == 0){
            printf("Ingrese el elemento V[%d]: \n", i);
            scanf("%d", &V[i]);
        } else
            do{
                printf("Ingrese el elemento V[%d]: \n", i);
                scanf("%d", &V[i]);
            } while (V[i]<=V[i-1]);
    }
}

void OrdenamientoRec(int A[], int B[], int C[], int i, int j, int k, int N, int M){
    if ((i<N || j<M) && A[i] == B[j]){
        k++;
        C[k] = A[i++];
        j++;
        OrdenamientoRec(A,B,C,i,j,k,N,M);
    } else if ((A[i] < B[j] || j>M-1) && i<N) {
        k++;
        C[k] = A[i++];
        OrdenamientoRec(A,B,C,i,j,k,N,M);
    } else if ((A[i]>B[j] || i>N-1) && j<M) {
        k++;
        C[k] = B[j++];
        OrdenamientoRec(A,B,C,i,j,k,N,M);
    } else
        MostrarElemArreglo(C,0,k);
}

void MostrarElemArreglo(int V[], int i, int N){
    if (i<=N){
        printf("V[%d] = %d \n", i, V[i]);
        MostrarElemArreglo(V,i+1,N);
    }
}
