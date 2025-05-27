#include "TDACola.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/* Una planta de VTV de automóviles gestiona sus turnos mediante una lista simple LT, donde cada nodo
corresponde a un turno solicitado y contiene los siguientes datos: dominio del vehículo (cadena de 7,
oredenado), fecha del turno (cadena de 8, formato AAAAMMDD), hora (cadena de 5, formato 24horas
HH:MM)
Además, se tiene en una lista doble PA con los puestos de atención (no es dato la cantidad de puestos), un
nodo por puesto, con la siguiente estructura: puesto (cadena de 3), sublista de automóviles asignadas al
puesto; para cada automóvil: dominio, cantidad de obvservaciones encontradas.
Una cola C registra los automóviles que van arribando a la planta, cada elemento de la cola es un dominio.
Se puede, resolver en lenguaje C:
i) utilizando los operadores del TDA Cola, mediante un subprograma por cada ítem resuelva:
    a) Eliminar de LT, los turnos incorrectos. Un turno es incorrecto si el último número del dominio no
    coinicide con el número del mes del turno, considerando que en octubre se atienden los dominios
    finalizados en 0, y en noviembre y diciembre se acepta cualquier dominio. Los dominio no pueden tener el
    formato actual (AA999AA) o el anterior (AAA999). Finalmente, informar el porcentaje de turnos depurados
    (considerando el total de turnos asignados).
    b) Simular la atención de los automóviles de C para el mes de abril, verificando que posean turno, y
    asignado a algún puesto aleatoriamente (utilizar la función rand() de stdlib.h de la siguiente manera:
    rand() % N + 1, siendo N cantidad de puestos, dará la posición del puesto en PA) Cada automóvil a
    atender deberá insertarse al final de la sublista correspondiente. Los dominios de C que tengan turno para
    otro mes quedarán en la cola. Listar los dominios de los autos rechazados por no tener turno.
    c) Se tiene un archivo de texto TESTEOS.TXT (no ordenado por nigún criterio) con los automóviles
    observados y rechazados por los puestos de atención, en cada línea la siguiente información: Puesto,
    Dominio, Cantidad de observaciones, Estado([O]bservado,[R]echazado). Eliminar de la sublista del puesto
    que corresponda, cada automóvil rechazado y completar la cantidad de observaciones para los 
    observados.
ii) escribir el main() completo que realice las invocaciones a los subprogramas definidos en i) además de las
operaciones de inicialización de estructuras necesarias, e invocación a funciones de carga de las mismas (que
no debe desarrollar).
iii) definir el tipo de la cola estática utilizado en el prorama. Desarrollar SacaC(). Indicar en qué archivo/s iría
cada definición/desarrollo. */

typedef struct nodo{
    char dominioVeh[8];//ordenado por este criterio
    char fechaTurno[9];
    char hora[6];
    struct nodo * sig;
}nodo;

typedef nodo * TLista;

typedef struct nodito{
    char dominio[8];
    int cantObserva;
    struct nodito * sig;
}nodito;

typedef nodito * subLista;

typedef struct nodoD{
    char puesto[4];
    subLista autosPorPuesto;
    struct nodoD *ant, *sig;
}nodoD;

typedef nodoD * pNodoD;

typedef struct {
    pNodoD pri, ult;
}TListaD;

int verificarDom(TLista act);
void eliminarIncorrectos(TLista *LT);
void atencionAutos(TListaD *PA, TLista LT, TCola *C);
void analisisArch(TListaD *PA, char nomArch[20]);

void main(){
    TLista LT;
    TListaD PA;
    TCola C;
    LT = NULL;
    PA.pri = NULL;
    PA.ult = NULL;
    //cargaLT(&L);
    //cargaPA(&PA);
    //cargaC(&C);

    eliminarIncorrectos(&LT);
    atencionAutos(&PA,LT,&C);
    analisisArch(&PA, "TESTEOS.TXT");   
}


void eliminarIncorrectos(TLista *LT){
    TLista act = *LT, ant = NULL, elim;
    int contTA = 0, contTD = 0;
    if (*LT != NULL){
        while (act != NULL){
            contTA++;
            if (verificarDom(act)){
                contTD++;
                elim = act;
                act = act->sig;
                if (ant == NULL)
                   *LT = (*LT)->sig;
                else
                    ant->sig = act;
                free(elim);
            } else {
                ant = act;
                act = act->sig;
            }
        }
        printf("El porcentaje de turnos depurados es: %.2f%%", (float)contTD*100/contTA);
    }
}


