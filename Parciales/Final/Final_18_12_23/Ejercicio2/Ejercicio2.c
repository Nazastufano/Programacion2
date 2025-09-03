#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Ej 2.- Un sistema de reproducción de música administra las canciones disponibles para ser
reproducidas mediante una lista simple enlazada con la siguiente estructura:
    Id Interprete   (Cadena de 10, ordenada)
    Sublista de canciones
        Id Canción (entero, se puede repetir para diversos interpretes)
        Titulo canción
        Duración (en segundos)
Existe una lista de reproducción implementada mediante una lista circular, en la que cada nodo
contiene Id Canción e Id Interprete. El orden de dicha lista es el de la reproducción de las canciones, o
sea que no se encuentra ordenada por ningún criterio.
Se pide, definir los tipos de las estructuras utilizadas y resolver:
    Dado un Id intérprete, listar todas las canciones disponibles de él (con el formato indicado más 
    abajo), eliminando las que estén, de la lista de reproducción. Al final del listado, mostrar la cantidad
    de canciones eliminadas y su duración en minutos. 
    Intérprete: XXXXXXXXXXX
        Id Cancion      Titulo Cancion      Eliminada
        9999999         XXXXXXXXXXXXXX      N
        9999999         XXXXXXXXXXXXXX      S
        .....
    99 Canciones eliminadas (999 minutos) */

#define ST10 11
#define ST20 21

typedef struct nodito{
    int idCancion;
    char tituloCan[ST20];
    int duracion;
    struct nodito * sig;
}nodito;

typedef nodito * subLista;

typedef struct nodo{
    char idInterprete[ST10];
    subLista sub;
    struct nodo * sig;
}nodo;

typedef nodo * TLista;

typedef struct nodoC{
    char idInterprete[ST10];
    int idCancion;
    struct nodoC *sig;
}nodoC;

typedef nodoC * TListaC;

void listar(TLista L, TListaC *LC, char idInterprete[ST10]);

void main(){
    TLista L;
    TListaC LC;
    char idInterprete[ST10];
    LC = NULL;
    L = NULL;
    cargaL(&L);
    cargaLC(&LC);

    printf("Ingrese el id de un interprete: \n");
    scanf("%s", idInterprete);

    listar(L, &LC, idInterprete);
}

void listar(TLista L, TListaC *LC, char idInterprete[ST10]){
    TListaC antLC, actLC, elimLC;
    TLista aux;
    subLista sAux;
    int cantElim = 0, duracionElim = 0, elimina;

    if (*LC != NULL){        
        aux = L;
        while (aux != NULL && strcmp(aux->idInterprete, idInterprete) < 0)
            aux = aux->sig;
        
        if (aux != NULL && strcmp(aux->idInterprete, idInterprete) == 0){
            printf("Interprete: %s\n", idInterprete);
            printf("    Id Cancion      Titulo Cancion      Eliminada");
            sAux = aux->sub;
            while (sAux != NULL){
                antLC = *LC;
                actLC = (*LC)->sig;
                elimina = 0;
                
                do{
                    if (actLC->idCancion == sAux->idCancion && strcmp(aux->idInterprete, idInterprete) == 0)
                        elimina = 1;
                    else {
                        antLC = actLC;
                        actLC = actLC->sig;
                    }
                } while (actLC != (*LC)->sig && !elimina);
                
            
                if (elimina){
                    printf("    %s              %s                  %c",sAux->idCancion, sAux->tituloCan, 'S');
                    duracionElim += sAux->duracion;
                    cantElim += 1;

                    elimLC = actLC;
                    actLC = actLC->sig;
                    if (elimLC == *LC)
                        *LC = antLC;
                    antLC->sig = actLC;
                    free(elimLC);
                } else
                    printf("    %s              %s                  %c",sAux->idCancion, sAux->tituloCan, 'N');
                
                sAux = sAux->sig;
            }
            if (cantElim)
                printf("%d canciones eliminadas (%d minutos)\n", cantElim, (duracionElim / 60));
        }
    }
}

/*     if (*LC != NULL){
        antLC = *LC;
        actLC = (*LC)->sig;

        do{
            aux = L;
            elimina = 0;
            while (aux != NULL && strcmp(aux->idInterprete, actLC->idInterprete) < 0)
                aux = aux->sig;
            
            if (strcmp(aux->idInterprete, actLC->idInterprete) == 0){
                printf("Interprete: %s\n", actLC->idInterprete);
                printf("    Id Cancion      Titulo Cancion      Eliminada");
                
                sAux = aux->sub;
                while (sAux != NULL){
                    if (sAux->idCancion == actLC->idCancion && !elimina){
                        printf("    %s              %s                  %c",sAux->idCancion, sAux->tituloCan, 'S');

                        elimina = 1;
                        duracionElim += sAux->duracion;
                        cantElim += 1;
                    } else
                        printf("    %s              %s                  %c",sAux->idCancion, sAux->tituloCan, 'N');
                
                    sAux = sAux->sig;
                }
                
            }
            if (elimina){
                elimLC = actLC;
                actLC = actLC->sig;
                if (elimLC == *LC)
                    *LC = antLC;
                antLC->sig = actLC;
                free(elimLC);
            } else {
                antLC = actLC;
                actLC = actLC->sig;
            }
        } while (actLC != (*LC)->sig);    

        
        if (cantElim)
            printf("%d canciones eliminadas (%d minutos)\n", cantElim, (duracionElim / 60));
    }    */