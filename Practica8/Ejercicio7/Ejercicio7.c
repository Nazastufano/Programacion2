#include <stdio.h>

/* 7. Desarrollar una función que obtenga el grado de un vértice (dato) de un grafo almacenado en:
a) una matriz de adyacencia
b) una lista de adyacencia
c) media matriz (triángulo superior) */

typedef struct nodo{
    int verticeAdy;
    struct nodo *sig;
}nodo;

typedef nodo * TLista;

typedef struct {
    int vertice;
    TLista LVA;
}TV;

int obtenerGradoMatriz(int matAdy[10][10], int vertice);
int obtenerGradoLista(TV vecAdy[10], int vertice);
int obtenerGradoMedMat(int matAdy[10][10], int vertice);

void main(){
    int matAdy[10][10];
    TV vecAdy[10];
    int vertice;
    //cargaVec(vecAdy);
    //cargaMat(matAdy);
    do{
        printf("Ingrese un vertice para obtener el grado: \n");
        scanf("%d",&vertice);
    } while (vertice<0 || vertice>10);
    
    printf("El grado del vertice obtenido por la matriz de adyacencia es: %d\n",obtenerGradoMatriz(matAdy,vertice));
    printf("El grado del vertice obtenido por la lista de adyacencia es: %d\n",obtenerGradoLista(vecAdy,vertice));
    printf("El grado del vertice obtenido por media matriz de adyacencia (triangulo superior) es: %d\n",obtenerGradoMedMat(matAdy,vertice));
}

int obtenerGradoMatriz(int matAdy[10][10], int vertice){
    int i, grado=0;
    for (i = 0; i < 10; i++)
        if (i != vertice && matAdy[vertice][i] == 1)
            grado++;
    return grado;
}

int obtenerGradoLista(TV vecAdy[10], int vertice){
    int grado = 0;
    TLista aux = vecAdy[vertice].LVA;

    while (aux != NULL){
        if (aux->verticeAdy != vertice)
            grado++;
        
        aux = aux->sig;
    }
    
    return vertice;
}

int obtenerGradoMedMat(int matAdy[10][10], int vertice){
    int i, j, grado=0;

    for (i = 0; i < 10; i++)
        for (j = i+1; j < 10; j++)
            if (j == vertice || i == vertice)
                    grado++;
        
    return grado;
}