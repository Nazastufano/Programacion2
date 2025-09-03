#include "TDAPila.h"
#include <stdio.h>

/* Ej 4.- (Utilizar TDA Pila) Dada una matriz de adyacencia que representa un digrafo acíclico de N vértices
(numerados de 1 a N), con aristas ponderadas y una Pila P que contiene en cada elemento V (un vértice 1 a N,
ordenada) y un G, determinar recursivamente sobre al menos una de las estructuras si todos los V tienen grado
de salida G. Definir el tipo de la Pila estática y desarrollar las funciones utilizadas. NOTA: P puede perderse */

#define MAX 10
int verifica(int matAdy[MAX][MAX], TPila P, int N);

void main(){
    int matAdy[MAX][MAX];
    int N;
    TPila P;

    iniciaP(&P);

    if (verifica(matAdy, P, N))
        printf("Todos los V tienen grado de salida G \n");
    else
        printf("No todos los V tienen grado de salida G \n");
}


int verifica(int matAdy[MAX][MAX], TPila P, int N){
    TElementoP elem;
    int grado = 0, j;
    if (!vaciaP(P)){
        sacaP(&P, &elem);
        for (j = 0; j < N; j++)
            grado += matAdy[elem.V-1][j] != 0;
        
        return grado == elem.G ? verifica(matAdy,P,N) : 0;
    } else
        return 1;
}