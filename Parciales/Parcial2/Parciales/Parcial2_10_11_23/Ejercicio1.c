#include <stdio.h>
/* Ej 1- Dado un árbol binario de enteros proveniente de la transformación de un bosque,
calcular, mediante una o más funciones int la cantidad de árboles que tenían alguna clave
negativa entre los niveles K1 y K2 (datos, K1 <= K2, no necesariamente los árboles tenían K1
o K2 niveles) */

int verificar(ARBOL A, int K1, int K2){
    ARBOL aux = A;
    int condicion = 1;
    while (aux != NULL && condicion){
        condicion = recorrerArbol(A->izq, 2, K1, K2);
        
        aux = aux->der;
    }
    return condicion
}

int recorrerArbol(ARBOL A, int nivel, int K1, int K2){
    if (A != NULL){
        if (nivel >= K1)
            if (A->dato < 0)
                return 1;
        
        if (nivel<K2)
            return recorrerArbol(A->izq, nivel+1, K1,K2) || recorrerArbol(A->der, nivel, K1,K2);  
    }
    return 0;
}