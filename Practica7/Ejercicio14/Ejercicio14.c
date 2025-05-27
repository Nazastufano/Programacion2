#include <stdio.h>
#include <stdlib.h>

/* 14. Desarrollar una función que compruebe que si un árbol binario es un ABB. */

typedef struct nodo{
    int dato;
    struct nodo *izq, *der;
}nodo;

typedef nodo * ARBOL;

void addnodo(ARBOL* ABB, int e);
int esABB(ARBOL ABB, int min, int max);

void main(){
    ARBOL ABB;
    ABB = NULL;
    //cargarABB(&ABB);

    /* carga ARBOL ejemplo. Ej 1 */
    addnodo(&ABB, 10);
    addnodo(&ABB->izq, 6);
    addnodo(&ABB->izq->izq, 3);
    addnodo(&ABB->izq->der, 7);

    addnodo(&ABB->der, 13);
    addnodo(&ABB->der->izq, 11);
    addnodo(&ABB->der->der, 14); 

    if (esABB(ABB, -9999, 9999))
        printf("El arbol es de busqueda binaria\n");
    else
        printf("No es arbol de busqueda binaria\n");   
}

void addnodo(ARBOL* ABB, int e) {
    *ABB = (ARBOL)malloc(sizeof(nodo));
    (*ABB)->dato = e;
    (*ABB)->izq = NULL;
    (*ABB)->der = NULL;
}

int esABB(ARBOL ABB, int min, int max){
    if (ABB != NULL)
        if (ABB->dato > min && ABB->dato < max)
            return esABB(ABB->izq, min, ABB->dato) && esABB(ABB->der, ABB->dato, max);
        else
            return 0;
    else 
        return 1;   
}