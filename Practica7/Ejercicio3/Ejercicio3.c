#include <stdio.h>

/* 3. Desarrollar funciones para:
a) devolver la suma de los elementos múltiplos de 3 de un árbol binario.
b) retornar la cantidad de hojas de un árbol binario.
c) informar si un valor recibido como parámetro se encuentra en un árbol binario. */

typedef int TElementoA;

typedef struct nodo{
    TElementoA dato;
    struct nodo *izq, *der;
}nodo;

typedef nodo * ARBOL;

int sumaMultdeTres(ARBOL A);
int cantHojas(ARBOL A);
int estaX(ARBOL A, TElementoA X);

void main(){
    ARBOL A;
    TElementoA X;
    A = NULL;

    //cargaArb(&A);

    printf("La suma de los elementos multiplos de 3 del arbol es: %d \n", sumaMultdeTres(A));
    
    printf("La cantidad de hojas del arbol es: %d\n", cantHojas(A));

    printf("Ingrese un valor a buscar en el arbol binario: \n");
    scanf("%d", &X);

    if (estaX(A,X))
        printf("El elemento %d, se encuentra en el arbol. \n", X);
    else
        printf("El elemento %d, no se encuentra en el arbol. \n", X);
}

int sumaMultdeTres(ARBOL A){
    if (A != NULL)
        if (A->dato % 3 == 0)
            return A->dato + sumaMultdeTres(A->izq) + sumaMultdeTres(A->der);
        else
            return sumaMultdeTres(A->izq) + sumaMultdeTres(A->der);
    else
        return 0;
}

int cantHojas(ARBOL A){
    if (A != NULL)
        if (A->der == NULL && A->izq == NULL)
            return 1 + cantHojas(A->izq) + cantHojas(A->der);
        else
            return cantHojas(A->izq) + cantHojas(A->der);
    else
        return 0;   
}

int estaX(ARBOL A, TElementoA X){
    if (A!=NULL)
        if (X == A->dato)
            return 1;
        else
            return estaX(A->izq, X) || estaX(A->der, X);
    else
        return 0;
        
    
}