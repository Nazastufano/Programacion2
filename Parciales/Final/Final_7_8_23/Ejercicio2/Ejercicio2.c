#include <stdio.h>
#include <stdlib.h>
#include "TDAPila.h"
#include <ctype.h>

/* Ej 2.- (Utilizar TDA Pila) Se tiene una lista L doblemente enlazada ordenada de forma ascendente que 
contiene en cada nodo una cadena de caracteres. Se tiene ademas, una Pila P que contiene en cada 
elemento dos datos: un entero E (es 0) y un caracter C.
Se pide: 
A) Utilizando el TDA Pila, desarrollar en C subprogramas para: 
   i) Actualizar P de forma tal que, en cada elemento de P, E contenga la cantidad de elementos de fa 
lista que tienen a C como inicial. El recorrido sobre P debe ser recursivo. 
   ii) Eliminar de L los nodos que contengan cadenas cuya inicial no este en P almacenando en un 
archivo binario RESUMEN.DAT de structs la siguiente información para las cadenas eliminadas: 
Cadena, CantVocales, CantConsonantes 
b) Suponer que P es estatica. Definir los tipos asociados y desarrollar SacaP() y PoneP(). lndicar en que 
archivo(s) estan las definiciones y funciones. */


typedef struct nodoD{
   char *cadena;
   struct nodoD *ant, *sig;
}nodoD;

typedef nodoD * pNodoD;

typedef struct {
   pNodoD pri, ult;
}TListaD;

typedef struct {
   char *cadena;
   int cantVocales;
   int cantConsonantes;
} TElementoA;

void main(){
   TListaD L;
   TPila P;

   L.pri = NULL;
   L.ult = NULL;
   iniciaP(&P);

   cargaLD(&L);
   cargaP(&P);

   actualizarP(L, &P);
   eliminarNodos(&L,P, "RESUMEN.DAT");
}

void actualizarP(TListaD L, TPila *P){
   TElementoP elem;
   pNodoD auxLD = L.pri;
   if (!vaciaP(*P)){
      sacaP(P, &elem);
      while (auxLD != NULL && auxLD->cadena[0] <= elem.C){
         elem.E += auxLD->cadena[0] == elem.C;
         
         auxLD = auxLD->sig;
      }
      actualizarP(L,P);
      poneP(P,elem);
   }
}

void eliminarNodos(TListaD *L, TPila P, char nom[21]){
   FILE *archB;
   pNodoD aux = (*L).pri, elim;
   TElementoA elemA;
   int esta, i;

   if ((archB = fopen(nom, "wb")) == NULL)
      printf("No se pudo abrir el archivo. Es posible que no exista. \n");
   else {
      while (aux != NULL){
         if (!estaEnPila(P, aux->cadena[0])){
            strcpy(elemA.cadena, aux->cadena);
            
            cargarLetras(&elemA);

            fwrite(&elemA, sizeof(TElementoA), 1, archB);
            
            elim = aux;
            if (aux == (*L).pri){
               (*L).pri = aux->sig;
               if ((*L).pri == NULL)
                  (*L).ult = NULL;
               else
                  (*L).pri->ant = NULL;
            } else if (aux == (*L).ult){
               (*L).ult = (*L).ult->ant;
               (*L).ult->sig = NULL;
            } else {
               aux->ant->sig = aux->sig;
               aux->sig->ant = aux->ant;
            }
            free(elim);
         }
         aux = aux->sig;
      }
      
      fclose(archB);
   }
}

int esVocal(char car){
   car = toupper(car);
   return car == 'A' || car == 'E' || car == 'I' || car == 'O' || car == 'U';
}

int estaEnPila(TPila P, char car){
   TElementoP elem;
   if (!vaciaP(P)){
      sacaP(&P, &elem);
      
      if (elem.C == car)
         return 1;
      else
         return estaEnPila(P, car);
      
      poneP(&P,elem);
   } else
      return 0;
}

void cargarLetras(TElementoA *elemA){
   int i;
   for (i = 0; i < strlen((*elemA).cadena); i++){
      if (esVocal((*elemA).cadena[i]))
         (*elemA).cantVocales++;
      else
         (*elemA).cantConsonantes++;
   }
}