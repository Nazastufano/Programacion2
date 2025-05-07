#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* 3. Simular un gestor de archivos simplificado mediante listas de carpetas que contengan sublistas 
de carpetas y archivos. Implementar el listado del contenido de una carpeta ingresada como 
dato. No es necesario listar el contenido de las subcarpetas de dicha carpeta. */

typedef struct nodito{
    char nombre[20];
    struct nodito * sig;
}nodito;
typedef nodito * subLista;

typedef struct nodo{
    char nombre[20];
    subLista subCarpetas;
    subLista subArchivos;
    struct nodo * sig;
}nodo;

typedef nodo * TLista;

void mostrar(TLista L, char nombre[20]);

void main(){
    TLista L;
    L = NULL;
    cargarLista(&L);
    mostrar(L, "ejemplo");
}

void mostrar(TLista L, char nombre[20]){
    TLista aux = L;
    subLista sAux;
    while (aux != NULL && strcmp(nombre, aux->nombre) != 0)
        aux = aux->sig;
        
    if (aux != NULL){
        printf("Contenido de la carpeta: %s\n", nombre);
        
        printf("Archivos: \n");
        sAux = aux->subArchivos;
        while (sAux != NULL){
            printf("    %s.exe\n", sAux->nombre);
            sAux = sAux->sig;
        }

        printf("Carpetas: \n");
        sAux = aux->subCarpetas;
        while (sAux != NULL){
            printf("    %s \n", sAux->nombre);
            sAux = sAux->sig;
        }
    }
}   