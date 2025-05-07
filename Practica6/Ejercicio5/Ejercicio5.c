#include <stdio.h>
#include <stdlib.h>
#include "TDAColaCir.h"
#include "TDAPilaDin.h"
/* 5. Una lista contiene en cada nodo una cola de números enteros. Desarrollar un programa que
genere una pila con los elementos máximos de cada cola de la lista. (Utilizar TDA pila dinámica
y TDA cola circular). */

typedef struct nodo{
    TCola dato;
    struct nodo * sig;
}nodo;

typedef nodo * TLista;

void generaPila(TLista L, TPila *P);


void main(){
    TLista L;
    TPila P;
    
    iniciaP(&P);
    //cargaL(&L);
    generaPila(L, &P);
}

void generaPila(TLista L, TPila *P){
    TLista aux;
    TCola C;
    TElementoC max, elemC;
    aux = L;
    while (aux != NULL){
        C = aux->dato;
        
        if (!vaciaC(C)){
            sacaC(&C,&max);
            
            while (!vaciaC(C)){
                sacaC(&C, &elemC);
            
                if (max<elemC)
                    max = elemC;
            }
            
            poneP(P,max);
        }
        
        aux = aux->sig;
    }   
}