#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 4. Desarrollar un programa que gestione las reservas de pasajes para los vuelos de una aerolínea. 
Para ello se cuenta con una lista de destinos con la siguiente estructura: 
    • Destino 
    • Sublista ordenada de Vuelos (a dicho destino) 
        o Código de vuelo 
        o Fecha y horario de salida 
        o Capacidad de pasajeros 
        o Sublista de pasajes vendidos (para dicho vuelo) 
             Documento del pasajero 

Tanto para la reserva como para su cancelación se solicita: destino, código de vuelo y 
documento del pasajero. El programa debe además permitir agregar destinos y vuelos. Cada 
vuelo tiene una fecha y horario de salida y capacidad de pasajeros. El programa debe también 
listar el estado (cantidad de reservas, lugares disponibles, etc.) de todos los vuelos de un 
destino solicitado al operador. 

NOTA: Dado que no se requieren cálculos con las fechas y horarios de salida, se sugiere almacenar dicho campo 
como una cadena. */
typedef struct noditoPV{
    int documentoPas;
    struct noditoPV * sig;
}noditoPV;

typedef noditoPV * subListaPV;

typedef struct noditoV{
    int codVuelo;
    char fechaYHoraSalida[20];
    int capacidad;
    subListaPV subPasajesVen;
    struct noditoV * sig;
}noditoV;

typedef noditoV * subListaV;

typedef struct nodo{
    char destino[20];
    subListaV subVuelos;
    struct nodo * sig;
}nodo;

typedef nodo * TLista;

void reserva(TLista *L, char destino[20], int codVuelo, int documento);
void cancelar(TLista *L, char destino[20], int codVuelo, int documento);
void agregarVuelo(TLista *L, char destino[20], int codVuelo, char fechaHora[20], int capacidad);
void agregarDestino(TLista *L, char destino[20]);
void listarEstado(TLista L, char destino[20]);

void main(){

}

void reserva(TLista *L, char destino[20], int codVuelo, int documento){
    TLista aux = *L;
    subListaV sAuxV;
    subListaPV sAuxPV, sAntPV = NULL, nuevaRes;
    int cantPV = 0;
    if (aux != NULL){
        while (aux != NULL && strcmp(destino, aux->destino) != 0)
            aux = aux->sig;
        
        if (aux != NULL){
            sAuxV = aux->subVuelos;
            while (sAuxV != NULL && sAuxV->codVuelo < codVuelo)
                sAuxV = sAuxV->sig;
            
            if (sAuxV != NULL && sAuxV->codVuelo == codVuelo){
                sAuxPV = sAuxV->subPasajesVen;
                while (sAuxPV != NULL){
                    sAntPV = sAuxPV;
                    sAuxPV = sAuxPV->sig;
                    cantPV++;
                }
                
                if (sAntPV == NULL || cantPV < sAuxV->capacidad){
                    nuevaRes = (subListaPV)malloc(sizeof(noditoPV));
                    nuevaRes->documentoPas = documento;
                    nuevaRes->sig = NULL;
                    
                    if (sAntPV == NULL)
                        sAuxV->subPasajesVen = nuevaRes;
                    else
                        sAntPV->sig = nuevaRes;
                }
            }
        }
    }    
}

void cancelar(TLista *L, char destino[20], int codVuelo, int documento){
    TLista aux = *L;
    subListaV sAuxV;
    subListaPV sAuxPV, sAntPV = NULL, sElimPV;
    if (aux != NULL){
        while (aux != NULL && strcmp(destino, aux->destino) != 0)
            aux = aux->sig;
        
        if (aux != NULL){
            sAuxV = aux->subVuelos;
            while (sAuxV != NULL && sAuxV->codVuelo < codVuelo)
                sAuxV = sAuxV->sig;
            
            if (sAuxV != NULL && sAuxV->codVuelo == codVuelo){
                sAuxPV = sAuxV->subPasajesVen;
                
                while (sAuxPV != NULL && sAuxPV->documentoPas != documento){
                    sAntPV = sAuxPV;
                    sAuxPV = sAuxPV->sig;
                }

                if (sAuxPV != NULL && sAuxPV->documentoPas == documento){
                    sElimPV = sAuxPV;
                    if (sAntPV == NULL)
                        sAuxV->subPasajesVen = NULL;
                    else
                        sAntPV->sig = sAuxPV->sig;
                    free(sElimPV);
                }
            }
        }
    }
}

void agregarVuelo(TLista *L, char destino[20], int codVuelo, char fechaHora[20], int capacidad){
    TLista aux = *L, ant = NULL, nuevo;
    subListaV nuevoV, sAntV = NULL, sActV;

    if (aux != NULL){        
        while (aux != NULL && strcmp(destino, aux->destino) != 0){ //busco destino
            ant = aux;
            aux = aux->sig;
        }
        
        if (aux != NULL){ //lo encontré    
            nuevoV = (subListaV)malloc(sizeof(noditoV));
            nuevoV->codVuelo = codVuelo;
            nuevoV->capacidad = capacidad;
            strcpy(nuevoV->fechaYHoraSalida, fechaHora);
            nuevoV->subPasajesVen = NULL;

            sActV = aux->subVuelos;

            while (sActV != NULL && codVuelo < sActV->codVuelo){
                sAntV = sActV;
                sActV = sActV->sig;
            }

            if (sAntV == NULL){
                nuevoV->sig = aux->subVuelos;
                aux->subVuelos = nuevoV;
            } else {
                sAntV->sig = nuevoV;
                nuevoV->sig = sActV->sig;
            }
        }
    }
}

void agregarDestino(TLista *L, char destino[20]){
    TLista aux = *L, nuevo, ant = NULL;
    
    nuevo = (TLista)malloc(sizeof(nodo));
    strcpy(nuevo->destino, destino);
    nuevo->subVuelos = NULL;

    while (aux != NULL){
        ant = aux;
        aux = aux->sig;
    }
    
    if (ant == NULL){
        nuevo->sig = *L;
        *L = nuevo;
    } else {
        ant->sig = nuevo;
        nuevo->sig = aux;
    }
}

void listarEstado(TLista L, char destino[20]){
    TLista aux = L, ant = NULL;
    subListaPV sAuxPV;
    subListaV sAuxV;
    int contPV;
    while (aux != NULL && strcmp(aux->destino, destino) != 0){
        ant = aux;
        aux = aux->sig;
    }
    if (aux != NULL){
        sAuxV = aux->subVuelos;
        while (sAuxV != NULL){
            sAuxPV = sAuxV->subPasajesVen;
            contPV = 0;
            while (sAuxPV != NULL){
                contPV++;
                sAuxPV = sAuxPV->sig;
            }
            printf("La cantidad de reservas es: %d y los lugares disponibles son: %d\n", contPV, sAuxV->capacidad-contPV);
        }
    } else 
        printf("El destino ingresado no se encuentra disponible\n");
}