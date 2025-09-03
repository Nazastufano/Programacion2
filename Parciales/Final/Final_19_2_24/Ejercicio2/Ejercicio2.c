#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TDACola.h"

/* Ej 2.- Un sistema de reproducción de música administra las playlists públicas en una lista doblemente
enlazada LP con la siguiente estructura:
    Id Playlist (numérico, ordenada)
    Sublista de canciones
        Id Canción (cadena de 15, los primeros 4 caracteres determinan el intérprete)
        Título canción (cadena de 20)
        Duración (en segundos)
Se tiene una playlist C que ha tomado a su vez canciones de LP, implementada mediante una cola, en la
que cada elemento contiene Id Playlist (ordenada por este criterio), Id Canción.
Se pide: utilizando el TDA COLA
  a) En un único recorrido de la cola resolver (sin perder la cola ni cambiar el orden de la misma):
   i)  Hallar el tiempo en horas y minutos de reproducción de la playlist C (sin considerar las que se 
       eliminan en ii))
   ii) Eliminar De C aquellas canciones que estén interpretadas por "DUKI" y sean de la playlist X (X es
       dato de entrada)
       
  b) Dado un Id Interprete (cadena de 4), eliminar sin recorrer LP más de una vez todas las canciones 
     disponibles de él en las playlists X e Y de LP (X e Y datos validados) y listarlas (con el formato
     siguiente)

    Intérprete: XXXX
    PLAYLIST 99999
        Id Canción      Titulo Cancion
        xxxxxxxxxx      xxxxxxxxxxxxxxxxx 
        xxxxxxxxxx      xxxxxxxxxxxxxxxxx
  c) Suponiendo la cola circular definir su tipo y desarrollar los operadores PoneC() y VaciaC(). Indicar
     donde estarían estas definiciones. */


#define ST4 5
#define ST15 16
#define ST20 21

typedef struct nodito{
    char idCancion[ST15];
    char titulo[ST20];
    unsigned int duracion;
    struct nodito * sig;
} nodito;

typedef nodito * subLista;

typedef struct nodoD{
    int idPlaylist;
    subLista sub;
    struct nodoD *ant, *sig;
} nodoD;

typedef nodoD * pNodoD;

typedef struct {
    pNodoD pri, ult;
}TListaD;


void recorrerCola(TListaD LP, TCola *C, int X);
void listarPorInterprete(TListaD LP, char idInterprete[ST4], int X, int Y);

void main(){
    TListaD LP;
    TCola C;
    int X, Y;
    char idInterprete[ST4];

    LP.pri = NULL;
    LP.ult = NULL;
    cargaL(&LP);
    iniciaC(&C);
    cargaC(&C);

    printf("Ingrese el id de una playlist: \n");
    scanf("%d", &X);

    recorrerCola(LP, &C, X);

    printf("Ingrese el id de un inteprete: \n");
    scanf("%s", idInterprete);
    printf("Ingrese el id de una playlist: \n");
    scanf("%d", &X);
    printf("Ingrese otro id de una playlist: \n");
    scanf("%d", &Y);
    listarPorInterprete(LP, idInterprete, X, Y);
}

void recorrerCola(TListaD LP, TCola *C, int X){
    pNodoD aux = LP.pri;
    subLista sAct;
    TElementoC elem;
    unsigned int tiempoRep = 0;

    elem.idPlaylist = 9999; 
    poneC(C, elem);
    
    sacaC(C, &elem);
    while (elem.idPlaylist != 9999){
        if (!(strncmp(elem.idCancion, "DUKI", 4) == 0 && elem.idPlaylist == X)){
            while (aux->idPlaylist < elem.idPlaylist)
                aux = aux->sig;
            
            sAct = aux->sub;
            while (strcmp(sAct->idCancion, elem.idCancion) != 0)
                sAct = sAct->sig;
    
            tiempoRep += sAct->duracion;
            
            poneC(C,elem);
        }
        sacaC(C,&elem);        
    }
    if (tiempoRep)
        printf("La cantidad de horas y minutos de reproduccion es: %d:%d \n", tiempoRep / 3600, (tiempoRep % 3600) / 60);
}

void listarPorInterprete(TListaD LP, char idInterprete[ST4], int X, int Y){
    pNodoD aux = LP.pri;
    subLista sAct, sAnt, sElim;
    int tope = (X<Y) ? Y : X;
    
    printf("Interprete: %s \n", idInterprete);
    while (aux->idPlaylist <= tope){
        if (aux->idPlaylist == X || aux->idPlaylist == Y){
            sAnt = NULL;
            sAct = aux->sub;
            printf("PLAYLIST %d \n", aux->idPlaylist);
            printf("    Id Cancion      Titulo Cancion \n");
            while (sAct != NULL){
                if (strncmp(sAct->idCancion, idInterprete, 4) == 0){
                    sElim = sAct;
                    sAct = sAct->sig;

                    if (sElim == aux->sub)
                        aux->sub = aux->sub->sig;                        
                    else
                        sAnt->sig = sAct;
    
                    printf("    %s      %s", sElim->idCancion, sElim->titulo);
                    free(sElim);
                } else {
                    sAnt = sAct;
                    sAct = sAct->sig;
                } 
            }
        }
        aux = aux->sig;
    }
}