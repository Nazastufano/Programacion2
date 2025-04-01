#include <stdio.h>
#include <stdlib.h>
/* 28. Rehacer el ejercicio 12* suponiendo que los números se encuentran en un archivo de texto,
todos en la misma línea. ¿Como modificaría la lectura, si hubiera un valor por línea? 

* 12. Desarrollar un programa que muestre la suma de un conjunto de números naturales ingresados
por teclado. La serie finaliza al ingresar el número 0. 

*/

void main(){
    FILE *arch;
    int num, suma = 0;
    arch = fopen("datos.txt", "r");

    if (arch == NULL)
        printf("Error en la apertura. Es posible que el archivo no exista \n");
    else {
        while (fscanf(arch, "%d", &num) == 1)
            suma += num;
        
        fclose(arch);
    }
    printf("La suma de los elementos del archivo es: %d", suma);
}