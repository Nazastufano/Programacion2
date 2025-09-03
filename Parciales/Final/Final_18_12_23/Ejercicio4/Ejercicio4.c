#include <stdio.h>

/* Ej 4.- Dado un árbol binario que proviene de la transformación de un bosque de enteros, hallar la
cantidad de nodos del bosque que tenían grado par. Definir tipos. */

typedef struct nodo{
    int dato;
    struct nodo *izq, *der;
}nodo;

typedef nodo * ARBOL;

int contGrado(ARBOL A);
int contNodos(ARBOL A);
int contar(ARBOL A, int izq); 

void main(){
    ARBOL A;
    A = NULL;
    CargaA(&A);
    
    printf("La cantidad de nodos del bosque que tienen grado par es: %d\n", contNodos(A));
}

int contGrado(ARBOL A){
    int grado = 0;
    while (A != NULL){
        grado++;
        A = A->der;
    }
    return grado;
}

int contNodos(ARBOL A){
    int cont = 0;
    
    while (A != NULL){
        cont += contar(A->izq, 1);
        A = A->der;
    }
    return cont;
}

int contar(ARBOL A, int izq){
    if (A != NULL){
        if (izq && contGrado(A) % 2 == 0){
            return 1 + contar(A->izq, 1) + contar(A->der, 0);
        } else
            return contar(A->izq, 1) + contar(A->der, 0);
    } else
        return 0;
}