#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "TDACola.h"

/* */

#define ST6 7
#define ST25 26

typedef struct nodito{
    char apeYNom[ST25];
    int cantEntCom;
    char mailCont[ST25];
    char tipoEntr;
    struct nodito *sig;
}nodito;

typedef nodito * subLista;

typedef struct nodo{
    char codPartido[ST6];
    int capacidadEst, cantEntrVend;
    struct nodo * sig;
    subLista sub;
}nodo;

typedef nodo * TLista;

typedef struct {
    char codPartido[ST6];
    char apeYNom[ST25], mailCont[ST25]; 
    int cantEntCom;
    char tipoEntr;
}TElementoA;

void cargarArch(TLista L, char nom[ST25]);

void main(){
    TLista L;
    L = NULL;

    cargarL(&L);

    cargarArch(L, "COMPRAS.DAT");
}   

void cargarArch(TLista L, char nom[ST25]){
    FILE *archB;
    TElementoA elem;
    subLista sAnt, sAct, sNuevo;
    TLista actL;
    TElementoC elemC;
    TCola C;

    if ((archB = fopen(nom, "rb")) == NULL)
        printf("No se pudo abrir el archivo. \n");
    else {
        iniciaC(&C);
        while (fread(&elem, sizeof(TElementoA), 1, archB) == 1){
            actL = L;
            while (actL != NULL && strcmp(actL->codPartido, elem.codPartido) < 0)
                actL = actL->sig;
            
            if (actL != NULL && strcmp(actL->codPartido, elem.codPartido) == 0){
                if (actL->capacidadEst*0.4 <= actL->cantEntrVend + elem.cantEntCom){
                    sAnt = NULL;
                    sAct = actL->sub;
                    
                    sNuevo = (subLista)malloc(sizeof(nodito));
                    sNuevo->cantEntCom = elem.cantEntCom;
                    strcmp(sNuevo->apeYNom, elem.apeYNom);
                    strcmp(sNuevo->mailCont, elem.mailCont);
                    sNuevo->tipoEntr = elem.tipoEntr;
                    sNuevo->sig = NULL;
                    
                    while (sAct != NULL && sAct->tipoEntr < sNuevo->tipoEntr){
                        sAnt = sAct;
                        sAct = sAct->sig;
                    }

                    if (sAnt == NULL) {
                        sNuevo->sig = actL->sub;
                        actL->sub = sNuevo;
                    } else {
                        sAnt->sig = sNuevo;
                        sNuevo->sig = sAct;
                    }
                } else {
                    printf("Se ha superado el aforo del estadio, no fue posible realizar la compra. \n");
                    strcpy(elemC.apeYNom, elem.apeYNom);
                    strcpy(elemC.codPar, elem.codPartido);
                    strcpy(elemC.mailCont, elem.mailCont);
                    poneC(&C, elemC);
                }
            } else 
                printf("El codigo de partido no existe. \n");
        }
        fclose(archB);
    }
}
