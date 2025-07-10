#include <stdio.h>
#include "TDACola.h"
#include "TDAPila.h"

/* 11. Para un grafo almacenado en una matriz de adyacencia, desarrollar funciones para:
a) mostrar todos sus vértices mediante recorrido en profundidad
b) mostrar todos sus vértices mediante recorrido en amplitud
c) devolver la cantidad de componentes conexas */

#define MAX 10

void mostrarVerticesProf(int matAdy[MAX][MAX]);
void mostrarVerticesAmpl(int matAdy[MAX][MAX]);
int cantCompConex(int matAdy[MAX][MAX]);
int recorridoCompleto(int vec[MAX]);
TElementoP buscoAdyNoVisitado(int vec[MAX]);

void main(){
    int matAdy[MAX][MAX];

    //cargarMat(matAdy);

    mostrarVerticesAmpl(matAdy);
    mostrarVerticesProf(matAdy);
    printf("La cantidad de componentes conexas es: %d\n", cantCompConex(matAdy));
}

void mostrarVerticesProf(int matAdy[MAX][MAX]){
    int vec[MAX] = {0}, j;
    TPila P;
    TElementoP V = 0;

    iniciaP(&P);
    vec[V] = 1;
    printf("Vertice: %d\n", V);
    while (!recorridoCompleto(vec)){
        j=0;
        while (j<MAX && matAdy[V][j] != 1 || vec[j] == 1)
            j++;
        
        if (j == MAX)
            sacaP(&P,&V);
        else {
            poneP(&P, V);
            V = j;
            vec[V] = 1;
            printf("Vertice: %d\n", V);
        }
    }
}

void mostrarVerticesAmpl(int matAdy[MAX][MAX]){
    TCola C;
    TElementoC V = 0;
    int vec[MAX] = {0}, j;
    
    iniciaC(&C);
    poneC(&C,V);
    vec[V] = 1;
    printf("Vertice: %d\n", V);
    while (!recorridoCompleto(vec)){
        sacaC(&C,&V);
        for (j = 0; j < MAX; j++){
            if (matAdy[V][j] == 1 && vec[j] != 1){
                vec[j] = 1;
                poneC(&C,j);
                printf("Vertice: %d\n", j);
            }
        }
    }
}

int cantCompConex(int matAdy[MAX][MAX]){
    int cco = 0, j;
    int vec[MAX] = {0};
    TCola C;
    TElementoC V = 0;

    while (!recorridoCompleto(vec)){
        V = buscoAdyNoVisitado(vec);
        poneC(&C,V);
        cco++;
        vec[V] = cco;
        while (!recorridoCompleto(vec) && !vaciaC(C)){
            sacaC(&C,&V);
            for (j = 0; j < MAX; j++){
                if (matAdy[V][j] == 1 && vec[j] == 0){
                    vec[j] = cco;
                    poneC(&C,j);
                }
            }
        }
    }

    return cco;
}

int recorridoCompleto(int vec[MAX]){
    int j = 0;
    while (j < MAX && vec[j] == 1)
        j++;
        
    return j == MAX;
}

TElementoP buscoAdyNoVisitado(int vec[MAX]){
    int j = 0;
    while (j < MAX -1 && vec[j] != 0)
        j++;
    
    return j;
}