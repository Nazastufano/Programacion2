#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 8. Dada una lista doblemente enlazada que contiene los inscriptos a un curso, en la que en cada 
nodo se tiene: 
    • Apellido (ordenada por este campo) 
    • Nombre (los inscriptos con el mismo apellido, se ordenan por este campo) 
    • Categoría (docente, alumno, externo) 
a) listarlos en orden alfabético, indicando el importe total recaudado. El valor del curso es un 
dato leído por teclado, los docentes tienen un 30% de descuento, y los alumnos un 10%.  
b) listar los inscriptos externos en orden alfabético descendente. 
c) verificar si existe una persona con apellido X (dato) y nombre Y (dato) dentro de la lista de 
inscriptos */   

typedef struct nodoD{
    char apellido[20];
    char nombre[20];
    char categoria[20];
    struct nodoD *sig, *ant;
}nodoD;

typedef nodoD * pNodoD;

typedef struct {
    pNodoD pri, ult;
}TListaD;

void listarOrden(TListaD LD, float valorCurso);
void listarExternos(TListaD LD);
int buscarPersona(TListaD LD, char X[20], char Y[20]);

void main(){
    TListaD LD;
    float valorCurso;
    char Y[20], X[20];
    do{
        printf("Ingrese el valor del curso: \n");
        scanf("%f", &valorCurso);
    } while (valorCurso < 0);


    listarOrden(LD, valorCurso);

    listarExternos(LD);

    printf("Ingrese un apellido a buscar");
    scanf("%s", X);
    
    printf("Ingrese el nombre de la persona a buscar: \n");
    scanf("%s", Y);

    if (buscarPersona(LD, X, Y))
        printf("Existe la persona: %s, %s\n", X, Y);
    else
        printf("No existe la persona: %s, %s\n", X, Y);
}

void listarOrden(TListaD LD, float valorCurso){
    pNodoD aux = LD.pri;
    float importeTotal = 0;

    while (aux != NULL){
        if (strcmp(aux->categoria, "docente") == 0)
            importeTotal += valorCurso*(1 - 0.3);
        else if (strcmp(aux->categoria, "alumno") == 0)
            importeTotal += valorCurso*(1 - 0.1);
        else 
            importeTotal += valorCurso;
        printf("%s, %s es %s \n", aux->apellido, aux->nombre, aux->categoria);
        aux = aux->sig;
    }

    if (importeTotal)
        printf("El importe total recaudado es: %.2f\n", importeTotal);
}

void listarExternos(TListaD LD){
    pNodoD aux = LD.ult;

    while (aux != NULL){
        if (strcmp(aux->categoria, "externo") == 0)
            printf("%s, %s \n", aux->apellido, aux->nombre);
        
        aux = aux->ant;
    }
}

int buscarPersona(TListaD LD, char X[20], char Y[20]){
    pNodoD aux = LD.pri;

    while (aux != NULL && (strcmp(aux->apellido, X) != 0 || strcmp(aux->nombre, Y) != 0))
        aux = aux->sig;
    
    if (aux != NULL)
        return 1;
    else 
        return 0;
}