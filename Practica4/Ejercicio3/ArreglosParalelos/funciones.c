#include <stdio.h>
#include <string.h>
#include "funciones.h"

agendaContactos iniciarAgenda(){
    agendaContactos contactos;
    contactos.cant = -1;
    return contactos;
}

void agregarContacto(agendaContactos *contactos, TElementoDC nom[15], TElementoDC num[15]){
    if ((*contactos).cant<SIZE){
        (*contactos).cant++;
        insertarOrdenado(contactos,nom,num);
    }
}

void insertarOrdenado(agendaContactos *contactos, TElementoDC nom[15], TElementoDC num[15]){
    int i = (*contactos).cant - 1;

    while (i >= 0 && strcmp(nom, contactos->nombre[i]) < 0) {
        strcpy(contactos->nombre[i + 1], contactos->nombre[i]);
        strcpy(contactos->numero[i + 1], contactos->numero[i]);
        i--;
    }

    strcpy(contactos->nombre[i + 1], nom);
    strcpy(contactos->numero[i + 1], num);
}

void listarAgenda(agendaContactos contactos){
    int i;
    for (i = 0; i <= contactos.cant; i++){
        printf("Nombre del contactos %d: %s\n",i+1, contactos.nombre[i]);
        printf("Numero del contactos %d: %s\n",i+1, contactos.numero[i]);
    }
}

int buscarNombre(agendaContactos contactos, TElementoDC nom[15]){
    int i=0;
    
    while (i<=contactos.cant && strcmp(contactos.nombre[i], nom) != 0)
        i++;

    if (i<=contactos.cant)
        return i;
    else
        return -1;
}

int buscarNombreBinaria(agendaContactos contactos, TElementoDC nom[15]){
    int inicio = 0, fin = contactos.cant -1, medio, pos = -1, cmp;
    
    while (inicio <= fin && pos == -1){
        medio = (inicio + fin) / 2;
        cmp = strcmp(nom, contactos.nombre[medio]);
        if(cmp == 0)
            pos = medio;
        else if (cmp<0)
            fin = medio - 1;
        else
            inicio = medio + 1;
    }
    
    return pos;   
}