#include <stdio.h>
/* 8. El draw de un torneo de tenis se representa mediante un árbol binario invertido. Desarrollar
subprogramas que muestren:
    a) el nombre del ganador.
    b) los nombres de los 2 finalistas.
    c) los nombres de los 4 semifinalistas.
    d) los nombres de todos los competidores y la cantidad. */
#define MAX 20

typedef char TElementoA;

typedef struct nodo{
    TElementoA dato[20];
    struct nodo *izq, *der;
}nodo;

typedef nodo * ARBOL;

void mostrarGanador(ARBOL A);
void mostrarFinalistas(ARBOL A);
void mostrarCuartos(ARBOL A, int nivel);
void mostrarCompetidores(ARBOL A, int *cant);

void main(){
    ARBOL A;
    int cant = 0;
    A = NULL;
    //cargaA(&A);

    mostrarGanador(A);
    mostrarFinalistas(A);
    mostrarCuartos(A,1);
    mostrarCompetidores(A, &cant);
}


void mostrarGanador(ARBOL A){
    if (A != NULL)
        printf("El ganador es: %s\n", A->dato);    
}

void mostrarFinalistas(ARBOL A){
    if (A != NULL && A->der != NULL && A->izq != NULL)
        printf("Los dos semifinalistas son: %s y %s \n", A->izq->dato, A->der->dato);
}

void mostrarCuartos(ARBOL A, int nivel){
    if (A != NULL){
        if (nivel == 3)
            printf("Jugador en cuartos: %s\n", A->dato);
        else {
            mostrarCuartos(A->izq, nivel+1);
            mostrarCuartos(A->der, nivel+1);
        }        
    }
}


void mostrarCompetidores(ARBOL A, int *cant){
    if (A != NULL){
        if (A->der == NULL && A->izq == NULL){
            printf("Competidor: %s \n", A->dato);
            (*cant)++;
        }
        
        mostrarCompetidores(A->izq, cant);
        mostrarCompetidores(A->der, cant);
    }
}

/*
void ganador(ARBOL A){
    if (A != NULL){
        if (A->der == NULL && A->izq == NULL)
            printf("El ganador es: %s\n", A->dato);
        else {
            ganador(A->der);
            ganador(A->izq);
        }
    }
}

// b) los nombres de los 2 finalistas.
void nombreFinalistas(ARBOL A){
    if (A != NULL){
        if (A->der->dato == A->izq->dato){
            
        }
    }
    
}

*/