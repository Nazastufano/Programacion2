#include <stdio.h>
#include <stdlib.h>

/* 5. Resolver mediante subprogramas las siguientes operaciones sobre una lista doblemente 
enlazada: 
a) insertar un elemento en la posición media. Si la cantidad de elementos de la lista es impar 
insertar en la posición media más uno. Considerar la inserción en una lista vacía (único 
nodo) 
b) eliminar un elemento conociendo la posición (puntero) del anterior, nulo para eliminar el 
primer elemento. 
c) eliminar todas las ocurrencias del elemento X (recibido como parámetro) */

typedef struct nodoD{
    int dato;
    struct nodoD *sig, *ant;
}nodoD;

typedef nodoD * pNodoD;

typedef struct{
    pNodoD pri, ult;
} TListaD;

void insertarPosMedia(TListaD *LD, int elem);
void eliminarAnt(TListaD *LD, pNodoD puntero);
void eliminarOcurrencias(TListaD *LD, int X);

void main(){
    TListaD LD;
    int X, elem;
    LD.pri = NULL;
    LD.ult = NULL;
    printf("Ingrese un elemento para insertar en el medio de la lista: \n");
    scanf("%d", &elem);
    insertarPosMedia(&LD, elem);
    
    eliminarAnt(&LD, NULL);

    printf("Ingrese un dato para eliminar todas las ocurrencias: \n");
    scanf("%d", &X);
    eliminarOcurrencias(&LD, X);
}

/* a) insertar un elemento en la posición media. Si la cantidad de elementos de la lista es impar 
insertar en la posición media más uno. Considerar la inserción en una lista vacía (único 
nodo) */

void insertarPosMedia(TListaD *LD, int elem){
    pNodoD act = (*LD).pri, ant = NULL, nuevo;
    int contN = 0, posM;
    
    while (act != NULL){
        contN++;
        act = act->sig;
    }

    nuevo = (pNodoD)malloc(sizeof(nodoD));
    nuevo->dato = elem;
    nuevo->ant = NULL;
    nuevo->sig = NULL;
    
    if (contN){
        if (contN % 2 == 0)
            posM = contN / 2;
        else
            posM = (contN / 2) + 1;
        
        act = (*LD).pri;
        contN = 1;

        while (contN < posM){
            contN++;
            act = act->sig;
        }

        if (LD->pri == act){
            nuevo->sig = LD->pri;
            LD->pri->ant = nuevo;
            LD->pri = nuevo;
        } else {
            nuevo->ant = act->ant;
            nuevo->sig = act;
            act->ant->sig = nuevo;            
            act->ant = nuevo;
        }
    } else {
        (*LD).pri = nuevo;
        (*LD).ult = nuevo;
    }
}

/* b) eliminar un elemento conociendo la posición (puntero) del anterior, nulo para eliminar el 
primer elemento. */

void eliminarAnt(TListaD *LD, pNodoD puntero){
    pNodoD aux = LD->pri, elim;

    while (aux != NULL && aux->ant != puntero)
        aux = aux->sig;
    
    if (puntero == aux->ant){
        elim = aux;
        if (aux == LD->pri){
            LD->pri = LD->pri->sig;
            if (LD->pri != NULL)
                LD->pri->ant = NULL;
            else
                LD->ult = NULL;
        } else if (aux == LD->ult){
            LD->ult = LD->ult->ant;
            LD->ult->sig = NULL;
        } else {
            aux->ant->sig = aux->sig;
            aux->sig->ant = aux->ant;
        }
            
        free(elim);
    }
}

// c) eliminar todas las ocurrencias del elemento X (recibido como parámetro)
void eliminarOcurrencias(TListaD *LD, int X){
    pNodoD aux = LD->pri, elim;
    
    while (aux != NULL){
        if (aux->dato == X){
            elim = aux;
            aux = aux->sig;
            if (elim == LD->pri){ // es pri
                LD->pri = LD->pri->sig;
                    
                if (LD->pri != NULL)
                    LD->pri->ant = NULL;
                else
                    LD->ult = NULL;
            } else if (elim == LD->ult){ // es ult
                LD->ult = LD->ult->ant;
                LD->ult->sig = NULL;
            } else { //muevo
                elim->ant->sig = elim->sig;
                elim->sig->ant = elim->ant;
            }
                
            free(elim);
        } else
            aux = aux->sig;
    }
}