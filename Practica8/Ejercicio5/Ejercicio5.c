#include <stdio.h>

/* 5. Dado un vértice determinado de un digrafo representado en una matriz de adyacencia,
implementar funciones que devuelvan:
a) su grado de entrada
b) su grado de salida
c) el grado de dicho vértice */

int gradoDeEntrada(int matrizAdyDG[10][10], char vertice);
int gradoDeSalida(int matrizAdyDG[10][10], char vertice);
int gradoDelVertice(int matrizAdyDG[10][10], char vertice);
int calcPos(char vertice);

void main(){
    char vertice;
    int matrizAdyDG[10][10];
    //cargaMatriz(matrizAdyDG);
    
    //Vertices de A a Z, valor 0 a 24
    do{
        printf("Ingrese un vertice a visitar\n");
        scanf(" %c", &vertice);
    } while (vertice < 65 || vertice > 90);

    printf("El grado de entrada del vertice %c es: %d\n", gradoDeEntrada(matrizAdyDG, vertice));
    printf("El grado de salida del vertice %c es: %d\n", gradoDeSalida(matrizAdyDG,vertice));
    printf("El grado del vertice %c es: %d\n", gradoDelVertice(matrizAdyDG,vertice));
}

int gradoDeEntrada(int matrizAdyDG[10][10], char vertice){
    int pos, i, grado = 0;
    pos = calcPos(vertice);
    for (i = 0; i < 10; i++)
        if (matrizAdyDG[i][pos] == 1)
            grado++;
        
    return grado;
}

int gradoDeSalida(int matrizAdyDG[10][10], char vertice){
    int pos, j, grado = 0;
    pos = calcPos(vertice);
    for (j = 0; j < 10; j++)
        if (matrizAdyDG[pos][j] == 1)
            grado++;
        
    return grado;
}

int gradoDelVertice(int matrizAdyDG[10][10], char vertice){
    int pos, i, grado = 0;
    pos = calcPos(vertice);
    for (i = 0; i < 10; i++)
        if (i != pos)
            grado += matrizAdyDG[pos][i] + matrizAdyDG[i][pos];
        
    return grado;
}

int calcPos(char vertice){
    return vertice - 65;
}