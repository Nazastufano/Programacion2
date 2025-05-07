#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TDACola.h"
/* La municipalidad de Mar del Plata gestiona las multas que hacen los agentes en el sistema de
estacionamiento medido de la siguiente forma:
Tiene una lista doblemente enlazada LD que representa los distintos agentes que realizan las multas en la
ciudad. Cada nodo representa a un agente, y posee los siguientes campos: Código (cadena de 5; la lista está
ordenada de forma descendente por este campo), Nombre y Apellido (Cadena de 30), Estudiante [S/N], y
además una sublista de multas realizadas con los siguientes datos para cada multa: patente (cadena de 7),
fecha juliana (cuenta los días desde el 1 de enero de un año no bisiesto; Ej: el 5 de febreo se representa con
el número 36) y hora (cadena de 5, por ejemplo: 17:30), tiempo abonado (en horas y minutos, dos enteros
positivos); tiempo real de ocupación (en horas y minutos, dos enteros positivos). La sublista se encuentra
ordenada por patente.
Se pide desarrollar un programa en lenguaje C, modularizzado y utilizando TDA cuando corresponda que:
i) resuelva:
    a) En base a una cola C, donde se encuentran todos los vehiculos que fueron relevados por los distintos
    agentes, actualizar la lista doblemente enlazada con las multas que correspondan (cuando el tiempo
    abonado es menor al tiempo real de ocupación) para infracciones cometidas en septiembre (el resto
    debe quedar en la cola, en el mismo orden que tenían). Cada elemento de C contiene: CódigoAgente,
    Patente, FechaMulta (en formato juliano), HoraMulta (cadena de 5), Tiempo pagado (en minutos), Tiempo
    real de ocupación (en minutos).
    b) Generar un archivo binario MULTAS.DAT con las multas que realizó el agente AG en los meses pares,
    antes de las 12:00 y despues de las 18:00 hs. En este mismo proceso se tiene que corroborar e informar si
    al agente le corresponde la bonificación de 15%. [La bonificación le corresponde a un agente, si es
    estudiante y si tiene más de K multas] (K y AG son datos)
    c) Eliminar de la lista doble, todas las multas realizadas por el agente X, de las patentes que empiecen con
    "AF", eliminar el agente si queda sin multas. (X, es dato y podría no existir)
ii) incluyendo el main() completo que relice las invocaciones a los subprogramas definidos en i) además de las
operaciones de inicialización de estructuras necesarias, e invocación a funciones de carga ed las mismas (que
no debe desarrollar).
iii) defina el tipo de la cola dinámica utilizando en el programa. Desarrollar SacaC(). Indicar en qué archivo/s
iría cada definición/desarrollo. */

typedef struct nodito{
    char patente[8]; //ordenada por este campo
    int fechaJuliana;
    char hora[6];
    unsigned int tiempoAbonado[2];
    unsigned int tiempoRealOcu[2];
    struct nodito * sig;
}nodito;

typedef nodito * subLista;

typedef struct nodoD{
    char codigo[6]; //ordenada por este campo mayor->menor
    char nomYApe[31];
    char estudiante;
    subLista multas;
    struct nodoD *ant, *sig;
}nodoD;

typedef nodoD * pNodoD;

typedef struct {
    pNodoD pri, ult;
} TListaD;

void actualizaLD(TListaD *LD, TCola *C);
void generarArchivoB(TListaD LD, char AG[6], int K, char nomArch[20]);
void eliminarMultas(TListaD *LD, char X[6]);
int mesPar(int fechaJuliana);
int horaCorrecta(char hora[6]);

void main(){
    TListaD LD;
    TCola C;
    char AG[6], X[6];
    int K;
    LD.pri = NULL;
    LD.ult = NULL;
    
    //cargaLD(&LD);
    iniciaC(&C);
    //cargaC(&C);
    actualizaLD(&LD, &C);
    
    printf("Ingrese el codigo de un agente para buscar\n");
    scanf("%s", AG);
    
    printf("Ingrese una cantidad de multas a superar\n");
    scanf("%d", &K);
    
    generarArchivoB(LD, AG, K, "MULTAS.DAT");

    printf("Ingrese un agente para buscar: \n");
    scanf("%s", X);

    eliminarMultas(&LD, X);
}


