#include <stdio.h>
#include <stdlib.h>
/* 2. Generar una lista simplemente enlazada a partir del contenido de un arreglo de N enteros no
ordenados:
a) invirtiendo el orden de sus elementos (no se permite recorrer el arreglo comenzando por el
último elemento)
b) manteniendo el orden de sus elementos.
c) de forma ordenada */


#define SIZE 10
typedef struct nodo{
    int dato;
    struct nodo * sig;
} nodo;

typedef nodo * TLista;
void cargarArreglo(int [SIZE], int N);
void cargarListaOrdenInverso(TLista *L, int N, int []);
void cargarListaOrdenArreglo(TLista *L, int N, int []);
void cargarListaOrdenada(TLista *L, int N, int []);

void main(){
    int N;
    int A[SIZE];
    do{
        printf("Cuantos elementos desea almacenar en el arreglo? (MAX 10)\n");
        scanf("%d", &N);
    } while (N<0 || N>9);
    cargarArreglo(A,N);

}

void cargarArreglo(int A[SIZE], int N){
    int i;
    for (i = 0; i < N; i++){
        printf("Ingrese el elemento de la posicion %d\n", i+1);
        scanf("%d", &A[i]);
    }
}

void cargarListaOrdenInverso(TLista *L, int N, int A[SIZE]){
    TLista aux;
    int i;
    for (i = 0; i < N; i++){
        aux = (TLista)malloc(sizeof(nodo));
        aux->dato = A[i];
        aux->sig = *L;
        *L = aux;
    }
}

void cargarListaOrdenArreglo(TLista *L, int N, int A[SIZE]){
    TLista aux, ult = NULL;
    int i;
    for (i = 0; i < N; i++){
        aux = (TLista)malloc(sizeof(nodo));
        aux->dato = A[i];
        aux->sig = NULL;
        
        if (ult == NULL)
            *L = aux;
        else
            ult->sig = aux;
        ult = aux;
    }
}

void cargarListaOrdenada(TLista *L, int N, int A[SIZE]){
    TLista aux, act, ant;
    int i;
    for (i = 0; i < N; i++){
        aux = (TLista)malloc(sizeof(nodo));
        aux->dato = A[i];
        if (*L == NULL || A[i] <(*L)->dato){
            aux->sig = *L;
            *L = aux;
        } else {
            act = *L;
            while (act!=NULL && act->dato < A[i]){
                ant = act;
                act = act->sig;
            }
            aux->sig = act;
            ant->sig = aux;
        }
    }
}