#include <stdio.h>

/* 15. Desarrollar una función que reciba tres números enteros y devuelva si son consecutivos entre sí
o si no lo son. */

int SonConsecutivos(int a, int b, int c);

void main(){
    int num1,num2,num3;
    printf("Ingrese 3 numeros: \n");
    scanf("%d %d %d", &num1, &num2, &num3);

    SonConsecutivos(num1,num2,num3);
}

int SonConsecutivos(int a, int b, int c){
    int aux;
    while (a>b || b>c || a>c) {
        if (a>b) {
            aux = b;
            b = a;
            a = aux;
        } else if (b>c) {
            aux = c;
            c = b;
            b = aux;
        } else if (a>c) {
            aux = c;
            c = a;
            a = aux;
        }
    }
    
    return (b == a+1 && c == b+1) ? printf("Son consecutivos") : printf("No son consecutivos");
}