#include <stdio.h>
#include <string.h>
/* 6. Se tiene una lista con equipos de fútbol (nombre y puntaje en el torneo), la cual está ordenada
descendentemente por puntaje (los equipos con el mismo puntaje están ordenados
alfabéticamente). Cada equipo cuenta con una sublista de jugadores (nombre y edad, estado
([A]ctivo, [S]uspendido)).
a) Listar para todos los clubes los jugadores cuyo nombre comienza con la letra K (dato). Al
finalizar mostrar cantidad de jugadores listados y el club que tiene más jugadores que
cumplan el criterio solicitado.
b) Listar los clubes que tienen un mínimo de X (dato) puntos junto con todos sus jugadores,
mostrando edad promedio de cada equipo.
c) Verificar si el equipo E (dato) tiene P (dato) puntos.
d) Eliminar los jugadores que se encuentren en estado inactivo en todos los equipos. */

typedef struct nodito{
    char nombre[20];
    unsigned int edad;
    char estado;
    struct nodito * sig;
} nodito;

typedef nodito * subLista;

typedef struct nodo{
    char nombreEquipo[20];
    unsigned int puntaje;
    subLista sub;
    struct nodo * sig;
}nodo;

typedef nodo * TLista;

void listarJugadores(TLista , char );
void listarPorPuntos(TLista , int );
int verificarPuntos(TLista , char [20], int);
void main(){
    TLista L;
    char K, E[20];
    int X, P;
    //cargaLista(&L);
    
    printf("Ingrese una letra para listar los jugadores: \n");
    scanf(" %c", &K);
    listarJugadores(L,K);
    
    printf("Ingrese una cantidad de puntos a superar \n");
    scanf("%d", &X);
    listarPorPuntos(L,X);

    printf("Ingrese el nombre de un equipo\n");
    scanf("%s", E);
    printf("Ingrese los puntos a consultar\n");
    scanf("%d", &P);
    if (verificarPuntos(L,E,P))
        printf("El equipo %s, tiene %d puntos\n", E, P);
    else
        printf("El nombre del equipo no existe o los puntos ingresados no son correctos");
    
}

void listarJugadores(TLista L, char K){
    TLista aux = L;
    subLista sAux;
    char nombreClubMasJug[20];
    int contJug = 0, contPorClub, contMaxPorClub = 0;
    while (aux != NULL){
        sAux = aux->sub;
        contPorClub = 0;
        while (sAux != NULL){
            if (sAux->nombre[0] == K){
                contPorClub++;
                printf(" -%s\n", sAux->nombre);
            }
                
            sAux = sAux->sig;
        }
        contJug += contPorClub;
        if (contPorClub>contMaxPorClub){
            contMaxPorClub = contPorClub;
            strcpy(nombreClubMasJug, aux->nombreEquipo);
        }
        aux = aux->sig;
    }
    if (contJug){
        printf("La cantidad de jugadores listados es %d\n", contJug);
        printf("El club con mas jugadores que cumplen el criterio es %s con %d jugadores \n", nombreClubMasJug, contMaxPorClub);
    } else
        printf("No hubo jugadores que cumplan el criterio");
}

void listarPorPuntos(TLista L, int X){
    TLista lAux = L;
    subLista sAux = NULL;
    int sumaEdad, contJug;

    while (lAux != NULL){
        if (lAux->puntaje >= X){
            sumaEdad = 0;
            contJug = 0;
            sAux = lAux->sub;
            printf("Club: %s\n",lAux->nombreEquipo);

            while (sAux != NULL){
                sumaEdad += sAux->edad;
                contJug++;
                printf(" -%s\n", sAux->nombre);
                sAux = sAux->sig;
            }
            if (contJug)
                printf("El promedio de edade es %.2f\n", sumaEdad/(float)contJug);
        }
        lAux = lAux->sig;
    }
}

int verificarPuntos(TLista L, char E[20], int P){
    TLista lAux = L;
    int res = 0;
    while (lAux != NULL && strcmp(lAux->nombreEquipo, E) != 0)
        lAux = lAux->sig;
    
    if (lAux != NULL && lAux->puntaje == P)
        res = 1;
    
    return res;
}

//d) Eliminar los jugadores que se encuentren en estado inactivo en todos los equipos. 

void eliminarInactivos(TLista *L){
    TLista aux = L;
    subLista sAct, sAnt, elim;

    while (aux != NULL){
        sAct = aux->sub;
        sAnt = NULL;
        while (sAct != NULL){
            if (sAct->estado == 'S'){
                elim = sAct;
                if (sAnt == NULL)
                    aux->sub = sAct->sig;    
                else 
                    sAnt->sig = sAct->sig;
                sAct = sAct->sig;
                free(elim);
            } else {
                sAnt = sAct;
                sAct = sAct->sig;
            }
            
        }
        aux = aux->sig;
    }
}