#include <stdio.h>

/* 20. Realizar un programa iterativo que calcule e imprima el equivalente binario de un número
entero positivo dado. */

void MostrarArreglo(int []);
void CalcularBinario(int);

void main(){
    unsigned int num, res;
    
    do {
        printf("Ingrese un numero para pasar a binario: \n");
        scanf("%d", &num);
        
        CalcularBinario(num);
        
        printf("Desea ingresar otro numero? (0 salir) \n");
        scanf("%d", &res);
    } while (res != 0);
}

void MostrarArreglo(int v[]){
    int i;
    for (i = 0; i < 8; i++)
        printf("%d ", v[i]);
    printf("\n");
}

void CalcularBinario(int num) {
    int i = 7, val;
    int v[8] = {0};
    
    while (num !=0) {
        val = num % 2;
        num = num/2;
        v[i--] = val;
    }
    MostrarArreglo(v);
}