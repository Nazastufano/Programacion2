#include <stdio.h>
/*10) Reescribir cada una de las siguientes porciones de código en una sola sentencia mediante el uso
del operador condicional:

a)  if(a < b)
        c = a;
    else 
        c = b;

b)  if(a < b && b < c)
        printf(“ordenados”);
    else 
        printf(“desordenados”);
*/

void main(){
    int a,b,c;
    
    //a)
    c = (a < b) ? a : b;

    //b)
    (a < b && b < c) ? printf("ordenados") : printf("desordenados");
}