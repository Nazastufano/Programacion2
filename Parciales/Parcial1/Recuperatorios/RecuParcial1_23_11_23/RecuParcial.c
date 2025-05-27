#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TDACola.h"
/* Una distribuidora de autopartes maneja una lista circular de puestos de preparación de pedidos con la siguiente
estructura:
        Id Puesto (1..100, ordenado, no se repite).
        Nombre Preparador (Cadena de hasta 30 caracteres).
        Cantidad total de productos solicitados (pendientes a despachar)
        Sublista de productos
            Código de producto (cadena de 7, no se puede repetir)
            Destinatario (1..200, puede repetirse en distintos puestos).
            Cantidad de productos solicitados
            Cantidad de productos enviados (inicialmente en cero).
Los pedidos se preparan con un conjunto de robots que traen las estanterías hasta los preparadores. Esto se
representa con una lista simplemente enlazada de robots y las estanterías con una cola de productos. La estructura
de la lista es la siguiente:
        Id Robot (numérico)
        Id Puesto (numérico)
        Cola de productos de la estantería
            Código de producto (cadena de 7, Ordenado, no se repite)
            Cantidad disponible
        
Se pide, resolver en en lenguaje C:
i) utilizando los operadores del TDA Cola, mediante un subprograma por cada ítem resuelva:
    a) Se tiene un archivo de texto PEDIDO.TXT (no ordenado por ningún criterio), en cada línea la siguiente
    información: Id Puesto, NombrePreaparador, CantidadProductos, y para cada uno: destinatario, CódigoProducto,
    CantidadProducto.
        En el siguiente ejemplo se tienen los datos del puesto 10, con el preparador "Juan" y con 3 productos a preparar que
        son: 4 unidades del producto "XA0D001" para el destinatario 110, 1 unidad del producto "X000ART" para el
        destinatario 10 y 7 unidades del producto "AMORT02" para el destinatario 70.
        10 Juan 3 110 XA0D001 4 10 x000ART 1 70 AMORT02 7
    Utilizar este archivo para actualizar la lista de puestos, algunos de los cuales podrían ya existir con sublistas vacías.
    b) Simular la preparación de los pedidos analizando los elementos de las colas, y con cada robot, buscar el puesto
    en la lista. Luego actalizar en la sublista, para el producto correspondiente, las cantidades de productos enviados
    hasta igualar la de productos solicitados utilizando la cantidad disponible de la cola (quedarán en la cola
    solamente productos con disponibilidad).
    c) Dado un código de producto, eliminarlo de todos los puestos con número menor a X (X dato).
ii) escribir el main() completo que realice las invocaciones a los subprogramas definidos en i) además
de las operaciones de inicialización de estructuras necesarias, e invocación a funciones de carga de las mismas (que
no debe desarrollar).
iii) definir el tipo de la cola estática utilizado en el programa. Desarrollar VaciaC() y SacaC(), Indicar en qué archivo/s
iría cada definición/desarrollo. */

typedef struct nodito{
    char codProd[8];
    int destinatario;
    int cantProdSoli;
    int cantProdEnvi;
    struct nodito * sig;
}nodito;

typedef nodito * subLista;

typedef struct nodoC{
    int idPuesto;
    char NombrePrep[31];
    int cantTotalPro;
    subLista sub;
    struct nodoC *sig;
}nodoC;

typedef nodoC * TListaC;

typedef struct nodo{
    int idRobot;
    int idPuesto;
    TCola C;
    struct nodo * sig;
}nodo;

typedef nodo * TLista;

void actualizarConArch(TListaC *LC, char nomArch[20]);
void preparacionPedido(TLista L, TListaC LC);
void eliminarPuestos(TListaC LC, char codProd[8], int X);

void main(){
    TLista L;
    TListaC LC;
    char codProd[8];
    int X;

    //cargaL(&L);
    //cargaLC(&LC);
    actualizarConArch(&LC, "PEDIDOS.TXT");
    preparacionPedido(L, LC);
    
    printf("Ingrese un codigo de producto \n");
    scanf("%s", codProd);
    printf("Ingrese un numero para eliminar de todos los puestos dicho producto \n");
    scanf("%d", &X);
    eliminarPuestos(LC, codProd, X);
}

