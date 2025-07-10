
/* 21. Dada la matriz de alcance correspondiente a un digrafo, realizar una función recursiva para
hallar el vértice alcanzado por la mayor cantidad de vértices. En el caso de que existan más de
uno, devolver el primero encontrado. */

#define MAX 10

void mayorCantAlca(int R[MAX][MAX], int i, int j, int N, int cantAdy, int *maxCantAdy, int *vertice);

void main(){

}

void mayorCantAlca(int R[MAX][MAX], int i, int j, int N, int cantAdy, int *maxCantAdy, int *vertice){
    if (i<=N){
        if (R[i][j] == 1)
            cantAdy +=1;
        
        if (j<N){
            mayorCantAlca(R, i, j+1, N,cantAdy, maxCantAdy, vertice);
        } else {
            if (cantAdy > *maxCantAdy){
                *maxCantAdy = cantAdy;
                *vertice = i;
            }
            mayorCantAlca(R, i+1, 0, N, 0, maxCantAdy, vertice);
        }
    }
}