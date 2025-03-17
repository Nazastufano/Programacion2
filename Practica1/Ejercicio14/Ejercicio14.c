#include <stdio.h>

/* 14. Desarrollar un subprograma que muestre un cuadrado con bordes de N numerales (N es
parámetro de entrada). 
Por ej: para N = 4 
####
#  #
#  #
####
*/

void MostrarCuadrados(int N);

void main(){
    unsigned int N;
    printf("Ingrese un N: ");
    scanf("%d", &N);

    MostrarCuadrados(N);
}

void MostrarCuadrados(int N){
    int i,j;
    for (i = 1; i <= N; i++){
        for (j = 1; j <= N; j++){
            if (j == 1 || j == N || i == 1 || i == N) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}