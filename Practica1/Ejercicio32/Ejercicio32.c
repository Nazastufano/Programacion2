#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* 32. En un archivo binario se registran temperaturas diarias máxima y mínima para algunas ciudades
del país en un mes determinado. Cada registro tiene los siguientes campos: ciudad (cadena de
20, archivo ordenado por este campo), día del mes (1..30), temperatura máxima (float),
temperatura mínima (float). Listar para cada ciudad sus temperaturas máximas y mínimas en el
mes; y al final del listado la ciudad que tuvo la menor temperatura en el mes, indicando el día. */

typedef struct {
    char ciudad[21];
    unsigned int dia;
    float tempMax, tempMin;
} TRDatosTemp;

void MostrarTemp(char *);

void main(){
    MostrarTemp("temperaturas.dat");
}

void MostrarTemp(char *nomArch){
    TRDatosTemp reg;
    FILE *archB;
    float menorTemp = 99;
    unsigned int diaMenorTemp;
    char nomMenorTemp[21];

    if ((archB = fopen(nomArch, "rb")) == NULL)
        printf("Error al abrir el archivo. Es posible que el archivo no exista");
    else {
        while (fread(&reg, sizeof(TRDatosTemp), 1, archB) == 1) {
            printf("La temperatura maxima es %f, y la minima %f de la ciudad %s \n", reg.tempMax, reg.tempMax, reg.ciudad);
            if (menorTemp > reg.tempMin){
                menorTemp = reg.tempMin;
                diaMenorTemp = reg.dia;
                strcpy(nomMenorTemp, reg.ciudad);
            }
        }
        fclose(archB);
        printf("La ciudad que tuve menor temperatura es %s el dia %d", nomMenorTemp, diaMenorTemp);
    }

}
