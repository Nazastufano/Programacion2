#include <stdio.h>
#include <string.h>
#include "funciones.h"

void iniciarAgenda(datosContacto *contactos, int *k){
    int i;
    char nomAux[15], numAux[15];

    do{
        printf("Cuantos contactos desea ingresar?\n");
        scanf("%d", k);          
    } while (*k<1 || *k>SIZE);
    
    for (i = 0; i < *k; i++){
        printf("Ingrese el nombre del contacto %d\n", i+1);
        scanf("%s", nomAux);
        
        printf("Ingrese el numero del contacto %d\n", i+1);
        scanf("%s", numAux);

        insertarOrdenado(contactos,nomAux,numAux,i);
    }
}

void agregarContacto(datosContacto *contactos, int *k){
    char nom[15],num[15];
    if (*k<SIZE){
        printf("Ingrese el nombre del contacto\n");
        scanf("%s", nom);
            
        printf("Ingrese el numero del contacto\n");
        scanf("%s", num);
        insertarOrdenado(contactos,nom,num,*k);
        (*k)++;
    } else
        printf("Agenda llena. No se puede agregar mas contactos. \n");
    
    
}

void insertarOrdenado(datosContacto *contactos, char nom[15], char num[15],int k){
    int i = k - 1;

    while (i >= 0 && strcmp(nom, contactos->nombre[i]) < 0) {
        strcpy(contactos->nombre[i + 1], contactos->nombre[i]);
        strcpy(contactos->numero[i + 1], contactos->numero[i]);
        i--;
    }

    strcpy(contactos->nombre[i + 1], nom);
    strcpy(contactos->numero[i + 1], num);
}

void listarAgenda(datosContacto contactos, int k){
    int i;
    for (i = 0; i < k; i++){
        printf("Nombre del contactos %d: %s\n",i+1, contactos.nombre[i]);
        printf("Numero del contactos %d: %s\n",i+1, contactos.numero[i]);
    }
    
}

void buscarNombre(datosContacto contactos, int tam){
    char nom[15];
    int i=0;
    printf("Ingrese el nombre a buscar: ");
    scanf("%s", nom);

    while (i<tam && strcmp(contactos.nombre[i], nom) != 0)
        i++;
    if (i<=tam)
        printf("El numero de telefono del contacto: %s es: %s\n", nom, contactos.numero[i]);
    else
        printf("El contacto: %s no se encuentra en la agenda\n", nom);   
}

void buscarNombreBinaria(datosContacto contactos, int tam){
    int inicio = 0, fin = tam -1, medio, encontrado = 0, cmp;
    char nom[15];

    printf("Ingrese el nombre a buscar: ");
    scanf("%s", nom);
    
    while (inicio <= fin && !encontrado){
        medio = (inicio + fin) / 2;
        cmp = strcmp(nom, contactos.nombre[medio]);
        if(cmp == 0)
            encontrado = 1;
        else if (cmp<0)
            fin = medio - 1;
        else
            inicio = medio + 1;
    }
    
    if (encontrado == 1)
        printf("El numero de telefono del contacto: %s es: %s\n", nom, contactos.numero[medio]);
    else
        printf("El contacto: %s no se encuentra en la agenda\n", nom);
}