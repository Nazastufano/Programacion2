#include <stdio.h>

/* 2. Recodificar en el lenguaje C los siguientes ejercicios de Programación I desarrollados en Pascal:
a) Sea V un arreglo de enteros, se pide:
    I. Calcular e informar la suma de sus elementos.
    II. Mostrar sus elementos.
    III. Mostrar sus elementos en orden inverso. */

#define SIZE 10
//a)
void SumaArreglo(int [SIZE], int, int, int); //i)
void MostrarElemArreglo(int [SIZE], int, int); //ii)
void MostrarElemArregloInv(int [SIZE], int, int); //iii)

void CargaArregloInt(int [SIZE], int *);
void main(){
    int N, V[SIZE];
    CargaArregloInt(V, &N);
    
    SumaArreglo(V,0,N,0);

    printf("Elementos en orden izquierda a derecha \n");
    MostrarElemArreglo(V,0,N);
    
    printf("Elementos en orden derecha a izquierda \n");
    MostrarElemArregloInv(V, 0,N);
}
void CargaArregloInt(int V[SIZE], int *N){
    int i;
    do{
        printf("Ingrese el cuantos elementos va a tener el arreglo: (MAX = 10) \n");
        scanf("%d", N);
    } while (*N > SIZE || *N < 1);
    
    for (i = 0; i < *N; i++){
        printf("Ingrese el elemento V[%d]: \n", i);
        scanf("%d", &V[i]);
    }
}

//i)
void SumaArreglo(int V[SIZE], int i, int N, int suma){
    if (i<N)
        SumaArreglo(V, i+1, N, suma+V[i]);
    else
        printf("La suma de los elementos del vector es: %d \n", suma);
}

//ii)
void MostrarElemArreglo(int V[SIZE], int i, int N){
    if (i<N){
        printf("V[%d] = %d \n", i, V[i]);
        MostrarElemArreglo(V,i+1,N);
    }
}

//iii)
void MostrarElemArregloInv(int V[SIZE], int i, int N){
    if (i<N){    
        MostrarElemArregloInv(V,i+1,N);
        printf("V[%d] = %d \n", i, V[i]);
    }
} 