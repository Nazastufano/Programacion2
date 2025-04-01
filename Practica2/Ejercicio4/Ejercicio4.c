#include <stdio.h>
#include <stdlib.h>

/* 4. Desarrollar un programa que cree dinámicamente un arreglo de números reales que contenga
N elementos (N es ingresado por teclado). Ingresar sus elementos y mostrar aquellos que sean
positivos utilizando aritmética de punteros. Al finalizar, liberar la memoria solicitada en tiempo
de ejecución. */

int main() {
    int N,i; 
    float *pFloat;
    
    printf("Ingrese N: \n");
    scanf("%d", &N);
    pFloat = (float *)malloc(N*sizeof(float));
    for (i = 0; i < N; i++){
        printf("Ingrese el elemento %d\n", i);
        
        scanf("%f", (pFloat+i));
    }
    for (i = 0; i < N; i++)
        if (*(pFloat+i) >= 0)
            printf("%.2f ", *(pFloat+i));
    
    free(pFloat);
}