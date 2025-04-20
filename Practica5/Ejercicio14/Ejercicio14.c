#include <stdio.h>
#include "TDACola.h"
#include "TDAPila.h"

/* 14. Utilizar las estructuras que considere adecuadas para determinar si una palabra almacenada en
una cola es palíndroma. Se conoce de antemano la cantidad de letras de la palabra (N). */
void cargaC(TCola *, int *);
void verificarPalindroma(TCola *, int);

void main(){
    TCola C;
    int N=0;
    iniciaC(&C);
    cargaC(&C, &N);
    printf("largo N/2: %d\n", N / 2);
    verificarPalindroma(&C, N);
}

void cargaC(TCola *C, int *N){
    TElementoC elem;
    
    do{
        printf("Ingrese un palabra terminada con un '.'\n");
        scanf(" %c", &elem);
        if (elem != '.'){
            poneC(C,elem);
            (*N)++;
        }
    } while (elem != '.');
}

void verificarPalindroma(TCola *C, int N){
    TPila P;
    TElementoP elemP;
    TElementoC elemC;
    int i;
    iniciaP(&P);
    for (i = 0; i < N / 2; i++){
        sacaC(C,&elemC);
        poneP(&P,elemC);
    }
    
    if (N%2 == 1)
        sacaC(C,&elemC);
    
    do{
        sacaC(C,&elemC);
        sacaP(&P,&elemP);
    }while (!vaciaC(*C) && elemC == elemP);
    
    if (vaciaC(*C))
        printf("Es palindroma\n");
    else
        printf("No es palindroma\n");
    
}