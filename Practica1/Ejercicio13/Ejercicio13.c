#include <stdio.h>

/* 13. Corregir los errores del siguiente fragmento de código para que muestre los números naturales
impares hasta el 15 inclusive.

#define <stdio.h>
#define N 9 
int i;
for(i = 1; I < N; i++);
    printf(“%d”, &I); 
*/
#define N 15 

void main(){
    int i;
    for(i = 1; i <= N; i++)
        (i % 2 == 0) ? printf("%d", i): printf(" ");
}