#include <stdio.h>
#include <stdlib.h>

/* 30. Desarrollar un programa que lea y procese un archivo de texto generado por un radar vigía.
Cada línea contiene patente de un vehículo, velocidad registrada, velocidad máxima permitida,
fecha y hora de la medición. Cada dato está separado por un espacio. El programa debe
generar un archivo binario con los registros donde la velocidad registrada supere en más de un
20% a la velocidad máxima. Cada registro del archivo binario contiene los mismos datos que el
archivo de texto. Mostrar, al final del proceso, la cantidad de mediciones procesadas y la
cantidad de registros generados en el archivo binario. */

typedef struct {
    char patente[8], fecha[9], hora[6];
    int velocidad, velMax;
} TRegVigia;

void LecEscriArch(FILE *, FILE *);

void main(){
    FILE *archT, *archB;
    
    LecEscriArch(archT,archB);
}

void LecEscriArch(FILE *archT, FILE *archB){
    TRegVigia reg;
    int cantMedProc=0, cantRegGen=0;
    archT = fopen("mediciones.txt", "r");
    if (archT == NULL)
        printf("Error en la apertura del archivo de texto. Es posible que el archivo no exista \n");
    else {
        archB = fopen("registros.dat", "wb");
        if (archB == NULL) {
            printf("Error en la apertura del archivo binario. Es posible que el archivo no exista \n");
            fclose(archT);
        } else {
            //fscanf(archT, "%s %d %d %s %s", reg.patente, &reg.velocidad, &reg.velMax, reg.fecha, reg.hora);
            while (fscanf(archT, "%s %d %d %s %s", reg.patente, &reg.velocidad, &reg.velMax, reg.fecha, reg.hora) == 5){
                cantMedProc++;
                if (reg.velocidad>reg.velMax*1.2){
                    cantRegGen++;
                    
                    fwrite(&reg, sizeof(TRegVigia), 1, archB);
                }
                //fscanf(archT, "%s %d %d %s %s", reg.patente, &reg.velocidad, &reg.velMax, reg.fecha, reg.hora);
            }
            fclose(archB);
            fclose(archT);
        }
    }
    printf("La cantidad de mediciones procesadas fue %d y la cantidad de registros generados fue %d \n", cantMedProc, cantRegGen);
}
