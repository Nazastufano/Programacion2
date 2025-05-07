#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* 3. Escribir un programa que lea desde un archivo un texto que contiene una cantidad desconocida
de palabras (una en cada línea) y genere una lista ordenada de todas las palabras existentes en
el texto con su frecuencia de aparición.*/

typedef struct {
    char palabra[20];
    int apariciones;
} TElementoL;

typedef struct nodo{
    TElementoL dato;
    struct nodo * sig;
} nodo;

typedef nodo * TLista;

void analisisTexto(TLista *L, char *);
void muestraContenido(TLista L);
void main(){
    TLista L;
    L = NULL;
    analisisTexto(&L, "texto.txt");
    muestraContenido(L);
}

void muestraContenido(TLista L){
    while (L != NULL){
        printf("Elemento de la lista %s, con %d apariciones \n", L->dato.palabra, L->dato.apariciones);
        L = L->sig;
    }
}
void analisisTexto(TLista *L, char *nom){
    FILE *arch;
    TLista aux, act, ant;
    TElementoL elem;

    if ((arch = fopen(nom, "r")) == NULL)
        printf("Problema al abrir el archivo. Es posible que no exista\n");
    else {
        while (fscanf(arch, "%s", elem.palabra) == 1){
            act = *L;
            ant = NULL;

            while (act != NULL && strcmp(elem.palabra, act->dato.palabra) > 0){
                ant = act;
                act = act->sig;
            }

            if (act != NULL && strcmp(elem.palabra, act->dato.palabra) == 0){
                act->dato.apariciones++;
            } else {
                aux = (TLista)malloc(sizeof(nodo));
                strcpy(aux->dato.palabra, elem.palabra);
                aux->dato.apariciones = 1;
                aux->sig = act;

                if (ant == NULL)
                    *L = aux;
                else 
                    ant->sig = aux;
            }
        }
        fclose(arch);
    }
}