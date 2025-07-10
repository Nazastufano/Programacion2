#include <stdio.h>
/* Ej 3- Dado os grafos G = (V, E) con |V|=N y G' = (V', E') con |V'|=N, determinar si G es
subgrafo de G' o G' es subgrafo de G o ninguno de los anteriores. Ambos grafos están
almacenados en la misma matriz (G en el triángulo inferior y G' en el superior) y ninguno
tiene bucle. */

#define MAX 10

void determinar(int matAdy[MAX][MAX], int N){
    int i = 0, j, g = 0, gPri = 0;

    if (i<=N && (g == 0 || gPri==0)){
        j = i+1;
        while (j<=N && (g == 0 || gPri==0)){
            if (matAdy[j][i] != matAdy[i][j]){
                if (matAdy[j][i] == 0)
                    g = 1;
                else
                    gPri = 1;
            }
            j++;
        }
        i+1;
    }

    if (gPri == g && gPri == 1 && g == 1)
        printf("Uno es subgrafo inducido del otro\n");
    else if (g == 0)
        printf("G' es subgrafo de G\n");
    else if (gPri == 0)
        printf("G es subgrafo de G'\n");
    else
        printf("Ninguno de los anteriores\n");
        
}