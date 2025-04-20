#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

Texto crear(char *c){
    Texto cad;
    int i=0;
    while (c[i] != '\0')
        i++;
    
    cad.largo=i;
    cad.texto = malloc(sizeof(char)*cad.largo);
    for (i = 0; i < cad.largo; i++)
        cad.texto[i]=c[i];

    return cad;
}

void destruir(Texto *t){
    free(t->texto);
    t->texto=NULL;
    t->largo = 0;
}

int tamanio(Texto t){
    return t.largo;
}

void imprimir(Texto t){
    int i;
    for (i = 0; i < t.largo; i++)
        printf("%c", t.texto[i]);
    printf("\n");
}

void imprimirArch(Texto t, char *nomArch){
    int i;
    FILE * arch;
    if ((arch = fopen(nomArch, "w"))==NULL)
        printf("Problema al abrir el archivo. Es posible que no exista. \n");
    else {
        for (i = 0; i < t.largo; i++)
            fprintf(arch,"%c",t.texto[i]);
    
        fclose(arch);
    }
}

char caracterEn(Texto texto, int posicion){
    return texto.texto[posicion];
}

Texto concatenar(Texto t1, Texto t2){
    Texto tAux;
    int i;
    for (i = 0; i < t1.largo; i++)
        tAux.texto[i]=t1.texto[i];
    
    for (i = 0; i < t2.largo; i++)
        tAux.texto[t1.largo+i]=t2.texto[i];
    tAux.largo = t1.largo + t2.largo;
    return tAux;
}

Texto reemplazar(Texto texto, char caracter, char nuevoCaracter){
    int i;
    for (i = 0; i < texto.largo; i++)
        if (caracter == texto.texto[i])
            texto.texto[i] = nuevoCaracter;
    
    return texto;
}

Texto subTexto(Texto texto, int desde, int hasta){
    Texto tAux;
    int i,j;
    for (i = desde; i <= hasta; i++)
        tAux.texto[i-desde]=texto.texto[i];
    
    tAux.largo=hasta-desde;
    return tAux;
}

int comienzaCon(Texto texto, Texto prefijo){
    int i=0;
    while (i < prefijo.largo && texto.texto[i] == prefijo.texto[i])
        i++;
    
    if (i<prefijo.largo)
        return 0;
    else
        return 1;   
}

int terminaCon(Texto texto, Texto subfijo){
    int i=0;
    
    while (i < subfijo.largo && texto.texto[texto.largo-subfijo.largo+i] == subfijo.texto[i])
        i++;
    
    if (i<subfijo.largo)
        return 0;
    else
        return 1;
}