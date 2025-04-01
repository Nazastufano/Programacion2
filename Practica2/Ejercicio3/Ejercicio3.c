#include <stdio.h>
#include <stdlib.h>
/* 3. Implementar un programa que cree dinámicamente 3 variables enteras, muestre su suma y su
producto. Asegurarse de administrar correctamente la memoria e implementar una función
para evitar duplicaciones de código en la creación y lectura de cada variable. */


int main(){
    int *num1, *num2, *num3, suma, producto;
    
    num1 = (int *)malloc(sizeof(int));
    num2 = (int *)malloc(sizeof(int));
    num3 = (int *)malloc(sizeof(int));
    
    printf("Ingrese el num 1\n");
    scanf(" %d", num1);
    
    printf("Ingrese el num 2\n");
    scanf(" %d", num2);
    
    printf("Ingrese el num 3\n");
    scanf(" %d", num3);
    
    suma = *num1 + *num2 + *num3;
    producto = *num1 * *num2 * *num3;

    free(num1);
    free(num2);
    free(num3);
    
    printf("La suma es %d y el producto es %d",suma,producto);
    return 0;
}