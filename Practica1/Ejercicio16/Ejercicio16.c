#include <stdio.h>

/* 16. Desarrollar un subprograma que reciba una cantidad de segundos y devuelva su equivalente en
el formato horas:minutos:segundos */

void SegundosAHMS(unsigned int s);

void main(){
    unsigned int s;
    printf("Ingrese una cantidad de segundos: \n");
    scanf("%d",&s);

    SegundosAHMS(s);
}

void SegundosAHMS(unsigned int s){
    unsigned int seg, min, horas;
    horas = s / 3600;
    min = (s % 3600) / 60;
    seg = s % 60;

    printf("%d:%d:%d", horas,min,seg);
}