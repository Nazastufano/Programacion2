#include <stdio.h>

/* Ej 3- Dados dos disgrafos G y G' con V=V' y aristas ponderadas, con |V|=N. G almacenado en
una matriz de adyacencia M y G' almacenado en una lista de adyacencia L. Se pide verificar
si los vértices de G que no tienen bucles y tienen grado de entrada par verifican tener en G'
grado de salida impar y búcle. El recorrido sobre M debe ser recursivo.
Si la solución es iterativa sobre M, el puntaje obtenido será no mayor a 1,5p */

#define MAX 10

typedef struct nodo{
    int vertice;
    struct nodo * sig;
}nodo;

typedef nodo * TLista;

typedef struct {
    int vertice;
    TLista verticesAdy;
} TV;

void main(){
    int M[MAX][MAX], N;
    TV L[MAX];
    cargaMatAdy(M, &N);
    cargaLista(L, N);
}

int cantNodosVerifican(int M[MAX][MAX], TV L[MAX], int i, int j, int N, int cantVertices){
    if (j<=N){
        if (M[i][j] != 0)
            cantVertices++;
        
        if (i<N && M[j][j] == 0)
            return cantNodosVerifican(M, L, i+1, j, N, cantVertices);
        else
            if (cantVertices % 2 == 0 && M[j][j] == 0 && revisarLista(L[j].verticesAdy, j))
                return 1 + cantNodosVerifican(M,L, 0, j+1, N, 0);
            else
                return cantNodosVerifican(M, L, 0, j+1, N, 0);
    } else
        return 0;
}


int revisarLista(TV vecLista[MAX], int pos){
    TLista aux = vecLista[pos].verticesAdy;
    int bucle = 0, grado= 0;

    while (aux != NULL){
        if (aux->vertice == vecLista[pos].vertice)
            bucle = 1;
        
        grado++;
        aux  = aux->sig;
    }
    return bucle && grado % 2;
}