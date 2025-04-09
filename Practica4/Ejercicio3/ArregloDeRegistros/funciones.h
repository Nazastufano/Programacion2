#define SIZE 50
#include <stdio.h>
#include <string.h>

typedef struct {
    char nombre[15];
    char numero[15];
} datosContacto;

void insertarOrdenado(datosContacto contactos[SIZE], char nom[15], char num[15], int tam);

void iniciarAgenda(datosContacto contactos[SIZE], int *tam);

void agregarContacto(datosContacto contactos[SIZE], int *tam);

void listarAgenda(datosContacto contactos[SIZE], int tam);

void buscarNombre(datosContacto contactos[SIZE], int tam);

void buscarNombreBinaria(datosContacto contactos[SIZE], int tam);