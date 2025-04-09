#include <stdio.h>

#define LARGOMAX 1000
typedef struct {
    char texto[LARGOMAX];
    int largo;
} Texto;

Texto crear(char *c);

void destruir(Texto t);

int tamanio(Texto t);

void imprimir(Texto t);

void imprimirArch(Texto t, FILE * arch);

char caracterEn(Texto texto, int posicion);

Texto concatenar(Texto t1, Texto t2);

Texto reemplazar(Texto texto, char caracter, char nuevoCaracter);

Texto subTexto(Texto texto, int desde, int hasta);

int comienzaCon(Texto texto, Texto prefijo);

int terminaCon(Texto texto, Texto subfijo);