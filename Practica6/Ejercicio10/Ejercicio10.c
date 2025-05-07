#include <stdio.h>
#include <stdlib.h>

/* 10. Dada una lista doblemente enlazada de caracteres que representa una palabra, verificar si es 
palíndroma. */

typedef struct nodoD{
    char dato;
    struct nodoD *sig, *ant;
} nodoD;

typedef nodoD * pNodoD;

typedef struct {
    pNodoD pri, ult;
} TListaC;

void cargarLista(TListaC *LC);
int esPalindroma(TListaC LC);

void main(){
    TListaC LC;

    cargarLista(&LC);
    
    if (esPalindroma(LC))
        printf("Es palindroma\n");
    else
        printf("No es palindroma\n");
}

void cargarLista(TListaC *LC){
    char dato;
    pNodoD nuevo, nodoAnt = NULL;
    
    LC->pri = NULL;
    LC->ult = NULL;
    do{
        printf("Ingrese el dato a almacenar\n");
        scanf(" %c", &dato);
    
        if (dato != '.'){
            nuevo = (pNodoD)malloc(sizeof(nodoD));
            nuevo->ant = nodoAnt;
            nuevo->dato = dato;
            nuevo->sig= NULL;
            
            if (nodoAnt == NULL)
                LC->pri = nuevo;
            else
                nodoAnt->sig = nuevo;
            
            nodoAnt = nuevo;
        }
    } while (dato != '.');
    (*LC).ult = nuevo;
}

int esPalindroma(TListaC LC){    
    int res = 0;
    if (LC.pri != NULL){
        while ((LC.pri != LC.ult && LC.pri->ant != LC.ult) && LC.pri->dato == LC.ult->dato){
            LC.pri = LC.pri->sig;
            LC.ult = LC.ult->ant;
        }
        if (LC.pri == LC.ult || LC.pri->ant == LC.ult)
            res = 1;
    }
    
    return res;
}

