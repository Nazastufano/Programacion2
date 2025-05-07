#include <stdio.h>
#include <stdlib.h>

/* 1. Dadas dos listas simplemente enlazadas de enteros L1 y L2: 
a) verificar si son iguales. Considerar que están ordenadas. 
b) añadir L2 al final de L1, en el caso de que el primer elemento de L2 sea mayor al último de 
L1. En otro caso, añadir L1 al final de L2. 
c) eliminar de L1 los nodos cuyas posiciones se encuentran en L2, la cual está ordenada. */

typedef struct nodo{
    int dato;
    struct nodo * sig;
} nodo;

typedef nodo * TLista;

int verificarIgualdad(TLista L1, TLista L2);
void fusionarListas(TLista *L1, TLista *L2);
void eliminarNodos(TLista *L1, TLista *L2);
void main(){
    TLista L1, L2;
    L1 = NULL;
    L2 = NULL;

    if (verificarIgualdad(L1,L2))
        printf("Las listas son iguales\n");
    else
        printf("Las listas son distintas\n");
    
}

int verificarIgualdad(TLista L1, TLista L2){
    TLista aux1 = L1, aux2 = L2;
    if (aux1 != NULL && aux2 != NULL){
        while (aux1 != NULL && aux2 != NULL && aux1->dato == aux2->dato){
            aux1 = aux1->sig;
            aux2 = aux2->sig;
        }
        
    }
    return aux1 == NULL && aux2 == NULL;
}

/* b) añadir L2 al final de L1, en el caso de que el primer elemento de L2 sea mayor al último de 
L1. En otro caso, añadir L1 al final de L2. */

void fusionarListas(TLista *L1, TLista *L2){
    TLista aux1 = *L1, ant = NULL, aux2 = *L2;
    
    if (aux1 != NULL && aux2 != NULL){
        while (aux1 != NULL){
            ant = aux1;
            aux1 = aux1->sig;
        }

        if (ant->dato < aux2->dato)
            ant->sig = aux2;
        else {
            aux1 = *L1;
            while (aux2 != NULL){
                ant = aux2;
                aux2 = aux2->sig;
            }
            
            ant->sig = aux1;
        }
    }
}

//c) eliminar de L1 los nodos cuyas posiciones se encuentran en L2, la cual está ordenada. 

void eliminarNodos(TLista *L1, TLista *L2){
    TLista elim, ant = NULL, aux1 = *L1, aux2 = L2;
    int pos = 0;
    while (aux1 != NULL && aux2 != NULL){
        pos++;
        if (pos == aux2->dato){
            elim = aux1;
            if (ant == NULL)
                *L1 = aux1->sig;
            else
                ant->sig = aux1->sig;
                
            aux1 = aux1->sig;
            free(elim);
            aux2 = aux2->sig;
        } else {
            ant = aux1;
            aux1 = aux1->sig;
        }
    }
}