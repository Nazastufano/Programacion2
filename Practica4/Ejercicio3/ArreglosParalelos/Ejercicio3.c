#include <stdio.h>
#include <string.h>
#include "funciones.h"
/* 3. Desarrollar una agenda de contactos mediante un TDA. Para cada contacto se almacena
nombre y teléfono. Los contactos deben estar ordenados alfabéticamente. El TDA debe contar
con los siguientes operadores: iniciar agenda, agregar contacto, listar agenda, buscar por
nombre (búsqueda lineal).
Se solicitan dos implementaciones diferentes: una con arreglos paralelos y otra con arreglo de
registros.
Mejorar el operador buscar por nombre, recodificándolo como búsqueda binaria. */

void main(){
    datosContacto contactos;
    int tam = 0;
    iniciarAgenda(&contactos, &tam);
    
    listarAgenda(contactos, tam);

    agregarContacto(&contactos, &tam);
    listarAgenda(contactos, tam);

    buscarNombre(contactos, tam);
    buscarNombreBinaria(contactos, tam);
}