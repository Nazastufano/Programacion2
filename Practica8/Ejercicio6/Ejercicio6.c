#include <stdio.h>
/* 6. Resolver el ejercicio anterior suponiendo que el digrafo está almacenado en una lista de
adyacencia. */

typedef struct nodo{
    int dato;
    struct nodo * sig;
}nodo;

typedef nodo * TLista;

typedef struct {
    int dato;
    TLista LAdy;
}TV;

int gradoDeEntrada(TV vec[10], int vertice);
int gradoDeSalida(TV vec[10], int vertice);
int gradoDelVertice(TV vec[10], int vertice);


void main(){
    TV vec[10];
    int vertice;

    //cargaVecAdy(vec);

    do{
        printf("Ingrese un vertice a visitar\n");
        scanf("%d", &vertice);
    } while (vertice < 0 || vertice > 10);
    
    printf("El grado de entrada del vertice %d es: %d\n", gradoDeEntrada(vec, vertice));
    printf("El grado de salida del vertice %d es: %d\n", gradoDeSalida(vec,vertice));
    printf("El grado del vertice %d es: %d\n", gradoDelVertice(vec,vertice));
}

int gradoDeEntrada(TV vec[10], int vertice){
    TLista aux;
    int i, grado = 0;

    for (i = 0; i < 10; i++){
        aux = vec[i].LAdy;
        while (aux != NULL){
            if (vertice == aux->dato)
                grado++;
            aux = aux->sig;
        }
    }
    return grado;
}
int gradoDeSalida(TV vec[10], int vertice){
    TLista aux;
    int i = 0, grado = 0;
    
    while (i<9 && vec[i].dato != vertice)
        i++;
    
    aux = vec[i].LAdy;
    while (aux != NULL){
        grado++;
        aux = aux->sig;
    }
    return grado;
}

int gradoDelVertice(TV vec[10], int vertice){
    TLista aux;
    int i, grado = 0;

    for (i = 0; i < 10; i++){
        aux = vec[i].LAdy;
        while (aux != NULL){
            if (vec[i].dato != vertice){
                if (aux->dato == vertice)
                    grado++;
            } else 
                if (aux->dato != vertice)
                    grado++;
                                
            aux = aux->sig;
        }
    }
    return grado;
}