#include <stdio.h>
#include "fraccion.h"

/* 1. Realizar un TDA para números fraccionarios, es decir aquellos que se expresan como el
cociente de dos números enteros. Las operaciones que deberá soportar el TDA son:
◦ crear(entero numerador, entero denominador) retorna fracción.
◦ numerador(fracción f) retorna entero.
◦ denominador(fracción f) retorna entero.
◦ sumar(fracción f1, fracción f2) retorna fracción.
◦ restar(fracción f1, fracción f2) retorna fracción.
◦ multiplicar(fracción f1, fracción f2) retorna fracción.
◦ dividir(fracción f1, fracción f2) retorna fracción.
◦ simplificar(fracción f) retorna fracción simplificada.
◦ iguales(fracción f1, fracción f2) retorna verdadero o falso. */

void main(){
    fraccion f1, f2, fAux;
    f1 = crear(10,30);
    f2 = crear(1,3);

    printf("f1: %d/%d y f2: %d/%d \n", numerador(f1), denominador(f1), numerador(f2), denominador(f2));
    
    if (iguales(f1,f2))
        printf("Son iguales\n");
    else
        printf("No son iguales\n");
    
    fAux = sumar(f1,f2);
    printf("La suma de las fracciones f1: %d/%d y f2: %d/%d es %d/%d \n", numerador(f1), denominador(f1), numerador(f2), denominador(f2), numerador(fAux), denominador(fAux));
    fAux = restar(f1,f2);

    if (fAux.numerador != 0)
        printf("La resta de las fracciones f1: %d/%d y f2: %d/%d es %d/%d \n", numerador(f1), denominador(f1), numerador(f2), denominador(f2), numerador(fAux), denominador(fAux));
    else
        printf("La resta de las fracciones f1: %d/%d y f2: %d/%d es %d \n", numerador(f1), denominador(f1), numerador(f2), denominador(f2), numerador(fAux));
    
    fAux = multiplicar(f1,f2);
    if (fAux.numerador != 0)
        printf("La multiplicacion de las fracciones f1: %d/%d y f2: %d/%d es %d/%d \n", numerador(f1), denominador(f1), numerador(f2), denominador(f2), numerador(fAux), denominador(fAux));
    else
        printf("La multiplicacion de las fracciones f1: %d/%d y f2: %d/%d es %d \n", numerador(f1), denominador(f1), numerador(f2), denominador(f2), numerador(fAux));
    
    fAux = dividir(f1,f2);
    if (fAux.numerador != 0)
        printf("La division de las fracciones f1: %d/%d y f2: %d/%d es %d/%d \n", numerador(f1), denominador(f1), numerador(f2), denominador(f2), numerador(fAux), denominador(fAux));
    else
        printf("La division de las fracciones f1: %d/%d y f2: %d/%d es %d \n", numerador(f1), denominador(f1), numerador(f2), denominador(f2), numerador(fAux));

    f1 = simplificar(f1);
    printf("f1: %d/%d y f2: %d/%d \n", numerador(f1), denominador(f1), numerador(f2), denominador(f2));
}