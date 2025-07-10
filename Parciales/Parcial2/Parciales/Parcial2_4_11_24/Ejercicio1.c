#include <stdio.h>
#include <ctype.h>
/* Ej 1- Dado un árbol binario que proviene de la tranformación de un bosque de árboles de
cadenas, verificar que todos los árboles tienen algún nodo cuya clave comience con 
consonante y haya teniendo grado par (>0) en el árbol original. */

#define MAXCAD 20

typedef struct nodo{
    char dato[MAXCAD];
    struct nodo *izq, *der;
}nodo;

typedef nodo * ARBOL;

void main(){
    ARBOL A;
    A = NULL;
    cargaA(&A);

    if (verificarBosque(A))
        printf("Todos los arboles ");
    else
        printf("No todos los arboles ");
    
    printf("tienen algún nodo cuya clave comience con consonante y tuvo grado (>0) en el árbol original \n");
}

int verificarBosque(ARBOL A){
    int condicion;
    ARBOL aux = A;
    while (aux != NULL && condicion){
        condicion = recorrerArbol(aux->izq, 1);
        aux = aux->der;
    }
    return condicion;
}

int contGrado(ARBOL A){
    int grado = 0;
    while (A!=NULL){
        grado++;
        A = A->der;
    }
    return grado;
}

int recorrerArbol(ARBOL A, int izq){
    int grado, res= 0;
    if (A != NULL){
        if (izq == 1){
            grado = contGrado(A);
            if (esConsonante(A->dato[0]) && grado % 2 == 0 && grado > 0)
                return 1;
        }
        return recorrerArbol(A->izq, 1) || recorrerArbol(A->der, 0);
    } else
        return 0;
}

int esConsonante(char c){
    c = toupper(c);
    
    return !(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}