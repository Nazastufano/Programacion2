#include <stdio.h>
#include <ctype.h>

/* Ej 4.- Dado un árbol binario que proviene de la transformación de un bosque de caracteres, hallar la
cantidad de árboles del bosque que contenían al me nos dos nodos que su clave era vocal y ninguno de
sus hijos lo era. */

typedef struct nodoA{
    char dato;
    struct nodoA *izq, *der;
}nodoA;

typedef nodoA * ARBOL;

int cantArboles(ARBOL A);
int verHijos(ARBOL A);
void cantNodos(ARBOL A, int izq, int padre, int *cant);
int esVocal(char c);

void main(){
    ARBOL A;
    A = NULL;
    printf("La cantidad de arboles del bosque que contenian al menos dos nodos que su clave era vocal y ninguno de sus hijos lo era es: %d\n", cantArboles(A));
}

int cantArboles(ARBOL A){
    int cant, cantA = 0;
    while (A != NULL){
        cant = 0; 
        cantNodos(A->izq, 1, A->dato, &cant);
        
        cantA += cant >= 2;
        
        A = A->der;
    }
    return cantA;
}

int verHijos(ARBOL A){
    while (A != NULL && !esVocal(A->dato))
        A = A->der;
   
    return A == NULL;
}

void cantNodos(ARBOL A, int izq, int padre, int *cant){
    if (A!=NULL && *cant < 2){
        if (izq && esVocal(padre))
            *cant += verHijos(A->izq);
        
        if (*cant < 2){
            cantNodos(A->izq, 1, A->dato, cant);
            cantNodos(A->der, 0, padre, cant);
        }
    }
}
int esVocal(char c){
    c = toupper(c);
    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}