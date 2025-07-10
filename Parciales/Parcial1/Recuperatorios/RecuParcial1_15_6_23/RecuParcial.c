#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TDACola.h"

typedef struct nodoC{
    char patente[8];
    char cubreVIP;
    char radioViaj[4];
    unsigned int cantPasaj;
    char libre;
    struct nodoC *sig;
}nodoC;

typedef nodoC * TListaC;

typedef struct nodo{
    char patente[8];
    TCola C;
    struct nodo * sig;
}nodo;

typedef nodo * TLista;

typedef struct {
    int cantViajes;
    int totalPasajeros;
}TRegRes;

void procesarArch(TListaC LC, TLista *L, char nomArch[20]);
int cumpleRadio(char radioVia[4], char radioREG);
int cubreVIP(char cubreVIP, char vip);
void depurarViajes(TLista L);
void eliminarPatente(TLista *L, TListaC *LC, char P[9],TRegRes resumen[3]);
void inicializaVec(TRegRes resumen[3]);

void main(){
    TLista L;
    TListaC LC;
    char P[9];
    TRegRes resumen[3];
    L = NULL;
    LC = NULL;
    //cargaL(&L);
    //cargaLC(&LC);


    procesarArch(LC, &L, "VIAJES.DAT");

    depurarViajes(L);
    printf("Ingrese la patente a eliminar \n");
    scanf("%s", P);

    eliminarPatente(&L, &LC, P, resumen);
}
//Incompleto
void procesarArch(TListaC LC, TLista *L, char nomArch[20]){
    FILE *archB;
    TListaC auxLC;
    TLista actL, antL, nuevoL;
    TElementoC reg;
    if ((archB = fopen(nomArch, "rb")) == NULL)
        printf("No se pudo abrir el archivo. Es posible que no exista\n");
    else {
        while (fread(&reg, sizeof(TElementoC), 1, archB) == 1){
            auxLC = LC->sig;
            while (auxLC != LC && (reg.cantPasaj > auxLC->cantPasaj || auxLC->libre != 'N' || cubreVIP(auxLC->cubreVIP, reg.vip) || cumpleRadio(auxLC->radioViaj, reg.radio)))
                auxLC->sig;
            
            if (reg.cantPasaj <= auxLC->cantPasaj && auxLC->libre == 'S' && cubreVIP(auxLC->cubreVIP, reg.vip) && cumpleRadio(auxLC->radioViaj, reg.radio)){
                auxLC->libre = 'N';
                actL = *L;
                antL = NULL;
                
                while (actL != NULL && strcmp(actL->patente, auxLC->patente) != 0){
                    antL = actL;
                    actL = actL->sig;
                }    

                if (actL != NULL)
                    poneC(&(actL->C), reg);
                else {
                    nuevoL = (TLista)malloc(sizeof(nodo));
                    strcpy(nuevoL->patente,auxLC->patente);
                    iniciaC(&(nuevoL->C));
                    poneC(&(nuevoL->C), reg);
                    nuevoL->sig = NULL;
                    
                    if (antL == NULL)
                        *L = nuevoL;
                    else 
                        antL->sig = nuevoL;  
                }                
            }
            
        }
        fclose(archB);
    }
    
}

int cumpleRadio(char radioVia[4], char radioREG){
    if (radioVia[0] == radioREG || radioVia[1] == radioREG || radioVia[2] == radioREG)
        return 1;
    else
        return 0;   
}

int cubreVIP(char cubreVIP, char vip){
    if (cubreVIP == 'S' || (cubreVIP == 'N' && vip == 'N'))
        return 1;
    else
        return 0;
}

void depurarViajes(TLista L){
    TLista aux = L;
    int cantElim, maxCantElim = 0;
    char patenteMasElim[8];
    TElementoC elem, centinela;

    while (aux != NULL){
        centinela.cantPasaj = 999;
        poneC(&(aux->C), centinela);
        sacaC(&(aux->C), &elem);
        cantElim = 0;
        while (elem.cantPasaj != centinela.cantPasaj){
            if (elem.cantPasaj != 0)
                poneC(&(aux->C), elem);
            else 
                cantElim++;
            
            sacaC(&(aux->C), &elem);
        }
        if (cantElim >= maxCantElim){
            maxCantElim = cantElim;
            strcpy(patenteMasElim, aux->patente);
        }
        
        aux = aux->sig;
    }
}

void eliminarPatente(TLista *L, TListaC *LC, char P[9],TRegRes resumen[3]){
    TLista actL = *L, antL = NULL, lElim;
    TListaC actLC = (*LC)->sig, antLC =NULL, lCElim;
    TElementoC elem;

    inicializaVec(resumen);

    while (actL != NULL && strcmp(P, actL->patente) > 0){
        antL = actL;
        actL = actL->sig;
    }

    while (!vaciaC(actL->C)){
        sacaC(&(actL->C), &elem);
        if (elem.radio == 'U'){
            resumen[0].cantViajes += 1;
            resumen[0].totalPasajeros += elem.cantPasaj;
        } else if (elem.radio == 'R'){
            resumen[1].cantViajes += 1;
            resumen[1].totalPasajeros += elem.cantPasaj;
        }
        else {
            resumen[2].cantViajes += 1;
            resumen[2].totalPasajeros += elem.cantPasaj;
        }
    }
    lElim = actL;

    if (antL == NULL)
        *L = actL->sig;
    else
        antL->sig = actL->sig;
    free(lElim);
    
    while (actLC != *LC && srtcmp(actLC->patente, P) != 0){
        antLC = actLC;
        actLC = actLC->sig;
    }
    
    lCElim = actLC;
    if (actLC == *LC){
        antLC->sig = (*LC)->sig;
        *LC = antLC;
    }else
        antLC->sig = actLC->sig;
    
    free(lCElim);
}

void inicializaVec(TRegRes resumen[3]){
    int i;
    for (i = 0; i < 3; i++){
        resumen[i].cantViajes = 0;
        resumen[i].totalPasajeros = 0;
    }
}