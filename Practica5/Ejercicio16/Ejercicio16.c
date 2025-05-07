#include <stdio.h>
#include "TDACola.h"
#include "TDAPila.h"
/* 16. Simular un juego de naipes donde N jugadores van tomando un naipe del mazo por turno. El
juego finaliza cuando el mazo queda vacío. El puntaje de cada jugador consiste en la sumatoria
de los números de los naipes que fue tomando. Si el palo del naipe tomado coincide con el palo
del levantado en el turno anterior el número se duplica. Implementar utilizando las estructuras
(pilas y/o colas) que considere necesarias. */

void cargaP(TPila *P, int);
void cargaC(TCola *C, int);
void juego(TCola *C, TPila *P);
void mostrarPuntaje(TCola *C);
void main(){
    TPila P;
    TCola C;
    int N;
    do{
        printf("Cuantos jugadores son?\n");
        scanf("%d", &N);
    } while (N<0 || N>5);
    iniciaC(&C);
    iniciaP(&P);
    cargaP(&P, N);
    cargaC(&C, N);
    juego(&C,&P);
    mostrarPuntaje(&C);
}

void cargaP(TPila *P, int N){
    TElementoP elem;
    int i, rondas;
    do{
        printf("Cuantas rondas desea jugar?\n");
        scanf("%d", &rondas);
    } while (rondas<0 || rondas > 48/N);
    
    for (i = 0; i < N*rondas; i++){
        do{
            printf("Ingrese el palo de la carta ('b', 'e', 'o', 'c')\n");
            scanf(" %c", &elem.palo);
            
        } while (elem.palo != 'b' && elem.palo != 'e' && elem.palo != 'o' && elem.palo != 'c');
        
        do{
            printf("Ingrese el numero de la carta\n");
            scanf("%d", &elem.valor);
        } while (elem.valor<1 || elem.valor>12);
        
        poneP(P,elem);
    }
}

void cargaC(TCola *C, int N){
    TElementoC elem;
    int i;
    for (i = 0; i < N; i++){
        printf("Ingrese el nombre del participante: \n");
        scanf("%s", &elem.nomJugador);
        elem.paloAnt = '/';
        elem.puntos = 0;
        poneC(C, elem);
    }
}

void juego(TCola *C, TPila *P){
    TElementoC elemC;
    TElementoP elemP;

    while (!vaciaP(*P)){
        sacaP(P,&elemP);
        sacaC(C,&elemC);
        
        if (elemC.paloAnt == elemP.palo)
            elemC.puntos = elemC.puntos + 2*elemP.valor;
        else 
            elemC.puntos = elemC.puntos + elemP.valor;
        elemC.paloAnt = elemP.palo;
        poneC(C,elemC);
    }
}

void mostrarPuntaje(TCola *C){
    TElementoC elem;
    while (!vaciaC(*C)){
        sacaC(C,&elem);
        printf("El puntaje de %s es: %d\n", elem.nomJugador, elem.puntos);
    }
}