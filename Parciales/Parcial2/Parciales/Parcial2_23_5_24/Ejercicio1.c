#include <stdio.h>
/* Ej 1- Dado un árbol binario que proviene de la transformación de un bosque de árboles
generales, determinar si en el bosque todos los árboles verifican que su grado era igual al
grado de su raíz */

typedef struct nodo{
    int dato;
    struct nodo *izq, *der;
}nodo;

typedef nodo * ARBOL;

int verificarBosque(ARBOL A);
int calcGrado(ARBOL A);
int obtenerGradoint(ARBOL A, int gradoRaiz);

void main(){
    ARBOL A;
    A = NULL;
    //cargaA(&A);
    if (verificarBosque(A))
        printf("Todos los arboles del bosque verifican que su grado es igual al grado de su raiz\n");
    else
        printf("No todos los arboles del bosque verifican que su grado es igual al grado de su raiz\n");
}

int verificarBosque(ARBOL A){
    int condicion = 1, gradoRaiz, gradoMax;

    while (A != NULL && condicion){
        gradoRaiz = calcGrado(A->izq);
        
        if (gradoRaiz)
            condicion = obtenerGradoint(A->izq, gradoRaiz);

        A = A->der;
    }
    return condicion;
}

int calcGrado(ARBOL A){
    int gr = 0;
    while (A != NULL){
        gr++;
        A = A->der;
    }
    return gr;
}

int obtenerGradoint(ARBOL A, int gradoRaiz){
    int gr;
    if (A != NULL){
        if (calcGrado(A) > gradoRaiz)
            return 0;
        else
            return obtenerGradoint(A->izq, gradoRaiz) && obtenerGradoint(A->der, gradoRaiz);
    } else
        return 1;
}