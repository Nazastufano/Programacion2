#include <stdio.h>
#include <stdlib.h>

/* Ej 3.- Se tiene una lista de adyacencia que representa un digrafo de N vertices con aristas ponderadas, 
y un ABB con datos reales. Se pide obtener la cantidad de vertices del digrafo que cumplen que: no 
tienen bucle y el minimo costo de las aristas de salida no esta en el ABB. */

#define MAX 10
#define INF 99999;
typedef struct nodo{
    int verticeAdy;
    int pesoA;
    struct nodo * sig;
}nodo;

typedef nodo * TLista;

typedef struct {
    int vertice;
    TLista verticesAdy;
}TVTLista;

typedef struct nodoA{
    float dato;
    struct nodoA *izq, *der;
}nodoA;

typedef nodoA * ARBOL;


void main(){
    TVTLista listaAdy[MAX];
    ARBOL ABB;
    int N;
    ABB = NULL;
    cargaListaAdy(listaAdy, &N);
    cargaABB(&ABB);

    printf("La cantidad de vertices del digrafo que no tiene bucle y el costo minimo de las aristas de salida no esta en el arbol ABB es: %d \n", analizarLista(listaAdy,ABB,N));
}

int analizarLista(TVTLista listaAdy[MAX], ARBOL ABB, int N){
    TLista aux;
    int i, tieneBucle, valorMinimo, cantVertices = 0;
    for (i = 0; i < N; i++){
        valorMinimo = INF;
        tieneBucle = 0;
        aux = listaAdy[i].verticesAdy;
        while (aux != NULL){
            if (listaAdy[i].vertice == aux->verticeAdy)
                tieneBucle = 1;
            
            if (valorMinimo > aux->pesoA)
                valorMinimo = aux->pesoA;

            aux = aux->sig;
        }

        cantVertices += !tieneBucle && !busquedaABB(ABB, valorMinimo);
    }
    return cantVertices;
}

int busquedaABB(ARBOL ABB, int valorMin){
    if (ABB != NULL){
        if (valorMin < ABB->dato)
            return busquedaABB(ABB->izq, valorMin);
        else if (valorMin > ABB->dato)
            return busquedaABB(ABB->der, valorMin);
        else 
            return 1;
    } else
        return 0;
}