#include <stdio.h>
#include "funciones.h"
/* 2. Ingresar en una pila los caracteres almacenados (uno por línea) en un archivo de texto. Mostrar
el contenido de la pila.
a. Utilizar la implementación estática.
b. Utilizar la implementación dinámica.
c. Mantener la información en la pila. */

void lecturaArch(char *, TPila *);
void MostrarContenido(TPila *);

void main(){
    TPila P;
    iniciaP(&P);

    lecturaArch("caracteres.txt", &P);
    MostrarContenido(&P);
}

void lecturaArch(char *nomArch, TPila *P){
    FILE * arch;
    TElementoP elem;
    if ((arch = fopen(nomArch, "r")) == NULL)
        printf("El archivo no se pudo abrir. Es posible que no exista");
    else {
        while (fscanf(arch, " %c", &elem) == 1)
            poneP(P, elem);
        
        fclose(arch);
    }
}

void MostrarContenido(TPila *P){
    TElementoP elem;
    while (!vaciaP(*P)){
        sacaP(P, &elem);
        printf("Elemento de la pila: %c\n", elem);
    }
}
