#include <stdio.h>
#include "TDAPila.h"
/* 6. Desarrollar subprogramas (con estructuras iterativas) que trabajando sobre una pila de
enteros:
    a. cuente la cantidad de ceros que contiene.
    b. obtenga el valor promedio (sin perder la información de la pila)
    c. calcule los valores máximo y mínimo de la pila (sin perder la información de la pila)
    d. quite todos los valores mayores al último. */
void cargaP(TPila *, int);
void contarCeros(TPila *, int *);
void obtenerProm(TPila *, float *);
void calcMaxMin(TPila *, int *, int *);
void quitarValores(TPila *);
void main(){
    TPila P;
    int res, cantCeros = 0, min, max, cantElem;
    float prom;
    iniciaP(&P);
    printf("Ingrese la cantidad de elementos que desea almacenar \n");
    scanf("%d", &cantElem);
    cargaP(&P,cantElem);
    do{
        printf("Que operacion desea ejecutar? \n");
        printf("1. Contar la cantidad de ceros que contiene la pila \n");
        printf("2. Obtener el valor promedido de la pila \n");
        printf("3. Calcular el valor maximo y minimo de la pila \n");
        printf("4. Quitar todos los valores mayores al ultimo en la pila\n");
        printf("0. Salir \n");
        scanf("%d", &res);
        switch (res){
        case 1:
            contarCeros(&P, &cantCeros);
            printf("La cantidad de ceros de la pila es: %d \n", cantCeros);
            break;
        case 2:
            obtenerProm(&P, &prom);
            printf("El promedio de la pila es: %f\n", prom);
            break;
        case 3:
            calcMaxMin(&P,&min,&max);
            printf("El valor max es: %d y el valor min es: %d\n", max, min);
            break;
        case 4:
            quitarValores(&P);
            break;
        default:
            break;
        }
    } while (res != 4 && res != 0 && res != 1);
}

void cargaP(TPila *P, int cantElem){
    TElementoP elem;
    int i;
    for (i = 0; i < cantElem; i++){
        printf("Ingrese el elemento num: %d\n", i+1);
        scanf("%d", &elem);
        poneP(P,elem);
    }
}

void contarCeros(TPila *P, int *cantCeros){
    TElementoP elem;
    while (!vaciaP(*P)){
        sacaP(P,&elem);
        if (elem == 0)
            (*cantCeros)++;
    }
}

void obtenerProm(TPila *P, float *prom){
    TPila aux;
    TElementoP elem, suma = 0;
    int cont = 0;
    iniciaP(&aux);
    while (!vaciaP(*P)){
        sacaP(P, &elem);
        poneP(&aux, elem);
        suma += elem;
        cont++;
    }
    while (!vaciaP(aux)){
        sacaP(&aux, &elem);
        poneP(P,elem);
    }
    
    *prom = (float)suma/cont;
}
void calcMaxMin(TPila *P, int *min, int *max){
    TPila aux;
    TElementoP elem;
    *min = 99999;
    *max = 0;
    iniciaP(&aux);
    while (!vaciaP(*P)){
        sacaP(P, &elem);
        poneP(&aux, elem);
        if (elem>*max)
            *max = elem;
        else if (elem<*min)
            *min = elem;
    }

    while (!vaciaP(aux)){
        sacaP(&aux, &elem);
        poneP(P,elem);
    }
}
void quitarValores(TPila *P){
    TPila aux;
    TElementoP elem, ultElem;
    iniciaP(&aux);
    while (!vaciaP(*P)){
        sacaP(P, &elem);
        poneP(&aux, elem);
        if (vaciaP(*P) == 0)
            ultElem = elem;
    }

    while (!vaciaP(aux)){
        sacaP(&aux, &elem);
        if (elem>ultElem)
            poneP(P,elem);
    }
}