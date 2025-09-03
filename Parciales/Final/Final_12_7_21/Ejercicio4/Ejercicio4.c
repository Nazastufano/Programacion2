#include <stdio.h>

/* */

#define MAX 10

typedef struct nodo{
    int verticeAdy, pertenece, peso;
    struct nodo * sig;
}nodo;

typedef nodo * TLista;

typedef struct {
    int vertice;
    TLista verticesAdy;
}TVTLista;

void recorrer(TVTLista LAdy[MAX]);

void main(){
    TVTLista LAdy[MAX];
    cargarLAdy(LAdy);

    recorrer(LAdy);
}

void recorrer(TVTLista LAdy[MAX]){
    TLista aux;
    int i, vcc[MAX] = {0}, pesoMax = 0, pesoTotal = 0;
    int v1, v2;
    for (i = 0; i < MAX; i++){
        aux = LAdy[i].verticesAdy;
        while (aux != NULL){
            if (aux->pertenece && !vcc[aux->verticeAdy]){
                vcc[aux->verticeAdy] = 1;
                pesoTotal += aux->peso;
                if (aux->peso >= pesoMax){
                    pesoMax = aux->peso;
                    v1 = LAdy[i].vertice;
                    v2 = aux->verticeAdy;
                }
            }
            aux = aux->sig;
        }
    }
    printf("El costo del AAM es: %d \n", pesoTotal);
    printf("La arista de mayor peso del AAM es: %d y la unen los vertices V1=%d y V2=%d \n", pesoMax, v1,v2);
}