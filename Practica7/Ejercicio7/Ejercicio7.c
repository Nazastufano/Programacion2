#include <stdio.h>

/* 7. Desarrollar una función que retorne la suma del contenido de aquellos nodos de un árbol
binario que tengan grado 1 y se encuentren en un nivel X que es dato. */

typedef int TElementoA;

typedef struct nodo{
    TElementoA dato;
    struct nodo *izq, *der;
}nodo;

typedef nodo * ARBOL;

void main(){
    ARBOL A;
    int X;
    A = NULL;
    //cargaA(&A);
    printf("Ingrese un nivel X para sumar los datos de los nodos con solo un hijo: \n");
    scanf("%d", &X);
    
    printf("La suma de elementos de los nodos con un solo hijo del nivel X=%d es: %d \n", X, sumaElementos(A,0,X));
}

int sumaElementos(ARBOL A, int nivel, int X){
    if (A != NULL){
        if (nivel < X)
            return sumaElementos(A->izq, nivel + 1, X) + sumaElementos(A->der, nivel + 1, X);
        else if (nivel == X)
            if (A->der != NULL && A->izq == NULL || A->der == NULL && A->izq != NULL)
                return A->dato;
            else
                return 0;
        else
            return 0;
    } else
        return 0;
}