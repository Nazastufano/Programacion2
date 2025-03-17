#include <stdio.h>

/* 18. Desarrollar un subprograma que duplique los elementos de un vector ubicados en las
posiciones pares. Implementar 3 veces utilizando for, while y do while*/

#define SIZE 10

void DuplicarPosParesF(int v[]);
void DuplicarPosParesW(int v[]);
void DuplicarPosParesDW(int v[]);
void MostrarVec(int V[]);

void main(){
    int v[SIZE] = {0,1,2,3,4,5,6,7,8,9};

    MostrarVec(v);
    //DuplicarPosParesF(v);
    //DuplicarPosParesW(v);
    DuplicarPosParesDW(v);
    MostrarVec(v);
}

void DuplicarPosParesF(int v[]){
    int i;
    for (i = 0; i < SIZE; i++) 
        if (i % 2 == 0)
            v[i] *= 2;
}

void DuplicarPosParesW(int v[]){
    int i = 0;
    
    while (i++<SIZE) {
        if (i % 2 == 0)
            v[i] *= 2;
    }
}

void DuplicarPosParesDW(int v[]){
    int i = 0;
    do {
        if (i % 2 == 0)
            v[i] *= 2;
    } while (i++ < SIZE);
}

void MostrarVec(int v[]){
    int i;
    for ( i = 0; i < SIZE; i++)
        printf("%d ", v[i]);

    printf("\n");
}

