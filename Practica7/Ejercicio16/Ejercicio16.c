#include <stdio.h>
#include <stdlib.h>

/* 16. Implementar una función iterativa que inserte un elemento en un ABB. */

typedef int TDato;

typedef struct nodo{
    TDato dato;
    struct nodo *izq, *der;
}nodo;

typedef nodo * ARBOL;

void insertaIterativa(ARBOL *A, TDato X);

void main(){
    ARBOL A;
    TDato X;
    A = NULL;
    //cargaA(&A);
    printf("Ingrese un dato para insertar en el arbol ABB: \n");
    scanf("%d", &X);
    insertaIterativa(&A, X);
}

void insertaIterativa(ARBOL *A, TDato X){
    ARBOL aux = *A, nuevo, padre = NULL;
    
    nuevo = (ARBOL) malloc (sizeof (struct nodo));
    nuevo->dato = X;
    nuevo->der = NULL;
    nuevo->izq = NULL;
    
    if (*A == NULL)
        *A = nuevo;   
    else {
        while (aux != NULL){
            padre = aux;
            if (X > aux->dato)
                aux = aux->der;
            else
                aux = aux->izq;
        }

        if (padre->dato < nuevo->dato)
            padre->izq = nuevo;
        else
            padre->der = nuevo;
    }
}