#include <stdio.h>
/* Ej 2- (Utilizar TDA N-ario) Dado un árbol N-Ario de caracteres, obtener el máximo y el
mínimo grado de los nodos ubicados en el nivel K (dato) */
#define INF = 9999

void mian(){
    ARBOL A; 
    int grMax = -1, grMin = INF, K;
    
    A = NULL;
    cargaA(&A);

    printf("Ingrese un nivel para obtener el grado minimo y maximo: \n");
    scanf("%d", &K);
    minMaxNArio(A, raiz(A), &grMax, &grMin, 1, K);

    if (grMax != -1 && grMin != INF)
        printf("El grado maximo del nivel K=%d es: %d y el grado minimo es: %d\n", K, grMax, grMin);
}

void minMaxNArio(ARBOL A, pos P, int *grMax, int *grMin,int nivel, int K){
    pos C;
    int grado;
    if (!nulo(P)){
        C = hijoMasIzq(P,A);
        nivel++;
        while (!nulo(C)){
            if (nivel == K){
                grado = calcGr(A,C);
                if (grado < *grMin)
                    *grMin = grado;
                
                if (grado > *grMax)
                    *grMax = grado;
            }
            
            minMaxNArio(A,C,grMax,grMin,nivel, K);

            C = hermanoDer(C,A);
        }
    }
}

int calcGr(ARBOL A, pos P){
    pos C;
    int grado = 0;
    if (!nulo(P)){
        C = hijoMasIzq(A,P);
        while (!nulo(C)){
            grado++;
            C = hermanoDer(C,A);
        }
    }
    return grado;
}