
/* 18. Para un digrafo dado, desarrollar un programa que genere la matriz de alcance R a partir de la
matriz A resultante del algoritmo de Floyd. */

#define MAX 10
#define INF 9999

void main(){
    int matAdy[MAX][MAX], R[MAX][MAX];
    inicializarMat(R);
    //cargarMatAdy(matAdy);
    generarMatR(matAdy,R);
}

void generarMatR(int matAdy[MAX][MAX], int R[MAX][MAX]){
    int i, j;

    for (i = 0; i < MAX; i++)
        for (j = 0; j < MAX; j++)
            if (matAdy[i][j] != INF)
                R[i][j] = 1;
}

void inicializarMat(int R[MAX][MAX]){
    int i,j;
    for (i = 0; i < MAX; i++)
        for (j = 0; j < MAX; j++)
            R[i][j] = 0;
}