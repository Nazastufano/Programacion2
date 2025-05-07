#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/* 8. Rehacer el ejercicio 1* desarrollado para listas simplemente enlazadas, modificando su 
implementación como:  
    a) lista doblemente enlazada. 
    b) lista circular 
      
* 1. Dada una lista simplemente enlazada de caracteres, escribir una función void que:
a) muestre su contenido.
b) devuelva la cantidad de nodos que poseen vocales.
c) indique si la lista está ordenada.
d) elimine el elemento ubicado en una posición P (entero) pasada como parámetro. */

typedef struct nodoD{
    char dato;
    struct nodoD *ant, *sig;
}nodoD;

typedef nodoD * pNodoD;

typedef struct {
    pNodoD pri, ult;
}TLista;

void cargarLista(TLista *L);
void mostrarLista(TLista L);
int esVocal(char );
int cantNodosVocal(TLista L);
int listaOrdenada(TLista L);
void eliminarNodo(TLista *L, int P);

void main(){
    TLista L;
    int P;
    cargarLista(&L);
    mostrarLista(L);
    printf("La cantidad de nodos con vocales es: %d\n", cantNodosVocal(L));
    
    if (listaOrdenada(L))
        printf("La lista esta ordenada\n");
    else
        printf("La lista no esta ordenada\n");
    
    do{
        printf("Ingrese una posicion para eliminar dicho nodo\n");
        scanf("%d", &P);
    } while (P<0);

    eliminarNodo(&L, P);
    mostrarLista(L);
}

void cargarLista(TLista *L){
    char dato;
    pNodoD nuevo, nodoAnt = NULL;
    
    L->pri = NULL;
    L->ult = NULL;
    do{
        printf("Ingrese el dato a almacenar\n");
        scanf(" %c", &dato);
    
        if (dato != '.'){
            nuevo = (pNodoD)malloc(sizeof(nodoD));
            nuevo->ant = nodoAnt;
            nuevo->dato = dato;
            nuevo->sig= NULL;
            
            if (nodoAnt == NULL)
                L->pri = nuevo;
            else
                nodoAnt->sig = nuevo;
            
            nodoAnt = nuevo;
        }
    } while (dato != '.');
    (*L).ult = nuevo;
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

void mostrarLista(TLista L){
    pNodoD aux = L.pri;
    while (aux != NULL){
        printf("Caracter de la lista %c\n", aux->dato);
        aux = aux->sig;
    }    
}

int cantNodosVocal(TLista L){
    pNodoD aux = L.pri;
    int cantNV = 0;
    while (aux != NULL){
        if (esVocal(aux->dato))
            cantNV++;
        aux = aux->sig;
    }
    return cantNV;
}

int listaOrdenada(TLista L){
    pNodoD act = L.pri;
    int ord = 0;
    if (act != NULL){
        while (act->sig != NULL && act->dato <= act->sig->dato)
            act = act->sig;
        
        if (act->sig == NULL)
            ord = 1;
    }
    
    return ord;
}

void eliminarNodo(TLista *L, int P){
    pNodoD aux = (*L).pri, elim;
    int i = 1;

    while (aux != NULL && i < P){
        i++;
        aux = aux->sig;
    }
    if (aux != NULL){
        elim = aux;
        if (aux->ant == NULL){ //es primero
            (*L).pri = aux->sig;
            
            if (aux->sig == NULL) //unico nodo
                (*L).ult = NULL;
            else //no es unico nodo
                aux->sig->ant = NULL;

        } else if (aux->sig == NULL) { 
            (*L).ult = aux->ant;
            (*L).ult->sig = NULL;
        } else { //no es primero ni ultimo
            aux->ant->sig = aux->sig;
            aux->sig->ant = aux->ant;
        }
        free(elim);
    }
}