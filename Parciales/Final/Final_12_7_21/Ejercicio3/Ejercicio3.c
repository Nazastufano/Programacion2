#include "TDAArbol.h"
#include <stdio.h>

/* Ej 3.- (Utilizar TDA N-Ario) Se tiene un árbol binario AB proveniente de la transformación de
un bosque y un árol N-ario AN; ambos de enteros. Hallar e informar si se verifica que la suma de las
claves de cada uno de los árboles del bosque se encuentra en alguna hoja de AN. */

typedef struct nodoA{
    int dato;
    struct nodoA *izq, *der;
} nodoA;

typedef nodoA * ARBOLB;


int verifica(ARBOLB AB, ARBOLN AN);
int contarClaves(ARBOLB AB);
int recorrerNArio(ARBOLN AN, pos P, int clave);

void main(){
    ARBOLB AB;
    ARBOLN AN;
    AB = NULL;
    AN = NULL;
    
    if (verifica(AB, AN))
        printf("Se verifica que ");
    else
        printf("No se verifica que ");

    printf("la suma de las claves de cada uno de los arboles del bosque se encuentra en alguna hoja de AN \n");
}

int verifica(ARBOLB AB, ARBOLN AN){
    int cumple = 1, cantClaves;
    while (AB != NULL){
        cantClaves = contarClaves(AB->izq) + 1;
        cumple = recorrerNArio(AN, raiz(AN), cantClaves);
        AB = AB->der;
    }
    return cumple;
}

int contarClaves(ARBOLB AB){
    if (AB != NULL)
        return 1 + contarClaves(AB->izq) + contarClaves(AB->der);
    else
        return 0;
}

int recorrerNArio(ARBOLN AN, pos P, int clave){
    pos C;
    int cumple = 0;
    if (!nulo(P)){
        C = hijoMasIzq(P,AN);
        if (!nulo(hijoMasIzq(C,AN))){
            while (!nulo(C) && cumple){
                cumple = recorrerNArio(AN,C,clave);
                C = hermanoDer(C,AN);
            }
            return cumple;
        } else
            return info(C,AN) == clave;
    } else
        return 0;
}