#include <stdio.h>
#include "TDAPila.h"
#include <stdlib.h>

/* */

#define ST4 5
#define ST7 8

typedef struct nodoD{
    int zona;
    char camRad[ST4];
    TPila P;
    struct nodoD *ant, *sig;
}nodoD;

typedef nodoD * pNodoD;

typedef struct{
    pNodoD pri, ult;
}TListaD;

typedef struct nodoC{
    int zona, cantInfRad, cantInfCam;
    struct nodoC * sig;
}nodoC;

typedef nodoC * TListaC;

int cantRadares(TListaD LD);
int esIgual(TElementoP elem);
void generarLC(TListaC *LC, TListaD LD);
int vaciarPila(TPila P);

void main(){
    TListaD LD;
    TListaC LC;
    LD.pri = NULL;
    LD.ult = NULL;
    LC = NULL;

    cargaLD(&LD);

    printf("La cantidad de radares que en zonasa pares han hecho infracciones el 19/12 son: %d \n", cantRadares(LD));

    generarLC(&LC, LD);
}

int cantRadares(TListaD LD){
    pNodoD aux;
    int cant = 0;
    aux = LD.pri;
    
    while (aux != NULL){
        if (aux->zona % 2 == 1)
            reccorerPila(&(aux->P), &cant);

        aux = aux->sig;
    }

    return cant;
}

void reccorerPila(TPila *P, int *cant){
    TElementoP elem;
    if (!vaciaP(P)){
        sacaP(&P, &elem);
        if (esIgual(elem))
            *cant += 1;
        else
            reccorerPila(P, cant);
        poneP(&P, elem);
    }
}

int esIgual(TElementoP elem){
    return elem.fechaHora[0] == '1' && elem.fechaHora[1] == '2' && elem.fechaHora[4] == '1' && elem.fechaHora[5] == '9';
}

void generarLC(TListaC *LC, TListaD LD){
    pNodoD auxLD = LD.pri;
    TListaC antLC, actLC, nuevoLC;
    int vCont[2], zonaAct;

    while (auxLD != NULL){
        zonaAct = auxLD->zona;
        vCont[0] = 0;
        vCont[1] = 0;
        while (auxLD != NULL && zonaAct == auxLD->zona){
            if (auxLD->camRad[0] == 'C')
                vCont[0] += vaciarPila(auxLD->P);
            else 
                vCont[1] += vaciarPila(auxLD->P);
            auxLD = auxLD->sig;
        }
        if (vCont[0] && vCont[1]){
            nuevoLC = (TListaC)malloc(sizeof(nodoC));
            nuevoLC->zona = zonaAct;
            nuevoLC->cantInfCam = vCont[0];
            nuevoLC->cantInfRad = vCont[1];
            nuevoLC->sig = NULL;

            if (*LC == NULL){
                nuevoLC->sig = nuevoLC;
                *LC = nuevoLC;
            } else if (nuevoLC->cantInfCam + nuevoLC->cantInfRad < actLC->cantInfCam + actLC->cantInfRad){
                antLC->sig = nuevoLC;
                nuevoLC->sig = (*LC)->sig;
                *LC = nuevoLC;
            } else {
                antLC = *LC;
                actLC = (*LC)->sig;
                
                do{
                    antLC = actLC;
                    actLC = actLC->sig; 
                } while (actLC != (*LC)->sig && nuevoLC->cantInfCam + nuevoLC->cantInfRad > actLC->cantInfCam + actLC->cantInfRad);
                
                antLC->sig = nuevoLC;
                nuevoLC->sig = actLC->sig;
            }
        }
    }
}

int vaciarPila(TPila P){
    int cant = 0;
    TElementoP elem;
    while(!vaciaP(P)){
        sacaP(&P, &elem);
        cant++;
    }
    return cant;
}