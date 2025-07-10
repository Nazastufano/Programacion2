#include "TDAPila.h"
#include <stdio.h>

/* */
#define MAX 10
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


int verifica(int matAdy, TPila P, int N){
    TElementoP elem;
    int grado = 0, j;
    if (!vaciaP(P)){
        sacaP(&P, &elem);
        for (j = 0; j < N; j++)
            grado += matAdy[elem.V - 1][j] != 0;
        
        return grado == elem.G ? verifica(matAdy,P,N) : 0;
    } else
        return 1;
}