#define SIZE 50
#include <stdio.h>
#include <string.h>

typedef struct {
    char nombre[SIZE][15];
    char numero[SIZE][15];
} datosContacto;



void insertarOrdenado(datosContacto *contactos, char nom[15], char num[15], int tam);

void iniciarAgenda(datosContacto *contactos, int *tam);

void agregarContacto(datosContacto *contactos, int *tam);

void listarAgenda(datosContacto contactos, int tam);

void buscarNombre(datosContacto contactos, int tam);

void buscarNombreBinaria(datosContacto contactos, int tam);