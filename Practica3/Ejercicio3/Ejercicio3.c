#include <stdio.h>

/* 3. Dado un vector A de N elementos, obtener el promedio de sus elementos. */
#define SIZE 10
float CalcProm(int [], int, int, float);
void CargaArregloInt(int [SIZE], int *);

void main(){
    int N;
    int A[SIZE];
    CargaArregloInt(A,&N);

    printf("El promedio de los N=%d elementos es: %.2f\n", N, CalcProm(A,0,N,0));
}

void CargaArregloInt(int A[SIZE], int *N){
    int i;
    do{
        printf("Ingrese el cuantos elementos va a tener el arreglo: (MAX = 10) \n");
        scanf("%d", N);
    } while (*N > SIZE || *N < 1);
    
    for (i = 0; i < *N; i++){
        printf("Ingrese el elemento A[%d]: \n", i);
        scanf("%d", &A[i]);
    }
}

float CalcProm(int A[SIZE], int i, int N, float suma){
    if (i<N)
        return CalcProm(A,i+1,N, suma+A[i]);
    else
        return suma/N;
}
