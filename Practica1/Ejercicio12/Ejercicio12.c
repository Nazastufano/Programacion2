#include <stdio.h>
/* 12. Desarrollar un programa que muestre la suma de un conjunto de números naturales ingresados
por teclado. La serie finaliza al ingresar el número 0. */

void main() {
    int num;
    long int suma = 0;
    while (num !=0 ) {
        printf("Ingrese un numero (0 para dejar de ingresar): ");
        scanf("%d", &num);

        suma += num;
    }
    printf("La suma de los numeros ingresados es: %ld", suma);
}