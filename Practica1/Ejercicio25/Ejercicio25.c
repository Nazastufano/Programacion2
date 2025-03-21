#include <stdio.h>

/*25. Leer el nombre y la edad de N personas, calcular e imprimir:
a) el listado de nombres de las personas de más de X años (X es dato).
b) el porcentaje de las personas mayores de edad (sobre el total). */

#define LARGONOMBRE 20
#define MAXPERSONAS 100
void CargarPersonas(char [MAXPERSONAS][LARGONOMBRE], int [MAXPERSONAS], int);
void MostrarDatos(char [MAXPERSONAS][LARGONOMBRE], int [MAXPERSONAS], int , int);
void CalcPorcMayEd(char [MAXPERSONAS][LARGONOMBRE], int [MAXPERSONAS], int);
void main() {
    int N, X;
    char vNombres[MAXPERSONAS][LARGONOMBRE];
    int vEdad[MAXPERSONAS];

    printf("Cuantas personas desea ingresar? \n");
    scanf("%d", &N);

    CargarPersonas(vNombres, vEdad, N);
    
    printf("Ingrese la edad a superar\n");
    scanf("%d", &X);
    MostrarDatos(vNombres,vEdad,N,X);
    
    CalcPorcMayEd(vNombres,vEdad,N);
}

void CargarPersonas(char vNombres[MAXPERSONAS][LARGONOMBRE], int vEdad[MAXPERSONAS], int N){
    int i;
    for (i = 0; i < N; i++){
        printf("Ingrese el nombre de la persona num %d \n", i +1);
        scanf("%19s", vNombres[i]);
        printf("Ingrese la edad de la persona num %d \n", i +1);
        scanf("%d", &vEdad[i]);
    }
}

void MostrarDatos(char vNombres[MAXPERSONAS][LARGONOMBRE], int vEdad[MAXPERSONAS], int N, int X){
    int i;
    for (i = 0; i < N; i++)
        if (vEdad[i]>X)
            printf("%s \n", vNombres[i]);
    
}

void CalcPorcMayEd(char vNombres[MAXPERSONAS][LARGONOMBRE], int vEdad[MAXPERSONAS], int N){
    int i, contMay=0;
    for (i = 0; i < N; i++)
        if (vEdad[i]>=18)
            contMay++;
    
    printf("El porcentaje de personas mayores de edad es de %.2f%% ", (float)(contMay*100)/N);
}