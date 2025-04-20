#include <stdio.h>
#include "funciones.h"

/* 9. Desarrollar un programa que sume dos números enteros positivos, permitiendo una cantidad
de dígitos mayor a la que soportan los tipos numéricos. Los números pueden tener diferente
magnitud y deben ser ingresados comenzando desde su dígito más significativo (en orden).
Utilizar pilas de caracteres. */
void ingresaNum(TPila *P);
void sumaNums(TPila *, TPila *);
void mostrarPila(TPila *P);

void main(){
    TPila num1, num2;
    
    printf("Ingrese el primer numero:\n");
    ingresaNum(&num1);
    printf("Ingrese el segundo numero:\n");
    ingresaNum(&num2);
    
    printf("La suma es: ");
    sumaNums(&num1, &num2);
    printf("\n");
}

void ingresaNum(TPila *P){
    TElementoP elem;
    iniciaP(P);
    do{
        do{
            printf("Ingrese un digito (0-9) (. terminar): \n");
            scanf(" %c", &elem);
        } while ((elem < '0' || elem > '9') && elem != '.');
        
        if (elem != '.')
            poneP(P,elem);
    } while(elem != '.' && !vaciaP(*P));
}

void sumaNums(TPila *P1, TPila *P2){
    TPila PAux;
    TElementoP elem1, elem2, elemAux, resto;
    int sumaAnt = 0;
    iniciaP(&PAux);

    while (!vaciaP(*P1) && !vaciaP(*P2)){
        sacaP(P1, &elem1);
        sacaP(P2, &elem2);
        elemAux = elem1 + elem2 + sumaAnt - 48;
        resto = elemAux - 10;
        if (resto <= '0'){
            poneP(&PAux, elemAux);
            sumaAnt = 0;
        } else{
            poneP(&PAux, resto);
            sumaAnt = 1;
        }
    }
    if (!vaciaP(*P1)){
        while (!vaciaP(*P1)){
            sacaP(P1,&elem1);
            poneP(&PAux,elem1);
        }
    } else if (!vaciaP(*P2)){
        while (!vaciaP(*P2)){
            sacaP(P2,&elem2);
            poneP(&PAux,elem2);
        }
    }
    mostrarPila(&PAux);
}

void mostrarPila(TPila *P){
    TElementoP elem;
    if (!vaciaP(*P)){
        sacaP(P,&elem);
        printf("%c", elem);
        mostrarPila(P);
        poneP(P,elem);
    }
}