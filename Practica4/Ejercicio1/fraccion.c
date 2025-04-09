#include <stdio.h>
#include "fraccion.h"

fraccion crear(int numerador, int denominador){
    fraccion f;
    f.numerador = numerador;
    f.denominador = denominador;
    return f;
}

int numerador(fraccion f){
    return f.numerador;
}

int denominador(fraccion f){
    return f.denominador;
}

fraccion sumar(fraccion f1, fraccion f2){
    fraccion fAux;

    fAux.numerador = f1.numerador*f2.denominador + f2.numerador*f1.denominador;
    fAux.denominador = f1.denominador*f2.denominador;

    return simplificar(fAux);
}

fraccion restar(fraccion f1, fraccion f2){
    fraccion fAux;

    fAux.numerador = f1.numerador*f2.denominador - f2.numerador*f1.denominador;
    fAux.denominador = f1.denominador*f2.denominador;
    
    return simplificar(fAux);
}

fraccion multiplicar(fraccion f1, fraccion f2){
    fraccion fAux;

    fAux.numerador = f1.numerador*f2.numerador;
    fAux.denominador = f1.denominador*f2.denominador;

    return simplificar(fAux);
}

fraccion dividir(fraccion f1, fraccion f2){
    fraccion fAux;

    fAux.numerador = f1.numerador*f2.denominador;
    fAux.denominador = f2.numerador*f1.denominador;
    
    return simplificar(fAux);
}

fraccion simplificar(fraccion f){
    int i, maxNum, mcd = 1;
    
    if (f.numerador>f.denominador)
        maxNum=f.denominador;
    else
        maxNum=f.numerador;
    
    for (i = 1; i <= maxNum; i++)
        if (f.numerador % i == 0 && f.denominador % i == 0)
            mcd = i;
    
    
    f.numerador /= mcd;
    f.denominador /= mcd;

    return f;
}

int iguales(fraccion f1, fraccion f2){
    f1 = simplificar(f1);
    f2 = simplificar(f2);
    if (f1.numerador == f2.numerador && f1.denominador == f2.denominador)
        return 1;
    else
        return 0;
}