#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
/* 7. Rehacer los ejercicios 2 y 3 de pilas mediante subprogramas recursivos. Las pilas no deben
perder su información. */

void lecturaArch(char *, TPila *);
void muestraRec(TPila *);
void main(){
    TPila P;
    iniciaP(&P);

    lecturaArch("datos.txt", &P);
    muestraRec(&P);
}

void lecturaArch(char *nom, TPila *P){
    FILE *arch;
    TElementoP elem;

    if ((arch = fopen(nom, "r")) == NULL)
        printf("El archivo no se pudo abrir. Es posbile que no exista");
    else {
        while (fscanf(arch, " %c", &elem) == 1)
            poneP(P, elem);
        fclose(arch);
    }
}

void muestraRec(TPila *P){
    TElementoP elem;
    if (!vaciaP(*P)){
        sacaP(P, &elem);
        printf("%c \n", elem);
        muestraRec(P);
        poneP(P, elem);
    }
}