int verificarDom(TLista act){
    if (act->dominioVeh[5] != act->fechaTurno[5] || act->dominioVeh[4] != act->fechaTurno[5] && (act->fechaTurno[4] == '1' && act->fechaTurno[5] == '0'))
        return 1;
    else
        return 0;
}

void atencionAutos(TListaD *PA, TLista LT, TCola *C){
    pNodoD auxLD;
    TLista auxL = LT;
    TElementoC elem, centinela;
    subLista sAct, sAnt, nuevo;
    int N = 0, puesto, posNodo;
    
    if (PA->pri != NULL){
        auxLD = PA->pri;
        while (auxLD != NULL){
            N++;
            auxLD == auxLD->sig;
        }

        strcpy(centinela.dominio, "9999999");
        poneC(C,centinela);
        sacaC(C,&elem);
        while (strcpy(centinela.dominio, elem.dominio) != 0){
            auxL = LT;
            while (auxL != NULL && strcmp(auxL->dominioVeh, elem.dominio) < 0)
                auxL = auxL->sig;
            
            if (auxL != NULL && strcmp(auxL->dominioVeh, elem.dominio) == 0 && auxL->fechaTurno[5] == '4'){
                puesto = rand() % N + 1;
                auxLD =PA->pri;

                while (posNodo < puesto){
                    posNodo++;
                    auxLD = auxLD->sig;
                }
                
                sAnt = NULL;
                sAct = auxLD->autosPorPuesto;
                while (sAct != NULL && strcmp(sAct->dominio, elem.dominio) != 0){
                    sAnt = sAct;
                    sAnt = sAct->sig;
                }

                if (strcmp(sAct->dominio, elem.dominio) == 0)
                    sAct->cantObserva++;
                else {
                    nuevo = (subLista)malloc(sizeof(nodito));
                    strcpy(nuevo->dominio, elem.dominio);
                    nuevo->cantObserva=1;
                    nuevo->sig = NULL;
                    if (sAct == NULL)
                        auxLD->autosPorPuesto = nuevo;
                    else 
                        sAnt->sig = nuevo;
                }
            } else if (strcmp(auxL->dominioVeh, elem.dominio) == 0 && auxL->fechaTurno[5] != '4')
                poneC(C,elem);
            else 
                printf("El automovil %s fue rechazado por no tener turno \n", elem.dominio);
            
            sacaC(C, &elem);
        }
    }
}
void analisisArch(TListaD *PA, char nomArch[20]){
    subLista sAct, sAnt, sElim;
    pNodoD auxLD;
    FILE* arch;
    char puesto[4], dominio[9], estado, aux;
    int cantObser;
    if (PA->pri != NULL){
        if ((arch = fopen(nomArch, "r")) == NULL)
            printf("No se pudo abrir el archivo. Es posible que no exista\n");
        else {
            while (fscanf(arch,"%s %s %d%c%c",puesto,dominio, cantObser, &aux, &estado) == 5){
                auxLD = PA->pri;
                while (auxLD != NULL && strcmp(auxLD->puesto, puesto) != 0)
                    auxLD = auxLD->sig;
                
                if (auxLD != NULL && strcmp(auxLD->puesto, puesto) == 0){
                    sAnt = NULL;
                    sAct = auxLD->autosPorPuesto;
                    while (sAct != NULL && strcmp(sAct->dominio, dominio) != 0){
                        sAnt = sAct;
                        sAct = sAct->sig;
                    }
                    if (sAct != NULL && strcmp(sAct->dominio, dominio) == 0){
                        if (estado = 'O'){
                            sAct->cantObserva += cantObser;
                        } else {
                            sElim = sAct;
                            if (sAnt == NULL)
                                auxLD->autosPorPuesto =auxLD->autosPorPuesto->sig;
                            else
                                sAnt->sig = sAct->sig;
                            free(sElim);
                        }                        
                    }
                }
            }
            fclose(arch);
        }
    }
}