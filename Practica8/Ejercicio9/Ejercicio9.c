#include <stdio.h>
/* 9. Hallar el vértice con el mayor grado de entrada, en un digrafo representado por una lista de
adyacencia. */

typedef struct nodo{
    int vertice;
    struct nodo *sig;
}nodo;

typedef nodo * TLista;

typedef struct {
    int vertice;
    TLista LAdy;
}TV;

int obtenerVerMayGra(int vecGrado[10]);
int mayorGradoEntrada(int matAdyDG[10][10], TV vecVerAdy[10]);

void main(){
    int matAdyDG[10][10];
    TV vecVerAdy[10];

    //cargaMatAdy(matAdyDG);
    //cargaVecVer(vecVerAdy);

    printf("El vertice de mayor grado es: %d\n", mayorGradoEntrada(matAdyDG, vecVerAdy));
}

int mayorGradoEntrada(int matAdyDG[10][10], TV vecVerAdy[10]){
    int i;
    int vecGrado[10] = {0};
    TLista aux;

    for (i = 0; i < 10; i++){
        aux = vecVerAdy[i].LAdy;
        while (aux != NULL){
            if (vecVerAdy[i].vertice != aux->vertice)
                vecGrado[aux->vertice] += 1;
            
            aux = aux->sig;
        }
    }

    return obtenerVerMayGra(vecGrado);
}

int obtenerVerMayGra(int vecGrado[10]){
    int i, maxGrado = 0, verticeMG;
    for (i = 0; i < 10; i++)
        if (vecGrado[i]>maxGrado){
            maxGrado = vecGrado[i];
            verticeMG = i;
        }

    return verticeMG;
}