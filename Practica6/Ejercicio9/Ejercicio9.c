#include <stdio.h>
#include <stdlib.h>
/* 9. Copiar el contenido completo de una lista simplemente enlazada en una lista doblemente 
enlazada y en una lista circular, ambas inicialmente vacías. Ambas copias deben realizarse en la 
misma función. En ambos casos se debe mantener el orden de la lista original, siendo el último 
elemento de la lista simple el último de la circular. La lista original no debe ser modificada. */


//lista simple
typedef struct nodo{
    int dato;
    struct nodo * sig;
}nodo;

typedef nodo * TLista;

//lista doblemente enlazada
typedef struct nodoD{
    int dato;
    struct nodoD *ant, *sig;
} nodoD;

typedef nodoD * pNodoD;

typedef struct{
    pNodoD pri, ult;
} TListaD;

//lista circular
typedef struct nodoC{
    int dato;
    struct nodoC * sig;
}nodoC;

typedef nodoC * TListaC;

void copiarEnListas(TLista, TListaC *, TListaD *);

void main(){
    TLista L;
    TListaC LC;
    TListaD LD;
    L = NULL;
    LC = NULL;
    LD.pri = NULL;
    LD.ult = NULL;

    copiarEnListas(L, &LC, &LD);
}

void copiarEnListas(TLista L, TListaC *LC, TListaD *LD){
    TLista aux = L;
    TListaC nuevoC;
    pNodoD nuevoD;

    while (aux != NULL){
        nuevoC = (TListaC)malloc(sizeof(nodoC));
        nuevoC->dato = aux->dato;
        
        nuevoD = (pNodoD)malloc(sizeof(nodoD));
        nuevoD->dato = aux->dato;
        if (*LC == NULL){
            nuevoC->sig = nuevoC;
            
            nuevoD->ant = NULL;
            (*LD).pri = nuevoD;
        } else {            
            nuevoC->sig = (*LC)->sig;
            (*LC)->sig = nuevoC;

            nuevoD->ant = (*LD).ult;
            nuevoD->ant->sig = nuevoD;
        }
        *LC = nuevoC;
        
        nuevoD->sig = NULL;
        (*LD).ult = nuevoD;
        
        aux = aux->sig;
    }
}