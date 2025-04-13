#define SIZE 50
#include <stdio.h>
#include <string.h>

typedef char TElementoDC;

typedef struct {
    TElementoDC nombre[SIZE][15];
    TElementoDC numero[SIZE][15];
    int cant;
} agendaContactos;

void insertarOrdenado(agendaContactos *contactos, TElementoDC nom[15], TElementoDC num[15]);

agendaContactos iniciarAgenda();

void agregarContacto(agendaContactos *contactos, TElementoDC nom[15], TElementoDC num[15]);

void listarAgenda(agendaContactos contactos);

int buscarNombre(agendaContactos contactos, TElementoDC nom[15]);

int buscarNombreBinaria(agendaContactos contactos, TElementoDC nom[15]);