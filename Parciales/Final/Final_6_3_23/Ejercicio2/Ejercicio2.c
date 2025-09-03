#include <stdio.h>
#include "fechas.h"
#include <string.h>

/* Ej 2.- Una consultora de RRHH para proyectos tecnológicos meneja una lista simplemente enlazada con Sublistas
con la siguiente información en cada nodo: 
    Id Persona (ordenado, no se repite, cadena de 6)
    Rol (0..9, 0 indica que no tiene proyecto, sino es el rol en el proyecto actual, una persona no puede estar
    en más de un proyecto a la vez o en más de un rol en el mismo proyecto a la vez) 
    Fecha inicio (cadena de 8, aaaammdd, vacío si no tiene proyecto)
    Sublista de proyectos (puede estar vacía, son los roles/proyectos en el que concluyó su participación),
    en cada nodo: Empresa (puede repetirse, ordenada, cadena de 10, si inicia con # es extranjera), Rol (1..9),
    Meses que trabajó (entero corto)
Se pide resolver, modularizando:
a) En un archivo de texto FEBRERO.TXT, se encuentra la información de las personas (dato correcto) que
   participan en proyectos en el mes de febrero de 2023. EN cada línea (separando cada dato por un blanco) se
   tiene: IdPersona (ordenado, cadena de 6), Empresa (cadena de 10), Rol, Terminó, [S/N]. Con la información
   del archivo, actualizar la lista y sublistas según corresponda.
     Nota: Suponer la existencia de una función CANTM, en la librería fechas.h que recibe dos cadenas de formato
   aaaamm y retorna la diferencia en meses entre ambas. NO DESARROLLAR CANTM
b) Dados un P y E, eliminar todos los proyectos asociados a la empresa E de la persona P (puede o no existir). Al
   finalizar, indicar en cuántos proyectos de E la persona P ha concluido su participación. No eliminar el nodo
   de la lista si quedara sin proyectos
c) Gnerar una lista doble que en cada noto tenga Empresa (ordenada, cadena de 10) y CantP en la que figuren
   solo las empresas extranjeras siendo CantP la cantidad de personas distintas que ha contratado. */


#define ST6 7
#define ST8 9
#define ST10 11

typedef struct nodito{
    char empresa[ST10];
    unsigned int rol;
    short int mesQueTrab;
    struct nodito * sig;
}nodito;

typedef nodito * subLista;

typedef struct nodo{
    char idPersona[ST6];
    int rol;
    char fechaInicio[ST8];
    subLista sub;
    struct nodo * sig;
}nodo;

typedef nodo * TLista;

typedef struct {
    char idPersona[ST6], empresa[ST10];
    int rol; 
    char termino;
}TElementoA;

typedef struct nodoP{
    char empresa[ST10];
    int cantP;
    struct nodoP *ant, *sig;
}nodoP;

typedef nodoP * pNodoP;

typedef struct {
    pNodoP pri, ult;
}TListaD;


void actualizarConArch(TLista *L, char nom[20]);
void eliminar(TLista L, P[ST6],  E[ST10]);
void generarLD(TLista L, TListaD *LD);

void main(){
    TLista L;
    TListaD LD;
    char P[ST6], E[ST10];

    LD.pri = NULL;
    LD.ult = NULL;
    L = NULL;
    cargaL(&L);
    actualizarConArch(L, "FEBRERO.TXT");

    printf("Ingrese el id de una persona P \n");
    scanf("%s", P);

    printf("Ingrese el nombre de una empresa E\n");
    scanf("%s", E);

    eliminar(L,P,E);
    generarLD(L,&LD);
}

