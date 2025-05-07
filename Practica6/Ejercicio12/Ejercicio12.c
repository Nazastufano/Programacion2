#include <stdio.h>
#include <stdlib.h>
/* 12. Una lista doble contiene en cada nodo un rango de números enteros [A,B] y una sublista de 
enteros. Generar una lista simple paralela a la lista doble donde cada nodo contenga el 
promedio de los valores de la sublista y la cantidad de elementos de la misma que no 
pertenecen al rango [A,B]. */


typedef struct nodito{
    int dato;
    struct nodito * sig;
} nodito;

typedef nodito * subLista;

typedef struct {
    int a, b;
    subLista sub;
} TElementoLC;

typedef struct nodoD{
    TElementoLC datos;
    struct nodoD *ant, *sig;
} nodoD;

typedef nodoD * pNodoD;

typedef struct {
    pNodoD pri, ult;
} TListaD;

typedef struct {
    int cant;
    float promValSub; 
} TElementoL;

typedef struct nodo{
    TElementoL datos;
    struct nodo * sig;
} nodo;

typedef nodo * TLista;

void crearListaParalela(TListaD LD, TLista *L);

void main(){
    TListaD LC;
    TLista L;

}

void crearListaParalela(TListaD LD, TLista *L){
    pNodoD auxLD = LD.pri;
    subLista sAct, sAnt;
    TLista N, auxL;
    *L = NULL;

    int cont, suma;
    if (LD.pri != NULL){
        while (auxLD != NULL){
            sAct = auxLD->datos.sub;
            cont = 0;
            suma = 0;
            if (sAct != NULL){
                N = (TLista)malloc(sizeof(nodo));
                N->datos.cant = 0;
                N->datos.promValSub = 0;
                N->sig = NULL;
                while (sAct != NULL){
                    if (sAct->dato < auxLD->datos.a || auxLD->datos.b < sAct->dato)
                        N->datos.cant++;
                    
                    cont++;
                    suma += sAct->dato;

                    sAct = sAct->sig;
                }
                N->datos.promValSub = (float)suma/cont;
                
                if (*L == NULL)
                    *L = N;
                else
                    auxL->sig = N;
                auxL = N;
            }
            auxLD = auxLD->sig;
        }
    }
    
}