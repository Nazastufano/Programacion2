#include <stdio.h>

/*24. Desarrollar un programa que lea una matriz de enteros de NxM:
a) busque la posición de un valor x (puede no existir)
b) muestre el promedio de cada columna de la matriz. 
c) muestre para cada fila que tenga al menos un cero la cantidad de elementos que superan el
promedio de la matriz 
*/
#define SIZE 5
void CargarMatriz(int [][SIZE], int *, int *, int *);
void BuscarPos(int [][SIZE], int, int, int);
void MostrarPromPorCol(int [][SIZE], int, int);
void MostrarSupProm(int [][SIZE], int, int, float);

int main(){
    int mat[SIZE][SIZE],x, n,m, suma=0;
    float prom;
    CargarMatriz(mat, &suma, &n, &m);
    prom = (float)suma/(n*m);

    printf("Ingrese un elemento x a buscar: \n");
    scanf("%d", &x);
    
    BuscarPos(mat,x,n,m);
    
    MostrarPromPorCol(mat, n,m);
    MostrarSupProm(mat, n, m, prom);
}

void CargarMatriz(int mat[SIZE][SIZE], int *suma, int *n, int *m){
    int i,j;
    
    do {
        printf("Ingrese N y M \n");
        scanf("%d %d", n, m);
    } while (*n > SIZE || *m > SIZE);   

    for (i = 0; i < *n; i++) 
        for (j = 0; j < *m; j++){
            printf("Ingrese la posicion [%d][%d] ", i,j);
            scanf("%d", &mat[i][j]);
            *suma += mat[i][j];
        }
}

void BuscarPos(int mat[SIZE][SIZE], int x, int n, int m){
    int i=0, j=0;
    while (i < n && mat[i][j] != x) {
        
        while (j < m-1 && mat[i][j] != x)
            j++;
            
        if (mat[i][j] != x){
            j=0;
            i++;
        }
    }

    if (i<n)
        printf("La posicion del elemento %d es [%d][%d] \n",x, i, j);
    else
        printf("El elemento %d no se encuentra en la matriz \n",x);
}

void MostrarPromPorCol(int mat[SIZE][SIZE],int n, int m){
    int suma, i,j;

    for (j = 0; j < m; j++){
        suma = 0;
        for (i = 0; i < n; i++)
            suma += mat[i][j];
        printf("El promedio de la columna: %d es %.2f\n",j , (float)suma/m);
    }
    
}

void MostrarSupProm(int mat[SIZE][SIZE], int n, int m, float prom){
    int i,j, contElmSup;
    for (i = 0; i < n; i++){
        j=0;
        while (mat[i][j] != 0 && j < m-1)
            j++;
        
        if (mat[i][j] == 0){
            contElmSup = 0;
            for (j = 0; j < m; j++)
                if (mat[i][j]>prom)
                    contElmSup++;
            
            if (contElmSup>0)
                printf("En la fila %d superan el promedio %d elementos \n", i, contElmSup);        
        }
    }
}