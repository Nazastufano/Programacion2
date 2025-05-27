#include <stdio.h>
/* 19. Dado un árbol binario que proviene de la transformación de un bosque, determinar qué
cantidad de árboles lo componían. */


//La cantidad de arboles que lo componían es la longitud de la cadena de nodos a derecha desde la raíz


typedef struct nodo{
    int dato;
    struct nodo *izq, *der;
}nodo;

typedef nodo * ARBOL;

int cantArbDelBosq(ARBOL A);

void main(){
    ARBOL A;
    A = NULL;
    //cargaA(&A);
    printf("La cantidad de arboles que componian el bosque del arbol binario generado es: %d\n", cantArbDelBosq(A));
}

int cantArbDelBosq(ARBOL A){
    int cont = 0;
    while (A != NULL){
        cont++;
        A = A->der;
    }
    return cont;
}