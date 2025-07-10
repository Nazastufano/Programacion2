#include <stdlib.h>
#include <stdio.h>
#include "TDAPila.h"

/* Ej 1.- Suponer una lsita circular en la que cada elemento contiene números enteros. Se pide, eliminar de la
lista aquellos nodos que permitan que la lista quede ordenada de forma ascendente (considerando el orden
desde el primer nodo que no debe eliminarse). Con los valores eliminados generar una pila que contenga en
cada elemento Numero y Pos (siendo Numero el eliminado y Pos la posición en la que estaba en la lista antes
de comenzar las eliminaciones, considerando que 1 era la posición del primer nodo). 

Ej 2.-
a) Escribir el .h del TDA de la pila usada en el Ej1, suponiendo que la misma es estática.
b) Desarrollar PoneP y ConsultaP del .c del TDA */

typedef struct nodoC{
    int num;
    struct nodoC *sig;
}nodoC;

typedef nodoC * TListaC;

void main(){
    TListaC LC;
    TPila P;
    LC = NULL;
    //cargaLC(&LC);

    analizaLista(&LC, &P);
}

void analizaLista(TListaC *LC, TPila *P){
    TListaC act, ant = NULL, elim;
    TElementoP dato;
    int pos = 0;
    if (*LC != NULL){
        act = (*LC)->sig;
        iniciaP(P);
        do {
            pos++;
            if (ant != NULL && ant->num > act->num){                
                dato.num = act->num;
                dato.pos = pos;
                poneP(P,dato);
                    
                elim = act;
                if (*LC == elim)
                    *LC = ant;
                act = act->sig;
                ant->sig = act;
                
                free(elim);    
            } else {
                ant = act;
                act = act->sig;
            }
        } while (act != (*LC)->sig);
    }
}