#include <stdio.h>

/* 20. ¿Cómo modificaría el algoritmo anterior si además quisiera saber por cuántos vértices debe
pasar para llegar de vi a vj? */

#define MAX 10


typedef struct nodo{
    int dato;
    struct nodo *sig;
}nodo;

typedef nodo * TLista;

typedef struct {
    int vertice;
    TLista verticesAdy;
}TV;

void main(){

}

void alcanza(int matAdy[MAX][MAX], int vcc[MAX], int i, int j, int n, int *ok){
    int k;
    if (matAdy[i][j])
        *ok = 1;
    else {
        k = 0;
        while (k<=n && *ok == 0){
            if (matAdy[i][j] != 0 && vcc[i] != 1){
                vcc[i] = 1;
                alcanza(matAdy,vcc, k, j, n, ok);
            }
            k++;
        }
    }
}

void alcanzaLista(TV vecVerAdy[MAX], int i, int j, int vcc[MAX], int *ok){
    int k;
    TLista aux;
    if (vecVerAdy[i].vertice = j)
        *ok = 1;
    else {
        aux = vecVerAdy[i].verticesAdy;
        while (aux != NULL && *ok == 0){
            if (vcc[aux->dato] != 1){
                vcc[aux->dato] = 1;
                alcanzaLista(vecVerAdy, aux->dato, j, vcc, ok);
            }

            aux = aux->sig;
        }
    }
}

int contarVertices(int vv[MAX]){
    int i, cont = 0;
    for (i = 0; i < MAX; i++)
        cont += vv[i];
    
    return cont;
}