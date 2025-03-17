#include <stdio.h>
/* 11. Desarrollar una macro que devuelva cada uno de los siguientes resultados:
a) Máximo de 2 números 
b) Caracter es alfabético

Implementar un programa que utilice las macros desarrolladas. */
#define maximo(a,b) ((a<b) ? b : a)
#define esAlfa(c) ((c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z') ? printf("es alfabetico") : printf("no es alfabetico"))

void main(){
    int num1, num2;
    char car;
    //a)
    printf("Ingrese 2 numeros: ");
    scanf("%d %d", &num1, &num2);
    
    printf("El maximo entre %d y %d es: %d \n",num1,num2, maximo(num1,num2));
    //b)

    printf("Ingrese un caracter: ");
    scanf(" %c", &car);
    
    printf("El caracter '%c' ",car);
    esAlfa(car);
}
