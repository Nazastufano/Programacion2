#include <stdio.h>
#include <stdlib.h>

/* 5. Desarrollar un programa que cree un arreglo estático de punteros a enteros, y luego cargue en
él una cantidad desconocida de enteros (se encuentran en un archivo de texto). Posteriormente
a la carga, mostrar aquellos que sean positivos. Luego, para finalizar, liberar la memoria
solicitada en tiempo de ejecución. */
#define SIZE 100
void CargarArreglo(char *,int *,int *[SIZE]);
void MostrarPositivos(int *[SIZE], int);
void LiberarMemoria(int *[SIZE], int);

void main(){
    int *pNum[SIZE];
    int cantidad=-1;
    CargarArreglo("enteros.txt", &cantidad, pNum);
    MostrarPositivos(pNum, cantidad);
    LiberarMemoria(pNum, cantidad);
}

void CargarArreglo(char *nomArch, int *cantidad, int *pNum[SIZE]){
    FILE *arch;
    int num;
    if ((arch = fopen(nomArch, "r")) == NULL)
        printf("Error al abrir el archivo. Es posible que no exista");
    else {
        while ((fscanf(arch,"%d",&num) == 1) && (*cantidad < SIZE)) {
            (*cantidad)++;
            pNum[*cantidad] = (int *)malloc(sizeof(int));
            *pNum[*cantidad] = num;
        }
        fclose(arch);
    }
}

void MostrarPositivos(int *pNum[SIZE], int cantidad){
    int i;
    for (i = 0; i <= cantidad; i++)
        if (*pNum[i]>0)
            printf("%d ", *pNum[i]);
    printf("\n");
}

void LiberarMemoria(int *pNum[SIZE], int cantidad){
    int i;
    for (i = 0; i <= cantidad; i++)
        free(&(*pNum[i]));
}