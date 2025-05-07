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

typedef struct nodo{
    int dato;
    struct nodo * sig;
} nodo;

typedef nodo * TListaC;

void cargarLista(TListaC *L);
void mostrarLista(TListaC L);
int esVocal(char );
int cantNodosVocal(TListaC L);
int listaOrdenada(TListaC L);
void eliminarNodo(TListaC *L, int P);

void main(){
    TListaC L;
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

void cargarLista(TListaC *L){
    char dato;
    TListaC aux = NULL, nuevo, pri = NULL;
    *L= NULL;
    do{
        printf("Ingrese el dato a almacenar\n");
        scanf(" %c", &dato);
    
        if (dato != '.'){
            nuevo = (TListaC)malloc(sizeof(nodo));
            nuevo->dato = dato;
    
            if (aux == NULL){
                nuevo->sig = nuevo;
                pri = nuevo;
            } else {
                nuevo->sig = pri;
                aux->sig = nuevo;
            }
            
            aux = nuevo;
        }
    } while (dato != '.');
    
    if (aux != NULL)
        *L = aux;
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

void mostrarLista(TListaC L){
    TListaC aux = L;
    
    if (aux != NULL){
        do{
            aux = aux->sig;
            printf("Caracter de la lista %c\n", aux->dato);
        } while (aux != L);
    }
}

int cantNodosVocal(TListaC L){
    TListaC aux = L;
    int cantNV = 0;
    
    if (aux != NULL){
        do{
            if (esVocal(aux->dato))
                cantNV++;
            aux = aux->sig;
        }while (aux != L);
    }
    return cantNV;
}

int listaOrdenada(TListaC L){
    TListaC act;
    int ord = 0;
    if (act != NULL){
        act = L->sig;
        while (act != L && act->dato <= act->sig->dato)
            act = act->sig;
        
        if (act == L)
            ord = 1;
    }
    
    return ord;
}

void eliminarNodo(TListaC *L, int P){
    TListaC aux = *L, ant, elim;
    int i = 1;
    if (aux != NULL){
        aux = (*L)->sig;
        ant = *L;
        while (aux != *L && i < P){
            i++;
            ant = aux;
            aux = aux->sig;
        }

        if (i == P){
            elim = aux;
            if (aux == ant) // un solo nodo
                *L = NULL;
            else {
                ant->sig = aux->sig; //muevo
                if (aux == *L) //si es ultimo
                    *L = ant;
            }
            free(elim);
        }
    }
}