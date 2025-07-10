#include <stdio.h>
/* 19. Desarrollar un subprograma que determine si un vértice (vj) es alcanzable desde otro (vj) para
un digrafo almacenado en:
    a) una matriz de adyacencia
    b) una lista de adyacencia */


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

void alcanzaLista(TV vecVerAdy[MAX], int i, int j, int *ok);
void alcanza(int matAdy[MAX][MAX], int vcc[MAX], int i, int j, int n, int *ok);

void main(){
    TV vecVerAdy[MAX];
    int matAdy[MAX][MAX];
    int vv1[MAX] = {0},vv2[MAX] = {0};
    
    //iniciaLista(vecVerAdy);
    //iniciaMatAdy(matAdy);
    
    
}


void alcanza(int matAdy[MAX][MAX], int vcc[MAX], int i, int j, int n, int *ok){
    int k;
    if (matAdy[i][j])
        *ok = 1;
    else {
        k = 0;
        while (k<=n && *ok == 0){
            if (matAdy[i][j] != 0 && vcc[i] != 1)
                alcanza(matAdy,vcc, k, j, n, ok);
            k++;
        }
    }
}

void alcanzaLista(TV vecVerAdy[MAX], int i, int j, int *ok){
    int k;
    TLista aux;
    if (vecVerAdy[i].vertice = j)
        *ok = 1;
    else {
        aux = vecVerAdy[i].verticesAdy;
        while (aux != NULL && *ok == 0){
            alcanzaLista(vecVerAdy, aux->dato, j, ok);

            aux = aux->sig;
        }
    }
}