#include <stdio.h>
/*Transcribir en el entorno de desarrollo CodeBlocks el siguiente código, luego compilarlo y corregirlo hasta
que se pueda ejecutar:

#include <stdio.h>
void main()
Begin
    integer b, h = 3;
    b := 5;
    println(‘Bienvenido a Programacion B\n‘);
    printf(" Rectangulo con base b %d / y altura h %d \n", b, h, b);
    printf(" Superficie: %d \t Perimetro: %d", b*h, 2*b + 2*h);
    return 0;
End;*/

void main() {
    int b, h = 3;
    b = 5;
    
    printf("Bienvenido a Programacion B\n");
    printf(" Rectangulo con base b %d / y altura h %d \n", b, h, b);
    printf(" Superficie: %d \t Perimetro: %d", b*h, 2*b + 2*h);
    
    //return 0;
}