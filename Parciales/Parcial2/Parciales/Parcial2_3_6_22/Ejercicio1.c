#include <stdio.h>
/* Ej 1- Dado un árbol binario de enteros proveniente de la transformación de un árbol general, se
pide obtener la suma de las claves con grado impar ubicadas en niveles menores a K (dato). El
grado y el nivel se refieren a los del árbol original.
    Mostrar la invocación de la solución desarrollada
    No se permite en esta solución el uso de funciones VOID */

typedef struct nodo{
    int dato;
    struct nodo *izq, *der;
}nodo;

typedef nodo * ARBOL;

void main(){
    ARBOL A;
    int K;
    A = NULL;
    
    //cargaA(&A);
    printf("Ingrese un nivel K para el analisis\n");
    scanf("%d", &K);
    printf("La suma de las claves de grado impar ubicadas en niveles menores a K=%d es: %d \n", K, recorrer(A,1,K));
}

int calcGrado(ARBOL A){
    int grado = 0;
    while (A != NULL){
        grado++;
        A = A->der;
    }
    return grado;
}

int recorrer(ARBOL A, int nivel, int K){
    int valor = 0;
    if (A != NULL){
        if (nivel<K){
            if (calcGrado(A->izq) % 2 == 1)
                valor = A->dato;
            
            return valor + recorrer(A->izq,nivel+1, K) + recorrer(A->der, nivel, K);
        }
    }
    return 0;
}