#include <stdio.h>

/* 1. Desarrollar funciones (algunas pueden ser void) para:
a) calcular el producto de dos números enteros positivos a partir de sumas sucesivas.
b) calcular cociente y resto entre dos números enteros positivos a partir de restas sucesivas
c) hallar el máximo elemento de un vector de enteros (realizar una versión void y otra int) */
#define SIZE 10
int productoRecursivo(int, int);
void cociResRecrusivo(int, int, int, int);
void MaximoRecursivoVoid(int [SIZE], int, int, int);
int MaximoRecursivoInt(int [SIZE], int, int, int);
void CargarVector(int [SIZE], int *);
void main(){
    int a, b,vec[SIZE], N;
    printf("Ingrese a y b enteros, para multiplicar y obtener el cociente y resto recursivamente: \n");
    scanf("%d %d", &a, &b);
    
    printf("Resultado de producto recursivo: %d \n", productoRecursivo(a,b));
    cociResRecrusivo(a, b, 0, 0);
    
    CargarVector(vec, &N);
    MaximoRecursivoVoid(vec,0,N,0);
    printf("El maximo elemento del vector es: %d\n", MaximoRecursivoInt(vec,0,N,0));
}
//a
int productoRecursivo(int a, int b){
    if (a>0) 
        return b + productoRecursivo(a-1, b);
    else
        return 0;
}
//b
void cociResRecrusivo(int a, int b, int cociente, int resto){
    if (a-b >= 0)
        cociResRecrusivo(a-b, b, ++cociente, resto);
    else 
        printf("El cociente es: %d y el resto: %d\n", cociente, a);
}
//c
void MaximoRecursivoVoid(int vec[SIZE], int i, int N, int max){
    if (i<N){
        if (max < vec[i])
            max = vec[i];
        MaximoRecursivoVoid(vec, i+1, N, max);
    } else 
        printf("El maximo elemento del vector es: %d\n", max);
}

int MaximoRecursivoInt(int vec[SIZE], int i, int N, int max){
    if (i<N){
        if (max < vec[i])
            max = vec[i];
        return MaximoRecursivoInt(vec, i+1, N, max);
    } else
        return max;
}

void CargarVector(int vec[SIZE], int *N){
    int i;
    do{
        printf("Cuantos elementos desea ingresar al arreglo? (Max = 10)\n");
        scanf("%d", N);
    } while (*N > 10 || *N <= 0);
    
    for (i = 0; i < *N; i++){
        printf("Ingrese el elemento V[%d] ", i);
        scanf("%d", &vec[i]);
    }
}