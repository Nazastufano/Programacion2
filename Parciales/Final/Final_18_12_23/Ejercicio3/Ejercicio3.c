#include "TDAArbol.h"
#include "TDAPila.h"
#include <stdio.h>
#include <string.h>

/* Ej 3.- (Utilizar TDA N-Ario) Dado un árbol N-Ario de caracteres y una Pila P de cadenas, de forma
recursiva sobre P: dejar en ella solo las cadenas que tengan longitud impar y su inicial y ultima letra
sean hijos de un mismo nodo en A.
Escribir el tipo de la pila suponiendo que es Dinámica, desarrollar SacaP() */


void recursividad(ARBOL A, TPila *P);
int buscarArbol(ARBOL A, pos P, char ini, char ult);

void main(){
    ARBOL A;
    TPila P;
    A = NULL;
    iniciaP(&P);
    CargaA(&A);

}

void recursividad(ARBOL A, TPila *P){
    TElementoP elem;
    int largo;
    if (!vaciaP(*P)){
        sacaP(P, &elem);
        recursividad(A, P);

        largo = strlen(elem);
        if (largo % 2 == 1 && buscarArbol(A, raiz(A), elem[0], elem[largo-1]))
            poneP(P, elem);
    }
}

int buscarArbol(ARBOL A, pos P, char ini, char ult){
    pos C, L;
    int cumple = 0, bDos = 0, bUno = 0;
    if (!nulo(P)){
        C = L = hijoMasIzq(P, A);
        while (!nulo(C) && !cumple){
            if (info(C,A) == ini)
                bUno = 1;
            if (info(C,A) == ult)
                bDos = 1;
            
            cumple = (bUno && bDos) || buscarArbol(A, C, ini, ult);
            C = hermanoDer(C,A);
        }
         
    } 
    return cumple;
}