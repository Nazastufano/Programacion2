#include <stdio.h>
#include <stdlib.h>

/* 29. Un sensor de temperatura realiza mediciones periódicas (una cada 5 seg.). Las mismas son
registradas en un archivo binario, donde cada elemento es de tipo float. Implementar un
programa que genere dicho archivo y, otro programa que lo lea y muestre por pantalla
temperatura promedio, máxima y mínima. */

void CargaArchivo(FILE *);
void LecturaArchivo(FILE *);

void main(){
    FILE *arch;
    
    CargaArchivo(arch);
    LecturaArchivo(arch);   
}

void CargaArchivo(FILE *arch){
    float num;
    arch = fopen("datos.dat", "wb");
    if (arch == NULL)
        printf("Error en la apertura. Es posible que el archivo no exista \n");
    else {
        scanf("%f", &num);
        while (num != 0){
            fwrite(&num, sizeof(float), 1, arch);
            scanf("%f", &num);
        }
    }
    fclose(arch);
}

void LecturaArchivo(FILE *arch){
    float num, tempMax = 0, tempMin, suma = 0;
    int cantMedi = 0;
    arch = fopen("datos.dat", "rb");
    
    if (arch == NULL) 
        printf("Error de la apertura. Es posible que el archivo no exista \n");
    else {
        fread(&num, sizeof(float), 1, arch);
        tempMin = tempMax = num;
        while (!feof(arch)){
            cantMedi++;
            suma += num;
            if (tempMin > num)
                tempMin = num;
            
            if (tempMax < num)
                tempMax = num;
                
            fread(&num, sizeof(float), 1, arch);
        }
        fclose(arch);
        if (cantMedi)
            printf("La temperatura promedio es %.2f, la maxima es %.2f y la minima es %.2f \n", suma/cantMedi, tempMax, tempMin);
        else 
            printf("No hay mediciones en el archivo");
    }    
}