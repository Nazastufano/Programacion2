#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 31. El ranking de una asociación de tenistas es registrada en un archivo binario. Para cada jugador
se registra apellido y nombre, nacionalidad y puntaje. Realizar un subprograma que muestre los
datos del jugador ubicado en una posición recibida como parámetro. */

typedef struct{
    char apellidoYNombre[25], nacionalidad[25];
    int puntaje;
} TRegTenistas;

void LecEscriArch(char *, char *);
void MuestraPorPos(char *, int);

void main(){
    int pos;

    LecEscriArch("datos.txt", "tenistas.dat"); //testeo

    printf("Ingrese una posicion para buscar un tenista \n");
    scanf("%d", &pos);
    
    MuestraPorPos("tenistas.dat", pos);
}
//agregado innecesario para probar el ejercicio y practicar con lectura de archivo de texto
void LecEscriArch(char *nomArchT, char *nomArchB){
    TRegTenistas reg;
    FILE *archT, *archB;
    char apellido[15], nombre[15];
    archT = fopen(nomArchT, "r");
    if (archT == NULL)
        printf("Error al abrir el archivo de texto, es posible que no exista");
    else {
        archB = fopen(nomArchB, "wb");
        if (archB == NULL) {
            printf("Error al abrir el archivo binario, es posible que no exista");
            fclose(archT);
        } else {
            while (fscanf(archT,"%s %s %s %d", apellido, nombre, reg.nacionalidad, &reg.puntaje) == 4){
                strcat(apellido, " ");
                strcpy(reg.apellidoYNombre, apellido);
                strcat(reg.apellidoYNombre, nombre);
                fwrite(&reg, sizeof(TRegTenistas), 1, archB);
            }
            
            fclose(archB);
            fclose(archT);
        }   
    }
}
//Ejercicio:
void MuestraPorPos(char *nomArchB, int pos){
    TRegTenistas reg;
    FILE *archB;
    archB = fopen(nomArchB, "rb");
    if (archB == NULL)
        printf("Fallo al abrir el archivo binario. Es posible que no exista");
    else {
        fseek(archB, (pos-1)*sizeof(TRegTenistas), SEEK_SET);
        if (fread(&reg, sizeof(TRegTenistas), 1, archB) == 1)
            printf("El nombre y apellido del tenista es %s de nacionalidad %s y con un puntaje de %d \n", reg.apellidoYNombre, reg.nacionalidad, reg.puntaje);
        else 
            printf("No existe ningun tenista en la posicion ingresada");
        fclose(archB);
    }   
}