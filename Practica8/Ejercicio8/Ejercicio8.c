#include <stdio.h>
/*8. Desarrollar funciones recursivas para:
    a) generar un arreglo con el grado de cada vértice de un grafo almacenado en una matriz de
    adyacencia.
    b) hallar el vértice con el mayor grado de entrada, en un digrafo representado por una matriz
    de adyacencia. 
    c) determinar si todos los vértices de un grafo almacenado en media matriz de adyacencia
    (triángulo superior) tienen al menos un vértice adyacente con costo mayor a X (dato).
    d) generar un vector de registros con grado y vértice para aquellos vértices, de un grafo
    almacenado en una matriz de adyacencia, cuyo grado sea mayor a 3. */

typedef struct {
    int grado;
    int vertice;
} TReg;

void genararArreglo(int matAdy[10][10], int vec[10], int i, int j, int N);
void mayorGradoEntrada(int matAdy[10][10], int i, int j, int N, int grado, int *mayorGrado);
int verticeCostoMayorX(int matAdy[10][10], int i, int j, int N, int X);
void generarVecRegistros(int matAdy[10][10], TReg vecReg[10], int i, int j, int k, int N, int grado);

void main(){
    int matAdy[10][10], matAdyDG[10][10], matAdyPon[10][10];
    int vec[10] = {0};
    TReg vecReg[10];
    int N, M, O, mayorGrado=0, X;

    //cargarMatriz(matAdy, &N);
    genararArreglo(matAdy,vec,0,0,N);
    
    //cargarMatrizDG(matAdyDG, &M);
    mayorGradoEntrada(matAdyDG, 0,0,M,0,&mayorGrado);

    //cargarMatrizPon(matAdyPon,&O);
    printf("Ingrese un valor de X para superar por aristas adyacentes: \n");
    scanf("%d",&X);
    if (verticeCostoMayorX(matAdy,0,0,O,X))
        printf("Todos los vertices del grafo tienen al menos un vertice con costo mayor a X=%d", X);
    else
        printf("No todos los vertices del grafo tienen al menos un vertice con costo mayor a X=%d", X);    

    //cargarVecReg(vecReg);
    generarVecRegistros(matAdy,vecReg,0,0,-1,N,0);
}

void genararArreglo(int matAdy[10][10], int vec[10], int i, int j, int N){
    if (i<=N){  
        if (i != j && matAdy[i][j] == 1)
            vec[i] += 1;
        
        if (j<N)
            genararArreglo(matAdy,vec,i,j+1, N);
        else 
            genararArreglo(matAdy,vec,i+1,0, N);
    }
}

void mayorGradoEntrada(int matAdy[10][10], int i, int j, int N, int grado, int *mayorGrado){
    if (j <= N){
        if (i != j && matAdy[i][j] == 1)
            grado++;
        
        if (i<N)
            mayorGradoEntrada(matAdy, i+1, j, N, grado, mayorGrado);
        else {
            if (grado>*mayorGrado)
                *mayorGrado = grado;
            
            mayorGradoEntrada(matAdy, 0, j+1, N, 0, mayorGrado);
        }
    }
}

int verticeCostoMayorX(int matAdy[10][10], int i, int j, int N, int X){
    if (i<=N){
        if (matAdy[i][j] > X)
            return verticeCostoMayorX(matAdy,i+1,i+2,N,X);
        else if (j<N)
            return verticeCostoMayorX(matAdy,i,j+1,N,X);
        else
            return 0;
    } else
        return 1;
}

void generarVecRegistros(int matAdy[10][10], TReg vecReg[10], int i, int j, int k, int N, int grado){
    if (i<=N){
        if (i != j && matAdy[i][j] == 1)
            grado++;
        
        if (j<N)
            generarVecRegistros(matAdy, vecReg, i,j+1,k,N,grado);
        else {
            if (grado > 3){
                k++;
                vecReg[k].grado = grado;
                vecReg[k].vertice = i;
            }
            generarVecRegistros(matAdy, vecReg, i+1,0,k,N,0);
        }
    }
}