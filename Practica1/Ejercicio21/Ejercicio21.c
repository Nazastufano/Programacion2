#include <stdio.h>

/* 21. Desarrollar un programa que lea un vector y, mediante opciones de un menú, calcule e imprima
lo siguiente:
a) los elementos en posiciones impares 1,3,5 o sea segundo, cuarto, sexto...
b) genere otro vector con los elementos divisibles por k (k dato). Muestre el nuevo vector con
otra función
c) busca la posición de un valor x (puede no existir) */

#define SIZE 10

void MostrarPosImpar(int []);
void MostrarArreglo(int [], int);
void GenerarArreglo(int [], int k);
void CargarArreglo(int []);
int BuscarPos(int [], int x);

void main(){
    int k, x, res, pos, v[SIZE];
    
    CargarArreglo(v);

    do {
        printf("Que operacion desea ejecutar? \n");
        printf("1. Mostrar los elementos de las posiciones impares \n");
        printf("2. Generar un vector con los elementos divisibles por un k ingresado por teclado \n");
        printf("3. Buscar la posicion de un elemento x \n");
        printf("0. Salir \n");
        scanf("%d", &res);

        switch (res){
        case 1:
            MostrarPosImpar(v);
            break;
        case 2:
            printf("Ingrese un elemento k: \n");
            scanf("%d", &k);
            GenerarArreglo(v,k);
            break;
        case 3:
            printf("Ingrese un elemento x: \n");
            scanf("%d", &x);
            pos = BuscarPos(v,x);
            if (pos != -1) 
                printf("La posicion del elemento %d es %d \n",x, pos);
            else
                printf("El elemento %d no se encuentra en el arreglo \n", x);
            break;
        default:        
            break;
        }
    } while (res != 0);
}

void MostrarPosImpar(int v[]){
    int i;
    printf("{ ");
    for (i = 0; i < SIZE; i++)
        if (i % 2 == 1)
            printf("%d ", v[i]);
    printf("} \n");
}

void MostrarArreglo(int v[], int N){
    int i;
    printf("{ ");
    for (i = 0; i < N; i++)
        printf("%d ", v[i]);
    printf("} \n");
}

void GenerarArreglo(int v[], int k){
    int i, j=0, v2[SIZE] = {0};
    for (i = 0; i < SIZE; i++)
        if (v[i] % k == 0)
            v2[j++]= v[i];
    
    MostrarArreglo(v2,j-1);
}

int BuscarPos(int v[], int x){
    int i=0;
    while (i<SIZE && v[i] != x)
        i++;

    return (i < SIZE) ? i : -1;
}

void CargarArreglo(int v[]){
    int i;
    for (i = 0; i < SIZE; i++){
        printf("Ingrese el elemento de la posicion %d: \n", i);
        scanf("%d", &v[i]);
    }
}