void actualizarConArch(TListaC *LC, char nomArch[20]){
    TListaC act, ant, nuevo;
    subLista sAct, sAnt, sNuevo;
    FILE *arch;
    char nomPrep[31], codProd[8];
    int i, idPuesto, cantProductos, cantProducto, destinatario;
    

    if ((*LC) != NULL){
        if ((arch = fopen(nomArch, "r"))==NULL)
            printf("No se pudo abrir el archivo. Es posible que no exista\n");
        else {
            while (fscanf(arch, "%d %s %d", &idPuesto, nomPrep, &cantProductos) == 3){
                act = (*LC)->sig;
                ant = *LC;
                for (i = 0; i < cantProductos; i++){
                    fscanf(arch, "%d %s %d", &destinatario, codProd, &cantProducto);
                    
                    while (act != *LC && idPuesto > act->idPuesto){
                        ant = act;
                        act = act->sig;
                    }
                        
                    if (idPuesto==act->idPuesto){
                        sAnt = NULL;
                        sAct = act->sub;
                        
                        while (sAct != NULL && destinatario != sAct->destinatario && strcmp(sAct->codProd, codProd) != 0){
                            sAnt = sAct;
                            sAct = sAct->sig;
                        }

                        if (sAct == NULL){
                            sNuevo = (subLista)malloc(sizeof(nodito));
                            sNuevo->cantProdEnvi = 0;
                            sNuevo->cantProdSoli = cantProducto;
                            sNuevo->destinatario = destinatario;
                            strcpy(sNuevo->codProd, codProd);
                            sNuevo->sig = NULL;

                            if (sAnt == NULL)
                                act->sub = sNuevo;
                            else
                                sAnt->sig = sNuevo;                   
                        } else if (destinatario == sAct->destinatario && strcmp(sAct->codProd, codProd) == 0)
                            sAct->cantProdSoli += cantProducto;
                            
                        
                        act->cantTotalPro += cantProducto;
                    } else {
                        nuevo = (TListaC)malloc(sizeof(nodoC));
                        nuevo->cantTotalPro = cantProducto;
                        nuevo->idPuesto=idPuesto;
                        strcpy(nuevo->NombrePrep, nomPrep);
                        
                        sNuevo = (subLista)malloc(sizeof(nodito));
                        sNuevo->cantProdEnvi= 0;
                        sNuevo->cantProdSoli= cantProducto;
                        strcpy(sNuevo->codProd, codProd);
                        sNuevo->destinatario=destinatario;
                        sNuevo->sig= NULL;

                        nuevo->sub = sNuevo;

                        if (act == *LC){
                            ant->sig = nuevo;
                            *LC = nuevo;
                        } else{
                            ant->sig = nuevo;
                            nuevo->sig = act;
                        }
                    }
                }
            }
            fclose(arch);
        }
    }
}

void preparacionPedido(TLista L, TListaC LC){
    TLista auxL;
    TListaC auxLC;
    subLista sAct;
    TElementoC centinela, elem;
    int auxiliar = 0;
    if (LC != NULL){
        auxL = L;
        while (auxL != NULL){
            auxLC = LC->sig;
            while (auxLC != LC && auxL->idPuesto > auxLC->idPuesto)
                auxLC = auxLC->sig;
                
            if (auxL->idPuesto == auxLC->idPuesto){
                strcpy(centinela.codProd, "9999999");
                poneC(&(L->C), centinela);
                sacaC(&(L->C), &elem);

                while (elem.codProd != centinela.codProd){
                    sAct = auxLC->sub;
    
                    while (sAct != NULL && elem.cantDispo != 0){
                        if (strcmp(sAct->codProd, elem.codProd) == 0){  
                            if (sAct->cantProdSoli<=elem.cantDispo){
                                elem.cantDispo -= sAct->cantProdSoli;
                                sAct->cantProdEnvi = sAct->cantProdSoli;
                                sAct->cantProdSoli = 0;
                            } else {
                                sAct->cantProdEnvi += elem.cantDispo;
                                sAct->cantProdSoli -= elem.cantDispo;
                                elem.cantDispo = 0;
                            }
                        }
                        sAct = sAct->sig;
                    }
                    if (elem.cantDispo)
                        poneC(&(L->C), elem);
                    
                    sacaC(&(L->C), &elem);
                }
            }    
            auxL = auxL->sig;
        }   
    }
}

void eliminarPuestos(TListaC LC, char codProd[8], int X){
    TListaC act;
    subLista sAct, sAnt, sElim;
    
    if (LC != NULL){
        act = LC->sig;
    
        do {
            sAct = act->sub;
            sAnt = NULL;
            while (sAct != NULL){
                if (strcmp(sAct->codProd, codProd) == 0){
                    sElim = sAct;
                    sAct = sAct->sig;
                    
                    if (sAnt == NULL)
                        act->sub = sAct;
                    else
                        sAnt->sig = sAct;
                    free(sElim);
                } else {
                    sAnt = sAct;
                    sAct = sAct->sig;
                }
            }
            act = act->sig;
        } while (act != (LC)->sig && act->idPuesto < X);
    }
}