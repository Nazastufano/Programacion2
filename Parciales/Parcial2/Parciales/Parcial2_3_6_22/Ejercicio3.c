
/* Ej 3- Dado un digrafo de orden N almacenado en una matriz de adyacencia (los vértices numerados
de 1 a N) generar mediante una única función recursiva un arreglo con los vértices que tengan
bucle almacenando además su grado de salida. Mostrar el vector generado.
    Desarrollar un main completo que incluya declaraciones, inicializaciones, invocaciones y resultados obtenidos. */

#define MAX 10

typedef struct {
    int vertice;
    int gradoSalida;
} TV;


void main(){
    TV vecBuc[MAX];
    int matAdy[MAX][MAX];
    int N, K = -1;
    cargaMat(matAdy, &N);
    
    generarVec(matAdy, vecBuc, 0, 0, &K, N-1);
}

void generarVec(int matAdy[MAX][MAX], TV vecBuc[MAX], int i, int j, int *k, int N){
    if (i<=N){
        if (matAdy[i][i] != 0){
            if (j == 0){
                (*k)++;
                vecBuc[*k].vertice = i;
                vecBuc[*k].gradoSalida = 0;
            }
            
            vecBuc[*k].gradoSalida += matAdy[i][j];

            if (j<N)
                generarVec(matAdy,vecBuc,i,j+1,k,N);
            else 
                generarVec(matAdy, vecBuc, i+1,0,k,N);
        } else
            generarVec(matAdy, vecBuc, i+1,0,k,N);
    }    
}