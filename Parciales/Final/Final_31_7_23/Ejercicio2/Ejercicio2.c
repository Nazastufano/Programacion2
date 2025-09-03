#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "TDACola.h"

/* Ej 2) Una casa de remates recibe ofertas para los distintos lotes que saldrán a la venta que pueden
provenir de llamadas telefónicas o mail, y se almacenaron en un archivo binario OFERTAS.DAT que tiene
en cada elemento un struct con la siguiente información: CódigoLote (cadena de 5, validado, puede
repetirse, ordenada), DocumentoOfertante (cadena de 9), PrecioOfertado, Medio ([T]eléfono, [M]ail).
[Ninguna persona oferta más de una vez para el mismo lote]
En una lista circular LC se encuantran los datos de cada lote: CódigoLote (ordenada), PrecioBase.
Se quiere unificar la información de LC y del archivo en una lista simplemente enlazada L, cada nodo de
L contendrá: CódigoLote (ordenada, no se repite), PrecioRealEstimado, Sublista de ofertas telefónicas,
Sublista de ofertas por mail; cada sublista contiene: DocumentoOfertante, PrecioOfertado.
A) Utilizando el TDA Cola, desarrollar en C subprogramas para:
i) Genarar L, solo para aquellos lotes que tuvieron alguna oferta. El PrecioRealEstimado se obtiene
como el PrecioBase más el 20% del promedio entre la oferta más alta y la más baja (para ese lote).
ii) En una Cola C se tienen los Codigos Lote que se han vendido en una subasta por internet, se pide
eliminarlos de L (si estuvieran), generando un archivo LOTESBAJA.TXT que contenga un lote eliminado
por línea con la siguiente información: CodigoLote, CantOfertasTotales. La cola puede perderse.
B) Definir el tipo de C asumiendo que es circular. Desarrollar SacaC(), Indicar en qué archivo(s) se 
encuentran estas definiciones. */

#define ST20 21
#define ST5 6
#define ST9 10
#define INF 999999
typedef struct {
    char codLote[ST5], docOfert[ST9], medio;
    float precioOf;
}TElementoA;

typedef struct nodoC{
    char codLote[ST5];
    float precioBase;
    struct nodoC *sig;
}nodoC;

typedef nodoC * TListaC;

typedef struct nodito{
    char docOfert[ST9];
    float precioOf;
    struct nodito *sig;
}nodito;

typedef nodito * subLista;

typedef struct nodo{
    char codLote[ST5];
    float precioRealEst;
    subLista subOT, subOM;
    struct nodo *sig;
}nodo;

typedef nodo * TLista;

void generarL(TListaC LC, TLista *L, char nom[20]);
void moverSub(subLista *act, subLista sNuevo);
void eliminarL(TLista *L, TCola *C, char nom[20]);
void eliminarSub(subLista sAct, int *cantOfertados);


void main(){
    TListaC LC;
    TLista L;

    LC = NULL;
    L = NULL;
    cargarLC(&LC);
    generarL(LC, &L, "OFERTAS.DAT");
}

void generarL(TListaC LC, TLista *L, char nom[20]){
    FILE *archB;
    TLista actL = *L, nuevoL;
    TListaC actLC = LC->sig;
    subLista sNuevo, actM, actT;
    TElementoA elem;
    float ofertaMin, ofertaMax, precioBase;

    if ((archB = fopen(nom, "wb")) == NULL)
        printf("No se pudo abrir el archivo. \n");
    else {
        while (fread(&elem, sizeof(TElementoA), 1, archB) == 1){
            actM = NULL;
            actT = NULL;
            ofertaMax = 0;
            ofertaMin = INF;

            do{
                actLC = actLC->sig;
            }while (actLC != LC->sig && strcmp(actLC->codLote, elem.codLote) < 0);

            nuevoL = (TLista)malloc(sizeof(nodo));
            strcpy(nuevoL->codLote, elem.codLote);

            while (strcmp(actLC->codLote, elem.codLote) == 0 && !feof(archB)){
                precioBase = actLC->precioBase;
                sNuevo = (subLista)malloc(sizeof(nodito));
                strcpy(sNuevo->docOfert, elem.docOfert);
                sNuevo->precioOf = elem.precioOf;
                sNuevo->sig = NULL;

                if (elem.medio == 'T')
                    moverSub(&actT, sNuevo);
                else 
                    moverSub(&actM, sNuevo);
                    
                ofertaMax = ofertaMax > sNuevo->precioOf ? ofertaMax : sNuevo->precioOf;
                ofertaMin = ofertaMin < sNuevo->precioOf ? ofertaMin : sNuevo->precioOf;

                fread(&elem, sizeof(TElementoA), 1, archB);
            }

            nuevoL->precioRealEst = precioBase + ((ofertaMax+ofertaMin)/2)*0.2;
            nuevoL->subOM = actM;
            nuevoL->subOT = actT;
            nuevoL->sig = NULL;
            
            if (*L == NULL)
                *L = nuevoL;    
            else 
                actL->sig = nuevoL;

            actL = nuevoL;
        }
        fclose(archB);
    }
}


void moverSub(subLista *act, subLista sNuevo){
    sNuevo->sig = *act;
    *act = sNuevo;
}

void eliminarL(TLista *L, TCola *C, char nom[20]){
    TLista ant, act, elim;
    TElementoC elem;
    FILE *arch;
    int cantOfertados;
    if ((arch = fopen(nom, "w")) == NULL)
        printf("No se pudo abrir el archivo. \n");
    else {
        while (!vacia(*C) && *L != NULL){
            cantOfertados = 0;
            sacaC(C, &elem);
            ant = NULL;
            act = *L;
            while (act != NULL && strcmp(act->codLote, elem.codLote) < 0){
                ant = act;
                act = act->sig;
            }
            if (act != NULL && strcmp(act->codLote, elem.codLote) == 0){
                eliminarSub(act->subOM, &cantOfertados);
                eliminarSub(act->subOT, &cantOfertados);

                elim = act;
                act = act->sig;
                if (ant != NULL)
                    *L = act;
                else 
                    ant->sig = act;
                fprintf(arch, "%s %d", elim->codLote, cantOfertados);
                free(elim);
            }
        }
        fclose(arch);
    }
}

void eliminarSub(subLista sAct, int *cantOfertados){
    subLista sElim;
    while (sAct != NULL){
        sElim = sAct;
        cantOfertados++;
        sAct = sAct->sig;
        free(sElim);
    }
}