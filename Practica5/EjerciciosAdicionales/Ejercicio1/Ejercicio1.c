#include <stdio.h>
#include "TDAPila.h"

/* 1) Resolver recursivamente. En una Pila se han almacenado valores enteros, se desea saber cuántos
(excepto los dos primeros) son iguales al promedio de los dos anteriores, la pila puede perderse.
Por ejemplo:
    Pila(tope) : 1 3 2 0 1 5 3 5 Rta: 3 */

void analisisRec(TPila *, int *);
void cargaP(TPila *);
void main(){
    TPila P;
    
    int res = 0;
    iniciaP(&P);
    cargaP(&P);

    analisisRec(&P, &res);
    if (res)
        printf("Hay %d casos donde el elemento es igual al promedio de los dos anteriores\n", res);
    else
        printf("No hay casos donde el elemento es igual al promedio de los dos anteriores\n");
}
void cargaP(TPila *P){
    TElementoP elem;
    int i, N;
    do{
        printf("Ingrese cuantos elementos desea almacenar\n");
        scanf("%d", &N);
    } while (N<=0 || N>MAX);
    
    for (i = 0; i < N; i++){
        printf("Ingrese el elemento %d\n",i+1);
        scanf("%d", &elem);
        poneP(P,elem);
    }
}
void analisisRec(TPila *P, int *res){
    TElementoP elem1, elem2;
    if (!vaciaP(*P)){
        sacaP(P,&elem1);
        if (!vaciaP(*P)){
            sacaP(P,&elem2);
            if (!vaciaP(*P)){
                if ((elem1+elem2)/2 == consultaP(*P))
                    (*res)++;
                poneP(P,elem2);
                analisisRec(P,res);
            }
        }
    }
}
