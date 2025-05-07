#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* 7. A partir de la lista de equipos de fútbol con sublista de jugadores del ejercicio 6 de la práctica 6 
de Listas, crear una lista doblemente enlazada con los equipos que tengan algún jugador mayor 
de 30 años. Para cada equipo registrar cantidad de jugadores y edad promedio. La estructura 
de cada nodo de la lista doble es la siguiente: 
    • Nombre del equipo (ordenada por este campo)  
    • Cantidad de jugadores 
    • Edad promedio */

typedef struct nodito{
    char nombre[20];
    unsigned int edad;
    char estado;
    struct nodito * sig;
} nodito;
    
typedef nodito * subLista;
    
typedef struct nodo{
    char nombreEquipo[20];
    unsigned int puntaje;
    subLista sub;
    struct nodo * sig;
}nodo;
    
typedef nodo * TLista;

typedef struct nodoD{
    char nombreEquipo[20];
    int cantJugadores;
    float edadProm;
    struct nodoD *sig, *ant;
} nodoD;

typedef nodoD * pNodoD;

typedef struct {
    pNodoD pri, ult;
} TListaD;

void generarLista(TLista L, TListaD *LD);

void main(){
    TLista L;
    TListaD LD;
    L = NULL;
    LD.pri = NULL;
    LD.ult = NULL;
    //cargaLista(&L);
    generarLista(L, &LD);
}

void generarLista(TLista L, TListaD *LD){
    TLista auxL = L;
    pNodoD auxLD, nuevo;
    subLista sAux;
    int encontrado, contJug, sumaEdad;
    while (auxL != NULL){
        sAux = auxL->sub;
        encontrado = 0;
        contJug = 0;
        sumaEdad = 0;
        while (sAux != NULL) {
            if (sAux->edad > 30)
                encontrado = 1;
            contJug++;
            sumaEdad += sAux->edad;
            sAux = sAux->sig;
        }
    
        if (encontrado){
            nuevo = (pNodoD)malloc(sizeof(nodoD));
            nuevo->cantJugadores = contJug;
            nuevo->edadProm = (float)sumaEdad/contJug;
            strcpy(nuevo->nombreEquipo, auxL->nombreEquipo);
            nuevo->ant = NULL;
            nuevo->sig = NULL;
            if ((*LD).pri == NULL){
                (*LD).pri = nuevo;
                (*LD).ult = nuevo;
            } else {
                nuevo->ant = (*LD).ult;
                (*LD).ult->sig = nuevo;
                (*LD).ult = nuevo;
            }
        }
        auxL = auxL->sig;
    }
}