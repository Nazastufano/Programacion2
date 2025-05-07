#include <stdio.h>
/* 6. Resolver mediante subprogramas las siguientes operaciones sobre una lista circular: 
a) insertar un elemento conociendo la posición (puntero) del anterior. Tomar el último como 
anterior del primero, y nulo para insertar en una lista vacía. 
b) insertar un elemento conociendo la posición (puntero) del siguiente. Tomar el primero 
como siguiente del último, nulo para insertar en una lista vacía. 
c) eliminar todas las ocurrencias del elemento X (recibido como parámetro) */

typedef struct nodoC{
    int dato;
    struct nodoC * sig;
}nodoC;

typedef nodoC * TListaC;

void main(){

}
/* a) insertar un elemento conociendo la posición (puntero) del anterior. Tomar el último como 
anterior del primero, y nulo para insertar en una lista vacía. */

void insertarElemAnt(TListaC *LC, TListaC punteroAnt, int dato){
    TListaC aux, nuevo, ant = NULL;
    
    nuevo = (TListaC)malloc(sizeof(nodoC));
    nuevo->dato = dato;
    
    if (punteroAnt == NULL){
        nuevo->sig = nuevo;
        *LC = nuevo;
    } else {
        aux = (*LC)->sig;

        while (aux != punteroAnt && aux != *LC)
            aux = aux->sig;
        
        if (aux == punteroAnt){
            nuevo->sig = aux->sig;
            aux->sig = nuevo;
            if (punteroAnt == *LC)
                *LC = nuevo;
        }
    }
    
}

/* b) insertar un elemento conociendo la posición (puntero) del siguiente. Tomar el primero 
como siguiente del último, nulo para insertar en una lista vacía. */

void insertarElemSig(TListaC *LC, TListaC punteroSig, int dato){
    TListaC aux, nuevo, ant;

    nuevo = (TListaC)malloc(sizeof(nodoC));
    nuevo->dato = dato;

    if (punteroSig == NULL){
        nuevo->sig = nuevo;
        *LC = nuevo;
    } else {
        aux = (*LC)->sig;
        ant = *LC;
        while (aux != *LC && aux != punteroSig){
            ant = aux;
            aux = aux->sig;
        }
        if (aux == punteroSig){            
            nuevo->sig = aux;
            ant->sig = nuevo;
            if (ant == *LC) 
                *LC = nuevo;
        }   
    }    
}


/* c) eliminar todas las ocurrencias del elemento X (recibido como parámetro) */

void eliminarOcurrencias(TListaC *LC, int X){
    TListaC aux, elim, ant = *LC;
    if (*LC != NULL){
        aux = (*LC)->sig;
        do{            
            if (aux->dato == X){
                elim = aux;

                ant->sig = aux->sig;
                aux = aux->sig;
                
                if (elim == *LC) 
                    if (elim == elim->sig) // es unico
                        *LC = NULL;
                    else 
                        *LC = ant;
                free(elim);
            } else {
                ant = aux;
                aux = aux->sig;
            }
        } while (aux != *LC);
    }
}