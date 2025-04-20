#include <stdio.h>
#include "funciones.h"

/* 4. Ingresar en una cola los números almacenados (uno por línea) en un archivo de texto. Mostrar
el contenido de la cola.
a. Utilizar la implementación estática no circular.
b. Utilizar la implementación dinámica.
c. Mantener la información en la cola. */

void muestraCola(TCola *C);
void lecturaArch(char *, TCola *C);

void main(){
    TCola C;
    iniciaC(&C);
    lecturaArch("datos.txt", &C);
    muestraCola(&C);
}

void lecturaArch(char *nomArch, TCola *C){
    FILE *arch;
    int num;
    if ((arch = fopen(nomArch, "r")) == NULL)
        printf("No se pudo abrir el archivo. Es posible que no exista.\n");
    else{
        while (fscanf(arch,"%d",&num) == 1)
            poneC(C,num);
        
        fclose(arch);
    }
}
void muestraCola(TCola *C){
    int num;
    while (!vaciaC(*C)){
        sacaC(C,&num);
        printf("Num: %d \n", num);
    }
}