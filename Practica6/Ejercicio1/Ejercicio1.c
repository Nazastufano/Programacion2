#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/* 1. Dada una lista simplemente enlazada de caracteres, escribir una función void que:
a) muestre su contenido.
b) devuelva la cantidad de nodos que poseen vocales.
c) indique si la lista está ordenada.
d) elimine el elemento ubicado en una posición P (entero) pasada como parámetro. */

typedef struct nodo{
    char elemento;
    struct nodo * sig;
} nodo;

typedef nodo * TLista;

void muestraContenido(TLista L);
int esVocal(char );
void cantNodosConVocal(TLista L, int *);
int listaOrdenda(TLista L);
void eliminarNodo(TLista *L, int P);

void main(){
    TLista L;
    int cantNV = 0, P;
    
    muestraContenido(L);
    cantNodosConVocal(L, &cantNV);
    
    printf("La cantidad de nodos con vocales es: %d\n", cantNV);
    
    if (listaOrdenda(L))
        printf("La lista esta ordenada\n");
    else
        printf("La lista no esta ordenada\n");
    printf("El nodo de que posicion desea eliminar? \n");
    scanf("%d", &P);
    eliminarNodo(&L, &P);
}

void muestraContenido(TLista L){
    while (L != NULL){
        printf("Caracter de la lista: %c \n", L->elemento);
        L = L->sig;
    }
}

int esVocal(char c){
    switch (tolower(c)){
    case 'a':
        return 1;
        break;
    case 'e':
        return 1;
        break;
    case 'i':
        return 1;
        break;
    case 'o':
        return 1;
        break;
    case 'u':
        return 1;
        break;
        
    default:
        return 0;
        break;
    }
}

void cantNodosConVocal(TLista L, int *cantNV){
    while (L != NULL){
        if (esVocal(L->elemento))
            (*cantNV)++;
        L = L->sig;
    }
}

int listaOrdenda(TLista L){
    char aux = L->elemento;
    while (L != NULL && aux <= L->elemento){
        aux = L->elemento;
        L = L->sig;
    }
    return (L == NULL);
}

void eliminarNodo(TLista *L, int P){
    TLista aux = *L, ant = NULL;
    int i=0;

    while (aux != NULL && i<P){
        i++;
        ant = aux;
        aux = aux->sig;
    }

    if (aux != NULL){
        if (ant == NULL)
            (*L) = aux->sig;
        else
            ant->sig = aux->sig;
        free(aux);
    }   
}