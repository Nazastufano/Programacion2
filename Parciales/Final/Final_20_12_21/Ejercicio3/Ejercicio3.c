#include <stdio.h>
#include "TDAArbol.h"
#include <string.h>
#include <ctype.h>

/* Ej 3.- (Utilizar TDA N-Ario) Se tiene un árbol NArio de cadenas, mediante una función entera, determinar
cuantas cadenas de longitud impar que comiencen y terminen en vocal se encuentran en niveles impares. */

int esVocal(char c);
int cantCadenas(ARBOL A, pos P, int nivel);

void main(){
    ARBOLN A;
    A = NULL;
    cargaA(&A);

    printf("La cantidad de cadenas de longitud impar que comiencen y terminen en vocal se encuentran en niveles impares es: %d\n", cantCadenas(A,raiz(A),1));
}

int cantCadenas(ARBOL A, pos P, int nivel){
    pos C;
    int acum = 0, largo;
    if (!nulo(P)){
        C = hijoMasIzq(P,A);
        while (!nulo(C)){
            acum += cantCadenas(A, P, nivel+1);
            C = hermanoDer(C,A);
        }
        largo = strlen(info(P,A));
        return acum + (nivel % 2 == 1 && largo % 2 == 1 && esVocal(info(P,A)[0]) && esVocal(info(P,A)[largo-1]));
    } else
        return 0;
}

int esVocal(char c){
    c = toupper(c);
    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}