#include <stdio.h>
/* 21. Dado un árbol binario que proviene de la transformación de un bosque,
a) hallar la cantidad de árboles del bosque que tenían altura al menos K (dato de entrada)
b) generar un arreglo con la clave mayor de cada uno de los árboles que conforman el bosque.
c) verificar que todos los árboles contengan al menos un nodo de grado K (dato de entrada). */

#define MAX 20

typedef struct nodo{
    int dato;
    struct nodo *izq,*der;
}nodo;

typedef nodo * ARBOL;

int cantArboles(ARBOL A, int K);
int calcProf(ARBOL A, int nivel);
void generarArreglo(ARBOL A, int claves[MAX], int *i);
int calcMax(ARBOL A);
int arbolesConGradoK(ARBOL A, int K);
int contarHijos(ARBOL A);
int calcGrado(ARBOL A, int izq, int K);

void main(){
    ARBOL A;
    int alturaK, gradoK, claves[MAX], i = -1;
    A = NULL;
    //iniciaA(&A);

    printf("Ingrese una profundidad K a comparar\n");
    scanf("%d", &alturaK);
    printf("La cantidad de arboles del bosque inicial con profundidad K=%d es: %d\n", alturaK, cantArboles(A, alturaK));

    generarArreglo(A, claves, &i);

    printf("Ingrese un grado K \n");
    scanf("%d", &gradoK);
    if (arbolesConGradoK(A, gradoK))
        printf("Todos los arboles del bosque tiene al menos un nodo de grado K=%d\n", gradoK);
    else
        printf("No cumple la condicion de que todos los arboles del bosques tengan un nodo de grado K=%d\n", gradoK);
}


int cantArboles(ARBOL A, int K){
    ARBOL aux = A;
    int cont = 0;
    while (aux != NULL){
        if (calcProf(aux->izq, 1) >= K)
            cont++;
        aux = aux->der;
    }
    return cont;
}

int calcProf(ARBOL A, int nivel){
    int izq, der;
    if (A != NULL){
        izq = calcProf(A->izq, nivel + 1);
        der = calcProf(A->der, nivel);

        return izq < der ? der : izq;
    } else
        return nivel-1;
}

void generarArreglo(ARBOL A, int claves[MAX], int *i){
    ARBOL aux = A;

    while (aux != NULL){
        (*i)++;
        claves[*i] = calcMax(aux->izq);
        aux = aux->der;
    }
}

int calcMax(ARBOL A){
    int max, der, izq;
    if (A != NULL){
        izq = calcMax(A->izq);
        der = calcMax(A->der);
        max = izq < der ? der : izq;

        return A->dato > max ? A->dato : max;
    } else
        return 0;
}

int arbolesConGradoK(ARBOL A, int K){
    ARBOL aux = A;
    int res = 1;

    while (aux != NULL){
        if (calcGrado(aux->izq, 1, K))
            res = 0;
        aux = aux->der;
    }
    return res;
}

int contarHijos(ARBOL A){
    int cont = 0;
    while (A != NULL){
        cont++;
        A = A->der;
    }
    return cont;
}

int calcGrado(ARBOL A, int izq, int K){
    if (A != NULL)
        if (contarHijos(A) == K && izq == 1)
            return 1;
        else
            return calcGrado(A->izq, 1, K) || calcGrado(A->der, 0, K);
    else
        return 0;
}