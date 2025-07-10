#include <stdio.h>
#include "TDACola.h"
#include "TDAPila.h"
/* 12. Idem ejercicio 11 pero suponiendo el grafo almacenado en una lista de adyacencia */

#define MAX 50

typedef struct nodo{
    int verticeAdy;
    struct nodo * sig;

}nodo;

typedef nodo * TLista;

typedef struct {
    int vertice;
    TLista vertsAdys;
}TVec;

void mostrarVerticesProf(TVec listaAdy[MAX]);
void mostrarVerticesAmpl(TVec listaAdy[MAX]);
int cantCompConex(TVec listaAdy[MAX]);
int recorridoCompleto(int vec[MAX]);
TElementoP buscoAdyNoVisitado(int vec[MAX]);

void main(){
    TVec listaAdy[MAX];
    
    
    //cargaLista(listaAdy);

    mostrarVerticesAmpl(listaAdy);
    mostrarVerticesProf(listaAdy);
    printf("La cantidad de componentes conexas es: %d\n", cantCompConex(listaAdy));
}

void mostrarVerticesProf(TVec listaAdy[MAX]){
    int vec[MAX] = {0};
    TLista aux;
    TPila P;
    TElementoP V;
    
    iniciaP(&P);

    V = listaAdy[0].vertice;
    vec[V] = 1;
    aux = listaAdy[V].vertsAdys;
    
    printf("Vertice: %d\n", V);
    while (!recorridoCompleto(vec)){    
        while (aux != NULL && vec[aux->verticeAdy] == 1)
            aux = aux->sig;
        
        if (aux == NULL)
            sacaP(&P,&V);
        else {
            poneP(&P,V);
            V = aux->verticeAdy;
            vec[V] = 1;
            printf("Vertice: %d\n", V);
        }
    }
}

void mostrarVerticesAmpl(TVec listaAdy[MAX]){
    TLista aux;
    TCola C;
    TElementoC V;
    int vec[MAX] = {0};
    iniciaC(&C);

    V = listaAdy[0].vertice;
    poneC(&C,V);
    vec[V] = 1;
    printf("Vertice: %d\n", V);
    while (!recorridoCompleto(vec)){
        sacaC(&C,&V);
        aux = listaAdy[V].vertsAdys;
        while (aux != NULL && !recorridoCompleto(vec)){
            V = aux->verticeAdy;
            if (vec[V] != 1){
                vec[V] = 1;
                poneC(&C,V);
                printf("Vertice: %d\n", V);
            }
            aux = aux->sig;
        }
    }
}

int cantCompConex(TVec listaAdy[MAX]){
    TLista aux;
    TCola C;
    TElementoC V;
    int vec[MAX] = {0}, cco = 0;
    iniciaC(&C);

    while (!recorridoCompleto(vec)){
        V = buscoAdyNoVisitado(vec);
        poneC(&C,V);
        cco++;
        vec[V] = cco;
        while (!recorridoCompleto(vec) && !vaciaC(C)){
            sacaC(&C,&V);
            aux = listaAdy[V].vertsAdys;
            while (aux != NULL && !recorridoCompleto(vec)){
                V = aux->verticeAdy;
                if (vec[V] == 0){
                    vec[V] = cco;
                    poneC(&C,V);
                }
                aux = aux->sig;
            }    
        }
    }   
}


