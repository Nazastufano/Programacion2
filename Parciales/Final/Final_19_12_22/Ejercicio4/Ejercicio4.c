#include <stdio.h>
#include "TDACola.h"

/* Ej 4.- Se tienen: un grafo G con N vértices y aristas ponderadas almacenado en la mitad inferior de una matriz
de adyacencia M y una Cola C en la que en cada elemento se tiene id1 e ide2 (1 a N) y cos, siendo id1 e id2
vértices de G y cos un valor mayor a 0. Se pide,
a) dejar en C solo los elementos que verifiquen que id1 e id2 están unidos por una arista con costo a lo sumo
cos.
b) asumiendo que C está implementanda de modo circular, escribir el tipo y los operadores utilizados en la
solución */

#define MAX 10

void actualizaC(int matAdy[MAX][MAX], TCola *C, int N);

void main(){
    int matAdy[MAX][MAX];
    int N;
    TCola C;
    iniciaC(&C);
    cargaMat(matAdy, &N);
    actualizaC(matAdy, &C, N-1);
}

void actualizaC(int matAdy[MAX][MAX], TCola *C, int N){
    TElementoC elem, centinela;
    int v1, v2;
    centinela.id1 = 999;
    poneC(C, centinela);
    sacaC(C, &elem);
    while (elem.id1 != centinela.id1){
        if (elem.id1-1 > elem.id2-1){
            v1 = elem.id1-1;
            v2 = elem.id2-1;
        } else {
            v2 = elem.id1-1;
            v1 = elem.id2-1;
        }
        if (matAdy[v1][v2] >= elem.cos)
            poneC(C, elem);
        
        sacaC(C, &elem);
    }   
}