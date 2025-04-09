#include <stdio.h>
/* b) Sea A un arreglo de reales y un valor X real ingresado por teclado, se pide determinar en
que posición se encuentra la primera ocurrencia de X o -1 en caso de no encontrarlo.
Implementar:
    I. Considerando el arreglo desordenado, una búsqueda lineal recursiva.
    II. Para un arreglo ordenado en forma ascendente, una búsqueda binaria recursiva. */

#define SIZE 10

void CargaArregloFloat(float [SIZE], int *);
int BusquedaLinealElemento(float [SIZE], int, int, float);
int BusquedaBinariaElemento(float [SIZE], int, int, float);
void main(){
    float A[SIZE], X;
    int N, pos;

    CargaArregloFloat(A, &N);

    printf("Ingrese un elemento X a buscar en el arreglo \n");
    scanf("%f", &X);
    
    BusquedaLinealElemento(A, 0, N, X);
    pos = BusquedaBinariaElemento(A, 0, N, X);
    if (pos != -1)
        printf("El elemento X=%.2f esta en la posicion %d \n", X, pos);
    else
        printf("El elemento X=%f no se encuentra en el arreglo", X);
        
}

void CargaArregloFloat(float A[SIZE], int *N){
    int i;
    do{
        printf("Ingrese el cuantos elementos va a tener el arreglo: (MAX = 10) \n");
        scanf("%d", N);
    } while (*N > SIZE || *N < 1);
    
    for (i = 0; i < *N; i++){
        printf("Ingrese el elemento V[%d]: \n", i);
        scanf("%f", &A[i]);
    }
}
int BusquedaLinealElemento(float A[SIZE], int i, int N, float X){
    if (i<N) {
        if (A[i] == X)
            return i;
        else
            return BusquedaLinealElemento(A,i+1,N,X);
    } else
        return -1;
    
}

int BusquedaBinariaElemento(float A[SIZE], int i, int N, float X){
    int medio;
    if (i < N){
        medio = (i+N) / 2;
        if (A[medio] == X)
            return medio;
        else if (A[medio] > X)
            return BusquedaBinariaElemento(A, i, medio - 1, X);
        else
            return BusquedaBinariaElemento(A, medio + 1, N, X);
    } else 
        return -1;
}