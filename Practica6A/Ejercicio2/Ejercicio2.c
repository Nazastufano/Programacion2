#include <stdio.h>
#include <stdlib.h>

/* 2. A partir de una lista simplemente enlazada ordenada de enteros, generar dos listas 
simplemente enlazadas de salida: una conteniendo los valores impares ordenados 
descendentemente, y la segunda con los valores pares ordenados de manera ascendente. No 
se deberá crear nuevos nodos, sino utilizar los de la lista original generando nuevos enlaces.*/
typedef struct nodo{
    int dato;
    struct nodo * sig;
} nodo;

typedef nodo * TLista;

void crearListas(TLista *L, TLista *LP, TLista *LI);

void main(){
    TLista L, LP, LI;
    crearListas(&L, &LP, &LI);
}

void crearListas(TLista *L, TLista *LP, TLista *LI){
    TLista aux = *L, nodo, auxLP;
    
    *LP = NULL;
    *LI = NULL;

    while (aux != NULL){
        nodo = aux;
        aux = aux->sig;
        nodo->sig = NULL;

        if (nodo->dato % 2 == 0){
            if (*LP == NULL)
                *LP = nodo;
            else 
                auxLP->sig = nodo;
            
            auxLP = nodo;
        } else {
            nodo->sig = *LI;
            *LI = nodo;
        }
    }
}