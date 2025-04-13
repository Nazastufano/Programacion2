#include <stdio.h>
#include <string.h>
#include "funciones.h"

agendaContactos iniciarAgenda(){
    agendaContactos contac;
    contac.cant = -1;
    return contac;
}

void agregarContacto(agendaContactos *contactos, TElementoDC nom[15], TElementoDC num[15]){
    if ((*contactos).cant<SIZE){
        (*contactos).cant++;
        insertarOrdenado(contactos,nom,num);
    }
}

void insertarOrdenado(agendaContactos *contactos, TElementoDC nom[15], TElementoDC num[15]){
    int i = (*contactos).cant-1;

    while (i >= 0 && strcmp(nom, (*contactos).datos[i].nombre) < 0) {
        strcpy((*contactos).datos[i + 1].nombre, (*contactos).datos[i].nombre);
        strcpy((*contactos).datos[i + 1].numero, (*contactos).datos[i].numero);
        i--;
    }

    strcpy((*contactos).datos[i + 1].nombre, nom);
    strcpy((*contactos).datos[i + 1].numero, num);
}

void listarAgenda(agendaContactos contactos){
    int i;
    for (i = 0; i <= contactos.cant; i++){
        printf("Nombre del contactos %d: %s\n",i+1, contactos.datos[i].nombre);
        printf("Numero del contactos %d: %s\n",i+1, contactos.datos[i].numero);
    }
}

int buscarNombre(agendaContactos contactos, TElementoDC nom[15]){
    int i=0;
    while (i<=contactos.cant && strcmp(contactos.datos[i].nombre, nom) != 0)
        i++;
    if (i<=contactos.cant)
        return i;
    else
        return -1;
}

int buscarNombreBinaria(agendaContactos contactos, TElementoDC nom[15]){
    int inicio = 0, fin = contactos.cant - 1, medio, cmp;
    int pos = -1;

    while (inicio <= fin && pos == -1) {
        medio = (inicio + fin) / 2;
        cmp = strcmp(nom, contactos.datos[medio].nombre);
        if (cmp == 0)
            pos = medio;
        else if (cmp < 0)
            fin = medio - 1;
        else
            inicio = medio + 1;
    }

    return pos;
}