void actualizaLD(TListaD *LD, TCola *C){
    pNodoD aux;
    TElementoC valorImposible, elem;
    subLista sAux;
    if ((*LD).pri != NULL){
        strcpy(valorImposible.codigoAgente, "abcde");
        poneC(C, valorImposible);
        sacaC(C, &elem);

        while (strcmp(elem.codigoAgente, valorImposible.codigoAgente) != 0){
            aux = (*LD).pri;
            if (elem.tiempoPagado<elem.tiempoRealOcupacion && elem.fechaJuliana>243 && elem.fechaJuliana <=273){
                while (aux != NULL && strcmp(aux->codigo, elem.codigoAgente) < 0) //aux != NULL?????
                    aux = aux->sig;
                
                if (aux != NULL && strcmp(aux->codigo, elem.codigoAgente) == 0){
                    sAux = aux->multas;
                    while (sAux != NULL && strcmp(elem.patente, sAux->patente) > 0)
                        sAux = sAux->sig;
                    
                    if (sAux != NULL && strcmp(elem.patente, sAux->patente) == 0){
                        sAux->fechaJuliana = elem.fechaJuliana;
                        
                        strcpy(sAux->hora, elem.horaMulta);
                        
                        sAux->tiempoAbonado[0] = elem.tiempoPagado / 60;
                        sAux->tiempoAbonado[1] = elem.tiempoPagado % 60;

                        sAux->tiempoRealOcu[0] = elem.tiempoRealOcupacion / 60;
                        sAux->tiempoRealOcu[1] = elem.tiempoRealOcupacion % 60;
                    }
                }
            } else
                poneC(C, elem);

            sacaC(C, &elem);
        }
    }    
}

void generarArchivoB(TListaD LD, char AG[6], int K, char nomArch[20]){
    pNodoD aux = LD.pri;
    subLista sAux;
    FILE* archB;
    subLista elem;
    int contMultas = 0;
    if ((archB = fopen(nomArch, "wb")) == NULL)
        printf("El archivo no se pudo abrir. Es posible que no exista\n");
    else {
        while (aux != NULL && strcmp(AG, aux->codigo) != 0)
            aux = aux->sig;
        
        if (aux != NULL && strcmp(AG, aux->codigo) == 0){
            sAux = aux->multas;
            while (sAux != NULL){
                if (mesPar(sAux->fechaJuliana) && horaCorrecta(sAux->hora))
                    contMultas++;
                
                sAux = sAux->sig;
            }
            if (contMultas > K && aux->estudiante == 'S')
                printf("Al agente %s le corresponde la bonificacion del 15%c\n", AG, '%');
            else
                printf("Al agente %s no le corresponde la bonificacion del 15%c\n", AG, '%');
        }
    }
}

void eliminarMultas(TListaD *LD, char X[6]){
    pNodoD aux = (*LD).pri, elim;
    subLista sAnt, sAct, sElim;

    while (aux != NULL && strcmp(X, aux->codigo) < 0)
        aux = aux->sig;
    
    if (aux != NULL && strcmp(X, aux->codigo) == 0){
        sAct = aux->multas;
        sAnt = NULL;
        while (sAct != NULL){
            if (sAct->patente[0] == 'A' && sAct->patente[1] == 'F'){
                sElim = sAct;
                if (sAnt == NULL)
                    aux->multas = aux->multas->sig;
                else
                    sAnt->sig = sAct->sig;
                
                sAct = sAct->sig;
                free(sElim);
            } else {
                sAnt = sAct;
                sAct = sAct->sig;
            }
        }
        if (aux->multas == NULL){
            elim = aux;
            
            if (elim == (*LD).pri){
                (*LD).pri = (*LD).pri->sig;
                (*LD).pri->ant = NULL;
            } else if (elim == (*LD).ult){
                (*LD).ult = (*LD).ult->ant;
                (*LD).ult->sig = NULL;
            } else {
                aux->ant->sig = aux->sig;
                aux->sig->ant = aux->ant;
            }

            free(elim);
        }
        
    }
    
    
}

int mesPar(int fechaJuliana){
    if (31> fechaJuliana && fechaJuliana<=59 || 90 >fechaJuliana && fechaJuliana<= 120 || 151>fechaJuliana && fechaJuliana<= 181 || 212< fechaJuliana&& fechaJuliana<=243 || 273>fechaJuliana && fechaJuliana<=304 || 334>fechaJuliana && fechaJuliana<=365)
        return 1;
    else 
        return 0;
}

int horaCorrecta(char hora[6]){
    if (strcmp(hora, "12:00") <= 0 || strcmp(hora, "18:00") >= 0)
        return 1;
    else
        return 0;
}