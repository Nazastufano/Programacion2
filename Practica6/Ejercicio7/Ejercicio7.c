#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/* 7. Implementar un programa de biblioteca que administre la siguiente estructura: un arreglo de 
listas simples ordenadas alfabéticamente con los autores que comiencen con la misma letra, o 
sea que habrá un elemento del arreglo por cada letra del abecedario, aunque no existan 
autores que comiencen con dicha letra.  Para cada autor existe una sublista, ordenada por 
título, con los libros disponibles para ser prestados de cada autor:  
    • Autor 
    • Sublista de libros de dicho autor 
        o Titulo 
        o Autor 
        o Año de edición 
Se debe poder agregar libros a esta estructura.  
Además, gestionar una lista de socios con una sublista de libros prestados. Permitir las 
operaciones de registrar préstamos (mover el nodo de la sublista del autor al final de la sublista 
de libros prestados para el socio) y devoluciones (mover nodo del libro prestado de dicha 
sublista a la sublista del autor de acuerdo al orden indicado). Dicha lista posee la siguiente 
estructura: 
    • Socio 
    • Sublista de libros prestados 
        o Titulo 
        o Autor 
        o Año de edición */
#define TOTALLETRAS 26
typedef struct nodito{
    char titulo[20], autor[20];
    int anioEdicion;
    struct nodito * sig;
} nodito;

typedef nodito *subLista;

typedef struct nodoB{
    char autor[20];
    subLista subLA;
    struct nodoB * sig;
} nodoB;

typedef nodoB * TListaB;

typedef struct nodoS{
    char socio[20];
    subLista subLP;
    struct nodoS * sig;
} nodoS;

typedef nodoS * TListaS;

void agregarLibro(TListaB *, char [20], char [20], int);
void registrarPrestamo(TListaB [TOTALLETRAS], TListaS *, char [20], char [20], char [20]);
void devoluciones(TListaB *, TListaS *, char [20], char [20], char [20]);

void main(){
    TListaB LB[TOTALLETRAS];
    TListaS LS;
    // Inicia LB, Inicia LS;
    // Ejercicio
}

void agregarLibro(TListaB *LB, char titulo[20], char autor[20], int anio){
    TListaB act = *LB, ant = NULL, lNuevo = NULL;
    subLista sNuevo = NULL, sAct, sAnt;

    while(act != NULL && strcmp(autor, act->autor) > 0){
        ant = act;
        act = act->sig;
    }

    sNuevo = (subLista)malloc(sizeof(nodito));
    sNuevo->anioEdicion = anio;
    strcpy(sNuevo->autor,autor);
    strcpy(sNuevo->titulo,titulo);
    sNuevo->sig = NULL;
    if (act != NULL && strcmp(act->autor, autor) == 0){ //lo encontré (autor)
        sAct = act->subLA;
        sAnt = NULL;
        while (sAct != NULL && strcmp(titulo,sAct->titulo) > 0){ //busco titulo
            sAnt = sAct;
            sAct = sAct->sig;
        }

        if (sAnt == NULL){ //va primero (titulo)
            sNuevo->sig = sAct;
            act->subLA = sNuevo;
        } else { //no va primero (titulo)
            sAnt->sig = sNuevo;
            sNuevo->sig = sAct;
        }
        
    } else { // no lo encontré (autor)
        lNuevo = (TListaB)malloc(sizeof(nodoB));
        strcpy(lNuevo->autor,autor);
        lNuevo->subLA = sNuevo;
        if (ant == NULL){ //va primero (no hay datos) (autor)
            lNuevo->sig = act;
            (*LB) = lNuevo;
        } else { //no va primero (Hay datos) (autor)
            ant->sig = lNuevo;
            lNuevo->sig = act;
        }
    }
}

void registrarPrestamo(TListaB LB[TOTALLETRAS], TListaS *LS, char socio[20], char titulo[20], char autor[20]){
    TListaB lElim, actLB, antLB = NULL;
    TListaS actLS = *LS, antLS = NULL;
    subLista sElim, sAux, sAct, sAnt;
    int i = 97;
    actLB = LB[autor[0]-i];

    while (actLB != NULL && strcmp(autor, actLB->autor) > 0){ //busco autor
        antLB = actLB;
        actLB = actLB->sig;
    }
    if (actLB != NULL && strcmp(autor,actLB->autor) == 0){ //existe autor
        sAct = actLB->subLA;
        sAnt = NULL;
        while (sAct != NULL && strcmp(titulo, sAct->titulo) > 0){ //busco titulo
            sAnt = sAct;
            sAct = sAct->sig;
        }
        if (sAct != NULL && strcmp(titulo,sAct->titulo) == 0){ //existe titulo
            if (actLS != NULL){ //verifico que haya socios
                while (actLS != NULL && strcmp(socio, actLS->socio) != 0){ //busco socio
                    antLS = actLS;
                    actLS = actLS->sig;
                }
                if (actLS != NULL && strcmp(socio,actLS->socio) == 0){ //existe socio
                    //creo nodo aux, para cargar en el socio
                    sAux = (subLista)malloc(sizeof(nodito));
                    sAux->anioEdicion = sAct->anioEdicion;
                    strcpy(sAux->autor,autor);
                    strcpy(sAux->titulo,titulo);
                    sAux->sig = NULL;

                    //libero biblioteca
                    sElim = sAct; 
                    if (sAnt == NULL) //elimino cabeza de sublista autor
                        actLB->subLA = sAct->sig;
                    else { //elimino no cabeza de sublista autor
                        sAnt->sig = sAct->sig;
                    }
                    free(sElim);
                    
                    //reviso si el autor quedó vacio
                    if (actLB->subLA == NULL){
                        lElim = actLB;
                        if (antLB == NULL)
                            LB[autor[0]-i] = actLB->sig;
                        else 
                            antLB->sig = actLB->sig;
                        free(lElim);
                    }

                    //recorrer subLista al final
                    sAct = actLS->subLP;
                    sAnt = NULL;
                    while (sAct != NULL){
                        sAnt = sAct;
                        sAct = sAct->sig;
                    }
                    
                    if (sAnt == NULL) //cabeza de la sublista de socio
                        actLS->subLP = sAux;
                    else{ //no cabeza de la sublista de socio
                        sAnt->sig = sAux;
                        sAux->sig = sAct;
                    }
                }   
            }
        }
    }
}

void devoluciones(TListaB LB[TOTALLETRAS], TListaS *LS, char socio[20], char titulo[20], char autor[20]){
    TListaS ant = NULL, act = *LS;
    subLista sElim, sAnt, sAct;
    int i = 97;
    if (act != NULL){
        while (act != NULL && strcmp(socio, act->socio) != 0){
            ant = act;
            act = act->sig;
        }
        if (act != NULL && strcmp(socio, act->socio) == 0){
            sAct = act->subLP;
            sAnt = NULL;
            while (sAct != NULL && (strcmp(autor, sAct->autor) != 0 || strcmp(titulo, sAct->titulo) != 0)){
                sAnt = sAct;
                sAct = sAct->sig;
            }
            if (sAct != NULL){
                sElim = sAct;
                agregarLibro(&LB[autor[0] - i],titulo,autor, sElim->anioEdicion);
                if (sAnt == NULL)
                    act->subLP = sAct->sig;
                else
                    sAnt->sig = sAct->sig;
                free(sElim);
            }
        }
    }
}