#include <stdio.h>
#include "TDAPila.h"
/* Ej 2) Un hotel con 20 habitaciones cuenta con una lista L que mantiene las reservas ya confirmadas del
mes de juli conteniendo en cada nodo: Habitaciones(1..20) (ordenada, no se repite), Capacidad, Precio
por persona, Sublista de reservas confirmadas: en cada nodo contiene IdClienteResp (Cadena de 8),
Ocupantes (>0), Dia entrada (1 a 30) (ordenada), Dia salida (2 a 31)

A) Desarrollar en C subprogramas para:
j) A partir del recorrido de la lista L, generar una matriz M de 20x31 quee contenga en cada posición, la
cantidad de huéspedes confirmados. A partir del recorrido recursivo de M, informar la cantidad de
habitaciones que estarán ocupadas todos los días de las vacaciones de invierno (17 a 28 de julio)
ii) En una Pila P se tienen los números de habitación y los días en que ciertas habitiaciones deberán
clausurarse por una filtración de humedad. Utilizando el TDA Pila, y considerando que en cada elemento
se tiene H (no se repite en P), D, C siendo H la habitación, D día de inicio, C cant de días consecutivos
(puede exceder el mes de julio) se pide mediante un único recorrido de L:
    -   eliminar de L todas las reservas de las habitaciones que se vean afectadas en al menos un día
        según los datos de P;
    -   hallar y mostrar cuánto dinero le cuesta al hotel la baja de estas reservas de Julio;
    NOTAS: P puede perderse. No eliminar habitaciones de L
B) Definir el tipo de P asumiendo que es estática. Desarrollar SacaP(). Indicar en qué archivo(s) se
encuentran estas definiciones.

*/

#define ST8 9
#define MAXI 20
#define MAXJ 31
typedef struct nodito{
    char idClienteResp[ST8];
    unsigned int ocupantes;
    int diaEntrada, diaSalida;
    struct nodito * sig;
}nodito;

typedef nodito * subLista;

typedef struct nodo{
    int habitacion;
    int capacidad;
    float precioPP;
    subLista sub;
    struct nodo *sig;
}nodo;

typedef nodo * TLista;

void main(){
    TLista L;
    TPila P;
    int M[MAXI][MAXJ];
    
    iniciaP(&P);
    L = NULL;
    cargarP(&P);
    inicializarMat(M);
    generarMat(L,M);
    printf("La cantidad de habitaciones que estaran ocupadas todos los dias de las vacaciones de invierno son: %d \n", cantHOcup(M,0,0));
}


void generarMat(TLista L, int M[MAXI][MAXJ]){
    TLista aux = L;
    subLista sAux;
    int j;
    while (aux != NULL){
        sAux = aux->sub;
        while (sAux != NULL){
            for (j = sAux->diaEntrada-1; j < sAux->diaSalida; j++)
                M[aux->habitacion-1][j] = sAux->ocupantes;
            
            sAux = sAux->sig;
        }

        aux = aux->sig;
    }
}

int cantHOcup(int M[MAXI][MAXJ], int i, int j){    
    if (i<MAXI){
        if (M[i][j] != 0)
            if (j<27)
                return cantHOcup(M, i,j+1);
            else 
                return 1 + cantHOcup(M, i+1,16);
        else
            return cantHOcup(M, i+1,16);
    } else
        return 0;
}


void eliminarSubL(TLista L, TPila *P){
    TLista aux = L;
    subLista sAnt, sAct, sElim;
    TPila PAux;
    TElementoP elem;
    int esta;
    float acumPrecio = 0;
    iniciaP(&PAux);

    while (aux != NULL && !vacia(*P)){
        esta = 0;
        do{
            sacaP(P, &elem);
            if (elem.H == aux->habitacion){
                esta = 1;    
                sAnt = NULL;
                sAct = aux->sub;
                while (sAct != NULL){
                    if (sAct->diaEntrada <= elem.D && (elem.D+elem.C<=sAct->diaSalida || elem.D+elem.C>31)){
                        acumPrecio += sAct->ocupantes*aux->precioPP;    

                        sElim = sAct;
                        sAct = sAct->sig;
                        if (sAnt == NULL)
                            aux->sub = sAct;
                        else
                            sAnt->sig = sAct;
                        free(sElim);
                    } else {
                        sAnt = sAct;
                        sAct = sAct->sig;
                    }
                }
            } else
                poneP(&PAux, elem);
        } while (!vaciaP(*P) && !esta);
            
        while (!vaciaP(PAux)){
            sacaP(&PAux, &elem);
            poneP(P,elem);
        }

        aux = aux->sig;
    }
        printf("El dinero que le cuesta al hotel la baja de las reservas de Julio es %.2f \n", acumPrecio);
}