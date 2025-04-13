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
    agendaContactos contactos;
    TElementoDC nom[15],num[15];
    int i, pos, tam = 0;
    contactos = iniciarAgenda();

    do{
        printf("Cuantos contactos desea ingresar?\n");
        scanf("%d", &tam);          
    } while (tam<1 || tam>SIZE);
    
    for (i = 0; i < tam; i++){
        printf("Ingrese el nombre del contacto %d\n", i+1);
        scanf("%s", nom);
        
        printf("Ingrese el numero del contacto %d\n", i+1);
        scanf("%s", num);

        agregarContacto(&contactos, nom, num);
    }

    listarAgenda(contactos);

    printf("Ingrese el nombre a buscar: ");
    scanf("%s", nom);
    pos = buscarNombre(contactos, nom);
    if (pos >= 0)
        printf("El numero de telefono del contacto: %s es: %s\n", nom, contactos.numero[pos]);
    else
        printf("El contacto: %s no se encuentra en la agenda\n", nom);   


    printf("Ingrese el nombre a buscar: ");
    scanf("%s", nom);
    
    pos = buscarNombreBinaria(contactos, nom);
    if (pos >= 0)
        printf("El numero de telefono del contacto: %s es: %s\n", nom, contactos.numero[pos]);
    else
        printf("El contacto: %s no se encuentra en la agenda\n", nom);
}