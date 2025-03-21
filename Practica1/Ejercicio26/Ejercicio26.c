#include <stdio.h>

/* 26. Declarar un tipo struct para almacenar nombre, matrícula y promedio de un alumno.
Desarrollar una función que realice lectura de una variable del tipo creado. */

typedef struct {
    char nombre[20];
    int matricula;
    float prom;
} TRAlu;

void CargaAlumno(TRAlu *);
void MostrarAlumno(TRAlu );

int main(){
    TRAlu alumno1;
    
    CargaAlumno(&alumno1);
    MostrarAlumno(alumno1);
    return 0;
}
void CargaAlumno(TRAlu *alumno){
    printf("Ingrese el nombre del alumno \n");
    scanf("%s", alumno->nombre);
    printf("Ingrese la matricula del alumno \n");
    scanf("%d", &alumno->matricula);
    printf("Ingrese el promedio del alumno\n");
    scanf("%f", &alumno->prom);
}

void MostrarAlumno(TRAlu alumno){
    printf("Nombre: %s\n", alumno.nombre);
    printf("Matricula: %d\n", alumno.matricula);
    printf("Promedio: %.2f\n", alumno.prom);
}