void actualizarConArch(TLista *L, char nom[20]){
    FILE *arch;
    TElementoA elem;
    TLista ant, act, nuevo;
    subLista sAnt, sAct, sNuevo;
    char mesAux[ST6];
    if ((arch = fopen(nom, "r")) == NULL)
        printf("No se pudo abrir el archivo.\n");
    else {
        sAnt = NULL;
        sACt = *L;
        while (fscanf(arch, "%s %s %d %c", elem.idPersona, elem.empresa, &elem.rol, &elem.termino) == 4){
            while (act != NULL && strcmp(act->idPersona, elem.idPersona) < 0){
                ant = act;
                act = act->sig;
            }
            
            if (strcmp(act->idPersona, elem.idPersona) == 0){
                if (elem.termino == 'N')
                    act->rol = elem.rol;
                else {
                    act->rol = 0;

                    strncpy(mesAux, act->fechaInicio, 6);

                    sNuevo = (subLista)malloc(sizeof(nodito));
                    sNuevo->rol = elem.rol;
                    strcpy(sNuevo->empresa, elem.empresa);
                    sNuevo->mesQueTrab = CANTM(mesAux, "202302");
                    sNuevo->sig = NULL;
                    strpcy(act->fechaInicio, "");

                    sAnt = NULL;
                    sAct = act->sub;
                    while (sAct != NULL && strcmp(sAct->empresa, sNuevo->empresa) <= 0){
                        sAnt = sAct;
                        sAct = sAct->sig;
                    }

                    if (sAnt == NULL){
                        sNuevo->sig = act->sub;
                        act->sub = sNuevo;
                    } else {
                        sAnt->sig = sNuevo;
                        sNuevo->sig = sAct;
                    }
                }
            } else {
                nuevo = (TLista)malloc(sizeof(nodo));
                nuevo->sub = NULL;
                strcpy(nuevo->idPersona, elem.idPersona);
                
                if (elem.termino == 'S'){
                    nuevo->rol = 0;
                    strpcy(nuevo->fechaInicio, "");

                    sNuevo = (subLista)malloc(sizeof(nodito));
                    sNuevo->rol = elem.rol;
                    strcpy(sNuevo->empresa, elem.empresa);
                    sNuevo->mesQueTrab = 0;
                    sNuevo->sig = NULL;
                    
                    nuevo->sub = sNuevo;
                } else {
                    nuevo->rol = elem.rol;
                    strcpy(nuevo->fechaInicio, "202302");
                }
            
                if (ant == NULL){
                    nuevo->sig = *L;
                    *L = nuevo;
                } else {
                    ant->sig = nuevo;
                    nuevo->sig = act;
                }
                ant = nuevo;
            }
        }
        fclose(arch);
    }
}

void eliminar(TLista L, P[ST6],  E[ST10]){
    TLista act = L;
    subLista sAnt, sAct, sElim;
    int cantElim = 0;

    while (act != NULL && strcmp(act->idPersona, P) != 0)
        act = act->sig;
    

    if (act != NULL && strcmp(act->idPersona, P) == 0){
        sAnt = NULL;
        sAct = act->sub;
        while (sAct != NULL && strcmp(sAct->empresa, E) <= 0){
            if (strcmp(sAct->empresa, E) == 0){
                cantElim++;

                sElim = sAct;
                sAct = sAct->sig;
                if (sElim == act->sub)
                    act->sub = sAct;
                else 
                    sAnt->sig = sAct;
                
                free(sElim);
            } else {
                sAnt = sAct;
                sAct = sAct->sig;
            }
        }
        if (cantElim)
            printf("La cantidad de participaciones concluidas en la empresa %s es %d\n", E, cantElim);
    } else 
        printf("La persona %s no existe \n", P);
}

void generarLD(TLista L, TListaD *LD){
    pNodoP nuevo, auxLD;
    TLista actL = L;
    subLista sAct;
    char empresaAct[ST10];
    while (actL != NULL){
        sAct = actL->sub;
        
        strcpy(empresaAct, sAct->empresa);
        while (sAct != NULL){
            if (sAct->empresa[0] == '#' && strcmp(empresaAct, sAct->empresa) != 0){
                strcpy(empresaAct, sAct->empresa);
                auxLD = (*LD).pri;
                while (auxLD != NULL && strcmp(auxLD->empresa, empresaAct) < 0)
                    auxLD = auxLD->sig;

                if (auxLD == NULL || strcmp(auxLD->empresa, empresaAct) != 0){
                    nuevo = (pNodoP)malloc(sizeof(nodoP));
                    nuevo->cantP = 1;
                    strcpy(nuevo->empresa, empresaAct);
                    nuevo->sig = NULL;
                    nuevo->ant = NULL;
                    
                    if ((*LD).pri == auxLD){
                        nuevo->sig = (*LD).pri;
                        (*LD).pri->ant = nuevo;
                        (*LD).pri = nuevo;
                        if ((*LD).ult == NULL)
                            (*LD).ult = nuevo;
                    } else if (NULL == auxLD){
                        nuevo->ant = (*LD).ult;
                        (*LD).ult->sig = nuevo;
                        (*LD).ult = nuevo;
                    } else {
                        nuevo->sig = auxLD;
                        nuevo->ant = auxLD->ant;
                        auxLD->ant->sig = nuevo;
                        auxLD->ant = nuevo;
                    }
                } else 
                    auxLD->cantP += 1;
            }
            
            sAct = sAct->sig;
        }
        actL = actL->sig;
    }
}