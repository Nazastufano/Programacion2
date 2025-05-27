#include <stdio.h>
#include <string.h>
/* 6. Dado un árbol binario de cadenas de caracteres retornar el nivel en el que se encuentra la
cadena más larga que comienza con A */

#define MAX 20

typedef char TElementoA;
typedef struct nodo{
    TElementoA dato[MAX];
    struct nodo *izq, *der;
}nodo;

typedef nodo * ARBOL;

int palabraMLconA(ARBOL A, int nivel, int palabraML, int nivelPML);

void main(){
    ARBOL A;
    int res;
    A = NULL;

    //CargaA(&A);

    res = palabraMLconA(A, 0, 0, 0);
    if (res)
        printf("El nivel de la cadena mas larga que comienza con A es: %d\n", res);
    else
        printf("No hay palabras que comiencen con A\n");
}

int palabraMLconA(ARBOL A, int nivel, int palabraML, int nivelPML){
    int largo;
    if (A != NULL){
        if (A->dato[0] == 'A'){
            largo = strlen(A->dato);
            
            if (largo > palabraML){
                palabraML = largo;
                nivelPML = nivel;
            }
        }
        
        nivelPML = palabraMLconA(A->izq, nivel + 1, palabraML, nivelPML);
        nivelPML = palabraMLconA(A->der, nivel + 1, palabraML, nivelPML);
    }
    return nivelPML;
}
