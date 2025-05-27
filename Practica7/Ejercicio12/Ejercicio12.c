#include <stdio.h>
/* 12. Determinar cuántos elementos de un ABB son mayores que A y menores que B. A y B son
parámetros de entrada. */

typedef struct nodo{
    int dato;
    struct nodo *izq, *der;
}nodo;

typedef nodo * ARBOL;

int valoresEntreAB(ARBOL ABB, int A, int B);

void main(){

}

int valoresEntreAB(ARBOL ABB, int A, int B){
    if (ABB != NULL){
        if (A < ABB->dato && ABB->dato < B)
            return 1 + valoresEntreAB(ABB->izq, A, B) + valoresEntreAB(ABB->der, A, B);
        else if (A >= ABB->dato)
            return  valoresEntreAB(ABB->der, A, B);
        else 
            return valoresEntreAB(ABB->izq, A, B);
    } else
        return 0;
}